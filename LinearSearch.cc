//Linear Search 
//This program will allow the user to enter up to 20 Integers
//Then it will ask the user for a value that they wish to search for
//Using Linear search, the program will then find the value (if there is one) 
//Exercise 1 pg. 57
//Written by: Holly Oegema
//Date April 29th 2015

#include <iostream.h> 
#include <apvector.h> 
#include "apstring.h" 

//Prototypes
void Search(int i, apvector<int>Integers); 
bool SearchAgain(); 


int main() 
{     

    //Declarations 
    int intNum;
    int i; 
    bool SearchAgain = true; //This guarantees that the loop will run at least once 
    //Setting up the vector
    apvector<int>Integers(20); 
    
    //Collecting Values
    do
    {
        while ((cout << "\nEnter an integer value between 0-100 for Element "<< i << ": ")
        && (!(cin >> intNum) || intNum > 100)) //if the number is less than 0 or more than 100
        {  
            cout << "\nError! Your number is too great."; //We tell the user it's an error and ask them to enter a new number
            cout << "\nPlease enter an integer number between 1 and 100\n"; //Ask the user to enter a new number 
            cin.clear();  //Clear current value 
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //Ignore current value
 
        } //Once a valid value is collected the loop is terminated
    
        if (intNum > 0) //If the value is greater than 0
        {
            Integers[i] = intNum; //Assign the value to the vector
            //If the value is less than 0, it won't be assigned and the loop will just exit itself
            i++; //Looping variable
        }
    } while (intNum > 0 && i < 20);  //Finishing Condition

if (i == 0) 
        cout << "The vector contains no data!"; 
else 
{ 
    //Now that we have collected values we want the user to be able to search for a certain value
    while (SearchAgain == true) 
    { 
        Search(i, Integers); 
        SearchAgain = SearchAgain(); 
    } 
} 
    return 0; 
} 

void Search(int i, apvector<int>Integers)
{ 
    int SearchValue; //This variable will store the user's 'search value' 
    bool Found = false; 
    int j = 0; //Looping variable 
    
    //Collecting a search value
    while ((cout << "\nPlease enter the integer value you wish to search for: ")
        && (!(cin >> SearchValue) || SearchValue < 0 || SearchValue > 100)) //If the value entered is less than 0 or more than 100
        {  
            cout << "\nPlease enter an integer number between 1 and 100: "; //Ask the user to enter a new number 
            cin.clear();  //Clear current value 
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //Ignore current value
 
        } //Once a valid value is collected the loop is terminated
    
    //Search for the value itself
    while (Found == false && j < i) 
    { 
        if (Integers[j] == SearchValue) 
            Found == true; 
        else 
            j = j + 1; 
    } 
    if (Found == True) 
        cout << SearchValue << " found at element " << j << endl; 
    else 
        cout << "Sorry! We couldn't find " << SearchValue << " within the vector!"; 



} 

bool SearchAgain()
{ 
    //This function asks the user whether or not they would like to search for another value
    //Based on their response (Y or N) the function returns a boolean value
    char chrResponse; 
    while ((cout << "\nDo you wish to search for another value? (Y/N): ")
        && (!(cin >> chrResponse) || chrResponse != 'Y' && chrResponse !='N')) //If the value entered is not Y or N 
        {  
            cout << "\nInvalid Input! Please either Y or N\n"; //Ask the user to enter a new number 
            cin.clear();  //Clear current value 
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //Ignore current value
 
        } //Once a valid value is collected the loop is terminated
    
    if (chrResponse == 'Y') 
        return true; //The user wants to make another search-return a true value so the loop in the main function will continue
    else 
        return false; //If the user enters 'N', return a false value and the loop in the main function will stop


}