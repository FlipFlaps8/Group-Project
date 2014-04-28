//Group 8
//CSCE 121-501
//Pancake.h

#include "std_lib_facilities_4.h"
#include "Graph.h"
#include "Constants.h"

using namespace Graph_lib;

struct Pancake : Rectangle {
  Pancake(int size, int position);	//constructor
  int get_size();	//gets the size
  int s;	//size
  int p;	//position
};
