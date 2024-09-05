#include"gtest/gtest.h"
#include"Note.h"

TEST(NoteTest, SetNoteName) {
    Note n;

    std::istringstream simulatedInput("Nota di esempio\n");
    std::cin.rdbuf(simulatedInput.rdbuf());

    n.setNoteName();

    EXPECT_EQ(n.getNoteName(), "Nota di esempio");
}

TEST(NoteTest, SetNoteContent) {
    Note n;

    std::istringstream simulatedInput("Contenuto di esempio\n");
    std::cin.rdbuf(simulatedInput.rdbuf());

    n.setNoteContent();

    EXPECT_EQ(n.getNoteContent(), "Contenuto di esempio");
}

TEST(NoteTest, SetNoteIsLocked) {
    Note n;

    std::istringstream simulatedInput("1\n");
    std::cin.rdbuf(simulatedInput.rdbuf());

    n.setNoteIsLocked();

    EXPECT_EQ(n.getNoteIsLocked(), true);
}