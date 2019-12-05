//Kyle Zalewski
//CS202
//Prog 2
//
//kylezalewski_prog2.cpp

#include "kylezalewski_prog2.h"

//node constructor
node::node()
{
    //initialize prev and next pointers
    prev = NULL;
    next = NULL;

    //create transportation object based on user input
    int vehicleChoice = vehicleMenu();

    //construct scooter object
    if(vehicleChoice == 1)
    {
        scooter * s = new scooter;
        t = s;
    }

    //construct zipCar object
    if(vehicleChoice == 2)
    {
        zipCar * z = new zipCar;
        t = z;
    }

    //construct bicycle object
    if(vehicleChoice == 3)
    {
        bicycle * b = new bicycle;
        t = b;
    }
}

//node destructor
node::~node()
{
    delete t;
    delete prev;
    delete next;
}

//vehicle menu display function
int node::vehicleMenu()
{
    int vehicle = 0;
    do
    {
        //display vehicle selection menu
        cout << "Please select vehicle type:" << endl;
        cout << "1) Scooter" << endl; 
        cout << "2) ZipCar" << endl; 
        cout << "3) Bicycle" << endl;
        cin >> vehicle;

        //verify user input valiity
        if(!vehicle || vehicle < 1 || vehicle > 3)
        {
            cin.clear();
            cout << "Invalid selection. Please select again." << endl;
        }
        cin.ignore(100,'\n');
    }while(vehicle < 1 || vehicle > 3);

    return vehicle;
}

//go to prev node
node * & node::goPrev()
{
    return prev;
}

//go to next node
node * & node::goNext()
{
    return next;
}

//add node before current
void node::addPrev(node * toAdd)
{
    prev->next = toAdd;
    prev = toAdd;
}
void node::addNext(node * toAdd)
{
    next = toAdd;
    toAdd->prev = this;
}

//display node
void node::display()
{
    t->display();
}

//get id of node

int node::getId()
{
    return t->getId();
}

//list constructor
list::list()
{
    head = NULL;
    tail = NULL;
}

//list destructor
list::~list()
{
    //if list only has one item
    if(head == tail)
    {
        delete head;
        return;
    }

    //if list has multiple items
    deleteAll(head);   
}

//delete all nodes in list
void list::deleteAll(node * head)
{
    if(head!=tail)
        deleteAll(head->goNext());
    delete head;
}

//main menu display function
int list::mainMenu()
{
    int userChoice = 0;
    //display menu
    cout << "\nWelcome to inventory. Please make a selection:\n";
    cout << "1) View current inventory\n";
    cout << "2) Add new vehicle to inventory\n";
    cout << "3) Remove a vehicle from inventory\n";
    cout << "4) Exit inventory program\n";
    cin >> userChoice;

    //check for valid selection
    while(!userChoice || userChoice < 1 || userChoice > 4)
    {
        cin.clear();
        cin.ignore(100,'\n');
        cout <<"Invalid selection. Please select again\n";
        cin >> userChoice;
    }
    return userChoice;
}

//add node to DLL
bool list::addEnd()
{
    //create new node
    node * newNode = new node;

    //if list is empty
    if(!tail)
    {
        head = newNode;
        tail = newNode;
        return true;
    }

    //set prev, next pointers
    tail->addNext(newNode);
    tail = newNode;
    return true;
}

//remove node by ID
bool list::remNode()
{
    //if list is empty
    if(!head)
    {
        cout << "List is empty. No vehicles removed.\n";
        return false;
    }
    
    //user chooses vehicle to remove
    int choice = 0;
    cout << "Please enter ID for vehicle to remove. \n";
    cin >> choice;

    //if list only has one item
    if(head == tail)
    {
        delete head;
        head = NULL;
        tail = NULL;
        return true;
    }

    if(remNode(head, choice))
    {
        cout << "Vehicle successfully removed.\n";
        return true;
    }
    cout << "Vehicle ID not found. No vehicles removed.\n";
    return false;
}

//recursive removal function
bool list::remNode(node * & head, int choice)
{
    //if current head matches removal id
    if(head->getId() == choice)
    {
        /*
        //if deleting first of list of two test case
        this->head = this->head->goNext();
        this->head->goPrev() = NULL;
        delete this->head;
        
        if(head)
            head->goPrev() = temp->goPrev();
        temp->goPrev()->goNext() = temp->goNext();
        delete temp;
        temp = NULL;
        
        //set next pointer of previous node if it exists
        if(head->goPrev())
            head->goPrev()->goNext() = head;*/
        return true;
    }
    
    //traverse list if not found
    if(head->goNext())
        remNode(head->goNext(), choice);

    //if not found
    return false;
}

