//Group 8
//CSCE 121-501
//FlipFlap.cpp

#include "FlipFlap.h"
#inclue "find_solution.h"
//add whatever includes you need to make your show function work

bool FlipFlap::is_running(){
  return running;
}

int FlipFlap::current_screen(){
  return screen;
}

void FlipFlap::done(){
  running = false;
}

vector<int> pancake_stack(int l){
  vector<int> pancakes(l);
  for(int i =0; i < l; ++i)
    pancakes[i] = i + 1;
  random_shuffle(pancakes.begin(), pancakes.end());
  return pancakes;
}

void FlipFlap::flip(int p){
        ++current_flips;
        for(Pancake* pancake : game_stack_p){
                detach(*pancake);
        }
        auto it = std::next(game_stack_p.begin(), (p-1));
        reverse(it,game_stack_p.end());
        for(int i = (p-1); i < game_stack.size(); ++i){
                game_stack_p[i] = new Pancake(game_stack_p[i]->get_size(),i);
        }
        for(Pancake* pancake : game_stack_p){
                attach(*pancake);
        }
        //out box with calc_score and current_flips. Make outbox in .h and put
        //in setup as well so it's always there
        cout<<calc_score(current_flips)<<' '<<min_flips<<' '<<current_flips<<'\n';
        // ^ replace with out box
        redraw();
        if(check_score()){
                for(Pancake* pancake : game_stack_p){
                        detach(*pancake);
                }
                for(int i = 0; i < buttons.size(); ++i)
                        detach(buttons[i]);
                show_scores();
        }
}

bool FlipFlap::check_score(){
        bool in_order = true;
        for(int i = 0; i < (game_stack_p.size() - 1); ++i){
                if(game_stack_p[i]->get_size() < game_stack_p[i+1]->get_size())
                        in_order = false;
        }
        return in_order;
}

void FlipFlap::cb_flip(Address button, Address window){
        auto button_label = reference_to<Fl_Button>(button).label();
        stringstream s(button_label);
        int pancake = 0;
        s>>pancake;
        reference_to<FlipFlap>(window).flip(pancake);
}

void FlipFlap::button_list(int i){
  for (int k = 0; k < (i-1); ++k)
  {
    string* s = new string(to_string(k+1));
    buttons.push_back(new Button(Point(X_CENTER - 250,TABLE_TOP - 20*k),20,20,*s,cb_flip));
    attach(buttons[k]);
  }
}

int FlipFlap::calc_score(int flips){
        if(flips>min_flips)
                return (100 - 10 * (flips - min_flips)) * current_level;
        else
                return 100 * current_level;
}

void FlipFlap::setup(int level){
  current_flips = 0;
  current_level = level;
  //draw pancakes
  game_stack = pancake_stack(level);
  game_stack_p.resize(game_stack.size());
  for(int i = 0; i < game_stack.size(); ++i){
    game_stack_p[i] = new Pancake(game_stack[i],i);
  }
  for(Pancake* pancake : game_stack_p){
    attach(*pancake);
  }
  //draw buttons
  button_list(level);
  //display score
  //get min_flips
  vector<int> *solution = find_solution(game_stack);
  min_flips = solution->size();
}

void FlipFlap::show_splash(){
        //make a splash
        //make a start game button
        //make instructions
        show_levels();
}

void FlipFlap::show_levels(){
        //take in initials
        //read scores
        //make level buttons
        show_game();
}

void FlipFlap::show_game(){
  setup(9);
}

void FlipFlap::show_scores(){
  Text* t = new Text(Point(100,100),"Congratulations, you won!");
  attach(*t);
  //display initials
  //write highscores
  //read and display new highscores
  //make buttons to either play again or quit
}
