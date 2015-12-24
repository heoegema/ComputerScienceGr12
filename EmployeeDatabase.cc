//Employee Database
//Exercise 2 pg. 68
//This program will allow the user to choose from a variety of options
//such as add employee, display employee, calculate wages owed by the company
//sort the list as well as search the list
//Written by Holly Oegema
//Date: May 6th 2015

#include <iostream.h> 
#include "apstring.h" 
#include <apvector.h> 
#include <algorithm.h> 
#include <iomanip.h>


//Creating the struct 
struct Employee
{ 
    apstring FirstName; 
    apstring LastName;
    double hourlyRate; 
    int hoursWorked; 
    double wages; 
};

//Prototypes 
int CollectChoice(); 
void ErrorMessage();
void ReadEmployee(Employee &person, apvector<Employee> employeeList, int intNumEmployees); 
double CollectNumber(apstring strCondition, int intNumCondition);
void DisplayEmployee(const Employee &person);
int CalculateWages(apvector <Employee> &employeeList, int intNumEmployees); 
void SortListByWages(apvector<Employee> &employeeList, int intNumEmployees); 
bool SortListByNames(apvector<Employee> &employeeList, int intNumEmployees); 
bool SearchListLinear(apvector<Employee> employeeList, apstring searchName, int &foundLocation, int intNumEmployees); 
bool SearchListBinary(apvector<Employee> employeeList, apstring searchName, int &foundLocation, int intNumEmployees); 


 


int CollectChoice() 
{ 
    //This function will collect a user's choice from 0 - 5 (This prevents error and invalid input) 
    
    //Declarations 
    int intChoice; 
    
    cout << "\nPlease choose one of the options listed above (0-6): "; 
    while (!(cin >> intChoice) || intChoice <  0 || intChoice > 6) //if the number does not meet the conditions
      {  
             cout << "\nInvalid Option! Only Choices between 0 and 6 are valid!" << endl; 
              cin.clear();  //Clear current value 
              cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //Ignore current value
 
      } //Once a valid value is collected the loop is terminated
    
    return intChoice; //Return this value 


} 

void ErrorMessage() 
{ 
    //This function will display an error message if the user
    //tries to carry out a task that requires Employee Data and there is
    //none
    //We create a separate function for this to save space and make the code
    //more efficient. 
    
    cout << "\n\nSorry, there is currently no Employee Data."; 


} 

void ReadEmployee(Employee &person, apvector<Employee> employeeList, int intNumEmployees)
{ 
    
    //Collects the Employee's information (name, hours worked, hourly wages) 
    //Places these details into the parameter known as 'person' 
    
    //Declarations
    apstring strCondition, strName, strFirstName, strLastName;
    int intNumCondition;
    bool EmployeeExists = true; 
    int i = 0; //For looping purposes
    //Collecting the person's name
    
    //We asked the user for the employee's first and last name
    
    //For error handling purposes we don't want to have matching employees 
    while (EmployeeExists = true)
    {
        cout << "\n\nPlease enter the Employee's first name: "; 
        cin >> person.FirstName; 
        cout << "\n\nPlease enter the Employee's last name: "; 
        cin >> person.LastName; 
        EmployeeExists = false; //Set value to false
        //Check the list to see if the employee exists 
        
        while (i < intNumEmployees+ 1 && EmployeeExists = false) //This will run until the list has been run through or a matching employee is found
        { 
            //If there is an employee that has been entered with that name
            if (employeeList[i].FirstName == person.FirstName && employeeList[i].LastName == person.LastName)
            {
                EmployeeExists = true; //Set the EmployeeExists value to true
                
            } 
            else if (i == intNumEmployees) //If the loop gets through the list without finding a matching
            //set the EmployeeExists value to false
                EmployeeExists = false; //Set the value to true. 
            i = i + 1; //Looping variable
        } 
        
    } 
    
    //Now we want to collect the person's hours worked
    //and their hourly wage
    //We will adjust the strCondition and numerical condition based on the data being collected
    strCondition = "the employee's total hours worked"; //Set string condition 
    //This is the maximum amount of hours that can be worked during the year (according to most labour laws)
    intNumCondition = 2496; //Set condition
    person.hoursWorked =CollectNumber(strCondition, intNumCondition); //Collect Value
    strCondition = "the employee's hourly wage"; //Set string condition 
    intNumCondition = 200; //The maximum hourly wage is $200 
    person.hourlyRate = CollectNumber(strCondition, intNumCondition); //Collect Number
    
    //We can use this data collected (hourly wage and hours worked)
    //to determine the employee's wages
    person.wages = person.hourlyRate * person.hoursWorked; 


} 

