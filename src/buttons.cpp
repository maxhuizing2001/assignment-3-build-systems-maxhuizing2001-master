#include <iostream>
#include "include/buttons.h"

void simulation::buttons::reset(){
    std::fill(std::begin(m_requests), std::end(m_requests), NO_REQUEST);
    m_next_request = 1;
}

void simulation::buttons::request_floor(int floor){
    std::cout << "[BUTTONS]: button pressed: " << floor << "\n";

    if (m_requests[floor] == NO_REQUEST){
        m_requests[floor] = m_next_request++;
    }
}

bool simulation::buttons::is_requested(int floor) const{
    return m_requests[floor] != NO_REQUEST;
}

void simulation::buttons::clear_request(int floor){
    std::cout << "[BUTTONS]: floor request cleared: " << floor << "\n";

    m_requests[floor] = NO_REQUEST;
}

int simulation::buttons::first_request() const{
    int result = lift::NO_FLOOR;
    const int size = lift::MAX_FLOOR + 1;

    for (int i = 0; i < size; ++i){
        if (m_requests[i] != NO_REQUEST){
            if (result == lift::NO_FLOOR){
                result = i;
            }
            else if (m_requests[i] < m_requests[result]){
                result = i;
            }
        }
    }
    std::cout << "[BUTTONS]: floor request forwarded: " << result << "\n";

    return result;
}