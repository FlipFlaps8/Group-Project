//Group 8
//CSCE 121-501
//Scores.h
#include "std_lib_facilities_4.h"
using namespace std;

struct Player { //contains player name and score
  string name;
  int score;
};

class Scores
{
public:

	Scores();						//constructor

	void read_highscores();					//read high scores from file into scores vector

	void write_highscores();				//write high scores from scores vector into file

	void game_score(string initials, int score);	
	
	vector<Player> get_highscores();			//get scores vector

private:

	vector<Player> scores;					//vector of players and scores
};
