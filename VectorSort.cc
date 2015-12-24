//Vector Sorting Program
//This program will collect up to 20 elements and store them in a vector
//It will then sort them into ascending order
//Exercise 5 pg. 47
//Date: April 25th 2015
//Written by Holly Oegema

#include <iostream.h>
#include <apvector.h>

//Prototypes
void Sort(int i, apvector<int> &Integers); 
void Display(int i, apvector<int> Integers); 

int main()

{
    int i = 0;
    int intNum;
    apvector <int> Integers(20);
   
    //Displaying program information and instructions
   
    cout << "\t\t\tInteger Collector";
    cout << "\n\nYou can enter up to 20 integers between 0-100.";
    cout << "\nOnce you're finished enter any negative number to exit.\n";
   cout << "\nThis program will then sort your numbers into ascending order"; 
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
  
   //First we have to check to see if there is any data
   if (i == 0)  //There is a possibility that no values were assigned to the vector
     cout << "The vector is empty and there is no data assigned to any elements.";
    
    else 
    { 
        Sort(int i, Integers); //Call on the function that will sort
    
        //Now that we've sorted the vector, we can display it 
        cout << "The sorted vector is: \n:"
        Display(int i, Integers); //Call on the function to display the sorted vector

    } 
    
    return 0; 
}     

void Sort(int i, apvector<int> &Integers) //We put an & next to the Integer vector because we want to modify the vector itself
{ 

    //This function sorts the vector into ascending order (smallest to greatest) 
    //In order to do this, we'll compare the values in the vector that are next to each other 
    //For example: Integer[j] and Integers[j+1], if the Integer lower in the list {Integer[j]) is greater than Integers[j+1]
    //We'll switch them 
    int Temp; //This will hold the value that we're moving
    int j; //Looping variable
    int k; //Looping variable 
    
    for (j = 0; j < i; j++) 
    { 
        for(k = 0; k < i - 1; k++) 
        { 
            if (Integers[k] > Integers[k+1]) //We only need to switch the values over if the element earlier on in the list is a greater value
            { 
                Temp = Integers[k]; //Assign the larger value to a Temporary variable (this is so we don't lose it...) 
                Integers[k] = Integers[k+1]; //Move the smaller value to the element earlier in the list
                Integers[k+1] = Temp; //Assign the larger value to the element later on in the list
        
        
            } 
        }
    } 

} 

void Display(int i, apvector<int> Integers) 
{ 
    //This program will display the vector
    int j; 
    while (j < i) 
    { 
        cout << Integers[j]; 
        if (j != i) 
            cout << ",";
        j = j + 1; 

    } 

}