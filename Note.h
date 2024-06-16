#include <iostream>
#include <string>
class Note {
public:

    explicit Note(int id);
    Note()=default;

    void setNoteName();

    void setNoteContent();

     std::string getNoteName()const;

     std::string getNoteContent()const;

     int getNoteId()const;

    void setNoteIsLocked();

    [[nodiscard]] bool getNoteIsLocked()const;
private:
    std::string NoteName;
    std::string NoteContent;
    int NoteId;
    bool IsLocked;
};