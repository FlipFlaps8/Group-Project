//Group 8
//CSCE 121-501
//FlipFlap.cpp

#include "FlipFlap.h"
#include "Pancake.h"
//add whatever includes you need to make your show function work

bool FlipFlap::is_running(){
  return running;
}

int FlipFlap::current_screen(){
  return screen;
}

void FlipFlap::done(){
  running = false;
}

vector<int> pancake_stack(int l){
  vector<int> pancakes(l);
  for(int i =0; i < l; ++i)
    pancakes[i] = i;
  random_shuffle(pancakes.begin(), pancakes.end());
  return pancakes;
}

void FlipFlap::setup(int level){
  //draw pancakes
  vector<int> game_stack = pancake_stack(level);
  vector<Pancake*> game_stack_p(game_stack.size());
  for(int i = 0; i < game_stack.size(); ++i){
    game_stack_p[i] = new Pancake(game_stack[i],i);
  }
  for(Pancake* pancake : game_stack_p){
    win.attach(*pancake);
  }
  win.wait_for_button();
  //draw buttons
  //display score
}

void FlipFlap::update(){
}

void FlipFlap::show_splash(){

}

void FlipFlap::show_levels(){

}

void FlipFlap::show_game(){
  setup(9);
}

void FlipFlap::show_scores(){

}
