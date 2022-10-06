#ifndef INCLUDED_LIFT_UP_STATE_H
#define INCLUDED_LIFT_UP_STATE_H

#include "lift_state.h"

namespace states {
    class lift_up_state : public lift_state{
    public:
        lift_up_state(simulation::lift* lift, simulation::buttons* buttons);
        void bind_states(lift_state* steady);
        virtual lift_state* execute() override;
    private:
        lift_state* m_steady;
    };
}


#endif //INCLUDED_LIFT_UP_STATE_H