double CollectNumber(apstring strCondition, int intNumCondition)
{ 
    //This function collects numeric values and returns a double value 
    //strCondition and intNumCondition are passed from the ReadEmployee function
    //and inform the user of the data being collected and the conditions on the numerical
    //value being collected based on the type. (ie. Wage, hours etc.) 
    
    //Declarations
    double dblNum; 
    
    while ((cout << "\nPlease enter " << strCondition << ": ")
    && (!(cin >> dblNum) || dblNum <  0 || dblNum > intNumCondition )) //if the number does not meet the conditions
         {  
             cout << "\nPlease enter a number between 0" << " and " << intNumCondition; //We tell the user it's an error
              cin.clear();  //Clear current value 
              cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //Ignore current value
 
        } //Once a valid value is collected the loop is terminated

    return dblNum; 
    
} 

void DisplayEmployee(const Employee &person)
{ 
    //Displays the Employee's details on screen, appropriately formatted 
    cout << "\n\nEmployee Name: "  << person.FirstName << " " << person.LastName;
    cout << "\nEmployee's Hourly Rate: $" << std::setprecision(2) << fixed <<person.hourlyRate;
    cout << "\nEmployee's Total Hours Worked: " << person.hoursWorked;
    cout << "\nEmployee's Wages: $"  << std::setprecision(2) << fixed << person.wages; 

} 
int CalculateWages(apvector <Employee> &employeeList, int intNumEmployees)
{ 
    //Calculates the wages to be paid in total by the company
    //We do this by simply adding up all the employee's wages
    
    //Declarations 
    int i = 0; //Looping variable 
    int intWagesTotal = 0; //This variable will keep track of the total amount of wages
    
    //We loop through the existing employees and add up their wages
    //We assign this numerical value to a variable called intWagesTotal
    while (i < intNumEmployees+1) 
    { 
           intWagesTotal = intWagesTotal + employeeList[i].wages; 
        i = i + 1; //Looping Variable
        
    } 
    
    return intWagesTotal; //Return the total wages the company must pay

} 

void SortListByWages(apvector<Employee> &employeeList, int intNumEmployees) 
{ 
    //Sorts the employeeList into order of wages, from lowest to highest 
    //This function will sort the vector using the insertion sort method
    //this method will move an Employee into it's 'proper' place within the list by 
    //comparing their wage value
    
    //Declarations
    int k; //Looping variable
    int j; //Looping variable
    Employee Temp;
    
   
      for (k = 1; k < intNumEmployees+1; k++) 
      { 
           
          Temp = employeeList[k]; //Assign the current element to variable Temp
          for (j = k; j > 0 && Temp.wages < employeeList[j-1].wages; j--) //This loop will find the element's place in the vector
          { 
              cout << "Sort loop.";
             employeeList[j] = employeeList[j-1]; //Move all values to the right
             
    
          } 
            employeeList[j] = Temp; 
            
      } 

     
    k = 1;
    while (k < intNumEmployees+1)
    { 
        DisplayEmployee(employeeList[k]);
        k++; 
    
    } 

} 

bool SortListByNames(apvector<Employee> &employeeList, int intNumEmployees)
{ 

     //Sorts the employeeList into order of wages, from lowest to highest 
    //This function will sort the vector using the insertion sort method
    //this method will move an Employee into it's 'proper' place within the list by 
    //comparing their wage value
    
    //Declarations
    int k; //Looping variable
    int j; //Looping variable
    Employee Temp;
    
   
      for (k = 1; k < intNumEmployees+1; k++) 
      { 
           
          Temp = employeeList[k]; //Assign the current element to variable Temp
          for (j = k; j > 0 && Temp.FirstName < employeeList[j-1].FirstName; j--) //This loop will find the element's place in the vector
          { 
              cout << "Sort loop.";
             employeeList[j] = employeeList[j-1]; //Move all values to the right
             
    
            } 
            employeeList[j] = Temp; 
            
      } 

     
    k = 1;
    while (k < intNumEmployees+1)
    { 
        DisplayEmployee(employeeList[k]);
        k++; 
    
    } 

    return true; 

} 
bool SearchListLinear(apvector<Employee> employeeList, apstring searchName, int &foundLocation, int intNumEmployees)
{ 
    
    //Search the employeeList for an Employee with the name searchName.
    //Returns a true value if found set found location to the index of the Employee
    //Return false if the employee is not found, setting foundLocation to 0 
    
    //Declarations
    bool blnFound = false; //For search purposes(if a result has been found or not)
    int i = 0; //For looping purposes 

    //We search the list for the Employee that the user searched for
    //This loop will run through the list until either a matching value has been found
    //or the list has been completely run through
    while (blnFound == false && i < intNumEmployees+1) 
    { 
        if (employeeList[i].FirstName == searchName) 
            blnFound = true; 
        else
            i = i + 1; 

    } 
    
    if (blnFound == true) 
    {
        foundLocation = i; //If a value is found set the location to it's index location
        return true; 
    } 
    else
    {
        foundLocation = 0; //If a value isn't found, we set this value to 0. 
        return false; 
    } 
    
} 

