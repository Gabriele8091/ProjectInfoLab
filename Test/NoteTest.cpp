#include"gtest/gtest.h"
#include"Note.h"


class NoteTest : public ::testing::Test {
protected:
    NoteTest() {
        note = new Note();
    }
    ~NoteTest() {
        delete note;
    }
    Note* note;
};

