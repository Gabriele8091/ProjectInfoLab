#include <iostream>
#include <string>
#include"Subject.h"

class Note{
public:
    explicit Note(int id, std::string Title, std::string Content, bool Locked, bool Important);

    void setName(std::string name);

    void setContent(std::string content);

    std::string getName()const;

    std::string getContent()const;

    int getId()const;

    void setLocked(bool locked);

    bool getLocked()const;

    bool getImportant()const;



private:

    std::string NoteName;
    std::string NoteContent;
    int NoteId;
    bool Locked;
    bool Important;

};