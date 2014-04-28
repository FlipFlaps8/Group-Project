//Group 8
//CSCE 121-501
//FlipFlap.cpp

#include "FlipFlap.h"
#include "find_solution.h"
//add whatever includes you need to make your show function work

vector<int> pancake_stack(int l){						//create a vector representing the stack
  vector<int> pancakes(l);							//of pancakes
  for(int i =0; i < l; ++i)
    pancakes[i] = i + 1;
  random_shuffle(pancakes.begin(), pancakes.end()); 				//randomize the stack
  return pancakes;
}

void FlipFlap::flip(int p){							//flip the top p pancakes
        ++current_flips;							//increment flips player has made
        for(Pancake* pancake : game_stack_p){					//detach old stack from window
                detach(*pancake);
        }
        auto it = std::next(game_stack_p.begin(), (p-1));			//flip order in the list
        reverse(it,game_stack_p.end());
        for(int i = (p-1); i < game_stack.size(); ++i){
                game_stack_p[i] = new Pancake(game_stack_p[i]->get_size(),i);
        }
        for(Pancake* pancake : game_stack_p){					//re-attach the changed pancakes
                attach(*pancake);
        }
        update_boxes();								//update on-screen counters
        redraw();								//redraw window
        if(check_score()){							//if stack is sorted
                for(Pancake* pancake : game_stack_p){				//detach pancake stack
                        detach(*pancake);
                }
                for(int i = 0; i < (current_level-1); ++i)			//detach flip buttons
                        detach(buttons[i]);
                show_scores(0);							//go to show scores (Win)
        }
       if(calc_score(current_flips) == 0){					//if score has hit 0
         for(Pancake* pancake : game_stack_p){					//detach pancakes
                        detach(*pancake);
                }
                for(int i = 0; i < (current_level-1); ++i)
                        detach(buttons[i]);					//detach flip buttons
                show_scores(1);							//go to show scores (Lose)
       }

}

bool FlipFlap::check_score(){							//check if won the game
        bool in_order = true;							//default true
        for(int i = 0; i < (game_stack_p.size() - 1); ++i){			//if any are smaller than the one
                if(game_stack_p[i]->get_size() < game_stack_p[i+1]->get_size()) //above them, return false
                        in_order = false;
        }
        return in_order;							
}

void FlipFlap::cb_flip(Address button, Address window){				//flip callback
        auto button_label = reference_to<Fl_Button>(button).label();		//grab position of pancake from button
        stringstream s(button_label);
        int pancake = 0;
        s>>pancake;
        reference_to<FlipFlap>(window).flip(pancake);				//pass the position to flip
}

void FlipFlap::button_list(int i){						//create list of flip buttons
   if (buttons.size() == 0){							//if the vector is empty
    for (int k = 0; k < 8; ++k){						//make buttons with names as positions
      string* s = new string(to_string(k+1));
      buttons.push_back(new Button(Point(X_CENTER - 250,TABLE_TOP - 20*k),20,20,*s,cb_flip));
    }
  }
  for (int k = 0; k < (i-1); ++k)
    attach(buttons[k]);								//attach each button
}

int FlipFlap::calc_score(int flips){						//get current score
        if(flips>min_flips)							//if they have passed minimun threshold
                return (100 - 10 * (flips - min_flips)) * current_level;	//return score
        else
                return 100 * current_level;					//return ideal score
}

void FlipFlap::update_boxes(){							//update on-screen counters
  stringstream ss;								//put min_flips into a string
  ss << min_flips;		
  min_box->put(ss.str());							//display minimun flips needed
  stringstream flbox;								//put current flips into a string
  flbox << current_flips;
  flips_box->put(flbox.str());							//display current flips
  stringstream scbox;								//put score in a string
  scbox << calc_score(current_flips);
  score_box->put(scbox.str());							//display current score
}

void FlipFlap::add_boxes(){							//create counter boxes
  min_box = new Out_box(Point(150,0),25,20,"Can be done in:");			//display minumun needed flips
  flips_box = new Out_box(Point(300,0),30,20,"Current flips:");			//display flips taken
  score_box = new Out_box(Point(450,0),50,20,"Current score:");			//display current score
  attach(*min_box);								//attach boxes
  attach(*flips_box);
  attach(*score_box);
  update_boxes();								//call update
}

