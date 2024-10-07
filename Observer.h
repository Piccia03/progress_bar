//
// Created by Francesco Impicciatore on 04/10/24.
//

#ifndef PROGRESS_BAR_OBSERVER_H
#define PROGRESS_BAR_OBSERVER_H
class Observer {
protected:
    virtual ~Observer();

public:
    virtual void update() = 0;
};
#endif //PROGRESS_BAR_OBSERVER_H
