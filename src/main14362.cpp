#include "exec_env/exec_env-dev.h"
#include "core/utils/error.h" // for Context class
#undef error // avoid name clash with error macro and possible following #include
#undef warning // avoid name clash with error macro and possible following #include

using namespace djnn;

#include "core/core-dev.h"
#include "base/base-dev.h"
#include "display/display-dev.h"
#include "gui/gui-dev.h"
#include "Button.h"

#include <iostream>

void
myFunc1(CoreProcess *s)
{


  if(s){

 
  std::cout << ("Button 1 clicked") << std::endl;
}
}
void
myFunc2(CoreProcess *c)
{

  if(c){
    
   
  std::cout << ("Button 2 clicked") << std::endl;
}
}
