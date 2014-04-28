//Group 8
//CSCE 121-501
//Pancake.cpp

#include "Pancake.h"

int height = 20;

int width1(int s1){	//calculate the width of a pancake from size s1
  return 40 + 40 * s1;
}

Point pPoint(int s, int p){	//calculate the top left point of a pancake with a given size and position
	return Point(X_CENTER - width1(s)/2, TABLE_TOP - height * p);
}

Pancake::Pancake(int size, int position) : Rectangle(pPoint(size,position),width1(size),20), s(size), p(position){}	//construct a pancake

int Pancake::get_size(){	//get the size of a pancake
	return s;
}
