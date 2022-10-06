//
// Created by dza02 on 9/17/2021.
//

#include <iostream>
#include "include/lift_init_state.h"

states::lift_init_state::lift_init_state(simulation::lift* lift, simulation::buttons* buttons):
    lift_state(lift, buttons)
{
}

void states::lift_init_state::bind_states(lift_state* steady){
    m_steady = steady;
}


states::lift_state* states::lift_init_state::execute()  {
    std::cout << "[STATE::INIT]" << '\n';

    lift_state* next_state = this;

    get_lift().set_target_floor(0);

    if (get_lift().get_target_floor() > get_lift().sense_floor()){
        get_lift().move_up();
    }
    else if (get_lift().get_target_floor() < get_lift().sense_floor()){
        get_lift().move_down();
    }
    else{
        get_buttons().reset();
        next_state = m_steady;
    }
    return next_state;
}