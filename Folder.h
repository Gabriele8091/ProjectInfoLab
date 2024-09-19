#include"Note.h"
#include<iostream>
#include<map>
//cerca le note per contenuto del testo per importanti
class Folder:public Subject {
public:

    explicit Folder(int id,std::string name);

    Folder()=default;

    void setName(std::string name);

    int getId()const;

    std::string getName();

    void showNotes();

    void addNote(std::string &name, std::string &content, bool &Locked,bool& Important);

    void deleteNote(int id);

    Note *getNote(int id);

    bool getEmpty()const;

    bool getLocked()const;

    void  setImportantName();

    void notify(int c) override;

    void removeObserver(Observer* o) override;

    void addobserver(Observer*o) override;

    ~Folder() override =default ;

    int printNoteCounter() const;


private:
    int NumberOfNotes;
    std::string  FolderName;
    int FolderId;
    std::map<int, Note> notes;
    bool Empty;
    std::list<Observer*> O;
};