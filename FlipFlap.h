//Group 8
//CSCE 121-501
//FlipFlap.h

#ifndef FLIPFLAP_GUARD
#define FLIPFLAP_GUARD

#include "Simple_window.h"
#include "Pancake.h"
#include "Scores.h"
#include "GUI.h"
#include <FL/Fl_Button.H>

using namespace Graph_lib;

struct FlipFlap : Simple_window {

  FlipFlap(): Simple_window(Point(100,100),600,400,"FlipFlap"){}

  void setup(int l);
  static void cb_flip(Address button, Address window);
  void flip(int p);

  void show_splash();
  void show_levels();
  void show_game();
  void show_scores(int i);
  void button_list(int i);
  int calc_score(int flips);
  void add_boxes();
  void update_boxes();
  void level_list();
  static void cb_select(Address l_button, Address window);
  static void cb_replay(Address, Address window)
  bool check_score();
  void print_highscores();
  void new_game();

  private:
  vector<int> game_stack;
  vector<Pancake*> game_stack_p;
  Vector_ref<Button> buttons;
  Vector_ref<Text> high_score_list;
  int current_level;
  Scores scores;
  string initials;
  int current_flips;
  int current_score;
  int min_flips;
  Vector_ref<Button> level_buttons;
  Out_box* min_box;
  Out_box* flips_box;
  Out_box* score_box;
  Button* replay;
  Text* end_text;
};
#endif
