//Group 8
//CSCE 121-501
//FlipFlap.h

struct FlipFlap(){
  
  enum{SPLASH_SCREEN, LEVELS_SCREEN, GAME_SCREEN, SCORES_SCREEN};
  
  bool is_running();
  int current_screen();
  
  void show_splash();
  void show_levels();
  void show_game();
  void show_scores();
  
  private:
  bool running;
  int screen;
};
