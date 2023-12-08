/* Authors: Al Zahra, Yihang Yuan, Gaurav Dubey
   Date: 12-07-2023
   Description: This file implements the game logic and state for a simple grid-based game. It involves a captain collecting
   		vegetables while avoiding rabbits and optionally a snake. The game takes place on a 2D grid where each cell
		can contain a vegetable, a rabbit, a snake, or the captain.
*/

#include "GameEngine.h"

// @brief Initializes the game by setting up veggies, captain, rabbits and snake
void GameEngine::initializeGame() {
	initVeggies();								// Initialize vegetables
	initCaptain();								// Initialize captain
	initRabbits();								// Initialize rabbits
	initSnake();
	score = 0;								// Reset the game score to zero
	bites = 0;  
}


// @brief Initializes and loads veggies from a file and sets up the game field
void GameEngine::initVeggies() {
	string filename;
	ifstream inveggief;

	// Continuously prompt for the vegetable file until a valid file is provided
	while(true) {
		cout << "Please enter the name of the vegetable point file: ";
		getline(cin, filename);
		inveggief.open(filename);

		if(inveggief)
			break;					// Exit loop if file opens successfully
		else
			cout << endl << filename << " does not exist! Please enter the name of the vegetable point file: ";
	}

	// these variables are for dealing with format
	string dummy;
	char comma; 
	string line;

	getline(inveggief, line); 				// Process file contents and populate the veggies vector
	istringstream iss(line);

	getline(iss, dummy, ',');  				// Read until the first comma
	iss >> height >> comma;     				// Read height and the next comma
	iss >> width;               				// Read width

	// Garlic,G,5
	while(getline(inveggief, line)) { 			// add veggies to vector
		string name;
		string symbol;
		string pointsStr;
		int points;

		istringstream iss(line);

		getline(iss, name, ',');
		getline(iss, symbol, ',');
		getline(iss, pointsStr);
		points = stoi(pointsStr);
    		VeggiePoints[name]=points;

		Veggie* veggie = new Veggie(symbol, name, points);
		veggies.push_back(veggie);

	}

	array2D = new FieldInhabitant** [height]; 	// create 2D array and initialize it
	for(int i =0; i < height; ++i) {
		array2D[i] = new FieldInhabitant* [width];
		for(int j =0; j < width; ++j) {
			array2D[i][j] = nullptr;
		}
	}

	srand(time(NULL)); // current time as seed

	for(int i = 0; i < NUMBEROFVEGGIES; ++i) { // put veggies into field
		int xp, yp, vegIndex;
		do {
			xp = rand() % height;
			yp = rand() % width;
			vegIndex = rand() % veggies.size();
		}while(array2D[xp][yp] != nullptr);

		array2D[xp][yp] = veggies[vegIndex];
	}

	inveggief.close();

}


// @brief Initializes the captain in the game field
void GameEngine::initCaptain(){

	// Randomly place the captain on the field
	srand(time(NULL));
	int xp, yp;
	do {
			xp = rand() % height;
			yp = rand() % width;

	}while(array2D[xp][yp] != nullptr);

	Captain * myCaptain = new Captain( xp, yp);
	captain = myCaptain;
	array2D[xp][yp] = captain;

}



// @brief Initializes the rabbits in the game field
void GameEngine::initRabbits() {
	srand(time(NULL));

	// Randomly place rabbits on the field and ensure they do not overlap with veggies or the captain
	for(int i = 0; i < NUMBEROFRABBITS; ++i) {
		int xp, yp;
		do {
			xp = rand() % height;
			yp = rand() % width;
		}while(array2D[xp][yp] != nullptr);

		Rabbit* rabbit = new Rabbit(xp, yp);
		rabbits.push_back(rabbit);
		array2D[xp][yp] = rabbit;
	}
}



// @brief Initializes the snake in the game field
void GameEngine::initSnake(){
  string addSnake = "";
  cout << "Would you be interested to add a Snake to the Game?" << endl;
  cout << "This will make game a little challenging! y/N: ";
  getline(cin,addSnake);
  if(addSnake.empty() || ( addSnake[0] !='y' && addSnake[0] != 'Y')) {
    cout << "Not adding a Snake." << endl;
    this->snake=nullptr;
    return;
  }
  cout << "Awesome! Adding a Snake to the game." << endl;
	srand(time(NULL));
	int xp, yp;
	do {
			xp = rand() % height;
			yp = rand() % width;

	}while(array2D[xp][yp] != nullptr);

	Snake * mySnake = new Snake( xp, yp);
	snake = mySnake;
	array2D[xp][yp] = snake;
}


// @brief Calculates the remaining number of veggies on the field
// @return The number of remaining veggies
int GameEngine::remainingVeggies(){

	// Count the number of remaining vegetables
	int count = 0; 

	for(int i = 0; i < height; i++){

		for(int j = 0; j < width; j++){

			Veggie * veggie = dynamic_cast<Veggie *>(array2D[i][j]);

			if(veggie != nullptr){
				count += 1;
			}
		}
	}

	return count;
}


