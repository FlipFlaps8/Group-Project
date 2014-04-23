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

	Scores();

	void read_highscores();

	void write_highscores();

	int game_score(string initials, int score);

	vector<Player> get_highscores();

private:

	vector<Player> scores;
};
