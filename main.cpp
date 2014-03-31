//Group 8
//CSCE 121-501
//Due April 28, 2014
//main.cpp

#include "std_lib_facilities_4.h"
#include "Graph.h"
#include "Simple_window.h"
#include "Show.h"

const int SPLASH_SCREEN = 0;
const int LEVELS_SCREEN = 1;
const int GAME_SCREEN = 2;
const int SCORES_SCREEN = 3;

int current_screen = SPLASH_SCREEN;

int main()
  try{
    switch(current_screen){
      case SPLASH_SCREEN:
        show_splash();
        break;
      case LEVELS_SCREEN:
        show_levels();
        break;
      case GAME_SCREEN:
        show_game();
        break;
      case SCORES_SCREEN:
        show_scores();
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