// @brief Displays the introduction message for the game
void GameEngine::intro() {

	// Print the introduction, game rules and points for each veggie
	cout << "Welcome to Captain Veggie!" << endl
		 << "The rabbits have invaded your garden and you must harvest" << endl
		 << "as many vegetables as possible before the rabbits eat them" << endl
		 << "all! Each vegetable is worth a different number of points" << endl
		 << "so go for the high score!" << endl
		 << endl
		 << "The vegetables are:" << endl;

	for(int i = 0; i < veggies.size(); i ++){
		
		cout << veggies[i]->getSymbol() <<": "
			 << veggies[i]->getName() << " "
			 << veggies[i]->getPoints() << " points" 
			 << endl;
	}

	cout << "Captain Veggie is V, and the rabbits are R's." << endl
		 << endl
		 << "Good luck!" << endl
		 << endl;
	

}


// @brief Prints the current state of the game field
void GameEngine::printField(){

	// Print the game field with its current state, showing positions of veggies, rabbits and captain
	cout << string(width + 2, '#') << endl; // header
	
	for(int i = 0; i < height; i++){
		
		cout << '#';
		
		for(int j = 0; j< width; j++){

			Veggie * veggie = dynamic_cast<Veggie *>(array2D[i][j]);
			
			if(veggie != nullptr){

				cout << veggie->getSymbol();

			}else{

				Rabbit * rabbit = dynamic_cast<Rabbit *>(array2D[i][j]);
				
				if(rabbit != nullptr){
					
					cout << "R";
					 
				}else{

					Captain * myCaptain = dynamic_cast <Captain *>(array2D[i][j]);

					if(myCaptain != nullptr){

						cout << "V";

					}else{
						Snake * mySnake = dynamic_cast <Snake *>(array2D[i][j]);
						if(mySnake)
							cout << "S";
						else
							cout << " ";
					}
				}
				
			}
		}

		cout << '#' << endl;

	}

	cout << string(width + 2, '#') << endl;

}


// @brief Getter for the current game score
// @return The current score
int GameEngine::getScore(){			
	return this->score;			// Return the current score
}


// @brief Moves all the rabbits on the field randomly
void GameEngine::moveRabbits(){

	// Move each rabbit to a random new position on the field and ensure rabbits do not overlap with each other or other objects
	srand(time(NULL));

	int x, y, xdp, ydp;
	Rabbit * myRabbit;
	Veggie * myVeggie;

	for(int i = 0; i < rabbits.size(); i ++){

		myRabbit = rabbits[i];
		
		x = myRabbit->getX();
		y = myRabbit->getY();
		
		xdp = rand() % 3 - 1;
		ydp = rand() % 3 - 1;

		if(xdp == 0 && ydp ==0){

			continue;

		}else{
			
			x += xdp;
			y += ydp;

			if( x < 0 || y < 0 || x >= height || y >= width){ // boundary check
				
				continue; //forfeit
			}

			if(array2D[x][y]){ // we have an non-empty spot

				myVeggie = dynamic_cast<Veggie *>(array2D[x][y]);

				if(!myVeggie){ 
          //we didn't find a veggie here ... forfeit this move
					continue;
        }
			}

		}
    //we have a veggie at this spot
		array2D[myRabbit->getX()][myRabbit->getY()] = nullptr; // old location
		myRabbit->setX(x);
		myRabbit->setY(y);
		array2D[x][y] = myRabbit; // new location
		
	}
}


// @brief Moves the snake
// @return nothing
void GameEngine::moveSnake(){
  //check if we have a snake in the game
  Snake *  mySnake=nullptr;
  mySnake = this->snake;
  //lets return no snake found
  if(!mySnake)
    return;

  int snakeX, snakeY;
  snakeX=snake->getX();
  snakeY=snake->getY();
  Pair moves[4] = {make_pair(snakeX-1,snakeY),
                   make_pair(snakeX+1,snakeY),
				   make_pair(snakeX,snakeY+1),
				   make_pair(snakeX,snakeY-1)};
  double distances[4] = {FLT_MAX,FLT_MAX,FLT_MAX,FLT_MAX};
  double minDis = -1.0;
  int minIdx=-1;
  int x=-1;
  int y=-1;
  for(int s=0;s<4;s++){
	if(!isValid(moves[s].first,moves[s].second))
		continue;
	Veggie* veggie = dynamic_cast<Veggie *>(array2D[moves[s].first][moves[s].second]);
	if(veggie)
		continue;
	Rabbit* rabbit = dynamic_cast<Rabbit *>(array2D[moves[s].first][moves[s].second]);
	if(rabbit)
		continue;
	distances[s]=calculateHValue(moves[s].first,moves[s].second);
	if((minIdx < 0)||(minDis > distances[s])){
		minIdx=s;
		minDis=distances[s];
	}
  }
  if(minIdx<0)
	return;
  else {
	x=moves[minIdx].first;
	y=moves[minIdx].second;
  }
  //no path found
  if(x==-1 || y==-1)
    return;
  
  //new location

	//do we have captain here
	if(array2D[x][y]){
		Captain* myCaptain = dynamic_cast<Captain *>(array2D[x][y]);
		if(myCaptain){
      cout << "Snake bit the Captain!" << endl;
      cout << "You lose last 5 Veggies! :(" << endl;
      bites+=1;
			//lose veggies
			myCaptain->loseLast5Veggies();
      //respawn snake
			srand(time(NULL));
      int xp, yp;
      do {
          xp = rand() % height;
          yp = rand() % width;
        
      }while(array2D[xp][yp] != nullptr);
      //new location  
      Snake * mySnake = new Snake( xp, yp);
      Snake * temp = nullptr;
      temp = snake;
      array2D[snake->getX()][snake->getY()] = nullptr;
      snake = mySnake;
      //delete current snake
      delete temp;
      array2D[xp][yp] = snake;
   		return;
		}
	}
	array2D[mySnake->getX()][mySnake->getY()] = nullptr; // old location
	snake->setX(x);
	snake->setY(y);
	array2D[x][y] = snake; // new location
}




