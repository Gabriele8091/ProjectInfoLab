
#include "Database.h"

Database::Database() {
    IsEmpty = true;
    NumberOfFolders =0;
    createImportantFolder();
}

void Database::createFolder() {
    Folder folder(NumberOfFolders);
    NumberOfFolders++;
    datas.insert(std::pair<int, Folder>(folder.getFolderId(), folder));
    IsEmpty=false;
    }

    void Database::removeFolder() {
    if(IsEmpty){
        std::cout << "There are no folders to remove!" << std::endl;
        return;
    }
    else {
        showFolders();
        std::cout << "Enter the ID of the folder you want to remove: " << std::endl;
        int id;
        std::cin >> id;
        datas.erase(id);
        if(datas.empty()){
            IsEmpty = true;
        }
    }
}

void Database::showFolders() {
    if(IsEmpty){
        std::cout << "There are no folders to show!" << std::endl;
        return;
    }
    else{
        for(auto it = datas.begin(); it != datas.end(); it++) {
            std::cout << "Folder ID: " << it->first << " Folder Name: " << it->second.getFolderName() << std::endl;
        }
    }
}

Folder *Database:: getFolder(int id) {
  for(auto it = datas.begin(); it != datas.end(); it++) {
      if(it->first == id) {
         return &it->second;
      }
      else {
          std::cout << "Folder not found!" << std::endl;
          return nullptr;
      }
   }
 }


bool Database::getIsEmpty()const {
    return IsEmpty;
}

void Database::createImportantFolder() {
    Folder folder;
    folder.setImportantName();
    datas.insert(std::pair<int, Folder>(NumberOfFolders, folder));
    NumberOfFolders++;
    IsEmpty = false;
}


