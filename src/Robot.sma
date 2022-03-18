use core
use base
use gui
use display




_define_
Robot (Process frame, string path_to_png, double x0, double y0){


	Double x (0)
	Double y (0)

	Double vitesseX(2)
	Double vitesseY(2)

	Double targetX(800)
	Double targetY(600)
	LogPrinter lp ("new targetX")
	targetX =:> lp.input


	FillColor fill(255,0,0)
	Rectangle target(800,550,50,50)
	Double Dist_initx(0)
	Double Dist_inity(0)
 	Rotation Rot(0,440,330)
 	Image robot (path_to_png, 100, 600, 150, 150)

	Image bombe ("src/Bombe.png", 100, 100, 35, 45)
	Double to_be_squared(0)
	Double distance(0)

	Sqrt mysqrt(0)
	Pow left_pow (0, 2)
	Pow right_pow (0, 2)

	robot.x - bombe.x =:> left_pow.base 
	robot.y - bombe.y =:> right_pow.base
	left_pow.result + right_pow.result =:> to_be_squared
	to_be_squared =:> mysqrt.input
	mysqrt.output => distance



	Spike goto
	Spike arrived
	frame.move.x=:>bombe.x

	frame.move.y=:>bombe.y
	

	

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


	(distance < robot.width + 75) -> arrived

LogPrinter lp("debug robot fsm : ")
robot_fsm.state =:> lp.input


}