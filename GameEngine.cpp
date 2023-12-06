#include "GameEngine.h"

// @brief Initializes the game by setting up veggies, captain, and rabbits
void GameEngine::initializeGame() {
<<<<<<< HEAD
	initVeggies();								// Initialize vegetables
	initCaptain();								// Initialize captain
	initRabbits();								// Initialize rabbits
	score = 0;									// Reset the game score to zero
=======
	initVeggies();
	initCaptain();
	initRabbits();
	initSnake();
	score = 0;
  bites = 0;
>>>>>>> d5e754bcf511384e1ad49d4459802161677c59a8
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
			break;								// Exit loop if file opens successfully
		else
			cout << endl << filename << " does not exist! Please enter the name of the vegetable point file: ";
	}

	// these variables are for dealing with format
	string dummy;
	char comma; 
	string line;

	getline(inveggief, line); 					// Process file contents and populate the veggies vector
	istringstream iss(line);

	getline(iss, dummy, ',');  					// Read until the first comma
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

<<<<<<< HEAD

// @brief Calculates the remaining number of veggies on the field
// @return The number of remaining veggies
=======
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

>>>>>>> d5e754bcf511384e1ad49d4459802161677c59a8
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
	return this->score;						// Return the current score
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


<<<<<<< HEAD
// @brief Moves the captain vertically on the field
// @param movement The amount to move the captain (-1 for up, 1 for down)
=======
void GameEngine::moveSnake(){
  Snake *  mySnake=nullptr;
  mySnake = this->snake;
  if(!mySnake)
    return;

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
  int i=mySnake->getX();
  int j=mySnake->getY();
  grid[i][j].setParams(0.0,0.0,0.0,i,j);

  //run a* algorithm
  int x=-1;
  int y=-1;
  
  /*
   Create an open list having information as-
   <f, <i, j>>
   where f = g + h,
   and i, j are the row and column index of that cell
   Note that 0 <= i <= ROW-1 & 0 <= j <= COL-1
   This open list is implemented as a set of pair of
   pair.*/
  set<pPair> openList;
 
  // Put the starting cell on the open list and set its
  // 'f' as 0
  openList.insert(make_pair(0.0, make_pair(i, j)));
 
  // We set this boolean value as false as initially
  // the destination is not reached.
  bool foundDest = false;
 
  while (!openList.empty()) {
      pPair p = *openList.begin();
 
      // Remove this vertex from the open list
      openList.erase(openList.begin());
 
      // Add this vertex to the closed list
      i = p.second.first;
      j = p.second.second;
      grid[i][j].closed = true;
 
      /*
       Generating all the 4 successor of this cell
 
                 N  
                 |  
                 |  
           W----Cell----E
                  | 
                  |  
                  S 
 
       Cell-->Popped Cell (i, j)
       N -->  North       (i-1, j)
       S -->  South       (i+1, j)
       E -->  East        (i, j+1)
       W -->  West        (i, j-1)
       */
 
      // To store the 'g', 'h' and 'f' of the 8 successors
      double gNew, hNew, fNew;
 
      //----------- 1st Successor (North) ------------
 
      // Only process this cell if this is a valid one
      if (isValid(i - 1, j) == true) {
          // If the destination cell is the same as the
          // current successor
          if (isDestination(i - 1, j) == true) {
              // Set the Parent of the destination cell
              grid[i - 1][j].pR = i;
              grid[i - 1][j].pC = j;
              foundDest = true;
              break;
          }
          // If the successor is already on the closed
          // list or if it is blocked, then ignore it.
          // Else do the following
          else if (grid[i - 1][j].closed == false
                   && isUnBlocked(grid, i - 1, j)
                          == true) {
              gNew = grid[i][j].g + 1.0;
              hNew = calculateHValue(i - 1, j);
              fNew = gNew + hNew;
 
              // If it isn’t on the open list, add it to
              // the open list. Make the current square
              // the parent of this square. Record the
              // f, g, and h costs of the square cell
              //                OR
              // If it is on the open list already, check
              // to see if this path to that square is
              // better, using 'f' cost as the measure.
              if (grid[i - 1][j].f == FLT_MAX
                  || grid[i - 1][j].f > fNew) {
                  openList.insert(make_pair(
                      fNew, make_pair(i - 1, j)));
 
                  // Update the details of this cell
                  grid[i - 1][j].f = fNew;
                  grid[i - 1][j].g = gNew;
                  grid[i - 1][j].h = hNew;
                  grid[i - 1][j].pR = i;
                  grid[i - 1][j].pC = j;
              }
          }
      }
 
      //----------- 2nd Successor (South) ------------
 
      // Only process this cell if this is a valid one
      if (isValid(i + 1, j) == true) {
          // If the destination cell is the same as the
          // current successor
          if (isDestination(i + 1, j) == true) {
              // Set the Parent of the destination cell
              grid[i + 1][j].pR = i;
              grid[i + 1][j].pC = j;
              foundDest = true;
              break;
          }
          // If the successor is already on the closed
          // list or if it is blocked, then ignore it.
          // Else do the following
          else if (grid[i + 1][j].closed == false
                   && isUnBlocked(grid, i + 1, j)
                          == true) {
              gNew = grid[i][j].g + 1.0;
              hNew = calculateHValue(i + 1, j);
              fNew = gNew + hNew;
 
              // If it isn’t on the open list, add it to
              // the open list. Make the current square
              // the parent of this square. Record the
              // f, g, and h costs of the square cell
              //                OR
              // If it is on the open list already, check
              // to see if this path to that square is
              // better, using 'f' cost as the measure.
              if (grid[i + 1][j].f == FLT_MAX
                  || grid[i + 1][j].f > fNew) {
                  openList.insert(make_pair(
                      fNew, make_pair(i + 1, j)));
                  // Update the details of this cell
                  grid[i + 1][j].f = fNew;
                  grid[i + 1][j].g = gNew;
                  grid[i + 1][j].h = hNew;
                  grid[i + 1][j].pR = i;
                  grid[i + 1][j].pC = j;
              }
          }
      }
 
      //----------- 3rd Successor (East) ------------
 
      // Only process this cell if this is a valid one
      if (isValid(i, j + 1) == true) {
          // If the destination cell is the same as the
          // current successor
          if (isDestination(i, j + 1) == true) {
              // Set the Parent of the destination cell
              grid[i][j + 1].pR = i;
              grid[i][j + 1].pC = j;
              foundDest = true;
              break;
          }
 
          // If the successor is already on the closed
          // list or if it is blocked, then ignore it.
          // Else do the following
          else if (grid[i][j + 1].closed == false
                   && isUnBlocked(grid, i, j + 1)
                          == true) {
              gNew = grid[i][j].g + 1.0;
              hNew = calculateHValue(i, j + 1);
              fNew = gNew + hNew;
 
              // If it isn’t on the open list, add it to
              // the open list. Make the current square
              // the parent of this square. Record the
              // f, g, and h costs of the square cell
              //                OR
              // If it is on the open list already, check
              // to see if this path to that square is
              // better, using 'f' cost as the measure.
              if (grid[i][j + 1].f == FLT_MAX
                  || grid[i][j + 1].f > fNew) {
                  openList.insert(make_pair(
                      fNew, make_pair(i, j + 1)));
 
                  // Update the details of this cell
                  grid[i][j + 1].f = fNew;
                  grid[i][j + 1].g = gNew;
                  grid[i][j + 1].h = hNew;
                  grid[i][j + 1].pR = i;
                  grid[i][j + 1].pC = j;
              }
          }
      }
 
      //----------- 4th Successor (West) ------------
 
      // Only process this cell if this is a valid one
      if (isValid(i, j - 1) == true) {
          // If the destination cell is the same as the
          // current successor
          if (isDestination(i, j - 1) == true) {
              // Set the Parent of the destination cell
              grid[i][j - 1].pR = i;
              grid[i][j - 1].pC = j;
              foundDest = true;
              break;
          }
 
          // If the successor is already on the closed
          // list or if it is blocked, then ignore it.
          // Else do the following
          else if (grid[i][j - 1].closed == false
                   && isUnBlocked(grid, i, j - 1)
                          == true) {
              gNew = grid[i][j].g + 1.0;
              hNew = calculateHValue(i, j - 1);
              fNew = gNew + hNew;
 
              // If it isn’t on the open list, add it to
              // the open list. Make the current square
              // the parent of this square. Record the
              // f, g, and h costs of the square cell
              //                OR
              // If it is on the open list already, check
              // to see if this path to that square is
              // better, using 'f' cost as the measure.
              if (grid[i][j - 1].f == FLT_MAX
                  || grid[i][j - 1].f > fNew) {
                  openList.insert(make_pair(
                      fNew, make_pair(i, j - 1)));
 
                  // Update the details of this cell
                  grid[i][j - 1].f = fNew;
                  grid[i][j - 1].g = gNew;
                  grid[i][j - 1].h = hNew;
                  grid[i][j - 1].pR = i;
                  grid[i][j - 1].pC = j;
              }
          }
      }
  }

  //

  if(foundDest){
    //traceroute
    int row = captain->getX();
    int col = captain->getY();
 
    stack<Pair> Path;
 
    while (!(grid[row][col].pR == row
             && grid[row][col].pC == col)) {
        Path.push(make_pair(row, col));
        int temp_row = grid[row][col].pR;
        int temp_col = grid[row][col].pC;
        row = temp_row;
        col = temp_col;
    }
    pair<int, int> nextStep = Path.top();
    x = nextStep.first;
    y = nextStep.second;
    /*Path.push(make_pair(row, col));
    while (!Path.empty()) {
        pair<int, int> p = Path.top();
        Path.pop();
        cout << "-> (" << p.first << "," << p.second <<") " << endl;
    }*/
  } else {
    ;
  }



  //delete grid
  for(int r=0;r<height;r++)
   delete[]  grid[r];
  delete[] grid;

  //new location
  //no path found
  if(x==-1 || y==-1)
    return;
  
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



>>>>>>> d5e754bcf511384e1ad49d4459802161677c59a8
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
<<<<<<< HEAD

	// Display the end game message and show the list of collected veggies and final score
=======
  int actualPoints = 0;
>>>>>>> d5e754bcf511384e1ad49d4459802161677c59a8
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
      cout << "Since snake bit the captain, you lost " << this->score - actualPoints << " points!" << endl;
      cout << "Final score: " << actualPoints << endl;
    }
  }

}
