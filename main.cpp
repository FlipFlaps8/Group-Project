//Group 8
//CSCE 121-501
//Due April 28, 2014
//main.cpp

#include "FlipFlap.h"

int main()
  try{
    FlipFlap engine;                        //create the game engine
    srand(time(0));                         //initialize randomizer
    engine.show_splash();                   //show the splash screen
    return gui_main();                      //run game
  }
  catch(exception& e){                      //print exceptions
    cerr<<"Error: "<<e.what()<<'\n';
    keep_window_open();
    return 1;
  }
  catch(...){                               //catch unknown errors
    cerr<<"Unknown error\n";
    keep_window_open();
    return 2;
  }
