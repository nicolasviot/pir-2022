use core
use base
use display
use gui
import flux1_factorised
import flux2_factorised
import Button


_main_
Component root {
  Frame f ("myButton", 0, 0, 500, 500)
  Exit ex (0, 1)
  f.close -> ex
  
 /*
 clock ((àà)
 clock.end -> flux1.in
  clock.end -> flux2.in
 */

  FillColor first_rectangle_fill(0, 0, 0)
  Rectangle first_rectangle(0,0, 200, 100)
  FillColor second_rectangle_fill(0, 0, 0)
  Rectangle second_rectangle(300,0, 200, 100)

  flux1_factorised _ (first_rectangle_fill.g, second_rectangle_fill.g)

   FSM fsm {
    State idle {
      0 =: first_rectangle_fill.g
      Timer t (500)
    }
    State green
    {
      255 =: first_rectangle_fill.g
      Timer t (500)
    }

     idle -> green (idle.t.end)
     green -> idle(green.t.end)
   }
  
  Translation _(0, 200)
  FillColor third_rectangle_fill(0, 255, 0)
  Rectangle third_rectangle(0,0, 200, 100)
  FillColor fourth_rectangle_fill(0, 255, 0)
  Rectangle fourth_rectangle(300,0, 200, 100)
  Button myButton (f, "press me", 250, 0)
  flux2_factorised _ (third_rectangle_fill.g, fourth_rectangle_fill.g, myButton.click)
   FSM fsm_2 {
    State idle {
      0 =: third_rectangle_fill.g
      Timer t (500)
    }
    State green
    {
      255 =: third_rectangle_fill.g
      Timer t (500)
    }

     idle -> green (idle.t.end)
     green -> idle (green.t.end)
   }
}

    