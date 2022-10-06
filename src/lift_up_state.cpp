//
// Created by dza02 on 9/17/2021.
//

#include <iostream>
#include "include/lift_up_state.h"

states::lift_state* states::lift_up_state::execute(){
    std::cout << "[STATE::UP] (target: " << get_lift().get_target_floor() << ", current: " << get_lift().sense_floor() <<")\n";

    lift_state* next_state = this;
    // we are moving, check if we should stop
    if (get_lift().get_target_floor() > get_lift().sense_floor()){
        get_lift().move_up();
    }
    else{
        next_state = m_steady;
    }

    return next_state;
}

void states::lift_up_state::bind_states(lift_state* steady) {
    m_steady = steady;
}

states::lift_up_state::lift_up_state(simulation::lift* lift, simulation::buttons* buttons) :
    lift_state(lift, buttons),
    m_steady{}
{}


