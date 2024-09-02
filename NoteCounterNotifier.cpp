
#include "NoteCounterNotifier.h"

void NoteCounterNotifier::update() {
    noteCounter++;
}

void NoteCounterNotifier::update2() {
    noteCounter--;
}

void NoteCounterNotifier::printNoteCounter() const {
    std::cout  << noteCounter << std::endl;
}