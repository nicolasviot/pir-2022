use core
use gui
use base


_define_
side_bas_cycle (double x__, double y__){



FillColor fill(0, 255, 0)

FillOpacity fo (1)
FillColor fc (100, 100, 100)
Circle cercle (x__,y__,30)
LogPrinter lp ("valeur de l'incrément : ")

col aka fo.a
r_cycle aka cercle.r

	FSM rect{
		State idle{
			
		}
		State level1{
			Timer t (5000)
			Clock sec (500)
			
			Incr x (1)
			sec.tick -> x
			col - x.state/300 =:> col
			r_cycle + (x.state) =:> r_cycle
			fc.g + (x.state*4) =:> fc.r
			x.state =:>lp.input


			
		}
		

		idle -> level1(cercle.press)
		level1 -> idle(level1.t.end)
	}



}