bool SearchListBinary(apvector<Employee> employeeList, apstring searchName, int &foundLocation, int intNumEmployees)
{ 
    
    //This function will be accessed if the user decides to sort
    //the function using names (this search method will only work if the list is sorted.) 
    
    //Declarations
    int left = 0;
    int right = intNumEmployees; 
    int middle;
    
    while (left != right) 
    { 
        middle = left +(right-left)/2; 
        if (employeeList[middle].FirstName < searchName) 
            left = middle + 1; 
        else
            right = middle; 
        
    } 
    
    if (employeeList[left].FirstName == searchName)
        foundLocation = left; 
    else
    
        return false; //No matching results were found,return a false value

    return true; //If it reaches this point-it means a result was found, return a true value
    
} 

int main() 
{ 
    
    //Setting up the vector that will contain the Company's employee information
    apvector <Employee> company; 
    
    //Declarations 
    int intChoice = 0; //Mainly for menu choices 
    int intNumEmployees = 0; //To record how many Employees there are (it changes as new entries are added) 
    int intFoundLocation;
    bool blnSortedListName = false; 
    apstring strSearchName;
    bool blnFoundLocation; 
    
    do 
    { 
        
        //Displaying Program Information 
        cout << "\n\nGromit Industries Payroll" << endl; 
        cout << "-------------------------" << endl; 
        cout << "1. Enter new employee." << endl; 
        cout << "2. Display employee details." << endl; 
        cout << "3. Calculate Wages" << endl; 
        cout << "4. Sort employees by wages." << endl; 
        cout << "5. Sort employees by first name." << endl; 
        cout << "6. Search by name." << endl; 
        cout << "0. Quit.\n\n" << endl; 
        intChoice = CollectChoice(); //We call on the CollectChoice function to collect a valid 'choice' value
        
        switch(intChoice) //Different things will happen depending on what choice the user makes 
        { 
            case 0: 
                break; 
            case 1: 
                intNumEmployees++; //Increase the number of employees
                company.resize(intNumEmployees+1); //Resize the vector
                ReadEmployee(company[intNumEmployees], company, intNumEmployees); //Call on this function to collect data for a new employee 
                cout << "\nNew Employee added successfully!\n\n"; 
                blnSortedListName = false; //Once a new employee is added the list becomes unsorted
                break;
            case 2: 
                //This case will display the details for the Employee last entered
                if (intNumEmployees == 0) //If there hasn't been any employee data entered we can't do anything
                    ErrorMessage(); //Display the error message
                else  //Else, if there is data
                    DisplayEmployee(company[intNumEmployees]); //Call the DisplayEmployee function
                break;
            case 3:
                //This case will display the amount of wages owed by the company in total
                if (intNumEmployees == 0) //If there has been no data entered
                    ErrorMessage(); //Display the error message
                else //Else, if there is data we call on the CalculateWages Function and display the result
                    cout << "\n\nThe company must pay $" << setprecision(2) << fixed << CalculateWages(company, intNumEmployees) << " in wages\n\n";
                   break;
            case 4:
                //This case will sort the Employee List by wages (from lowest to highest)
                //Call the function to sort the list 
                if (intNumEmployees == 0) //If there is no employee data display an error message
                    ErrorMessage();
                else  //Else, if there is data, we'll call on the SortListByWages function to sort the list
                       SortListByWages(company, intNumEmployees); 
                break;
            case 5: 
                //This case will sort the employee list by first name (From a-z)
                if (intNumEmployees == 0) //If there are no employees, display an error message
                    ErrorMessage(); 
                //Sort the list and assign the returned true value to blnSortedListName
                //this boolean value will be used for searching purposes
                else  
                       blnSortedListName = SortListByNames(company, intNumEmployees);
                break; 
            case 6: 
                //This case will allow the user to search for an Employee by name
                if (intNumEmployees == 0) //If there is no employees, display an error message
                    ErrorMessage();
                else
                { 
                    //We ask the user for the employee name they wish to search for
                    cout << "Enter the First Name of the Employee you wish to search for: ";
                       cin >> strSearchName; 
                    
                    //If the list is sorted by name-we will use the binary search function
                    if (blnSortedListName == true)
                        blnFoundLocation = SearchListBinary(company, strSearchName, intFoundLocation, intNumEmployees); 
                    else  //If the list isn't sorted, or is sorted by wages, we use the linear search function
                        blnFoundLocation = SearchListLinear(company, strSearchName, intFoundLocation, intNumEmployees); 
                    if (blnFoundLocation == true) //If a true value is returned (result was found)
                    {
                        //We inform the user that there was a positive search result
                        //we display where in the list the employee was located
                        //as well as displaying the data of the Employee they searched for
                        cout << "\n\nYour search for '" << strSearchName << "' has results at";
                        cout <<" index " << intFoundLocation << ":" << endl;
                        DisplayEmployee(company[intFoundLocation]);
                       }    
                    else //Else, the search did not return any positive results
                        cout << "Sorry! Employee not in database"; 
                }
                break; 
            
        } 

    
    } while (intChoice != 0); //If the user chose the 'quit option' we exit out of the loop 

    //This message will only appear if the user 'exits' out of the loop 
    //(They press 0) 
    
    cout << "\n\nGoodbye!"; 



    return 0; 
}