use core
use base
use display
use gui

_define_
flux2_factorised(Process input, Process output, Process _spike) {
  
 FSM myfsm {
   State actif {
     input =:> output
   }
   State inactif {

   }
   actif -> inactif (_spike)
   inactif -> actif (_spike)
 }
}

    