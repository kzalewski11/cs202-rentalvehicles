//Kyle Zalewski
//CS202
//Prog 2
//
//main.cpp

#include "kylezalewski_prog2.h"

int main()
{
    list l;                             //create list object
    int choice = l.mainMenu();                       //display menu
    
    //main program control structure
    while(choice < 4 && choice > 0)
    {
        //view inventory
        if(choice == 1)
        {
            l.display();
        }

        //add new vehicle to inventory
        if(choice == 2)
        {
            l.addEnd();
        }
        //remove a vehicle from inventory
        if(choice == 3)
        {
            l.remNode();
        }
        choice = l.mainMenu();
    }

    //exit program selection
    cout << "Thank you for using inventory. Goodbye." << endl;
    return 0;
}
