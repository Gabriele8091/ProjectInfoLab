#include<map>
#include<iostream>
#include"Folder.h"

class Database {
public:
    Database();

    void createFolder();

    void removeFolder();

    void showFolders();

    Folder* getFolder(int id);

    bool getIsEmpty()const ;

private:
    int NumberOfFolders;
    std::map<int, Folder> datas;
    bool IsEmpty;
};