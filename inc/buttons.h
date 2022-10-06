#ifndef INCLUDED_BUTTONS_H
#define INCLUDED_BUTTONS_H

#include <algorithm>
#include "lift.h"

namespace simulation {

    /*
     * This class simulates the physical lift buttons behavior exposing functionality like
     * requesting a floor, checking which floor is requested etc.
     * It maintains a priority queue of the requests sorted by the time of request and exposes this
     * functionality through the `request_floor` and `first_request` functions.
     */

    class buttons {
    public:
        constexpr static int NO_REQUEST = 0;
        buttons() = default;

        void reset();
        void request_floor(int floor);
        bool is_requested(int floor) const;
        void clear_request(int floor);
        int first_request() const;

    private:
        int m_requests[lift::MAX_FLOOR + 1];
        int m_next_request;
    };
}


#endif //INCLUDED_BUTTONS_H
