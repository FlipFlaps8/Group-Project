//Group 8
//CSCE 121-501
//Pancake.cpp

#include "Pancake.h"

Pancake::Pancake(int size, int position){
  int width = 40 + 40 * size;
  int height = 20;
  Graph_lib::Point point = Graph_lib::Point(FlipFlap::X_CENTER - width/2, FlipFlap::TABLE_TOP + height * position)
  Rectangle(point, width, height);
}
