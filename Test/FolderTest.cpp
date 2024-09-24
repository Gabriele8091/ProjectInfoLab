#include <gtest/gtest.h>
#include "Folder.h"
#include <gtest/gtest.h>


class FolderTest : public ::testing::Test {
protected:
    void SetUp() override {
        folder = new Folder(1, "Test Folder");
    }

    void TearDown() override {
        delete folder;
    }

    Folder* folder;
};


TEST_F(FolderTest, SearchNotesByName) {
    std::string title1 = "First Note";
    std::string content1 = "Some Content";
    bool locked = false;
    bool important = false;

    std::string title2 = "Special Note";
    std::string content2 = "More Content";

    folder->addNote(title1, content1, locked, important);
    folder->addNote(title2, content2, locked, important);

    std::list<Note> result = folder->searchNotesByName("Special");

    ASSERT_EQ(result.size(), 1);
    ASSERT_EQ(result.front().getName(), "Special Note");
}


TEST_F(FolderTest, SearchNotesByText) {
    std::string title = "Note";
    std::string content = "Specific Text";
    bool locked = false;
    bool important = false;

    folder->addNote(title, content, locked, important);

    std::list<Note> result = folder->searchNotesByText("Specific");

    ASSERT_EQ(result.size(), 1);
    ASSERT_EQ(result.front().getContent(), "Specific Text");
}


TEST_F(FolderTest, SearchImportantNotes) {
    std::string title1 = "Regular Note";
    std::string content1 = "Regular Content";
    bool locked = false;
    bool important1 = false;

    std::string title2 = "Important Note";
    std::string content2 = "Important Content";
    bool important2 = true;

    folder->addNote(title1, content1, locked, important1);
    folder->addNote(title2, content2, locked, important2);

    std::list<Note> result = folder->searchImportant();

    ASSERT_EQ(result.size(), 1);
    ASSERT_EQ(result.front().getName(), "Important Note");
    ASSERT_TRUE(result.front().getImportant());
}