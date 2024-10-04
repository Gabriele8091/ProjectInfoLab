#include<map>
#include<iostream>
#include"NoteCounterNotifier.h"

class Database {
public:
    Database();

    void createFolder(const std::string & name);

    void removeFolder(int id);

   void showFolders();

    Folder* getFolder(int id);

    bool getEmpty()const ;

    void createImportantFolder();

    std::list<std::list<Note>> searchImportant() const;

    std::list<std::list<Note>> searchNotesByName(const std::string& searchString) const;

    std::list<std::list<Note>> searchNotesByText(const std::string& searchString) const;

    std::list<Folder> searchFoldersByName(const std::string& searchString) const;



private:
    int NumberOfFolders;
    std::map<int, Folder> datas;
    bool Empty;
};