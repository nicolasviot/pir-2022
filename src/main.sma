use core
use display
use gui
use base

import Button
import Robot


_action_
smala_action1_c (Process src, Process data){
data.state = 820
}

_action_
smala_action1_continue (Process src, Process data){
data.state = 950
}
_action_
smala_action2_c (Process src, Process data){
data.state = 250
}


_action_
smala_action2_d (Process src, Process data){
data.state = 400
}

_action_
smala_action3_c (Process src, Process data){
data.state = 340
}








_action_
smala_action1 (Process src, Process data){
data.state = 0
}

_action_
smala_action2 (Process src, Process data){
data.state = 340
}

_action_
smala_action3 (Process src, Process data){
data.state = 440
}

_action_
smala_action4 (Process src, Process data){
data.state = 330
}

_action_
smala_action5 (Process src, Process data){
data.delta = 0
}

_action_
smala_action6 (Process src, Process data){
data.delta = 10
}


_main_
Component root {
  Frame f ("robot", 0, 0, 1920, 1080)
  Exit quit (0, 1)
  f.close->quit

FillColor reed (250, 250, 255)
Rectangle ree (0,0, 1900, 1000, 0, 0) 


   Int tragetX (1500)
   

  /*robot vue de face*/
  //svg = loadFromXML ("src/vueface.png")
 // Rotation Rot(0,440,330)
  Image robot_vueface ("src/vueface.png", 1570, 780, 150, 150)


        //doit etre actif à l'arrivé de point d'arret

    FSM fsm1 {
    State idle1 {
    
      FillColor reed (255, 0, 0)
      //Rectangle ree (1580, 620, 400, 400, 5, 5)
      //Circle c1 (200, 200, 50)
      Image direct ("src/direct.png", 1540, 840, 55, 45)
      Image direct2 ("src/direct2.png", 1700, 840, 55, 45)
      Timer t (100)
    }
    State pressed1
    {
      
      FillColor reed (255, 0, 0)
      Rectangle ree (1580, 6200, 400, 400, 5, 5)
      //Circle c1 (200, 200, 50)
      Image direct ("src/direct.png", 1530, 840, 55, 45)
      Image direct2 ("src/direct2.png", 1710, 840, 55, 45)
      Timer t (100)
    }

    State pressed2
    {
    
      FillColor reed (255, 0, 0)
      Rectangle ree (1580, 6200, 400, 400, 5, 5)
      
      Image direct ("src/direct.png", 1520, 840, 55, 45)
      Image direct2 ("src/direct2.png", 1720, 840, 55, 45)
      Timer t (100)
    }

    State pressed3
    {
      
      FillColor reed (255, 0, 0)
  Rectangle ree (1580, 6200, 400, 400, 5, 5)
      //Circle c1 (200, 200, 50)
      Image direct ("src/direct.png", 1510, 840, 55, 45)
      Image direct2 ("src/direct2.png", 1730, 840, 55, 45)
      Timer t (100)
    }


    idle1->pressed1 (idle1.t.end)
    pressed1->pressed2 (pressed1.t.end)
    pressed2->pressed3 (pressed2.t.end)
    pressed3->idle1 (pressed3.t.end)
    
    
  }





//waipoint


     OutlineColor _ (0, 0, 0)
     Line l (0, 430, 850, 430)

     Line l2 (1000, 430, 1500, 430)





  /*Chargement du fond de carte*/
  Image img ("src/Crte.png", 0, 0, 750, 500)
  
  
  /*robot*/
  svg = loadFromXML ("src/Robot.png")
  Rotation Rot(0,440,330)
  Image robot ("src/Robot.png", 425, 340, 150, 150)


  /*ponit*/
 
  Image point ("src/point.png", 425, 340, 150, 150)
  

/*bombe*/
  svg1 = loadFromXML ("src/Bombe.png")
  
  Image bombe ("src/Bombe.png", 0, 0, 35, 45)

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


  LogPrinter lp("Debug : ")


  distance =:> lp.input
/*
  Spike something_moved

  robot.x -> something_moved
  robot.y -> something_moved
  bombe.x -> something_moved
  bombe.y -> something_moved
*/
  
f.move.x=:>bombe.x

f.move.y=:>bombe.y







  






FSM fsm {
    State idle {
      Image bombe ("src/start.png",0, 0, 100, 100)
      FillColor red (255, 0, 0)
      FillOpacity a (0)
      Rectangle r (0, 0, 100, 100, 0, 0)
    }
    State pressed
    {
      Image bombe ("src/arret.png",1700,0, 100, 100)

      FillColor green (255, 0, 0)
      
      Rectangle r (0, 0, 100, 70, 0, 0)
      
    



    



        /*Boutons Simulation*/
       
        Button b (f,  " Back Home  ", 1105, 825)
        Button b2 (f, "    STOP    ", 855, 825)
        Button b3 (f, "    PLAY    ", 605, 825)
        Button b5 (f, "  contunue  ", 355, 825)
        FillOpacity a (0)
        Button b4 (f, "   Gauche   ", 1500, 830)
        Button b6 (f, "   droite       ", 1690, 825)
                
        Clock sec (200)
        Incr x (1)
        Incr y (1)
        0 =: x.state
        340 =: y.state
        10 =: x.delta
        0 =: y.delta
        sec.tick -> x
        sec.tick -> y
        x.state =:> robot.x
        y.state =:> robot.y

        (x.state-100) => point.x
        y.state => point.y
       


      /*contoune gauche*/
        NativeAction nac1 (smala_action1_c,x,1)
        NativeAction nac2 (smala_action2_c,y,1)
        b4.click->nac1
        b4.click->nac2
        


      /*contoune droit*/
        NativeAction nac1_d (smala_action1_c,x,1)
        NativeAction nac2_d (smala_action2_d,y,1)
        b6.click->nac1_d
        b6.click->nac2_d


      //revenir sur la route et contunuer
        NativeAction nac3 (smala_action1_continue,x,1)
        NativeAction nac4 (smala_action2,y,1)
        b5.click->nac3
        b5.click->nac4



        
        /*RESET*/
        NativeAction na1 (smala_action1,x,1)
        NativeAction na2 (smala_action2,y,1)
        b.click->na1
        b.click->na2
        
        /*STOP*/
        NativeAction na5 (smala_action5,x,1)
        b2.click->na5

        (robot.x>1500) ->na5

        (distance < robot.width + 75) ->na5
      
        
        
        /*Play*/
        NativeAction na9 (smala_action6,x,1)
        b3.click->na9

     /*   na5=:> (FSM fsm___ {
    State idle {
      Timer t (1000)
      FillColor red (255, 0, 0)
      Rectangle r (0, 0, 100, 70, 0, 0)
    }
    State pressed
    { Timer t (1000)
      FillColor green (0, 255, 0)
      Rectangle r (0, 0, 100, 70, 0, 0)
    }
    idle->pressed (idle.t.end)
    pressed->idle (pressed.t.end)
    
  })*/


        
 
      }
    idle->pressed (idle.r.press)
    pressed->idle (pressed.r.press)
    
  }





Robot myrobot(f, "src/Robot.png", 0, 0)
}