// @brief Moves the captain vertically on the field
// @param movement The amount to move the captain (-1 for up, 1 for down)
void GameEngine::moveCptVertical(int movement){

	// Move the captain up or down based on the movement parameter
	// Handle boundary conditions and interactions with veggies or rabbits
	Veggie * myVeggie;
	int x = captain->getX();
	int y = captain->getY();
	x += movement;

	if( x < 0 || x >= height){
		cout << "You can't move that way!" << endl;
		return;
	}else if(array2D[x][y] == nullptr){
		array2D[captain->getX()][y] = nullptr; // old location
		captain->setX(x);
		array2D[x][y] = captain;// new 
	}else{
		myVeggie = dynamic_cast<Veggie *>(array2D[x][y]);

		if (myVeggie != nullptr){

			cout << "Yummy! A delicious " << myVeggie->getName() << endl;
			captain->addVeggie(myVeggie);
			score += myVeggie->getPoints();

			array2D[captain->getX()][y] = nullptr; // old location
			captain->setX(x);
			array2D[x][y] = captain;// new 

		}else {
			cout << "Don't step on the bunnies!" << endl;
		}

	}
	

}


// @brief Moves the captain horizontally on the field
// @param movement The amount to move the captain (-1 for left, 1 for right)
void GameEngine::moveCptHorizontal(int movement){

	// Move the captain left or right based on movement parameter
	// Handle boundary conditions and interactions with veggies or rabbits
	Veggie * myVeggie;
	int x = captain->getX();
	int y = captain->getY();
	y += movement;

	if( y < 0 || y >= width){
		cout << "You can't move that way!" << endl;
		return;
	}else if(array2D[x][y] == nullptr){
		array2D[x][captain->getY()] = nullptr; // old location
		captain->setY(y);
		array2D[x][y] = captain;// new 
	}else{
		myVeggie = dynamic_cast<Veggie *>(array2D[x][y]);

		if (myVeggie != nullptr){

			cout << "Yummy! A delicious " << myVeggie->getName() << endl;
			captain->addVeggie(myVeggie);
			score += myVeggie->getPoints();

			array2D[x][captain->getY()] = nullptr; // old location
			captain->setY(y);
			array2D[x][y] = captain;// new 

		}else {
			cout << "Don't step on the bunnies!" << endl;
		}

	}
}


// @brief Processes the captain's movement based on user input
void GameEngine::moveCaptain(){

	// Read user input for captain's movement
	// Handle different movements commands (up, down, left, right)
	string line;
	char input;

	cout << "Would you like to move up(W), down(S), left(A), or right(D):";
	getline(cin, line);

	if(!line.empty()){
		
		if (line.size() > 1){
			cout << line << " is not a valid option"<< endl;
			return;
		}

		input = line[0];
		input = toupper(input);

		switch (input)
		{
		case 'W':
			moveCptVertical(-1);
			break;
		case 'S':
			moveCptVertical(1);
			break;
		case 'A':
			moveCptHorizontal(-1);
			break;
		case 'D':
			moveCptHorizontal(1);
			break;
		default:
            cout << input << " is not a valid option"<< endl;
		}

	}
}


// @brief Ends the game and displays the final score and collected veggies
void GameEngine::gameOver(){
   // Display the end game message and show the list of collected veggies and final score

  int actualPoints = 0;
  vector<string> collectedveggies = captain->getCollectedVeggies();

  cout << "GAME OVER!" << endl
	<< "You managed to harvest the following vegetables:" << endl;
	
  for(int i = 0; i < collectedveggies.size(); i++){
		cout << collectedveggies[i] << endl;
    		actualPoints+=VeggiePoints[collectedveggies[i]];
  }

  cout << "Your score was: " << this->score << endl;
  if(snake){
    if(bites){
      string times = (bites==1)? " time, you lost " : " times, you lost ";
      cout << "Since snake bit the captain "<< bites << times << this->score - actualPoints << " points!" << endl;
      cout << "Final score: " << actualPoints << endl;
    }
  }

}
