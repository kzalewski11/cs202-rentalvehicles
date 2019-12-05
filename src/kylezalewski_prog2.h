//Kyle Zalewski
//CS202
//Prog 2
//
//kylezalewski_prog2.h

#include <iostream>
#include <cstring>

using namespace std;

class transportation
{
    public:
        transportation();           //class default constructor
        virtual ~transportation();          //class destructor
        transportation(const transportation &t);  //copy constructor
        virtual void display() = 0;     //pure virtual display function 
        int getId();               //get ID of object

    protected:
        char * closestIntersection; //closest intersection to current location
        int iD;                     //vehicle identification number
        double hourlyCost;          //vehicle cost per hour
        bool checkedOut;            //vehicle is checked out
        int hoursTaken;             //number of hours checked out
        bool needsRepair;           //vehicle needs repair
        double amountEarned;        //amount earned since last service
};

class node
{
    public:
        node();                     //node default constructor
        node(transportation  &v);  //constructor with passed in object
        ~node();                    //node destructor
        int vehicleMenu();          //vehicle menu function
        node * & goPrev();             //go to prev function
        node * & goNext();             //go to next function
        void addPrev(node * toAdd); //add previous
        void addNext(node * toAdd); //add next
        void display();                  //display node information
        int getId();                //gets iD of object in node

    private:
        node * prev;                //prev pointer for DLL
        node * next;                //next pointer for DLL
        transportation * t;           //transportation pointer
};

class list
{
    public:
        list();                     //class default constructor
        ~list();                    //list destructor
        void deleteAll(node * head);           //delete all nodes recursively
        int mainMenu();            //main menu function
        bool addEnd();              //adds node to DLL
        bool remNode();             //removes last node from DLL
        bool remNode(node * & head, int choice);  //recursive removal function
        void display();             //wrapper for display recursion
        void display(node * head);  //recursive function for display
    private:
        node * head;                //head pointer for DLL
        node * tail;                //tail pointer for DLL
};

class scooter:public transportation
{
    public:
        scooter();                  //class default constructor
        void display();             //display scooter info
    private:
        int batteryLevel;           //0-100 percent battery charge
};

class zipCar:public transportation
{
    public:
        zipCar();                   //class default constructor
        ~zipCar();                  //class destructor
        zipCar(zipCar &z);          //copy constructor
        void display();             //display zipCar info
    private:
        char * licensePlate;        //license plate number for car
        int gasLevel;               //0-100 percent gas in tank
        bool userFilled;            //previous user filled tank
};

class bicycle:public transportation
{
    public:
        bicycle();                  //class default constructor
        void display();             //display bicycle info
    private:
        bool offRoad;               //bike is offroad capable

};
