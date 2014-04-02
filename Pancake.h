//Group 8
//CSCE 121-501
//Pancake.h

#include "Graph.h"
#include "FlipFlap.h"

using namespace Graph_lib;

struct Pancake : Rectangle {
  Pancake(int size, int position);
  Pancake(const Pancake& p1);
  Pancake& operator=(const Pancake& p1);
  int s;
  int p;
};
