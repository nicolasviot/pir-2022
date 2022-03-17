use core
use gui
use base


_define_
Waypoint (Process frame, Double x, Double y){


x aka image.x
y aka image.y


	Fsm drag_Waypoint{
		State idle
		State moving{
			frame.move.x =:> image.x
			frame.move.y =:> image.y

		}

		idle -> moving(image.press)
		moving -> idle(image.release)

	}



}






Waypoint target(.....)
target.x =:> robot.targetX
target.y =:> robot.targetY 