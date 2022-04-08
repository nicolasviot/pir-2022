use core
use gui
use base


_define_
side_bas (double x__, double y__){



FillColor fill(0, 255, 0)

FillOpacity fo (1)
FillColor fc (100, 100, 100)
Rectangle r (x__, y__, 100, 50, 0, 0)
LogPrinter lp ("valeur de l'incrément : ")

col aka fo.a
wi1 aka r.width

	FSM rect{
		State idle{
			
		}
		State level1{
			Timer t (5000)
			Clock sec (500)
			
			Incr x (1)
			sec.tick -> x
			col - x.state/300 =:> col
			wi1 + (x.state) =:> wi1
			fc.g + (x.state*4) =:> fc.r
			x.state =:>lp.input


			
		}
		

		idle -> level1(r.press)
		level1 -> idle(level1.t.end)
	}



}
