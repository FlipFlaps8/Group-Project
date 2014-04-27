//Group 8
//CSCE 121-501
//Scores.h
#include "Scores.h"
#include "std_lib_facilities_4.h"
#include <iostream>
#define MAX_SCORES 5

Scores::Scores(){
}
void Scores::read_highscores(){						// get high scores from file
  string filename = "HighScore.txt";					//file name
  ifstream iscore_file(filename.c_str());				//open file
  if(iscore_file){							//if file opens
	while(iscore_file.good()){
		Player p;						//make a new player
		iscore_file>>p.name;					//get name from file
		iscore_file>>p.score;					//get score from file
		scores.push_back(p);					//add player to scores vector
	}
  }
}
void Scores::write_highscores(){					//write high scores to file
  scores.erase(scores.begin()+6,scores.end());				//delete any scores after five
  ofstream oscore_file("HighScore.txt",ios::out | ios::trunc);		//clear old file
  for(int i = 0;i<scores.size()-1;++i){					//get scores from scores vector
	oscore_file<<scores[i].name<<' '<<scores[i].score<<' ';
  }
  oscore_file.close();							//close file
  scores.clear();							//clear scores vector
}
void Scores::game_score(string initials, int score){
	int count = 0;
	while(count<5 && scores[count].score>score){
		++count;
	}
	for(int i=4;i>count;--i){
		scores[i]=scores[i-1];
	}
	Player p;
	p.name=initials;
	p.score=score;
	scores[count]=p;
}
vector<Player> Scores::get_highscores(){				//get scores vector for use
	return scores;							//return scores vector
}
//end
