#include "Observer.h"

class Subject{
public:
    virtual void notify(int i) = 0;
    virtual void removeObserver(Observer* o) = 0;
    virtual void addobserver(Observer*o) = 0;
    virtual ~Subject() = default;
};