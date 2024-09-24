#include<vector>
#include<list>
#include<iostream>
class Observer{

public:

    virtual void update(int c) = 0;
    virtual void printNoteCounter() const = 0;
    virtual ~Observer() = default;
};
