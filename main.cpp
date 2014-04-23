//Group 8
//CSCE 121-501
//Due April 28, 2014
//main.cpp

#include "FlipFlap.h"

int main()
  try{
    FlipFlap engine;      //create the game engine
    srand(time(0));
    engine.show_splash();
    return gui_main();
  }
  catch(exception& e){
    cerr<<"Error: "<<e.what()<<'\n';
    keep_window_open();
    return 1;
  }
  catch(...){
    cerr<<"Unknown error\n";
    keep_window_open();
    return 2;
  }
