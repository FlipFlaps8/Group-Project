//Group 8
//CSCE 121-501
//FlipFlap.h

#ifndef FLIPFLAP_GUARD
#define FLIPFLAP_GUARD

#include "Simple_window.h"
#include "Pancake.h"

struct FlipFlap{

  static const int X_MAX = 599;
  static const int Y_MAX = 399;
  static const int X_CENTER = 299;
  static const int Y_CENTER = 199;
  static const int TABLE_TOP = 299;
  Simple_window win;

  enum{SPLASH_SCREEN, LEVELS_SCREEN, GAME_SCREEN, SCORES_SCREEN};

  FlipFlap(): win(Point(100,100),600,400,"FlipFlap"), running(true), screen(FlipFlap::SPLASH_SCREEN){}

  bool is_running();
  int current_screen();
  void done();

  void setup(int l);
  void cb_flip(Address button, Address window);
  void flip(int p);


  void show_splash();
  void show_levels();
  void show_game();
  void show_scores();
  void button_list(int i);

  private:
  bool running;
  int screen;
  vector<int> game_stack;
  vector<Pancake*> game_stack_p;
};
#endif
