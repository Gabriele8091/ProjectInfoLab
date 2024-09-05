#include "Folder.h"

class NoteCounterNotifier : public Observer{
public:

    void update() override;

    void update2() override;
    void printNoteCounter() const;


    ~NoteCounterNotifier() override= default;

private:
    int noteCounter;
};