use core
use base
use display
use gui
import Button

_define_
flux2(Process frame) {
  
  Button b (frame, "Button", 290, 300)
 // Image img ("/home/dolama/Bureau/pir/image/comme.png", 290, 0, 90, 90)

  Spike click

 
FSM fsmImg{
  State idleImg{
    Image img ("/home/dolama/Bureau/pir/image/comme.png", 290, 0, 90, 90)




                      FSM fsm {
                  State idle {
                    FillColor init_color (0, 0, 0)
                    Rectangle r1 (10, 0, 100, 70, 0, 0)
                    
                  
                    Timer t (500)
                  }
                  State Red_R1
                  {
                    FillColor red_color (255, 0, 0)
                    Rectangle r1 (10, 0, 100, 70, 0, 0)
                    Timer t (500)
                  }
                  State Green_R1
                  {
                    FillColor green_color (0, 255, 0)
                  Rectangle r1 (10, 0, 100, 70, 0, 0)
                    Timer t (500)
                  }



                

                  idle -> Red_R1 (idle.t.end)
                  Red_R1->Green_R1(Red_R1.t.end)
                  Green_R1->Red_R1(Green_R1.t.end)

              
                  


                }


              FSM fsmR {
                  State idleR {
                    FillColor init_color (0, 0, 0)
                    
                    Rectangle r2 (500, 0, 100, 70, 0, 0)
                  
                    Timer tR (500)
                  }
                  

                  State Red_R2
                  {
                    FillColor red_color (255, 0, 0)
                  Rectangle r2 (500, 0, 100, 70, 0, 0)
                    Timer tR (500)
                  }
                  State Green_R2
                  {
                    FillColor green_color (0, 255, 0)
                  Rectangle r2 (500, 0, 100, 70, 0, 0)
                    Timer tR (500)
                  }
                

                


                  idleR -> Red_R2 (idleR.tR.end)
                  Red_R2->Green_R2(Red_R2.tR.end)
                  Green_R2->Red_R2(Green_R2.tR.end)

                  


              }



  }
  State clk{

 Image img ("/home/dolama/Bureau/pir/image/panneau-stop.png", 290, 0, 90, 90)



     FSM fsm {
                  State idle {
                    FillColor init_color (0, 0, 0)
                    Rectangle r1 (10, 0, 100, 70, 0, 0)
                    
                  
                    Timer t (500)
                  }
                  State Red_R1
                  {
                    FillColor red_color (255, 0, 0)
                    Rectangle r1 (10, 0, 100, 70, 0, 0)
                    Timer t (500)
                  }
                  State Green_R1
                  {
                    FillColor green_color (0, 255, 0)
                  Rectangle r1 (10, 0, 100, 70, 0, 0)
                    Timer t (500)
                  }



                

                  idle -> Red_R1 (idle.t.end)
                  Red_R1->Green_R1(Red_R1.t.end)
                  Green_R1->Red_R1(Green_R1.t.end)

              
                  


                }



                FSM fsmR {
                  State idleR {
                    FillColor init_color (0, 0, 0)
                    
                    Rectangle r2 (500, 0, 100, 70, 0, 0)
                  
                   
                  }
                                


              }


  }

  idleImg->clk(b.click)
  clk->idleImg(b.click)

}







}

    