#ifndef INCLUDED_LIFT_INIT_STATE_H
#define INCLUDED_LIFT_INIT_STATE_H

#include "lift_state.h"


namespace states {
    class lift_init_state : public lift_state {
    public:
        lift_init_state(simulation::lift* lift, simulation::buttons* buttons);
        void bind_states(lift_state* steady);
        virtual lift_state* execute() override;
    private:
        lift_state* m_steady;
    };
}

#endif //INCLUDED_LIFT_INIT_STATE_H
