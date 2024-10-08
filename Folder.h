#include"Note.h"
#include<iostream>
#include<map>


class Folder : public Subject {
public:

    explicit Folder(int id, const std::string &name);

    Folder() = default;

    void setName(std::string name);

    int getId() const;

    std::string getName() const;

    void showNotes();

    void addNote(const std::string &name, const std::string &content, bool &Locked, bool &Important);

    void deleteNote(int id);

    Note *getNote(int id);

    bool getEmpty() const;


    void setImportantName();

    void notify(int c) override;

    void removeObserver(Observer *o) override;

    void addObserver(Observer *o) override;

    ~Folder() override = default;

    int printNoteCounter() const;

    std::list<Note> searchImportant() const;

    std::list<Note> searchNotesByName(const std::string &searchString) const;

    std::list<Note> searchNotesByText(const std::string &searchString) const;


private:
    int NumberOfNotes;
    std::string FolderName;
    int FolderId;
    std::map<int, Note> notes;
    bool Empty;
    std::list<Observer *> O;
};