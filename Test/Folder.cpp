
#include "Folder.h"

Folder::Folder(int id) {
    //std::cout << " Insert Folder Name: " << std::endl;
    //getline(std::cin, FolderName);
    FolderId = id;
    IsEmpty = true;
    NumberOfNotes = 1;
}

void Folder::setFolderName() {
    std::cout << " Insert Folder Name: " << std::endl;
    getline(std::cin, FolderName);
}

int Folder::getFolderId()const {
    return FolderId;
}

std::string Folder::getFolderName() {

    return FolderName;
}

void Folder::showNotes() {
    if (IsEmpty) {
        std::cout << "There are no notes to show!" << std::endl;
        return;
    } else {
        for (auto it = notes.begin(); it != notes.end(); it++) {
            std::cout << "Note ID: " << it->first << " Note Name: " << it->second.getNoteName() << std::endl;
        }
    }
}

void Folder::addNote() {
    Note note(NumberOfNotes);
    notes.insert(std::pair<int, Note>(note.getNoteId(), note));
    IsEmpty = false;
    NumberOfNotes++;
    notify();
}

void Folder::deleteNote(int id) {
    if (IsEmpty) {
        std::cout << "There are no notes to delete!" << std::endl;
        return;
    } else {
       // showNotes();
       // std::cout << "Enter the note id you want to delete: " << std::endl;
        //int id;
       // std::cin >> id;
        for (auto it = notes.begin(); it != notes.end(); it++) {
            if (it->first == id && !it->second.getNoteIsLocked()) {
                notes.erase(it);
                Folder::NumberOfNotes--;
               // std::cout << "Note deleted successfully!" << std::endl;
                break;
            }
            else
            {
               // std::cout << "Note is locked!" << std::endl;
            }
        }
    }
    notify2();
}

void Folder::editNote() {
    if (IsEmpty) {
        std::cout << "There are no notes to edit!" << std::endl;
        return;
    } else {
        showNotes();
        std::cout << "Enter the note id you want to edit: " << std::endl;
        int id;
        std::cin >> id;
        for (auto it = notes.begin(); it != notes.end(); it++) {
            if (it->first == id && !it->second.getNoteIsLocked()) {
                std::cout << "1. Edit Note Name" << std::endl;
                std::cout << "2. Edit Note Content" << std::endl;
                std::cout << "3. Lock Note" << std::endl;
                int choice;
                std::cin >> choice;
                switch (choice) {
                    case 1:
                        it->second.setNoteName();
                        break;
                    case 2:
                        it->second.setNoteContent();
                        break;
                    case 3:
                        it->second.setNoteIsLocked();
                        break;
                    default:
                        std::cout << "Invalid choice!" << std::endl;
                        break;
                }

            }
            else
            {
                std::cout << "Note is locked!" << std::endl;
            }
        }
    }
}

Note* Folder::getNote(int id) {
    for (auto it = notes.begin(); it != notes.end(); it++) {
        if (it->first == id) {
            return &it->second;
        }
        else
        {
            std::cout << "Note not found!" << std::endl;
            return nullptr;
        }
    }
}

bool Folder::getIsEmpty()const {
    return IsEmpty;
}

bool Folder::getIsLocked()const {
    return false;
}

void Folder::setImportantName() {
    this->FolderName = "ImportantNotes";
}


void Folder::notify() {
    for (auto &i : O) {
        i->update();
    }
}

void Folder::notify2() {
    for (auto &i : O) {
        i->update2();
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