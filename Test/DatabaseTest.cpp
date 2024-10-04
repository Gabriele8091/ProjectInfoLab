#include <gtest/gtest.h>
#include "Database.h"

class DatabaseTest : public ::testing::Test {
protected:

    void SetUp() override {

        db.createFolder(folderName1);
        db.createFolder(folderName2);
    }

    void TearDown() override {}

    Database db;
    std::string folderName1 = "Folder 1";
    std::string folderName2 = "Special Folder";
};


TEST_F(DatabaseTest, SearchFoldersByName) {
    std::list<Folder> result = db.searchFoldersByName("Special");
    ASSERT_EQ(result.size(), 1);
    ASSERT_EQ(result.front().getName(), "Special Folder");
}


TEST_F(DatabaseTest, SearchImportantNotes) {
    Folder *folder = db.getFolder(0);
    std::string title = "Important Note";
    std::string content = "Important Content";
    bool locked = false;
    bool important = true;

    folder->addNote(title, content, locked, important);
    std::list<std::list<Note>> result = db.searchImportant();

    ASSERT_EQ(result.front().size(), 1);
    ASSERT_EQ(result.front().front().getName(), "Important Note");
}

TEST_F(DatabaseTest, SearchImportantNotesNotFound) {
    Folder *folder = db.getFolder(0);
    std::string title = "Important Note";
    std::string content = "Important Content";
    bool locked = false;
    bool important = false;

    folder->addNote(title, content, locked, important);
    std::list<std::list<Note>> result = db.searchImportant();

    ASSERT_EQ(result.front().size(), 0);
}

TEST_F(DatabaseTest, SearchFolderByNameNotFound) {
    std::list<Folder> result = db.searchFoldersByName("Not Found");
    ASSERT_EQ(result.size(), 0);
}


TEST_F(DatabaseTest, GetFolderVoid) {
    Folder *folder = db.getFolder(4);
    ASSERT_EQ(folder, nullptr);
}