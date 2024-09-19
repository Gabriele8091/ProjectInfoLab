#include<map>
#include<iostream>
#include"NoteCounterNotifier.h"

class Database {
public:
    Database();

    void createFolder(std::string & name);

    void removeFolder(int id);

   void showFolders();

    Folder* getFolder(int id);

    bool getEmpty()const ;

    void createImportantFolder();

private:
    int NumberOfFolders;
    std::map<int, Folder> datas;
    bool Empty;
};