void FlipFlap::setup(int level){						//setup play screen
  initials=name_box->get_string();						//get their initials
  if(initials.size() == 0)							//if none entered, create "---"
        initials = "---";
  detach(*name_box);								//remove input box from screen
  for(int i = 0; i < level_buttons.size(); ++i)					//remove level select buttons from screen
    detach(level_buttons[i]);
  for(int i = 0; i < high_score_list.size(); ++i)				//remove high schores from screen
    detach(high_score_list[i]);
  current_flips = 0;
  current_level = level;
  //draw pancakes
  game_stack = pancake_stack(level);						//initialize stack of ints
  game_stack_p.resize(game_stack.size());					//initialize stack of pancakes
  for(int i = 0; i < game_stack.size(); ++i){
    game_stack_p[i] = new Pancake(game_stack[i],i);
  }
  for(Pancake* pancake : game_stack_p){						//attach stack of pancakes
    attach(*pancake);
  }
  //get min_flips
  vector<int> *solution = find_solution(game_stack);				//calculate minimum needed flips
  min_flips = solution->size();
  //draw buttons
  button_list(level);								//create flip buttons
  //display score
  add_boxes();									//add on screen counters
  redraw();									//draw window
}

void FlipFlap::print_highscores(){						//show high scores
	high_score_list.clear();						//clear existing list
        high_score_list.push_back(new Text(Point(100,100),"High scores:"));	//add title
        attach(high_score_list[0]);
        vector<Player> players = scores.get_highscores();			//get list from scores
        for(int i = 1; i<6; ++i){
                stringstream scorestream;
                string tab = "\t";
                scorestream<<players[i-1].name<<tab<<players[i-1].score;	//print name and score
                high_score_list.push_back(new Text(Point(100,100 + i * 40),scorestream.str()));
                attach(high_score_list[i]);
        }
        high_score_list.push_back(new Text(Point(250,50),"Select your level:")); //ask for level
        attach(high_score_list[high_score_list.size()-1]);
}

void FlipFlap::callback_showins(Address, Address pw){                            //show the instructions
                reference_to<FlipFlap>(pw).show_ins();
}

void FlipFlap::callback_showlevels(Address, Address pw){                         //go to the level select
                reference_to<FlipFlap>(pw).show_levels();
}

void FlipFlap::show_ins(){
        detach(*splash);                                                         //detach what's on the screen
        detach(*insbutton);
        instructions = new Image(Point(0,0),"instructions.jpg");                 //create the instructions image and gameplay button
        playbutton = new Button(Point(145,290), 315, 70, "Play!", callback_showlevels);
        attach(*instructions);                                                   //attach them
        redraw();
        attach(*playbutton);
}

void FlipFlap::show_splash(){                                                   //display splash screen
        splash = new Image(Point(0,0),"splash.jpg");                            //create the image and button
        insbutton = new Button(Point(250,120), 105, 50, "Instructions", callback_showins);
        attach(*splash);                                                        //attach them
        redraw();
        attach(*insbutton);
}

void FlipFlap::show_levels(){							//setup game
	name_box = new In_box(Point(X_CENTER,90),100,20,"Enter your initials"); //get initials
        attach(*name_box);
        initials = "--";
        scores.read_highscores();						//get high schores from scores
        print_highscores();							//display high scores
        level_list();								//create list of level select buttons
}

void FlipFlap::show_scores(int i){						//end screen
  stringstream ss;
   if (i == 0)									//if they won
    ss<<"Congratulations, "<<initials<<", you won! Your score was: "<<calc_score(current_flips); //print name and score
  else										//if they lost
    ss<<"Sorry, "<<initials<<", you lost.  Your score was 0.";			//print name 
  end_text = new Text(Point(100,100),ss.str());
  attach(*end_text);
  scores.game_score(initials,calc_score(current_flips));			//write name and score to scores
  scores.write_highscores();
  replay = new Button(Point(100,200),70,20,"Play again?",cb_replay);		//ask if they want to play again
  attach(*replay);
}
void FlipFlap::level_list(){							//create list of level select buttons
  if (level_buttons.size() == 0){						//if not full already
    for (int k = 2; k < 10; ++k)						//create buttons
    {
      string* L = new string(to_string(k));
      level_buttons.push_back(new Button(Point(X_CENTER - 50,TABLE_TOP + 100 - 30*k),100,20,*L,cb_select));
    }
  }
  for (int k = 2; k < 10; ++k){							//attach buttons
    attach(level_buttons[k-2]);
  }
}

void FlipFlap::cb_select(Address l_button, Address window){			//select callback
        auto button_level = reference_to<Fl_Button>(l_button).label();		//get level from name of button
        stringstream L(button_level);
        int selected_level = 0;
        L>>selected_level;
        reference_to<FlipFlap>(window).setup(selected_level);			//pass to setup
}
void FlipFlap::new_game(){							//function to restart
  detach(*replay);								//remove everything from window
  detach(*end_text);
  detach(*min_box);
  detach(*flips_box);
  detach(*score_box);
  redraw();
  show_levels();								//call show_levels
}

void FlipFlap::cb_replay(Address, Address window){				//replay button callback
  reference_to<FlipFlap>(window).new_game();					//pass window to new_game()
}

