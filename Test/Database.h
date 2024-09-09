#include<map>
#include<iostream>
#include"NoteCounterNotifier.h"

class Database {
public:
    Database();

    void createFolder();

    void removeFolder();

    void showFolders();

    Folder* getFolder(int id);

    bool getIsEmpty()const ;

    void createImportantFolder();
    int printFolderCounter() {
        return NumberOfFolders;
    }

private:
    int NumberOfFolders;
    std::map<int, Folder> datas;
    bool IsEmpty;
};