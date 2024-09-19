
#include "Database.h"

Database::Database() {
    Empty = true;
    NumberOfFolders =0;
    createImportantFolder();
}

void Database::createFolder(std::string & name) {
    Folder folder(NumberOfFolders,name);
    NumberOfFolders++;
    datas.insert(std::pair<int, Folder>(folder.getId(), folder));
    Empty=false;
    }

    void Database::removeFolder(int id) {
        for(auto it = datas.begin(); it != datas.end(); it++) {
            if(it->first == id) {
                datas.erase(it);
                break;
            }
        }
        if(datas.empty()){
            Empty = true;
        }
    }


Folder *Database:: getFolder(int id) {
  for(auto it = datas.begin(); it != datas.end(); it++) {
      if(it->first == id) {
         return &it->second;
      }

   }
 }


bool Database::getEmpty()const {
    return Empty;
}

void Database::createImportantFolder() {
    Folder folder;
    folder.setImportantName();
    datas.insert(std::pair<int, Folder>(NumberOfFolders, folder));
    NumberOfFolders++;
    Empty = false;
}

void Database::showFolders() {
    for(auto it = datas.begin(); it != datas.end(); it++) {
        std::cout << "Folder ID: " << it->first << " Folder Name: " << it->second.getName() << " Number of Notes held:"<< it->second.printNoteCounter() << std::endl;
    }
}
