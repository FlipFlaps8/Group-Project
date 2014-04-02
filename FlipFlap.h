//Group 8
//CSCE 121-501
//FlipFlap.h

#include "std_lib_facilities_4.h"
#include "Game.h"

struct FlipFlap{
  
  const int X_MAX = 599;
  const int Y_MAX = 399;
  const int X_CENTER = 299;
  const int Y_CENTER = 199;
  const int TABLE_TOP = 299;
  
  enum{SPLASH_SCREEN, LEVELS_SCREEN, GAME_SCREEN, SCORES_SCREEN};
  
  bool is_running();
  int current_screen();
  
  void show_splash();
  void show_levels();
  void show_game();
  void show_scores();
  
  private:
  bool running;
  int screen;
};
