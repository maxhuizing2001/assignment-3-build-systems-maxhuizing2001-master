#ifndef INCLUDED_LIFT_H
#define INCLUDED_LIFT_H

#include <iostream>

namespace simulation {

    /*
     * This class simulates physical lift movement and floor sensing.
     */
    class lift {
    private:
        int m_floor;
        int m_target_floor;
    public:
        constexpr static int MAX_FLOOR = 10;
        constexpr static int MIN_FLOOR = 0;
        constexpr static int NO_FLOOR = MIN_FLOOR - 1;

        lift(int initial_floor);

        int sense_floor() const;

        void move_down();

        void move_up();

        int get_target_floor() const;

        void set_target_floor(int floor);

    };
}

#endif //INCLUDED_LIFT_H
