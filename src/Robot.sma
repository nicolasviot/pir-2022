use core
use base
use gui
use display




_define_
Robot (Process frame, string path_to_png, double x0, double y0){


	Double vitesse(10)


	Double step_to_arrival(0)

	Double distance_to_target(0)
 	Image robot (path_to_png, 1200, 600, 150, 150)

	Double targetX(0)
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
	Spike left


	//(robot.x > targetX) -> left 
	OutlineWidth _(5)
	OutlineColor _ (255,0,0)
	Line myline (0,0,0,0)


	(robot.x+70) =:> myline.x1
	(robot.y+70) =:> myline.y1

	targetX =:> myline.x2
	targetY =:> myline.y2

	((distance_to_target)< 50) -> arrived

 	 FSM robot_fsm{
 	 	State idle
 	 	State start_moving { 
 	 		LogPrinter lp2 ("debug in fsm")

 	 		Double x0($robot.x)
 	 		Double y0($robot.y)
 			Int nb_step(10)
 			distance_to_target / vitesse =:> nb_step 
 	 		Clock myclock(50)
 	 		nb_step =:> lp2.input
			targetX -> (this){
				this.robot_fsm.start_moving.x0 = this.robot.x
				this.robot_fsm.start_moving.y0 = this.robot.y
				
			} 
			targetY -> (this){
				this.robot_fsm.start_moving.x0 = this.robot.x
				this.robot_fsm.start_moving.y0 = this.robot.y
				
			} 
// on remarque que si le waupoint es derier ou tous droit il n'arrive pas à la suivre

 	 		myclock.tick -> (this){
 	 			//funciton incrément
 	 			this.robot.x = this.robot.x + (this.targetX - this.robot_fsm.start_moving.x0)/ this.robot_fsm.start_moving.nb_step
 	 			this.robot.y = this.robot.y + (this.targetY - this.robot_fsm.start_moving.y0)/ this.robot_fsm.start_moving.nb_step
			  }





 	 	}

		  




		

 	 	idle -> start_moving (goto)
 	 	start_moving -> idle (arrived)
		start_moving -> start_moving (targetX)

		start_moving -> start_moving (targetY)
 	 	idle -> start_moving (robot.press)
		start_moving -> idle(robot.press)
		
 	 }


	(distance_to_target < robot.width + 100) -> arrived

LogPrinter lp ("debug : ")

//robot_fsm.state =:> lp.input

}