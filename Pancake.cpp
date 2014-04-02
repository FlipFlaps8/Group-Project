//Group 8
//CSCE 121-501
//Pancake.cpp

#include "Pancake.h"

int height = 20;

int width1(int s1){
  return 40 + 40 * s1;
}

Point pPoint(int s, int p){
        return Point(FlipFlap::X_CENTER - width1(s)/2, FlipFlap::TABLE_TOP - height * p);
}

Pancake::Pancake(int size, int position) : Rectangle(pPoint(size,position),width1(size),20), s(size), p(position){}
