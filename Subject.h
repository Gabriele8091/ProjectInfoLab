#include "Observer.h"

class Subject {
public:
    virtual void notify(int i) = 0;

    virtual void removeObserver(Observer *o) = 0;

    virtual void addObserver(Observer *o) = 0;

    virtual ~Subject() = default;
};