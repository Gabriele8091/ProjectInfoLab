//
// Created by gabri on 14/06/2024.
//

#include "Note.h"

Note::Note(int id, std::string Title, std::string Content, bool Locked, bool Important) {
    this->NoteName=Title;
    this->NoteContent=Content;
    this->NoteId=id;
    this->Locked=Locked;
    this->Important=Important;
}


void Note::setName(std::string name) {
    NoteName=name;

}

void Note::setContent(std::string content) {
    NoteContent=content;

}

std::string Note::getName() const {
    return NoteName;
}

std::string Note::getContent() const {
    return NoteContent;
}


int Note::getId() const {
    return NoteId;
}


bool Note::getLocked() const {
    return Locked;
}



void Note::setLocked(bool locked) {
    Locked=locked;
}

bool Note::getImportant() const {
    return Important;
}




