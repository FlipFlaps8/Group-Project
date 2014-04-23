//Group 8
//CSCE 121-501
//FlipFlap.h

#ifndef FLIPFLAP_GUARD
#define FLIPFLAP_GUARD

#include "Simple_window.h"
#include "Pancake.h"
#include "GUI.h"
#include <FL/Fl_Button.H>

using namespace Graph_lib;

struct FlipFlap : Simple_window {

  enum{SPLASH_SCREEN, LEVELS_SCREEN, GAME_SCREEN, SCORES_SCREEN};

  FlipFlap(): Simple_window(Point(100,100),600,400,"FlipFlap"), running(true), screen(FlipFlap::SPLASH_SCREEN){}

  bool is_running();
  int current_screen();
  void done();

  void setup(int l);
  static void cb_flip(Address button, Address window);
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
  Vector_ref<Button> buttons;
};
#endif
