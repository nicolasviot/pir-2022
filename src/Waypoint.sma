use core
use gui
use base


_define_
Waypoint (Process frame, double _x, double _y){



FillColor fill(0, 255, 0)
Circle cercle (_x, _y, 20)




x aka cercle.cx
y aka cercle.cy


	FSM drag_Waypoint{
		State idle
		State moving{
			frame.move.x =:> cercle.cx
			frame.move.y =:> cercle.cy
		}
		idle -> moving(cercle.press)
		moving -> idle(cercle.release)
	}



}
