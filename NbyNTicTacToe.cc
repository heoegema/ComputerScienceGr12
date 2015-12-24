//N by N Tic Tac Toe
//Exercise 4 pg. 47
//The user will choose a number between 3 and 10
//The program will create a board based on this data
//Date April 28th 2015
//Written by Holly Oegema

#include <iostream.h> 
#include <apmatrix.h> 
#include "apstring.h" 

//Prototypes

void DrawBoard(int intBoardSize, apmatrix<char> Board);
void PlayerTurn(int intBoardSize, apmatrix<char> &Board, int &intSpacesUsed, char &chrTurn);
bool CheckWin(int intBoardSize, apmatrix<char> Board, char Turn, int intSpacesUsed, bool &draw); 
int CollectValue(int intBoardSize, apstring Player, apstring Type); 
void DrawLine(int intBoardSize); 

int main() 

{ 
    
    //Declarations
    int intBoardSize; 
    int intSpacesUsed = 0; //This is to keep track of how many spaces are used
    char chrTurn = 'X'; //This is to keep track of whose turn it is
    bool draw = false; //This keeps track of whether or not the 'final result' is a draw
     
   
    //Displaying Program information 
    cout << "\t\t\t\t\tTic Tac Toe!"; 
    cout << "\n\n\t\tPlayer 1(X)         Player 2(O)" << endl; 
    
    //Collecting Board Size Information 
    //The loop will run until a value between 3 and 20 is chosen
    //3 is the default for Tic Tac Toe, and anything larger than 20 is too big for
    //the screen
    while ((cout << "\n\nEnter a Number between 3 and 20 to create your playing board: ")
    && (!(cin >> intBoardSize) || intBoardSize < 3 || intBoardSize > 20)) 
    
    {  
       
       	cout << "\nPlease enter an integer number between 3 and 20\n"; //Ask the user to enter a new number 
       	cin.clear();  //Clear current value 
       	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //Ignore current value
   
    } //Loop is terminated once a valid value is collected
     
    //Setting up Matrix
    //We make an n by n matrix based on the information given to us by the user 
    //and we set each value to ' '
    apmatrix<char> Board(intBoardSize, intBoardSize, ' '); 
    
    //Game Loop
    //While there isn't a win this loop will keep running 
    while(!(CheckWin(intBoardSize, Board, chrTurn, intSpacesUsed, draw)))
    
    { 
     
        DrawBoard(intBoardSize, Board);
        PlayerTurn(intBoardSize, Board, intSpacesUsed, chrTurn);
        
    }
    
    //As soon as the loop is terminated (Someone Wins or there's a draw)
    //The loop will end and jump to this bit of code
    //Important to note that this happens after a 'PlayerTurn' has taken place
    //meaning that the chrTurn would have already switched to the opposite
   
    if (chrTurn == 'O' && !draw) //If X (Player 1 Wins) 
    
    {     
        DrawBoard(intBoardSize, Board);
        cout << "\n\nCongratulations Player 1(X)! You have won!"; 
        
    } 
    
    else if (chrTurn == 'X' && !draw) //If Player O (Player 2 Wins) 
    
    { 
        
        DrawBoard(intBoardSize, Board);
        cout << "\n\nCongratulations Player 2(O)! You have won!";
        
    } 
    
    else //If neither player wins-this means it must be a draw
    
    { 
      
        DrawBoard(intBoardSize, Board);
        cout << "\nIt's a draw!";
        
    } 

} 

void DrawBoard(int intBoardSize, apmatrix<char> Board)

{ 
    //This function constructs the board and displays the contents of the matrix 
    
    //Declarations-these are all looping variables 
    int intRowCount = 0;
    int intColumnCount = 0; 
    int intSelection = 0;  
   
    cout << "\n % | "; //This is the corner piece of the board
    
    //This loop creates the 'top' part of the board that displays the column indices
       while (intSelection < intBoardSize) 
       
       { 
       	   cout << intSelection+1; //Since the matrix starts at 0, we want the coordinates to start at 1
       	    
       	   if (intSelection+1 < 10) //This is for numbers that are not greater than 9
          	 cout <<  " | ";
           else
           	 cout << "| "; //If the number is greater than 9 (double digit) we need to adjust the spacing
          							 
           intSelection = intSelection + 1; //Looping variable 
       
       }
   
       
       cout << "\n"; //New line
       DrawLine(intBoardSize); //Call on the draw line function (This is the line under the column indices)
   
       cout << "\n"; //New line
    
    //Displaying the rest of the board
    while(intRowCount < intBoardSize) //This loop will draw the rows by running the 'ColumnCount' loop multiple times
    {     
        if (intRowCount < 9) 
            cout << " "; //If the row number is a double digit, we don't need this space
        cout << intRowCount+1 << " | "; //This will display the 'downwards' coordinates
     
        while(intColumnCount < intBoardSize) //This loop will draw the spaces going across
        { 
           
             //This will display the values of the matrix in the board
              cout << Board[intRowCount][intColumnCount] << " | ";
                
                intColumnCount = intColumnCount + 1; //Looping variable
                 
              
        } 
        cout << "\n"; //New line
        
        DrawLine(intBoardSize); //Call on the draw line function
        
        intRowCount = intRowCount + 1; //Looping variable
        intColumnCount = 0; //Reset values
        
        cout << "\n"; //After this loop has been run once-we have constructed one 'row' 
            
      } 
    
} 
void DrawLine(int intBoardSize) 
{ 
//We make a function for this simply because we use it multiple times in the DrawBoard loop
//This function draws a line based on how large the board is
    int intLine = 0;
    
    while (intLine < intBoardSize +1) //This displays the 'lines' below each row
     {     
            
         cout << "---+";  
         intLine = intLine + 1; //Looping variable
                    
        
     }

}

