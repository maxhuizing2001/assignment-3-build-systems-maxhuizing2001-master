#ifndef INCLUDED_LIFT_STATE_H
#define INCLUDED_LIFT_STATE_H

#include "lift.h"
#include "buttons.h"

namespace states {

    class lift_state {
    public:
        lift_state(simulation::lift* lift, simulation::buttons* buttons);

        lift_state(const lift_state&) = delete;
        lift_state& operator=(const lift_state&) = delete;

        virtual lift_state* execute() = 0;
        virtual ~lift_state() noexcept = default;

    protected:
        simulation::buttons& get_buttons();
        simulation::lift& get_lift();

    private:
        simulation::lift* m_lift;
        simulation::buttons* m_buttons;
    };

}

#endif //INCLUDED_LIFT_STATE_H
