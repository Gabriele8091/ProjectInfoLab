#include <gtest/gtest.h>
#include "Note.h"

class NoteTest : public ::testing::Test {
protected:
    void SetUp() override {
        std::string title = "Test Note";
        std::string content = "Some Content";
        bool locked = false;
        bool Important = false;
        note = new Note(1, title, content, locked, Important);
    }

    void TearDown() override {
        delete note;
    }

    Note *note;
};

TEST_F(NoteTest, SetNoteName) {
    std::string name = "New Name";
    note->setName(name);
    ASSERT_EQ(note->getName(), "New Name");
}

TEST_F(NoteTest, SetNoteContent) {
    std::string content = "New Content";
    note->setContent(content);
    ASSERT_EQ(note->getContent(), "New Content");
}

TEST_F(NoteTest, SetNoteLocked) {
    bool locked = true;
    note->setLocked(locked);
    ASSERT_EQ(note->getLocked(), true);
}