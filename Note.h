#include <iostream>
#include <string>
class Note {
public:

    explicit Note(int id);
    Note()=default;

    void setNoteName();

    void setNoteContent();

    [[nodiscard]] std::string getNoteName()const;

    [[nodiscard]] std::string getNoteContent()const;

    [[nodiscard]] int getNoteId()const;

    void setNoteIsLocked();

    [[nodiscard]] bool getNoteIsLocked()const;
private:
    std::string NoteName;
    std::string NoteContent;
    int NoteId;
    bool IsLocked;
};