//Group 8
//CSCE 121-501
//Scores.h
#include "scores.h"
#include "std_lib_facilities_4.h"
#define MAX_SCORES 5

Scores::Scores(){
	read_highscores();
}
void Scores::read_highscores(){
  ifstream iscore_file("HighScore.txt")
  if(iscore_file.is_open()){
	while(iscore_file.is_good()){
		Player p;
		iscore_file>>p.name;
		iscore_file>>p.score;
		scores.push_back(p);
	}
	iscore_file.close();
  }
  
}
void Scores::write_highscores(){
  ofstream oscore_file("HighScore.txt",ios::trunc);
  for(int i = 0;i<scores.size();++i){
	oscore_file<<scores[i].name<<' '<<scores[i].score;
  }
  oscore_file.close;
}
void Score::game_score(string initials, int score){
	int count = 0;
	while(scores[count].score>score){
		++count;
		if(count=5)
			return 0;
	}
	for(int i=4;i>count;--i){
		scores[i]=scores[i-1];
	}
	Player p;
	p.name=initials;
	p.score=score;
	scores[count]=p;
}
vector<Player> Scores::get_highscore(){
	return scores;
}
