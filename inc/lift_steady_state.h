#ifndef INCLUDED_LIFT_STEADY_STATE__H
#define INCLUDED_LIFT_STEADY_STATE__H

#include "lift_state.h"

namespace states {
  class lift_steady_state : public lift_state{
    public:
        lift_steady_state(simulation::lift* lift, simulation::buttons* buttons);
        void bind_states(lift_state* up, lift_state* down);
        virtual lift_state* execute() override;
    private:
        lift_state* m_up;
        lift_state* m_down;
    };
}

#endif //INCLUDED_LIFT_STEADY_STATE__H
