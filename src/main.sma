use core
use display
use gui
use base

import Button
import Robot
import Waypoint
import detour
import Bombe



_main_
Component root {
  Frame f ("robot", 0, 0, 1920, 1080)
  Exit quit (0, 1)
  f.close->quit

FillColor reed (250, 250, 255)
Rectangle ree (0,0, 1900, 1000, 0, 0) 


Bombe myBombe(f, 700, 700)
detour myDetour(f, $myBombe.x + 50, $myBombe.y+50, $myBombe.x ,$myBombe.y+50,$myBombe.x+50 ,$myBombe.y)

Robot myrobot(f, "src/Robot.png", 0, 0)
Waypoint myWaypoint(f, 500, 500)
myWaypoint.x =:> myrobot.targetX
myWaypoint.y =:> myrobot.targetY

myWaypoint.drag_Waypoint.moving -> myrobot.arrived

}





