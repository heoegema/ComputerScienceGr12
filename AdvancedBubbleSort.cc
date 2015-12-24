/Advanced Bubble Sort Program
//This is similar to the Simple Bubble Sort method
//Except it has a flag variable to check to see if any passes were done
//If the flag variable has a false value (no passes were down) it means the vector is sorted. 
//Exercise 2 pg. 49 
//Date: April 25 2015
//Written by: Holly Oegema

#include <iostream.h> 
#include <apvector.h> 

//Prototypes
void Display(int i, apvector<int> Integers);
void AdvancedBubbleSort(int i, apvector<int> &Integers); 

int main() 
{ 
    int i = 0;
    int intNum;
    apvector <int> Integers(20);
   
    //Displaying program information and instructions
   
    cout << "\t\t\tInteger Sort with Advanced Bubble Sort";
    cout << "\n\nYou can enter up to 20 integers between 0-100.";
    cout << "\nOnce you're finished enter any negative number to exit.";
  	cout << "\nThis program will then sort your numbers into ascending order using advanced bubble sort.\n"; 
   
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
        
        cout << "\n\nThe unsorted vector is: \n"; 
        Display(i, Integers); //Call the function to display the vector
        
        AdvancedBubbleSort(i, Integers); //Call on the function that will sort the vector
    
        //Now that we've sorted the vector, we will display it again
        cout << "\n\nThe sorted vector is: \n";
        Display(i, Integers); //Call on the function to display the sorted vector

    } 
    
    return 0; 
}     

void AdvancedBubbleSort(int i, apvector<int> &Integers) //We put an & next to the Integer vector because we want to modify the vector itself
{ 

    //This function sorts the vector into ascending order (smallest to greatest) 
    //In order to do this, we'll compare the values in the vector that are next to each other 
    //For example: Integer[j] and Integers[j+1], if the Integer lower in the list {Integer[j]) is greater than Integers[j+1]
    //We'll switch them 
    int Temp; //This will hold the value that we're moving
    bool Flag; //This will indicate whether or not a pass has taken place
    int k; //Looping variable 
    
    do 
    { 
        Flag = false; //Reset the value of the flag incase a pass does not take place (and the vector is already sorted) 
        for(k = 0; k < i - 1; k++) 
        { 
            if (Integers[k] > Integers[k+1]) 
            { 
                Temp = Integers[k]; 
                Integers[k] = Integers[k+1];
                Integers[k+1] = Temp; 
                Flag = true; //If a pass has taken place-set the Flag to true, since the vector is not fully sorted
            } 
            
        } 
    
    } while (Flag == true); //The loop will keep running if Flag == True (a pass has taken place-and the vector is not fully sorted yet) 
    
} 

void Display(int i, apvector<int> Integers) 
{ 
    //This program will display the vector
    int j = 0; 
    while (j < i) 
    { 
        cout << Integers[j]; 
        if (j != i-1) 
            cout << ",";
        j = j + 1; 

    } 

} 
