use core
use gui
use base


_define_
side (double _x, double _y){



FillColor fill(0, 255, 0)

FillOpacity fo (0.5)
FillColor fc (100, 100, 100)
Rectangle r (_x, _y, 200, 50, 0, 0)
LogPrinter lp ("valeur de l'incrément : ")

col aka fo.a
wi aka r.width

	FSM rect{
		State idle{
			
		}
		State level1{
			Timer t (20000)
			Clock sec (1000)
			
			Incr x (1)
			sec.tick -> x
			col + x.state/300 =:> col
			wi - (x.state) =:> wi
			fc.g + (x.state*4) =:> fc.r
			x.state =:>lp.input
				
			
		}
		

		idle -> level1(r.press)

		level1 -> idle(level1.t.end)
	}



}
