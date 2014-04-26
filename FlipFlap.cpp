//Group 8
//CSCE 121-501
//FlipFlap.cpp

#include "FlipFlap.h"
#include "find_solution.h"
//add whatever includes you need to make your show function work

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
        update_boxes();
        redraw();
        if(check_score()){
                for(Pancake* pancake : game_stack_p){
                        detach(*pancake);
                }
                for(int i = 0; i < (current_level-1); ++i)
                        detach(buttons[i]);
                show_scores(0);
        }
       if(calc_score(current_flips) == 0){\
         for(Pancake* pancake : game_stack_p){
                        detach(*pancake);
                }
                for(int i = 0; i < (current_level-1); ++i)
                        detach(buttons[i]);
                show_scores(1);
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
   if (buttons.size() == 0){
    for (int k = 0; k < 8; ++k){
      string* s = new string(to_string(k+1));
      buttons.push_back(new Button(Point(X_CENTER - 250,TABLE_TOP - 20*k),20,20,*s,cb_flip));
    }
  }
  for (int k = 0; k < (i-1); ++k)
    attach(buttons[k]);
}

int FlipFlap::calc_score(int flips){
        if(flips>min_flips)
                return (100 - 10 * (flips - min_flips)) * current_level;
        else
                return 100 * current_level;
}

void FlipFlap::update_boxes(){
  stringstream ss;
  ss << min_flips;
  min_box->put(ss.str());
  stringstream flbox;
  flbox << current_flips;
  flips_box->put(flbox.str());
  stringstream scbox;
  scbox << calc_score(current_flips);
  score_box->put(scbox.str());
}

void FlipFlap::add_boxes(){
  min_box = new Out_box(Point(150,0),25,20,"Can be done in:");
  flips_box = new Out_box(Point(300,0),30,20,"Current flips:");
  score_box = new Out_box(Point(450,0),50,20,"Current score:");
  attach(*min_box);
  attach(*flips_box);
  attach(*score_box);
  update_boxes();
}

void FlipFlap::setup(int level){
  initials=name_box->get_string();
  if(initials.size() == 0)
        initials = "---";
  detach(*name_box);
  for(int i = 0; i < level_buttons.size(); ++i)
    detach(level_buttons[i]);
  for(int i = 0; i < high_score_list.size(); ++i)
    detach(high_score_list[i]);
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
  //get min_flips
  vector<int> *solution = find_solution(game_stack);
  min_flips = solution->size();
  //draw buttons
  button_list(level);
  //display score
  add_boxes();
  redraw();
}

void FlipFlap::print_highscores(){
	high_score_list.clear();
        high_score_list.push_back(new Text(Point(100,100),"High scores:"));
        attach(high_score_list[0]);
        vector<Player> players = scores.get_highscores();
        for(int i = 1; i<6; ++i){
                stringstream scorestream;
                string tab = "\t";
                scorestream<<players[i-1].name<<tab<<players[i-1].score;
                high_score_list.push_back(new Text(Point(100,100 + i * 40),scorestream.str()));
                attach(high_score_list[i]);
        }
        high_score_list.push_back(new Text(Point(250,50),"Select your level:"));
        attach(high_score_list[high_score_list.size()-1]);
}

void FlipFlap::show_splash(){
        //make a splash
        //make a start game button
        //make instructions
        show_levels();
}

void FlipFlap::show_levels(){
        //take in initials
	name_box = new In_box(Point(X_CENTER,90),100,20,"Enter your initials");
        attach(*name_box);
        initials = "--";
        scores.read_highscores();
        print_highscores();
        level_list();
}

void FlipFlap::show_scores(int i){
  stringstream ss;
   if (i == 0)
    ss<<"Congratulations, "<<initials<<", you won! Your score was: "<<calc_score(current_flips);
  else
    ss<<"Sorry, "<<initials<<", you lost.  Your score was 0.";
  end_text = new Text(Point(100,100),ss.str());
  attach(*end_text);
  scores.game_score(initials,calc_score(current_flips));
  scores.write_highscores();
   //make buttons to either play again or quit
  replay = new Button(Point(100,200),70,20,"Play again?",cb_replay);
  attach(*replay);
}
void FlipFlap::level_list(){
  if (level_buttons.size() == 0){
    for (int k = 2; k < 10; ++k)
    {
      string* L = new string(to_string(k));
      level_buttons.push_back(new Button(Point(X_CENTER - 50,TABLE_TOP + 100 - 30*k),100,20,*L,cb_select));
    }
  }
  for (int k = 2; k < 10; ++k){
    attach(level_buttons[k-2]);
  }
}

void FlipFlap::cb_select(Address l_button, Address window){
        auto button_level = reference_to<Fl_Button>(l_button).label();
        stringstream L(button_level);
        int selected_level = 0;
        L>>selected_level;
        reference_to<FlipFlap>(window).setup(selected_level);
}
void FlipFlap::new_game(){
  detach(*replay);
  detach(*end_text);
  detach(*min_box);
  detach(*flips_box);
  detach(*score_box);
  redraw();
  show_levels();
}

void FlipFlap::cb_replay(Address, Address window){
  reference_to<FlipFlap>(window).new_game();
}

