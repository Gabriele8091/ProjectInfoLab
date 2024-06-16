#include "Database.h"

class Interface {
public:
    Interface() : IsRunning(false), IsFolderMenu(false), IsNoteMenu(false) {};

    void Run(Database& db);

    void FolderMenu(Folder* folder);

    //void NoteMenu(Note* note);
private:
    bool IsRunning;
    bool IsFolderMenu;
    bool IsNoteMenu;
};