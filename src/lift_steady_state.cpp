//
// Created by dza02 on 9/17/2021.
//

#include <iostream>
#include "include/lift_steady_state.h"

void states::lift_steady_state::bind_states(lift_state* up, lift_state* down){
    m_up = up;
    m_down = down;
}

states::lift_steady_state::lift_steady_state(simulation::lift* lift, simulation::buttons* buttons)
    : lift_state(lift, buttons) {

}

states::lift_state* states::lift_steady_state::execute() {
    std::cout << "[STATE::STEADY]" << '\n';

    lift_state* next_state = this;

    if (get_lift().get_target_floor() != get_lift().sense_floor()){
        // we are stopping on the way somewhere
        if (get_lift().get_target_floor() > get_lift().sense_floor()){
            next_state = m_up;
        }
        else{
            next_state = m_down;
        }
    }
    else {
        // scan the floor_requests array for the first request and go there
        if (int request = get_buttons().first_request(); request != simulation::lift::NO_FLOOR){
            get_buttons().clear_request(request);
            get_lift().set_target_floor(request);

        }
    }

    return next_state;
}