void PlayerTurn(int intBoardSize, apmatrix<char> &Board, int &intSpacesUsed, char &chrTurn) //Basically this is what the player's turn will look like

{ 
    //Basically we'll collect 'values from the user-[intRow][intColumn] 
    //Then assign a value of either 1 or 2 to the matrix depending on whose turn it is
    //We also have to count how many spaces are taken
    //As well as check to see if the space is taken or not 
    //For reference Board[intRow][intColumn] 
    
    int intRow;
    int intColumn; 
    apstring strPlayer;
    apstring strNumberType; 

    if (chrTurn == 'X') //If it's Player 1's turn (X) 
    
    { 

        //Set the values of the string so the user can have appropriate instructions
        strPlayer = "Player 1(X)"; 
        strNumberType = "Column Number(Across)";
        cout << "\n" << strPlayer << " It's your turn!\n"; //Inform the player that it is their turn
        intColumn = CollectValue(intBoardSize, strPlayer, strNumberType);
        strNumberType = "Row Number(Down)"; 
        intRow = CollectValue(intBoardSize, strPlayer, strNumberType); 
   
    } 
    
    else //It it's Player 2's turn (O) 
    
    {     
    
         //Set the values of the string so the user can have appropriate instructions
        strPlayer = "Player 2(O)";
        strNumberType = "Column Number(Across)"; 
        cout << "\n" << strPlayer << " It's your turn!\n"; //Inform the player that it is their turn
    
        //Call a function that will return an integer value for intColumn
        intColumn = CollectValue(intBoardSize, strPlayer, strNumberType);
        strNumberType = "Row Number(Down)";
    
        //Call a function that will return an integer value for intRow
        intRow = CollectValue(intBoardSize, strPlayer, strNumberType);
   
    } 
    
    //Now that we have collected valid values, let's see if the space is taken
    if (chrTurn == 'X' && Board[intRow][intColumn] == ' ') //The space is free
    
    { 
          
        Board[intRow][intColumn] = 'X'; //We assign a value of 'X' to the matrix  
        intSpacesUsed = intSpacesUsed + 1; //We need this to check how much spaces are used...
        chrTurn = 'O'; //And finally we make it Player 2's turn 
        
    } 
    
    else if (chrTurn == 'O' && Board[intRow][intColumn] == ' ') //The space is free
       
    { 
    
           Board[intRow][intColumn] = 'O'; //We assign a value of 'O' to the matrix (O} 
           intSpacesUsed = intSpacesUsed + 1; 
       	   chrTurn = 'X'; 
        
    } 
    
    else //The space is taken 
   
    { 
       
        cout << "Sorry that space is taken! Please choose another one!\n";
        
    } 

}

