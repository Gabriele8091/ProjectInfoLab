//
// Created by gabri on 14/06/2024.
//

#include "Interface.h"
void Interface::ShowFolders(Database& db) {
    db.showFolders();
}

void Interface::ShowNotes(Folder* folder) {
    folder->showNotes();
}

void Interface::Run(Database& db) {
    IsRunning = true;
    while (IsRunning) {
        std::cout << "1. Create Folder\n2. Remove Folder\n3. Show Folders\n4. Choose a Folder\n5. Exit\n6. Show Important Notes\n";
        int choice;
        std::cin >> choice;
       std::cin.ignore();
        switch (choice) {
            case 1: {
                std::string Title;
                std::cout << "Insert the folder name:";
                std::getline(std::cin, Title);
                db.createFolder(Title);
                break;
            }
            case 2: {
                if (db.getEmpty()) {
                    std::cout << "There are no folders to delete!" << std::endl;
                    break;
                } else {
                    std::cout << "Choose a folder by his ID: ";
                    db.showFolders();
                    int folderChoice;
                    std::cin >> folderChoice;
                    db.removeFolder(folderChoice);
                    break;
                }
            }
            case 3: {
                if (db.getEmpty()) {
                    std::cout << "There are no folders to show!" << std::endl;
                    break;
                } else {
                    db.showFolders();
                    break;
                }
            }
            case 4: {
                if (db.getEmpty()) {
                    std::cout << "There are no folders to show!" << std::endl;
                    break;
                } else {
                    db.showFolders();
                    std::cout << "Choose a folder by his ID: ";
                    int folderChoice;
                    std::cin >> folderChoice;
                    FolderMenu(db.getFolder(folderChoice));
                    break;
                }
            }
            case 5: {
                std::cout<<"Goodbye!";
                IsRunning = false;
                break;
            }
            case 6: {
                std::list<std::list<Note>> List = db.searchImportant();
                for(auto it = List.begin(); it != List.end(); it++) {
                    for(auto it2 = it->begin(); it2 != it->end(); it2++) {
                        std::cout << "Note Name: " << it2->getName() << " Note Content: " << it2->getContent() << std::endl;
                    }
                }
                break;
            }

            default: {
                std::cout << "Invalid choice\n";
            }
        }
    }
}

void Interface::FolderMenu(Folder* folder) {
    IsFolderMenu = true;
    while (IsFolderMenu) {
        std::cout << "1. Create Note\n2. Remove Note\n3. Show Notes\n4. Choose a Note\n5. Edit the folder name\n6. Exit\n";
        int choice;
        std::cin >> choice;
        std::cin.ignore();
        switch (choice) {
            case 1: {
                std::string Title;
                std::string Content;
                std::cout << "Insert the note name:";
                std::getline(std::cin, Title);
                std::cout << "Insert the note content:";
                std::getline(std::cin, Content);
                bool Locked;
                std::cout << "Do you want to lock the note? (1/0):";
                int i;
                std::cin >> i;
                if (i == 1) {
                    Locked = true;
                } else {
                    Locked = false;
                }
                std::cout<<"Has the note to be important? (1/0): ";
                int b;
                bool important;
                std::cin>>b;
                if(b==1){
                    important=true;
                }
                else{
                    important=false;
                }

                folder->addNote(Title, Content, Locked, important);
                break;
            }
            case 2: {
                if (folder->getEmpty()) {
                    std::cout << "There are no notes to delete!" << std::endl;
                    break;
                } else {
                    folder->showNotes();
                    std::cout << "Choose a note by his ID: ";
                    int noteChoice;
                    std::cin >> noteChoice;
                    folder->deleteNote(noteChoice);
                    break;
                }
            }

            case 3: {
                if (folder->getEmpty()) {
                    std::cout << "There are no notes to show!" << std::endl;
                    break;
                } else {
                    folder->showNotes();
                    break;
                }
            }
            case 4: {
                if (folder->getEmpty()) {
                    std::cout << "There are no notes to show!" << std::endl;
                    break;
                } else {
                    folder->showNotes();
                    std::cout << "Choose a note by his ID: ";
                    int noteChoice;
                    std::cin >> noteChoice;
                    NoteMenu(folder->getNote(noteChoice));
                    break;
                }
            }
                case 5:{
                    std::cout<<"That's the folder name, edit it as you want: "<<std::endl<<folder->getName()<<std::endl;
                    std::string name;
                    std::getline(std::cin, name);
                    folder->setName(name);
                    break;
                }
            case 6: {
                IsFolderMenu = false;
                break;
            }
            default: {
                std::cout << "Invalid choice\n";
            }
        }
    }
}

void Interface::NoteMenu(Note* note) {
    IsNoteMenu = true;
    while (IsNoteMenu) {
        std::cout << "1. Edit Note Name\n2. Edit Note Content\n3. Lock/Unlock Note\n4. Print Note \n5. Exit";
        int choice;
        std::cin >> choice;
        std::cin.ignore();
        switch (choice) {
            case 1:
                if(note->getLocked()){
                    std::cout << "Note is locked!" << std::endl;
                    break;
                }
                else{
                    std::cout<<"That's the note name, edit it as you want: "<<std::endl<<note->getName();
                    std::string name;
                    std::getline(std::cin, name);
                    note->setName(name);
                    break;
                }

            case 2:
                if(note->getLocked()){
                    std::cout << "Note is locked!" << std::endl;
                    break;
                }
                else{
                    std::cout<<"That's the note content, edit it as you want: "<<std::endl<<note->getContent();
                    std::string content;
                    std::getline(std::cin, content);
                    note->setContent(content);
                    break;
                }
            case 3:
               bool locked;
               int i;
               std::cout<<"Do you want to lock the note? (1/0): ";
               std::cin>>i;
                if(i==1){
                    locked=true;
                    note->setLocked(locked);
                }
                else{
                    locked=false;
                    note->setLocked(locked);
                }
                break;
            case 4:
                std::cout << "Note Name: " << note->getName() << std::endl;
                std::cout << "Note Content: " << note->getContent() << std::endl;
                break;
            case 5:
                IsNoteMenu = false;
                break;
            default:
                std::cout << "Invalid choice\n";
        }
    }
}


