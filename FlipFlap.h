//Group 8
//CSCE 121-501
//FlipFlap.h

#include "std_lib_facilities_4.h"
#include "Simple_window.h"
#include "Graph.h"

struct FlipFlap{
  
  static const int X_MAX = 599;
  static const int Y_MAX = 399;
  static const int X_CENTER = 299;
  static const int Y_CENTER = 199;
  static const int TABLE_TOP = 299;
  static Simple_window win(Point(100,100),600,400,"FlipFlap");
  
  enum{SPLASH_SCREEN, LEVELS_SCREEN, GAME_SCREEN, SCORES_SCREEN};
  
  bool is_running();
  int current_screen();
  void done();
  
  void show_splash();
  void show_levels();
  void show_game();
  void show_scores();
  
  private:
  bool running;
  int screen;
};