bool CheckWin(int intBoardSize, apmatrix<char> Board, char Turn, int intSpacesUsed, bool &draw) //Now we need to check if there are any winners 
//This function will check to see if there's a winner or if there's a draw
//If this function returns a 'true' value the game loop will stop running
//If there isn't a win-the function will return a false value and the game will continue
{ 
    
    //In order to make the program more efficient, we only check for a win when 
    //there have been enough turns or spaces taken up (invalid turns don't count) 
    //for there to actually be the possibility of a win 
    //If this isn't the case-we simply return a value of false
    if (intSpacesUsed >= intBoardSize + (intBoardSize - 1)) 
    {    
        //Declarations 
        int Column = 0; 
        int Row = 0; 
        int Continue = 1;
    
        //Determining Turn Values
        //The 'character' value this function will receive will be the opposite of the one we want 
        //to check-so let's set the turn to the one we want to check
        //(this is because at the end of each turn-we switch the character to the next turn in
        //the PlayerTurn function 
    
        if (Turn == 'X') 
            Turn = 'O'; 
        else
            Turn = 'X'; 
        
        //Checking Row Wins (Across)
        while (Row < intBoardSize) 
        {    
            Continue = 1; //Set the value of Continue to 1 so the loop will run at least once
            
            //This inner loop will run while the Column value is less than the board size 
            //and continue = 1
            while (Column < intBoardSize && Continue == 1) 
            { 
            	 //If the board space is not equal to the current turn-set the continue value to 0
                //to end the loop and to check the next Row
                if (Board[Column][Row] != Turn) 
                	Continue = 0; 
                
                //If we reach this point-it means all the spaces have a matching character
                //in other words-there is a win and return a true value
                else if (Column == intBoardSize - 1) 
                    return true; 
                    
                Column = Column + 1; //Looping variable
            } 
        
            Row = Row + 1;  //Looping variable
            Column = 0; //Reset Value-Since we're jumping to check the next 'row'
        } 
        
        //Resetting values for the next checking loop
        Row = 0;
        Column = 0;
        Continue = 1;
        
        //Checking Column wins (Down)
        while (Column < intBoardSize)     
        {    
            Continue = 1; //Set the continue value to 1 so the loop will run at least once
            
            //This inner loop will run while the Row value is less than the board size 
            //and continue = 1
            while (Row < intBoardSize && Continue == 1) 
            { 
                //If the board space is not equal to the current turn-set the continue value to 0
                //to end the loop and to check the next Column
                if (Board[Column][Row] != Turn)  
                    Continue = 0;
                
                //If we reach this point-it means all the spaces have a matching character
                //in other words-there is a win and return a true value
                else if (Row == intBoardSize - 1) 
                    return true; 
                
                Row = Row + 1; //Looping variable
            } 
        
            Column = Column + 1; //Looping variable
            Row = 0; //Reset this value so we can check the next column
        
        
        }
        
        //Checking for Diagonal Wins
        //Reset the Row and Column values for checking and looping purposes 
        Row = 0; 
        Column = 0; 
        Continue = 1; 
        int DiagonalCheck = 0; //This will be our looping variable 
    	
    	//This loop will check for diagonal wins from the top left hand corner
    	//to the bottom right hand corner
    	
    	while (DiagonalCheck < intBoardSize && Continue == 1) 
    	{ 
    		//If the board space is not equal to the current turn-set the continue value to 0
            //to end the loop 
    		if (Board[DiagonalCheck][DiagonalCheck] != Turn) 
    			Continue = 0; 
    		
    		//If we reach this point-it means all the spaces in the diagonal have a matching
    		//character and therefore there is a win and return a true value
    		else if (DiagonalCheck == intBoardSize - 1)
    			return true; 
    		
    		DiagonalCheck = DiagonalCheck + 1; //Looping variable
    	
    	} 
    	
    	
    	//Reset Looping variables
    	DiagonalCheck = 0; 
    	Column = intBoardSize-1; //This time we're starting from the top right hand corner
    	Continue = 1; //So the loop will run through at least once
    	
    	//We'll need another loop to check for diagonal wins coming from the
    	//top right hand corner to the top left hand corner
    	
    	while (DiagonalCheck < intBoardSize && Continue == 1) 
    	{ 
    		
    		//If the board space is not equal to the current turn-set the continue value to 0
            //to end the loop 
    		if (Board[Column][DiagonalCheck] != Turn) //If the space in the bottom is not equal to the turn
    			Continue = 0; //Set Continue to 0 and the loop will be terminated
    		
    		//If we reach this point-it means all the spaces in the diagonal have a matching
    		//character and therefore there is a win and return a true value
    		else if (DiagonalCheck == intBoardSize - 1) 
    			return true;
    			
    		Column = Column - 1; //This is for checking purposes
    		DiagonalCheck = DiagonalCheck + 1; //Looping variable
    	
    	} 
    	
    
        //Check for a draw-a draw takes place if all the spaces are filled and there is no winner
        if (intSpacesUsed == intBoardSize*intBoardSize) 
        {    
            draw = true; //Change the draw value to true
            return true; //Return a 'Win' value of true-in order to end the game loop
        } 

         
         return false; //If the code reaches this point, it means there is no 'winner'
    } 
    
    else //If there isn't enough spaces taken up for a valid win-we return a false value
        return false; 
} 

int CollectValue(int intBoardSize, apstring Player, apstring Type) 
{ 
    
    //This function will collect and return coordinate values
    
    //Declarations 
    int intNumber; 

    cout << "\n" << Player << ":";
    while ((std::cout << " Please enter a " << Type << ": ")
    && (!(std::cin >> intNumber) || intNumber < 0 || intNumber > intBoardSize)) //If the number is less than 0 or greater than the board size
    {
       std::cout << "\nPlease enter an integer number between 1 and " << intBoardSize; //Ask the user to enter a new number  
       std::cin.clear();  //Clear current value  
       std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //Ignore current value
                     
    } //Loop is terminated once a valid value is collected
    
    //We return a number 1 less than what the user entered because the matrix starts at 0, but 
    //the user's 'choices' start at 1, so if they choose 1,1-we need to enter a value in '0,0'
    
    return intNumber-1; //Return this value

} 