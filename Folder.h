#include"Note.h"
#include<iostream>
#include<map>

class Folder {
public:

      explicit Folder(int id);

   Folder()=default;

    ~Folder() = default;

    void setFolderName();

     int getFolderId()const;

     std::string getFolderName();

    void showNotes();

    void addNote();

    void deleteNote();

    void editNote();

    Note *getNote(int id);
        [[nodiscard]] bool getIsEmpty()const;

    bool getIsLocked()const;
    void  setImportantName();

private:
    int NumberOfNotes;
    std::string  FolderName;
    int FolderId;
    std::map<int, Note> notes;
    bool IsEmpty;
};