//wrapper for display function
void list::display()
{
    cout << "Inventory List\n";
    cout << "___________________________\n";
    display(head);
}

//recursively display DLL
void list::display(node * head)
{
    //if list is empty, display message
    if(!head)
    {
        cout << "List is empty\n";
        return;
    }

    //display node information
    head->display();

    //recursively move to next node
    if(head != tail)
        display(head->goNext());
}

//transportation class constructor
transportation::transportation()
{
    //intersection prompt
    cout << "Please enter closest intersection\n";
    char temp[100];
    cin.getline(temp, 100);
    closestIntersection = new char[strlen(temp) + 1];
    strcpy(closestIntersection, temp);

    //vehicle ID prompt
    cout << "Please enter vehicle ID\n";
    cin >> iD;
    cin.ignore(100,'\n');

    //hourly cost prompt
    cout << "Please enter hourly cost\n";
    cin >> hourlyCost; 
    cin.ignore(100,'\n');

    //initialize other members
    checkedOut = false;
    hoursTaken = 0; 
    needsRepair = false;
    amountEarned = 0.0;
}

//transportation class destructor
transportation::~transportation()
{
    delete [] closestIntersection;
}

//transportation class copy constructor
transportation::transportation(const transportation &t)
{
    closestIntersection = new char[strlen(t.closestIntersection) + 1];
    strcpy(closestIntersection, t.closestIntersection);
    iD = t.iD;
    hourlyCost = t.hourlyCost;
    checkedOut = t.checkedOut;
    hoursTaken = t.hoursTaken;
    needsRepair = t.needsRepair;
    amountEarned = t.amountEarned;
}

//get id of transportation object
int transportation::getId()
{
    return iD;
}

//scooter class constructor
scooter::scooter()
{
    //initialize batteryLevel
    batteryLevel = 100;
}

//scooter display function
void scooter::display()
{
    //display scooter information
    cout << "Vehicle type: Scooter\n";
    cout << "Closest Intersection: " << closestIntersection << endl;
    cout << "Vehicle ID: " << iD << endl;
    cout << "Vehicle Hourly Cost: " << hourlyCost << endl;

    //vehicle checked out
    if(checkedOut)
        cout << "Vehicle has been checked out for " << hoursTaken << " hours \n";
    else
        cout << "Vehicle is currently not checked out.\n";
    if(needsRepair)
        cout << "Vehicle is in need of maintenance \n";
    cout << "Battery level is: " << batteryLevel << "%\n\n";
}

//zipCar class constructor
zipCar::zipCar()
{
    //license plate number prompt
    cout << "Please enter license plate number\n";
    char temp[100];
    cin.getline(temp, 100);
    licensePlate = new char[strlen(temp) + 1];
    strcpy(licensePlate, temp);

    //initialize other members
    gasLevel = 100;
    userFilled = false;
}

//zipCar class destructor
zipCar::~zipCar()
{
    delete [] licensePlate;
}

//zipCar class copy constructor
//needs init list to start base class copy constructor
zipCar::zipCar(zipCar &z)
{
    licensePlate = new char[strlen(z.licensePlate) + 1];
    strcpy(licensePlate, z.licensePlate);
    gasLevel = z.gasLevel;
    userFilled = z.userFilled;
}

//zipcar display function
void zipCar::display()
{
    //display zipcar information
    cout << "Vehicle type: Zipcar\n";
    cout << "Closest Intersection: " << closestIntersection << endl;
    cout << "Vehicle ID: " << iD << endl;
    cout << "Vehicle License Plate Number: " << licensePlate << endl;
    cout << "Vehicle Hourly Cost: " << hourlyCost << endl;
    //vehicle checked out
    if(checkedOut)
        cout << "Vehicle has been checked out for " << hoursTaken << " hours \n";
    else
        cout << "Vehicle is currently not checked out.\n";
    if(needsRepair)
        cout << "Vehicle is in need of maintenance \n";
    cout << "Vehicle gas level is " << gasLevel << "%\n\n";
}

//bicycle class constructor
bicycle::bicycle()
{
    //initialize offroad
    offRoad = false;
}

//bicycle display function
void bicycle::display()
{
    //display zipcar information
    cout << "Vehicle type: Bicycle\n";
    cout << "Closest Intersection: " << closestIntersection << endl;
    cout << "Vehicle ID: " << iD << endl;
    if(offRoad)
        cout << "This is an offroad bicycle.\n";
    cout << "Vehicle Hourly Cost: " << hourlyCost << endl;
    //vehicle checked out
    if(checkedOut)
        cout << "Vehicle has been checked out for " << hoursTaken << " hours \n";
    else
        cout << "Vehicle is currently not checked out.\n";
    if(needsRepair)
        cout << "Vehicle is in need of maintenance \n";
    cout << endl;
}
