use core
use gui
use base


_define_
detour (Process frame, double _x_d_1, double _y_d_1, double _x_d_2, double _y_d_2, double _x_d_3 , double _y_d_3){

Translation t (0, 0)
Rotation rot (0 ,0 ,0)


Spike pressed 
FillColor fill(0, 0, 255)
Circle cercle_1 (70 , 0 , 15)
Circle cercle_2 (30, -40, 15)
Circle cercle_3 (-30, -40, 15)
Circle cercle_4 (-70, 0, 15)








    OutlineWidth _(5)
	OutlineColor _ (255,0,0)
	Line myline_1 (0,0,0,0)
    Line myline_2 (0,0,0,0)
    Line myline_3 (0,0,0,0)

//line 1
	(cercle_1.cx) =:> myline_1.x1
	(cercle_1.cy) =:> myline_1.y1

	(cercle_2.cx) =:> myline_1.x2
	(cercle_2.cy) =:> myline_1.y2

//line 2
    (cercle_2.cx) =:> myline_2.x1
	(cercle_2.cy) =:> myline_2.y1

    (cercle_3.cx) =:> myline_2.x2
	(cercle_3.cy) =:> myline_2.y2

	cercle_3.cx =:> myline_3.x1
	cercle_3.cy =:> myline_3.y1

	cercle_4.cx =:> myline_3.x2
	cercle_4.cy =:> myline_3.y2



Spike touch

	FSM touch_detour{
		State idle
		State active{
			

		}

		idle -> active(cercle_1.press, pressed)
		active -> idle(cercle_1.release)

        idle -> active(cercle_2.press)
		active -> idle(cercle_2.release)

        idle -> active(cercle_3.press)
		active -> idle(cercle_3.release)

        idle -> active(myline_1.press)
		active -> idle(myline_1.release)

        idle -> active(myline_2.press)
		active -> idle(myline_2.release)

	}



}
