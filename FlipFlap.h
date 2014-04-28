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

  FlipFlap(): Simple_window(Point(100,100),600,400,"FlipFlap"){}            //create window

  void setup(int l);                                                        //setup play screen
  static void cb_flip(Address button, Address window);                      //callback to flip pancakes
  void flip(int p);                                                         //function to handle flipping pancakes

  void show_splash();                                                       //show the splash screen
  void show_levels();                                                       //level select screen
  void show_game();                                                         //show game
  void show_scores(int i);                                                  //display high scores
  void button_list(int i);                                                  //create pancake flipping buttons
  int calc_score(int flips);                                                //calculate current score
  void add_boxes();                                                         //add on screen counter boxes
  void update_boxes();                                                      //update counters
  void level_list();                                                        //make list of level select buttons
  static void cb_select(Address l_button, Address window);                  //call back for level select buttons
  static void cb_replay(Address, Address window);                           //call back for game replay button
  static void callback_showins(Address, Address pw);                        //call back for the instructions
  static void callback_showlevels(Address, Address pw);                     //call back to show the level select
  bool check_score();                                                       //check to see if won
  void print_highscores();                                                  //print high scores to screen
  void new_game();                                                          //create new game
  void show_ins();                                                          //show the instructions

  private:
  vector<int> game_stack;                                                   //ints to represent pancakes
  vector<Pancake*> game_stack_p;                                            //vector of pancakes
  Vector_ref<Button> buttons;                                               //vector of flip buttons
  Vector_ref<Text> high_score_list;                                         //list of high scores
  int current_level;                                                        //level selected
  Scores scores;                                                            //scores object
  string initials;                                                          //player initials
  int current_flips;                                                        //flips made so far
  int current_score;                                                        //current score
  int min_flips;                                                            //minimun flips necessary
  Vector_ref<Button> level_buttons;                                         //vector of level select buttons
  In_box* name_box;                                                         //input to receive player initials
  Out_box* min_box;                                                         //display minimun moves necessary
  Out_box* flips_box;                                                       //display flips made
  Out_box* score_box;                                                       //display current score
  Button* replay;                                                           //replay the game
  Image* instructions;                                                      //instructions screen
  Button* playbutton;                                                       //go to game button
  Image* splash;                                                            //splash screen
  Button* insbutton;                                                        //go to instructions button
  Text* end_text;                                                           //end screen text object
};
#endif
