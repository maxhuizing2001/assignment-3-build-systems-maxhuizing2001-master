#include "include/lift_state.h"

states::lift_state::lift_state(simulation::lift* lift, simulation::buttons* buttons):
    m_lift{lift},
    m_buttons{buttons}
{}

simulation::buttons& states::lift_state::get_buttons() {
    return *m_buttons;
}

simulation::lift& states::lift_state::get_lift() {
    return *m_lift;
}
