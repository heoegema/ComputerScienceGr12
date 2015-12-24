//Insertion Sort Method 
//This program will collect up to 20 vectors between 0 and 100 
//and sort them using the insertion sort method
//This program will display the vector before and after the search 
//Exercise 3 pg. 50
//Date: April 25th 2015
//Written by Holly Oegema

#include <iostream.h> 
#include <apvector.h> 

//Prototypes
void Display(int i, apvector<int> Integers);
void InsertionSort(int i, apvector<int> &Integers);

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
        
        cout << "The unsorted vector is: \n"; 
        Display(i, Integers); //Call the function to display the vector
        
        InsertionSort(i, Integers); //Call on the function that will sort the vector
    
        //Now that we've sorted the vector, we will display it again
        cout << "The sorted vector is: \n:"
        Display(i, Integers); //Call on the function to display the sorted vector

    } 
    
    return 0; 
}     

void Display(int i, apvector<int> Integers)
{ 
    //This function will display the vector
    int j; 
    while (j < i) 
    { 
        cout << Integers[j]; 
        if (j != i) 
            cout << ",";
        j = j + 1; 

    } 

} 
void InsertionSort(int i, apvector<int> &Integers) 
{ 
    //This function will sort the vector using the insertion sort method
    //this method will move a number into it's 'proper' place within the list
    int k; 
    int j;
    int Temp; 
    
    for (k = 1; k < n; k++) 
    { 
        Temp = Integers[k]; //Assign the current element to variable Temp
        for (j = k; j > 0 && Temp <Integers[j-1]; j--) //This loop will find the element's place in the vector
        { 
            Integers[j] = Integers[j-1]; //Move all values to the right
            Integers[j] = Temp; 
    
        } 

    } 

}