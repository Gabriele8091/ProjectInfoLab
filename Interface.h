#include "Database.h"

class Interface {
public:
    Interface() : IsRunning(false), IsFolderMenu(false), IsNoteMenu(false) {};

    void Run(Database &db);

    void FolderMenu(Folder *folder);

    void NoteMenu(Note *note);

    void ShowNotes(Folder *folder);

    void ShowFolders(Database &db);

private:
    bool IsRunning;
    bool IsFolderMenu;
    bool IsNoteMenu;
};