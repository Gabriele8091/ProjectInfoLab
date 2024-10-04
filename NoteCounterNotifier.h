#include "Folder.h"

class NoteCounterNotifier : public Observer {
public:

    void update(int c) override;

    void printNoteCounter() const override;

    ~NoteCounterNotifier() override = default;

private:
    int noteCounter;
};