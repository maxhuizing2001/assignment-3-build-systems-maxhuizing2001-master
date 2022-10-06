#include <iostream>
#include "include/lift_down_state.h"

states::lift_down_state::lift_down_state(simulation::lift* lift, simulation::buttons* buttons) :
    lift_state(lift, buttons),
    m_steady{}
{ }

void states::lift_down_state::bind_states(lift_state* steady){
    m_steady = steady;
}

states::lift_state* states::lift_down_state::execute() {

    std::cout << "[STATE::DOWN] (target: " << get_lift().get_target_floor() << ", current: " << get_lift().sense_floor() <<")\n";
    lift_state* next_state = this;
    // we are moving, check if we should stop
    if (get_lift().get_target_floor() < get_lift().sense_floor()){
        get_lift().move_down();
    }
    else{
        next_state = m_steady;
    }
    return next_state;
}
