
#include "NoteCounterNotifier.h"

void NoteCounterNotifier::update(int c) {
    noteCounter = c;
}

void NoteCounterNotifier::printNoteCounter() const {
    std::cout << noteCounter << std::endl;
}