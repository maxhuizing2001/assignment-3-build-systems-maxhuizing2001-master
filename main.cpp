#include <memory>
#include <vector>
#include "include/lift.h"
#include "include/buttons.h"

#include "include/lift_state.h"
#include "include/lift_init_state.h"
#include "include/lift_steady_state.h"
#include "include/lift_up_state.h"
#include "include/lift_down_state.h"

int main(){
    auto lift = std::make_unique<simulation::lift>(7);
    auto buttons = std::make_unique<simulation::buttons>();


    // run-time polymorphism
    auto init = std::make_unique<states::lift_init_state>(lift.get(), buttons.get());
    auto steady = std::make_unique<states::lift_steady_state>(lift.get(), buttons.get());
    auto up = std::make_unique<states::lift_up_state>(lift.get(), buttons.get());
    auto down = std::make_unique<states::lift_down_state>(lift.get(), buttons.get());

    steady->bind_states(up.get(), down.get());
    up->bind_states(steady.get());
    down->bind_states(steady.get());
    init->bind_states(steady.get());

    states::lift_state* state = init.get();

    // button presses are in reverse order
    std::vector button_presses{7, 1, 9, 3, 6};

    // simulation length in steps
    auto count{55};
    while(count--){
         state = state->execute();

         // do the button presses
         if (!button_presses.empty() && state != init.get()){
             buttons->request_floor( button_presses.back());
             button_presses.pop_back();
         }
    }

}
