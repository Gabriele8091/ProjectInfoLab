#include"Note.h"
#include<iostream>
#include<map>

class Folder:public Subject {
public:

      explicit Folder(int id);

   Folder()=default;



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


    void notify() override;

    void notify2() override;

    void removeObserver(Observer* o) override;

    void addobserver(Observer*o) override;

    ~Folder() override =default ;

    int printNoteCounter() const;


private:
    int NumberOfNotes;
    std::string  FolderName;
    int FolderId;
    std::map<int, Note> notes;
    bool IsEmpty;
    std::vector<Observer*> O;
};