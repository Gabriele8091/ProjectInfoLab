//
// Created by gabri on 14/06/2024.
//

#include "Interface.h"

void Interface::Run(Database& db) {
    IsRunning = true;
    while (IsRunning) {
        std::cout << "1. Create Folder\n2. Remove Folder\n3. Show Folders\n4. Choose a Folder\n5. Exit\n";
        int choice;
        std::cin >> choice;
       std::cin.ignore();
        switch (choice) {
            case 1:
                db.createFolder();
                break;
            case 2:
                db.removeFolder();
                break;
            case 3:
                db.showFolders();
                break;
            case 5:
                IsRunning = false;
                break;
            case 4:
                db.showFolders();
                if(db.getIsEmpty()){
                    std::cout << "There are no folders to choose!" << std::endl;
                    break;
                }
                else{
                    std::cout << "Choose a folder: ";
                    int folderChoice;
                    std::cin >> folderChoice;
                    FolderMenu(db.getFolder(folderChoice));
                }
            default:
                std::cout << "Invalid choice\n";
        }
    }
}

void Interface::FolderMenu(Folder* folder) {
    IsFolderMenu = true;
    while (IsFolderMenu) {
        std::cout << "1. Create Note\n2. Remove Note\n3. Show Notes\n4. Choose a Note\n5. Exit\n";
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
            case 5:
                IsFolderMenu = false;
                break;
            case 4:
                folder->showNotes();
                std::cout<< "Choose a note: ";
                int noteChoice;
                std::cin >> noteChoice;

                NoteMenu(folder->getNote(noteChoice));

            default:
                std::cout << "Invalid choice\n";
        }
    }
}

void Interface::NoteMenu(Note* note) {
    IsNoteMenu = true;
    while (IsNoteMenu) {
        std::cout << "1. Edit Note Name\n2. Edit Note Content\n3. Lock Note\n4. Print Note \n5. Exit";
        int choice;
        std::cin >> choice;
        std::cin.ignore();
        switch (choice) {
            case 1:
                note->setNoteName();
                break;
            case 2:
                note->setNoteContent();
                break;
            case 3:
                note->setNoteIsLocked();
                break;
            case 4:
                std::cout << "Note Name: " << note->getNoteName() << std::endl;
                std::cout << "Note Content: " << note->getNoteContent() << std::endl;
                break;
            case 5:
                IsNoteMenu = false;
                break;
            default:
                std::cout << "Invalid choice\n";
        }
    }
}


