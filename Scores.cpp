//Group 8
//CSCE 121-501
//Scores.h
#include "Scores.h"
#include "std_lib_facilities_4.h"
#include <iostream>
#define MAX_SCORES 5

Scores::Scores(){
}
void Scores::read_highscores(){
  string filename = "HighScore.txt";
  ifstream iscore_file(filename.c_str());
  if(iscore_file){
    cout<<"True?";
	while(iscore_file.good()){
		Player p;
		iscore_file>>p.name;
		iscore_file>>p.score;
		scores.push_back(p);
	}
  }
}
void Scores::write_highscores(){
  scores.erase(scores.begin()+6,scores.end());
  ofstream oscore_file("HighScore.txt",ios::out | ios::trunc);
  for(int i = 0;i<scores.size()-1;++i){
	oscore_file<<scores[i].name<<' '<<scores[i].score<<' ';
  }
  oscore_file.close();
  scores.clear();
}
void Scores::game_score(string initials, int score){
	int count = 0;
	cout<<"Test3"<<endl;
	while(count<5 && scores[count].score>score){
		++count;
		cout<<count<<endl;
	}
	cout<<count<<endl;
	for(int i=4;i>count;--i){
		scores[i]=scores[i-1];
		cout<<scores[i].score;
	}
	Player p;
	p.name=initials;
	p.score=score;
	scores[count]=p;
}
vector<Player> Scores::get_highscores(){
	return scores;
}
//end
