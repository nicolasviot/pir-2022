/*
 *	djnn Smala compiler
 *
 *	The copyright holders for the contents of this file are:
 *		Ecole Nationale de l'Aviation Civile, France (2017)
 *	See file "license.terms" for the rights and conditions
 *	defined by copyright holders.
 *
 *
 *	Contributors:
 *		Mathieu Magnaudet <mathieu.magnaudet@enac.fr>
 *
 */

use core
use base
use display
use gui

// local version
import Button

// smala lib
//import gui.widgets.Button


_main_
Component root {
  Frame f ("my frame", 0, 0, 400, 1000)
  Exit ex (0, 1)
  f.close -> ex


  FillColor r_color(255, 0, 0)

  Rectangle r (0, 0, 300, 200)
  Rectangle r2 (0, 300, 300, 200)
  Spike addPolyline 
  Double x1(0)
  Double x2(0)
  Double y1(0)
  Double y2(0)


  FSM fsm {
    State idle{

    }
    State temp{
      r.press.x =: x1
      r.press.y =: y1

      f.move.x =:> x2
      f.move.y =:> y2 
    }

    idle -> temp (r.press)
    temp -> idle (r2.release, addPolyline)

  }
  OutlineWidth _ (10)
  OutlineColor _ (0, 0, 255)

  addPolyline -> (root){

    addChildrenTo root {
      Polyline _ {
        Point _($root.x1, $root.y1)
        Point _($root.x2, $root.y2)
      }
    }
  }
}
