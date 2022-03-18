use core
use base
use gui
use display




_define_
Robot (Process frame, string path_to_png, double x0, double y0){


	Double vitesse(10)


	Double step_to_arrival(0)

	Double distance_to_target(0)
 	Image robot (path_to_png, 100, 600, 150, 150)

	Double targetX(800)
	Double targetY(600)

	Sqrt mysqrt(0)
	Pow left_pow (0, 2)
	Pow right_pow (0, 2)
	Double to_be_squared(0)

	robot.x - targetX =:> left_pow.base 
	robot.y - targetY =:> right_pow.base
	left_pow.result + right_pow.result =:> to_be_squared
	to_be_squared =:> mysqrt.input
	mysqrt.output => distance_to_target







	Spike goto
	Spike arrived

	((distance_to_target)< 100) -> arrived

 	 FSM robot_fsm{
 	 	State idle
 	 	State start_moving { 
 	 		LogPrinter lp2 ("debug in fsm")

 	 		Double x0($robot.x)
 	 		Double y0($robot.y)
 			Double nb_step(0)
 			distance_to_target / vitesse =: nb_step 
 	 		Clock myclock(100)
 	 		nb_step =: lp2.input
 	 		myclock.tick -> (this){
 	 			//funciton incrément
 	 			this.robot.x = this.robot.x + (this.targetX - this.robot_fsm.start_moving.x0)/ this.robot_fsm.start_moving.nb_step
 	 			this.robot.y = this.robot.y + (this.targetY - this.robot_fsm.start_moving.y0)/ this.robot_fsm.start_moving.nb_step
 	 		}



 	 	}





 	 	idle -> start_moving (goto)
 	 	start_moving -> idle (arrived)
 	 	idle -> start_moving (robot.press)
 	 }


	(distance_to_target < robot.width + 100) -> arrived

LogPrinter lp ("debug : ")

robot_fsm.state =:> lp.input

}