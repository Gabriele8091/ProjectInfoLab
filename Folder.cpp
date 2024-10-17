
#include "Folder.h"
//getline(std::cin, FolderName);

Folder::Folder(int id, const std::string &name) {
    FolderName = name;
    FolderId = id;
    Empty = true;
    NumberOfNotes = 0;
}

void Folder::setName(std::string name) {
    FolderName = name;
}

int Folder::getId() const {
    return FolderId;
}

std::string Folder::getName() const {
    return FolderName;
}

void Folder::addNote(const std::string &title, const std::string &content, bool &Locked, bool &Important) {
    Note note(NumberOfNotes, title, content, Locked, Important);
    notes.insert(std::pair<int, Note>(note.getId(), note));
    Empty = false;
    NumberOfNotes++;
    notify(NumberOfNotes);
}

void Folder::deleteNote(int id) {
    for (auto it = notes.begin(); it != notes.end(); it++) {
        if (it->first == id) {
            if(!it->second.getLocked())
            {
            notes.erase(it);
            NumberOfNotes--;
            }
            else
                std::cout << "Note is locked" << std::endl;
            break;
        }
    }
    if (NumberOfNotes == 0) {
        Empty = true;
    }
    notify(NumberOfNotes);
}

Note *Folder::getNote(int id) {
    for (auto it = notes.begin(); it != notes.end(); it++) {
        if (it->first == id) {
            return &it->second;
        }
    }
    return nullptr;
}

bool Folder::getEmpty() const {
    return Empty;
}

void Folder::setImportantName() {
    this->FolderName = "ImportantNotes";
}


void Folder::notify(int c) {
    for (auto &i: O) {
        i->update(c);
    }
}

void Folder::removeObserver(Observer *o) {
    for (auto it = O.begin(); it != O.end(); it++) {
        if (*it == o) {
            O.erase(it);
            break;
        }
    }
}

void Folder::addObserver(Observer *o) {
    O.push_back(o);
}

int Folder::printNoteCounter() const {
    for (auto &i: O) {
        i->printNoteCounter();
    }
    return 0;

}

void Folder::showNotes() {
    for (auto it = notes.begin(); it != notes.end(); it++) {
        std::cout << "Note ID: " << it->first << " Note Name: " << it->second.getName() << " Note Content: "
                  << it->second.getContent() << std::endl;
    }
}

std::list<Note> Folder::searchImportant() const {
    std::list<Note> ImportantNotes;
    for (auto it = notes.begin(); it != notes.end(); it++) {
        if (it->second.getImportant()) {
            ImportantNotes.push_back(it->second);
        }
    }
    return ImportantNotes;
}


std::list<Note> Folder::searchNotesByName(const std::string &searchString) const {
    std::list<Note> Notes;
    for (auto it = notes.begin(); it != notes.end(); it++) {
        if (it->second.getName().find(searchString) != std::string::npos) {
            Notes.push_back(it->second);
        }
    }
    return Notes;
}

std::list<Note> Folder::searchNotesByText(const std::string &searchString) const {
    std::list<Note> Notes;
    for (auto it = notes.begin(); it != notes.end(); it++) {
        if (it->second.getContent().find(searchString) != std::string::npos) {
            Notes.push_back(it->second);
        }
    }
    return Notes;
}