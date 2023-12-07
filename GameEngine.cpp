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


// @brief Moves the rabbit based on a* algorithm
// @return nothing
void GameEngine::moveSnake(){
  //check if we have a snake in the game
  Snake *  mySnake=nullptr;
  mySnake = this->snake;
  //lets return no snake found
  if(!mySnake)
    return;

  //next step for snake
  // let's initialize it out of the array2D for errors in algorithm outcome
  int x=-1;
  int y=-1;


  // A* Search Algorithm
  
  //1.  Initialize the open list
  // a set used instead of a list as we need to maintain a sorted, unique collection
  set<pPair> openList;
 
  //2.  Initialize the closed list
  
  /*create a grid of gNode where each gNode represents a spot in the array2D
    each gNode is initialzed with f,g,h as INF, it's parent as (-1,-1) and not closed
    it is declared as blocked if only if we have a rabbit or a veggie on the same spot in the array2D*/
  gNode **grid=nullptr;
  grid=new gNode*[height];
  for(int r=0; r<height ;r++){
    grid[r]=new gNode[width];
    for(int c=0;c<width;c++){
      bool blocked = false;
		  Veggie* myVeggie = dynamic_cast<Veggie *>(array2D[r][c]);
		  Rabbit* myRabbit = dynamic_cast<Rabbit *>(array2D[r][c]);
      if(myVeggie)
        blocked=true;
      if(myRabbit)
        blocked=true;
      grid[r][c].setParams(FLT_MAX,FLT_MAX,FLT_MAX,-1,-1,blocked,false);
    }
  }

  //f,g,h are all zero and it is its own parent
  //like a root of the tree
  //since it is already open we do not touch the closed member of gNode
  grid[mySnake->getX()][mySnake->getY()].setParams(0.0,0.0,0.0,mySnake->getX(),mySnake->getY());

  //put the starting node on the open 
  openList.insert(make_pair(0.0, make_pair(mySnake->getX(),mySnake->getY())));
 
  // We set this boolean value as false as initially
  // the destination is not reached.
  bool foundDest = false;
  
  //3.  while the open list is not empty
  while (!openList.empty()) {
    //a) find the node with the least f on 
    //the open list, call it "q"
    pPair q = *openList.begin();

    //b) pop q off the open list
    openList.erase(openList.begin());
    //c) generate q's 4 successors and set their 
    // parents to q
    Pair qSuccessors[4] = { make_pair(q.second.first-1, q.second.second),
                            make_pair(q.second.first+1, q.second.second),
                            make_pair(q.second.first, q.second.second+1),
                            make_pair(q.second.first, q.second.second-1)};

    // Add this vertex to the closed list
    grid[q.second.first][q.second.second].closed = true;


    // To store the 'g', 'h' and 'f' of the 8 successors

    /*
      d) for each successor
        i) if successor is the goal, stop search
      
        ii) else, compute both g and h for successor
        successor.g = q.g + distance between 
                            successor and q
        successor.h = distance from goal to 
        successor (Euclidean distance)
        
        successor.f = successor.g + successor.h
        iii) if a node with the same position as 
          successor is in the OPEN list which has a 
         lower f than successor, skip this successor
        iV) if a node with the same position as 
          successor  is in the CLOSED list which has
          a lower f than successor, skip this successor
          otherwise, add  the node to the open list
        end (for loop)
     */
    for(int s=0;s<4;s++){
      //we found destination but, we exited the for-loop and not the while-loop.
      //so lets continue
      if(foundDest)
        continue;
      if (isValid(qSuccessors[s].first, qSuccessors[s].second) == true) {
        // i) if successor is the goal, stop search
        if (isDestination(qSuccessors[s].first, qSuccessors[s].second) == true) {
            // Set the Parent of the destination cell
            grid[qSuccessors[s].first][qSuccessors[s].second].pR = q.second.first;
            grid[qSuccessors[s].first][qSuccessors[s].second].pC = q.second.second;
            foundDest = true;
            //exit this loop
            s=5;
        }
        // successor is in the CLOSED list -> skip
        // successor is blocked -> skip
        //else if further check f
        else if (!grid[qSuccessors[s].first][qSuccessors[s].second].closed && 
                  isUnBlocked(grid, qSuccessors[s].first, qSuccessors[s].second)) {

          double gNew, hNew, fNew;
          //compute both g and h for successor
          gNew = grid[q.second.first][q.second.second].g + 1.0;
          hNew = calculateHValue(qSuccessors[s].first, qSuccessors[s].second);
          fNew = gNew + hNew;

          //if filtered successor has a lower f -> skip
          //else add this successor node to the openlist
          if (grid[qSuccessors[s].first][qSuccessors[s].second].f == FLT_MAX || 
                grid[qSuccessors[s].first][qSuccessors[s].second].f > fNew) {
              //add to the open list
              // 
              openList.insert(make_pair(
                  fNew, make_pair(qSuccessors[s].first, qSuccessors[s].second)));

              // Update the details of this gNode
              grid[qSuccessors[s].first][qSuccessors[s].second].f = fNew;
              grid[qSuccessors[s].first][qSuccessors[s].second].g = gNew;
              grid[qSuccessors[s].first][qSuccessors[s].second].h = hNew;
              grid[qSuccessors[s].first][qSuccessors[s].second].pR = q.second.first;
              grid[qSuccessors[s].first][qSuccessors[s].second].pC = q.second.second;
          }
        }
      }
    }
    if(foundDest)
      break;
  }

  if(foundDest){
    //trace the route to the snake from the captain
    // only snake's spot will have its self parent
    int row = captain->getX();
    int col = captain->getY();
 
    stack<Pair> Path;

    //loop until we find snake
    while (!(grid[row][col].pR == row
             && grid[row][col].pC == col)) {
        Path.push(make_pair(row, col));
        int temp_row = grid[row][col].pR;
        int temp_col = grid[row][col].pC;
        row = temp_row;
        col = temp_col;
    }
    pair<int, int> nextStep = Path.top();
    //update next step
    x = nextStep.first;
    y = nextStep.second;
  }

  //delete grid for memory clean up
  for(int r=0;r<height;r++)
   delete[]  grid[r];
  delete[] grid;

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
