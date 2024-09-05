//
// Created by gabri on 14/06/2024.
//

#include "Interface.h"

void Interface::Run(Database& db) {
    IsRunning = true;
    while (IsRunning) {
        std::cout << " 1. Create Folder\n2. Remove Folder\n3. Show Folders\n4. Choose a Folder\n5. Exit\n";
        int choice;
        std::cin >> choice;
       std::cin.ignore();
        switch (choice) {
            case 1:
                db.createFolder();
                break;
            case 2:
                if(db.getIsEmpty()){
                    std::cout << " There are no folders to delete!" << std::endl;
                    break;
                }
                else{
                    db.removeFolder();
                    break;
                }
            case 3:
                    db.showFolders();
                    break;
            case 4:
                db.showFolders();
                    std::cout << " Choose a folder by his ID: ";
                    int folderChoice;
                    std::cin >> folderChoice;
                    FolderMenu(db.getFolder(folderChoice));
                    break;
                case 5:
                IsRunning = false;
                break;

            default:
                std::cout << " Invalid choice\n";
        }
    }
}

void Interface::FolderMenu(Folder* folder) {
    IsFolderMenu = true;
    while (IsFolderMenu) {
        std::cout << " 1. Create Note\n2. Remove Note\n3. Show Notes\n4. Choose a Note\n5. Edit the folder name\n6. Exit\n";
        int choice;
        std::cin >> choice;
        std::cin.ignore();
        switch (choice) {
            case 1:
                folder->addNote();
                break;
            case 2:
                folder->deleteNote();
                break;

            case 3:
                    folder->showNotes();
                    break;

            case 4:
                    folder->showNotes();
                    std::cout << " Choose a note by his ID: ";
                    int noteChoice;
                    std::cin >> noteChoice;
                    NoteMenu(folder->getNote(noteChoice));
                    break;

                case 5:
                    std::cout<<" That's the folder name, edit it as you want: "<<std::endl<<folder->getFolderName()<<std::endl;
                    folder->setFolderName();
                    break;
            case 6:
                IsFolderMenu = false;
                break;

            default:
                std::cout << " Invalid choice\n";
        }
    }
}

void Interface::NoteMenu(Note* note) {
    IsNoteMenu = true;
    while (IsNoteMenu) {
        std::cout << " 1. Edit Note Name\n2. Edit Note Content\n3. Lock/Unlock Note\n4. Print Note \n5. Exit";
        int choice;
        std::cin >> choice;
        std::cin.ignore();
        switch (choice) {
            case 1:
                if(note->getNoteIsLocked()){
                    std::cout << " Note is locked!" << std::endl;
                    break;
                }
                else{
                    std::cout<<" That's the note name, edit it as you want: "<<std::endl<<note->getNoteName();
                    note->setNoteName();
                    break;
                }

            case 2:
                if(note->getNoteIsLocked()){
                    std::cout << " Note is locked!" << std::endl;
                    break;
                }
                else{
                    std::cout<<" That's the note content, edit it as you want: "<<std::endl<<note->getNoteContent();
                    note->setNoteContent();
                    break;
                }
            case 3:
                note->setNoteIsLocked();
                break;
            case 4:
                std::cout << " Note Name: " << note->getNoteName() << std::endl;
                std::cout << " Note Content: " << note->getNoteContent() << std::endl;
                break;
            case 5:
                IsNoteMenu = false;
                break;
            default:
                std::cout << " Invalid choice\n";
        }
    }
}


