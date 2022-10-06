//
// Created by dza02 on 9/17/2021.
//

#include "include/lift.h"

simulation::lift::lift(int initial_floor) : m_floor{initial_floor} {}

int simulation::lift::sense_floor() const {
    return m_floor;
}

void simulation::lift::move_down() {
    std::cout << "[LIFT]: move down\n";
    --m_floor;
}

void simulation::lift::move_up() {
    std::cout << "[LIFT]: move up\n";

    ++m_floor;
}

int simulation::lift::get_target_floor() const {
    return m_target_floor;
}

void simulation::lift::set_target_floor(int floor){
    m_target_floor = floor;
}