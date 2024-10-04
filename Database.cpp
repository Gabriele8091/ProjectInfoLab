
#include "Database.h"

Database::Database() {
    Empty = true;
    NumberOfFolders = 0;
    createImportantFolder();
}

void Database::createFolder(const std::string &name) {
    Folder folder(NumberOfFolders, name);
    NumberOfFolders++;
    datas.insert(std::pair<int, Folder>(folder.getId(), folder));
    Empty = false;
}

void Database::removeFolder(int id) {
    for (auto it = datas.begin(); it != datas.end(); it++) {
        if (it->first == id) {
            datas.erase(it);
            break;
        }
    }
    if (datas.empty()) {
        Empty = true;
    }
}


Folder *Database::getFolder(int id) {
    for (auto it = datas.begin(); it != datas.end(); it++) {
        if (it->first == id) {
            return &it->second;
        }

    }
    return nullptr;
}


bool Database::getEmpty() const {
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
    for (auto it = datas.begin(); it != datas.end(); it++) {
        std::cout << "Folder ID: " << it->first << " Folder Name: " << it->second.getName() << " Number of Notes held:"
                  << it->second.printNoteCounter() << std::endl;
    }
}

std::list<std::list<Note>> Database::searchImportant() const {
    std::list<std::list<Note>> List;
    for (auto it = datas.begin(); it != datas.end(); it++) {
        List.push_back(it->second.searchImportant());
    }
    return List;
}

std::list<std::list<Note>> Database::searchNotesByName(const std::string &searchString) const {
    std::list<std::list<Note>> resultNotes;
    for (auto it = datas.begin(); it != datas.end(); it++) {
        resultNotes.push_back(it->second.searchNotesByName(searchString));
    }
    return resultNotes;
}

std::list<std::list<Note>> Database::searchNotesByText(const std::string &searchString) const {
    std::list<std::list<Note>> resultNotes;
    for (auto it = datas.begin(); it != datas.end(); it++) {
        resultNotes.push_back(it->second.searchNotesByText(searchString));
    }
    return resultNotes;
}

std::list<Folder> Database::searchFoldersByName(const std::string &searchString) const {
    std::list<Folder> resultFolders;
    for (auto it = datas.begin(); it != datas.end(); it++) {
        if (it->second.getName().find(searchString) != std::string::npos) {
            resultFolders.push_back(it->second);
        }
    }
    return resultFolders;
}

