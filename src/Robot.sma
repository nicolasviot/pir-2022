use core
use base
use gui
use display




_define_
Robot (string path_to_png, double x0, double y0){


	Double x (0)
	Double y (0)

	Double vitesseX(2)
	Double vitesseY(2)

	Double targetX(800)
	Double targetY(600)
	Double Dist_initx(0)
	Double Dist_inity(0)

	Spike goto
	Spike arrived

	

	 Rotation Rot(0,440,330)
 	 Image robot (path_to_png, 100, 600, 150, 150)

 	 robot.x =:> x
 	 robot.y =:> y

	((targetX - robot.x )< 100) -> arrived

	((targetX - robot.x )> 100) -> goto

 	 FSM robot_fsm{
 	 	State idle
 	 	State start_moving {
 	 		Clock myclock(100)


 	 		myclock.tick -> (this){
 	 			//funciton incrément
 	 			this.robot.x = this.robot.x + this.vitesseX
 	 			this.robot.y = this.robot.y + this.vitesseY
 	 		}



 	 	}







 	 	idle -> start_moving (goto)
 	 	start_moving -> idle (arrived)
 	 	idle -> start_moving (robot.press)
 	 }

LogPrinter lp("debug robot fsm : ")
robot_fsm.state =:> lp.input


}