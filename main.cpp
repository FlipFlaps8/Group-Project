//Group 8
//CSCE 121-501
//Due April 28, 2014
//main.cpp

#include "std_lib_facilities_4.h"
#include "Graph.h"
#include "Simple_window.h"
#include "FlipFlap.h"

int current_screen = FlipFlap::SPLASH_SCREEN;
FlipFlap engine;

int main()
  try{
    switch(current_screen){
      case FlipFlap::SPLASH_SCREEN:
        engine.show_splash();
        break;
      case FlipFlap::LEVELS_SCREEN:
        engine.show_levels();
        break;
      case FlipFlap::GAME_SCREEN:
        engine.show_game();
        break;
      case FlipFlap::SCORES_SCREEN:
        engine.show_scores();
        break
    }
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
