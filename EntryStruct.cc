//Entry Struct
//This program will allow the user to enter in a person's
//name, gender, and date of birth
//Read in the struct values and display them 
//Exercise 1 pg. 66
//Written by Holly Oegema
//Date: April 29th 2015

#include <iostream.h> 
#include "apstring.h" 

//Defining the Entry struct

struct Entry
{ 
//We are creating a struct and assigning certain 'features'/'variables'
//that are apart of this struct 'package' 

    apstring firstName;
    apstring surName; 
    char gender;
    int day;
    int month;
    int year; 

};

//Prototypes
void ReadEntry(Entry &person); 
void DisplayEntry(Entry person); 
int CollectNumber(apstring strCondition, int intNumCondition1, int intNumCondition2);
char CollectCharacter();
apstring CollectString(apstring strCondition); 

int main() 
{ 
    
    Entry human;
    ReadEntry(human);
    DisplayEntry(human);


    return 0; 
} 

void ReadEntry(Entry &person) 
{ 
    //This function will collect data for the Entry
    //and assign it to the appropriate variables 
    
    //Declarations
    //These are mainly 'conditions we will send' 
    //to the 'collection functions'
    //to ensure that we collect the right data
    apstring strCondition; 
    int intNumCondition1; 
    int intNumCondition2; 
    
    
    //The first piece of data we collect is the person's first name
    strCondition = "first name";
    person.firstName = CollectString(strCondition);
    
    //Next we collect the person's last name
    strCondition = "last name"; 
    person.surName = CollectString(strCondition); 
    
    //Then we collect a value for the person's gender
    person.gender = CollectCharacter();
    
    //Next we set conditions in order to collect a person's year of birth
    strCondition = "year"; 
    intNumCondition1 = 1898;
    intNumCondition2 = 2015;
    person.year = CollectNumber(strCondition, intNumCondition1, intNumCondition2);
    
    //Next we collect the numerical month the person was born
    intNumCondition1 = 1; 
    intNumCondition2 = 12; 
    strCondition = "month"; 
    person.month = CollectNumber(strCondition, intNumCondition1, intNumCondition2);
   
   //Now that we have the month and year data we can set the conditions for 
   //which days the user can enter as their birthday
   
   //Not every month has 31 days, we adjust the conditions based on which month the user enters
   
    if (person.month == 2) //However, Feburary can have 29 days if it's a leap year
    {	
    	//We use the year the person was born to determine whether or not a leap year
    	//is the case 
    	
   		//If the year is evenly disible by 4 and not evenly divisible by 100
   		//it's a leap year
    	if (person.year%4 == 0 && person.year%100 != 0)
    	{ 
    		
    		intNumCondition2 = 29; //Set the max condition to 29
    	
    	} 
    	
    	//If the year is evenly divisble by 4, evenly divisble by 100 and evenly divisble
    	//by 400, then it is also a leap year
      	else if (person.year%4 == 0 && person.year%100 == 0 && person.year%400 == 0) 
      	{ 
      	
      		intNumCondition2 = 29; //Set the max condition to 29
      	
      	} 
      	
      	else //If there requirements are not met, it's just a regular year
      		
      		intNumCondition2 = 28; //Set the max condition to 28
    
    }    
    //The month's of April, June, September and November have 30 days 
    else if (person.month == 4 || person.month == 6 || person.month == 9 || person.month == 11) 
    {    
        intNumCondition2 = 30; //Set the max condition to 30
        
    }    
    else //All other months have 31 days
    {
        intNumCondition2 = 31;  //Set the max condition to 31
        
    } 
    
    //Now we can collect the person's day of birth 
    strCondition = "day"; 
    person.day = CollectNumber(strCondition, intNumCondition1, intNumCondition2);

} 

int CollectNumber(apstring strCondition, int intNumCondition1, int intNumCondition2)
{ 
    //Declarations
    int intNum; 
    
    while ((cout << "\nEnter the integer " << strCondition << " you were born: ")
    && (!(cin >> intNum) || intNum <  intNumCondition1 || intNum > intNumCondition2)) //if the number does not meet the conditions
    {  
        cout << "\nPlease enter a number between " << intNumCondition1 << " and " << intNumCondition2; //We tell the user it's an error
        cin.clear();  //Clear current value 
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //Ignore current value
 
    } //Once a valid value is collected the loop is terminated

    return intNum; 
    
   
} 

char CollectCharacter() 
{ 
 //This function is used to collect any character values
     char chrGender; 
    
    while ((cout << "\nEnter your gender (M or F): ")
         && (!(cin >> chrGender) || chrGender != 'M' && chrGender != 'F')) //if M or F is not entered
         {  
             cout << "\nPlease enter either M or F"; //We tell the user it's an error
              cin.clear();  //Clear current value 
              cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //Ignore current value
 
        } //Once a valid value is collected the loop is terminated


    return chrGender;
} 

apstring CollectString(apstring strCondition) 
{ 
    //This function is used to collect any string values needed
    
    //Declarations
    apstring String;
    
    cout << "\nPlease enter your " << strCondition << ": ";
    cin >> String;
    
    return String; 


} 

void DisplayEntry(Entry person) 
{ 
     //This function will display the data entered for the entry struct
     
    cout << "\n\nFirst Name: " << person.firstName;
    cout << "\nLast Name: " << person.surName;
    cout << "\nGender: " << person.gender; 
    cout << "\nDate of Birth: "<< person.day << "/" << person.month << "/" << person.year;
    

}