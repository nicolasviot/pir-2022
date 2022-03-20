use core
use display
use gui
use base

import Button
import Robot
import Waypoint



_main_
Component root {
  Frame f ("robot", 0, 0, 1920, 1080)
  Exit quit (0, 1)
  f.close->quit

FillColor reed (250, 250, 255)
Rectangle ree (0,0, 1900, 1000, 0, 0) 

Robot myrobot(f, "src/Robot.png", 0, 0)
Waypoint myWaypoint(f, 500, 500)
myWaypoint.x =:> myrobot.targetX
myWaypoint.y =:> myrobot.targetY

}





