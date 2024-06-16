//
// Created by gabri on 14/06/2024.
//

#include "Note.h"

Note::Note(int id) {
    std::cout<< "Insert Note name:" << std::endl;
    getline(std::cin, NoteName);
    std::cout<< "Insert Note content:" << std::endl;
    getline(std::cin, NoteContent);
    NoteId = id;
    std::cout<< "Want to lock the note? 1=yes 0=no" << std::endl;
    int choice;
    std::cin >> choice;
    if (choice == 1) {
        IsLocked = true;
    } else {
        IsLocked = false;
    }
}

void Note::setNoteName() {
    std::cout<< "Insert Note name:" << std::endl;
    getline(std::cin, NoteName);
}

void Note::setNoteContent() {
    std::cout<< "Insert Note content:" << std::endl;
    getline(std::cin, NoteContent);
}

std::string Note::getNoteName() const {
    return NoteName;
}

std::string Note::getNoteContent() const {
    return NoteContent;
}


int Note::getNoteId() const {
    return NoteId;
}


bool Note::getNoteIsLocked() const {
    return IsLocked;
}



void Note::setNoteIsLocked() {
    std::cout<< "Want to lock the note? 1=yes 0=no" << std::endl;
    int choice;
    std::cin >> choice;
    if (choice == 1) {
        IsLocked = true;
    } else {
        IsLocked = false;
    }
}



