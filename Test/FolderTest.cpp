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



TEST(FolderTest, AddNote) {
    Folder folder(1);
    folder.addNote();
    EXPECT_EQ(folder.getNumberOfNotes(), 2);
}



TEST(FolderTest, DeleteNote) {

    Folder folder(1);

    folder.addNote();

    folder.deleteNote(1);
    EXPECT_EQ(folder.getNumberOfNotes(), 1);
}

