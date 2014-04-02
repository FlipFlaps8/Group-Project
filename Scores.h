//Group 8
//CSCE 121-501
//Scores.h

void find_solution();

void write_top5(Player& score){
  ofstream oscore_file;
  oscore_file.open("HighScore.txt");
  oscore_file<<scorel;
  oscore_file.close;
  
}
struct Player { //contains player name and score
  string name;
  int score;
}

Player scores[5];

void get_top5(){
  ifstream iscore_file("HighScore.txt")
  iscore_file>>
  
}
