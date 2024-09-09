#include "Database.h"
#include "gtest/gtest.h"
#include <sstream>
#include <iostream>

class DatabaseTest : public ::testing::Test {
protected:
    void SetUp() override {}
    void TearDown() override {}
};


TEST_F(DatabaseTest, CreateFolder) {
    Database db;
    db.createFolder();
    EXPECT_EQ(db.printFolderCounter(), 2);
}


TEST_F(DatabaseTest, RemoveFolder) {
    Database db;
    db.createFolder();
    db.removeFolder();
    EXPECT_EQ(db.printFolderCounter(), 1);
}
