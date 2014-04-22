//Group 8
//CSCE 121-501
//Due April 28, 2014
//main.cpp

#include "FlipFlap.h"

FlipFlap engine;      //create the game engine

int main()
  try{
    srand(time(0));
    switch(engine.current_screen()){  //check game state
      case FlipFlap::SPLASH_SCREEN:
        engine.show_splash();         //show_x() functions actually do things
        break;
      case FlipFlap::LEVELS_SCREEN:
        engine.show_levels();
        break;
      case FlipFlap::GAME_SCREEN:
        engine.show_game();
        break;
      case FlipFlap::SCORES_SCREEN:
        engine.show_scores();
        break;
      }
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
