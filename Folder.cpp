
#include "Folder.h"
//getline(std::cin, FolderName);

Folder::Folder(int id,std::string name) {
    FolderName = name;
    FolderId = id;
    Empty = true;
    NumberOfNotes = 0;
}

void Folder::setName(std::string name) {
   FolderName = name;
}

int Folder::getId()const {
    return FolderId;
}

std::string Folder::getName() {
    return FolderName;
}

void Folder::addNote(std::string &title, std::string& content, bool& Locked,bool& Important)  {
    Note note(NumberOfNotes,title,content,Locked,Important);
    notes.insert(std::pair<int, Note>(note.getId(), note));
    Empty = false;
    NumberOfNotes++;
    notify(NumberOfNotes);
}

void Folder::deleteNote(int id) {
    for(auto it = notes.begin(); it != notes.end(); it++) {
        if(it->first == id) {
            notes.erase(it);
            break;
        }
    }
    NumberOfNotes--;
    if(NumberOfNotes == 0) {
        Empty = true;
    }
    notify(NumberOfNotes);
}
Note* Folder::getNote(int id) {
    for (auto it = notes.begin(); it != notes.end(); it++) {
        if (it->first == id) {
            return &it->second;
        }
    }
}

bool Folder::getEmpty()const {
    return Empty;
}

bool Folder::getLocked()const {
    return false;
}

void Folder::setImportantName() {
    this->FolderName = "ImportantNotes";
}


void Folder::notify(int c) {
    for (auto &i : O) {
        i->update(c);
    }
}

void Folder::removeObserver(Observer* o){
    for(auto it = O.begin(); it != O.end(); it++) {
        if(*it == o) {
            O.erase(it);
            break;
        }
    }
}

void Folder::addobserver(Observer* o) {
    O.push_back(o);
}

int Folder::printNoteCounter() const {
    for (auto &i: O) {
        i->printNoteCounter();
    }
    return 0;

}

void Folder::showNotes() {
    for(auto it = notes.begin(); it != notes.end(); it++) {
        std::cout << "Note ID: " << it->first << " Note Name: " << it->second.getName() << " Note Content: " << it->second.getContent() << std::endl;
    }
}
