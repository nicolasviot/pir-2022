use core
use display
use gui
use base

import Button
import Robot
import Waypoint
import detour
import Bombe
import side
import side_bas


_main_
Component root {
  Frame f ("robot", 0, 0, 1920, 1080)
  Exit quit (0, 1)
  f.close->quit



FillColor reed (250, 250, 255)
Rectangle ree (0,0, 1900, 1000, 0, 0) 


Bombe myBombe(f, 700, 700)

//detour myDetour(f, $myBombe.x + 50, $myBombe.y+50, $myBombe.x ,$myBombe.y+50,$myBombe.x+50 ,$myBombe.y)

Robot myrobot(f, "src/Robot.png", 0, 0)
Waypoint myWaypoint(f, 500, 500)
myWaypoint.x =:> myrobot.targetX
myWaypoint.y =:> myrobot.targetY
/*
($myBombe.x>$myWaypoint.x)-> (root){
 root.myrobot.targetX = root.myBombe.x 
 root.myrobot.targetY = root.myBombe.y
}
*/


(((myBombe.y - myrobot.y)*(myBombe.y - myrobot.y)) < 50) && (((myBombe.y - myrobot.y)*(myBombe.y - myrobot.y)) < 50) ->myrobot._stop

myWaypoint.drag_Waypoint.moving -> myrobot.arrived



LogPrinter lp ("debug tangent : ")



FSM show_detour{
  State no_show{

  }
  State show{
    detour detour1 ("bas")
    detour detour2 ("haut")  
    myBombe.x =:> detour1.t.tx  
    myBombe.y =:> detour1.t.ty
    myBombe.x =:> detour2.t.tx  
    myBombe.y =:> detour2.t.ty
    Tangent tan (0)
    (myWaypoint.x - myrobot.x)/(myWaypoint.y - myrobot.y) =:> tan.input
    tan.output * 180 / 3.14 =:> detour1.rot.a
    tan.output * 180 / 3.14 + 180 =:> detour2.rot.a 
    tan.output =:> lp.input

  }
  no_show -> show(myrobot._stop)  
}





}





