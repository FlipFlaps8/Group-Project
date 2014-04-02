//Group 8
//CSCE 121-501
//FlipFlap.cpp

#include "FlipFlap.h"
#include "Game.h"
//add whatever includes you need to make your show function work

bool FlipFlap::is_running(){
  return running;
}

int FlipFlap::current_screen(){
  return screen;
}

void FlipFlap::show_splash(){

}

void FlipFlap::show_levels(){

}

void FlipFlap::show_game(){
  setup();
}

void FlipFlap::show_score(){

}
