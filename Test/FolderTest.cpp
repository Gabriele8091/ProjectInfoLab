#include"gtest/gtest.h"
#include"Folder.h"
#include <sstream>
#include <iostream>


TEST(FolderTest, SetFolderName) {
    Folder n;

    std::istringstream simulatedInput("Cartella di esempio\n");
    std::cin.rdbuf(simulatedInput.rdbuf());

    n.setFolderName();

    EXPECT_EQ(n.getFolderName(), "Cartella di esempio");
}

class FolderTest : public ::testing::Test {
protected:
    void SetUp() override {
        originalCinBuffer = std::cin.rdbuf();
        originalCoutBuffer = std::cout.rdbuf();
    }

    void TearDown() override {
        std::cin.rdbuf(originalCinBuffer);
        std::cout.rdbuf(originalCoutBuffer);
    }

    std::streambuf* originalCinBuffer;
    std::streambuf* originalCoutBuffer;
};

TEST_F(FolderTest, AddNote) {
    std::istringstream simulatedFolderInput("Test Folder\n");
    std::cin.rdbuf(simulatedFolderInput.rdbuf());
    Folder folder(1);

    std::istringstream simulatedNoteInput("Note Name\nNote Content\n0\n");
    std::cin.rdbuf(simulatedNoteInput.rdbuf());
    folder.addNote();

    Note* retrievedNote = folder.getNote(1);
    ASSERT_NE(retrievedNote, nullptr);
    EXPECT_EQ(retrievedNote->getNoteName(), "Note Name");
}



TEST_F(FolderTest, DeleteNote) {
    std::istringstream simulatedFolderInput("Test Folder\n");
    std::cin.rdbuf(simulatedFolderInput.rdbuf());
    Folder folder(1);

    std::istringstream simulatedNoteInput("Note to delete\nNote Content\n0\n");
    std::cin.rdbuf(simulatedNoteInput.rdbuf());
    folder.addNote();

   std::ostringstream coutBuffer;
   std::cout.rdbuf(coutBuffer.rdbuf());

    std::istringstream simulatedDeleteInput("1\n");
    std::cin.rdbuf(simulatedDeleteInput.rdbuf());

    folder.deleteNote();

   std::string output = coutBuffer.str();

    EXPECT_NE(output.find("Note deleted successfully!"), std::string::npos);

    Note* retrievedNote = folder.getNote(1);
    EXPECT_EQ(retrievedNote, nullptr);
}

