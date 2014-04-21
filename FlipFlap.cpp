//Group 8
//CSCE 121-501
//FlipFlap.cpp

#include "FlipFlap.h"
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

void button_list(int i){
  vector<In_Box> buttons(i);
  for (int k = 0; k < i; ++k)
  {
    stringstream s;
    s<<(k);
    buttons[k] = In_box(Point(X_CENTER - 250,TABLE_TOP - 20*k),20,20,s.str(),FlipFlap::cb_flip)
    win.attach(buttons[k]);
  }
}

void FlipFlap::setup(int level){
  //draw pancakes
  game_stack = pancake_stack(level);
  game_stack_p.resize(game_stack.size());
  for(int i = 0; i < game_stack.size(); ++i){
    game_stack_p[i] = new Pancake(game_stack[i],i);
  }
  for(Pancake* pancake : game_stack_p){
    win.attach(*pancake);
  }
  //draw buttons
  //display score
}

void FlipFlap::cb_flip(Address button, Address window){
        auto button_label reference_to<Fl_Button>(button).label();
        stringstream s(button_label);
        int pancake = 0;
        s>>pancake;
        flip(pancake);
}

void FlipFlap::flip(int p){

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
