#include "Folder.h"

class NoteCounterNotifier : public Observer{
public:

    void update(int c) override;

    void printNoteCounter() const;

    ~NoteCounterNotifier() override= default;

private:
    int noteCounter;
};