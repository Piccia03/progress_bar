//
// Created by Francesco Impicciatore on 04/10/24.
//

#ifndef PROGRESS_BAR_OBSERVER_H
#define PROGRESS_BAR_OBSERVER_H
class Observer {
protected:
    virtual ~Observer() = default;

public:
    virtual void update(int value) = 0;
};
#endif //PROGRESS_BAR_OBSERVER_H
