#include "linked_list.h"
#include <fstream>

Passenger::Passenger(string fName, string lName, string addr, int pID, int resNo, string tel, int seatNo, string menuPref, Passenger* nxt)  // Struct for passenger node
{
    firstName = fName;
    lastName = lName;
    address = addr;
    passengerID = pID;
    reservationNo = resNo;
    telephoneNumber = tel;
    seatNumber = seatNo;
    menuPreference = menuPref;
    next = nxt;
}

linked_list::linked_list()                                                      // Constructor for linked_list
{
    head = nullptr;
}

linked_list::~linked_list()                                                     // Deconstructor for linked_list
{
    Passenger* current = head;

    while (current != nullptr)      // Go through list until the end of the list is found
    {
        Passenger* next = current->next;
        delete current;             // Delete each item in the list
        current = next;
    }
    head = nullptr;
}

bool linked_list::insertPassenger(const Passenger& newPassenger)                // Function for adding a passenger to the list
{
    Passenger* newNode = new Passenger(newPassenger);

    if (!head || head->lastName > newNode->lastName)              // If head is empty or the last name of the new passenger comes first alphabetically, replace the first member of the list
    {
        newNode->next = head; 
        head = newNode; 
    } else {                                                      // Insert passenger elsewhere in list
       
        Passenger* current = head; 
        Passenger* previous = nullptr; 

        while (current && current->lastName <= newNode->lastName) // Search last names in list and place new passenger in alphabetical order
        {
            previous = current;
            current = current->next; 
        }

        newNode->next = current;                                  // Link next node
        if (previous) previous->next = newNode;                   // Link previous node, if applicable
    }

    return true;                                                  // Return true once the passenger is inserted
}

bool linked_list::removePassenger(int passengerID)                              // Function for removing a passenger from the list
{
        Passenger* current = head;
        Passenger* previous = nullptr;

        while (current && current->passengerID != passengerID) // Use current to search for passengerID, use previous to remember the previous node
        {
            previous = current;
            current = current->next;
        }
        if (!current) return false;                            // If the ID is not found, return false 

        if (previous)                                          // Use previous to reconnect the list
        {
            previous->next = current->next;
        } else {                                               // If previous has not updated, then the passenger ID is in the beginning of the list. Update head
            head = current->next;
        }
        delete current;                                        // Current no longer needed, delete it
        return true;                                           // Return true since ID is now updated
}

Passenger* linked_list::search(int passengerID)                                 // Function for searching for a passenger
{
        Passenger* current = head;

        while (current)                                                 // Search the list for the passenger's ID
        {
            if (current->passengerID == passengerID) return current;    // If the passenger is found, return the position
            current = current->next;
        }
        return nullptr;                                                 // If the passenger is not found, return NULL
}

void linked_list::printList()                                                   // Function for printing the list
{
        Passenger* current = head;

        while (current) // Go through the entire list and print passenger information
        {
            cout << "Passenger ID: " << current->passengerID << "; Name: " << current->lastName << ", " << current->firstName
                 << "; Seat: " << current->seatNumber << "; Menu Preference: " << current->menuPreference << endl;
            current = current->next;
        }
}

void linked_list::changeSeat(int passengerID, int newSeatNumber)                // Function for changing reserved seat
{
    Passenger* passenger = search(passengerID);
    Passenger* current = head;
    bool available = true;                              // Assume seat is available from beginning

    if (passenger) 
    {
        while(current)                                  // Search list of passengers and ensure that the seat is available
        {
            if(current->seatNumber == newSeatNumber)  // If the seat number is found, break out
            {                                           // of while and assign available to false
                available = false;
            }
            current = current->next;
        }

        if(!available)                                  // Give error if seat is already taken
        {
            cout << "ERROR: Seat already taken.\n";
        } 
        else                                            // Seat is available, change seat reservation
        {
            passenger->seatNumber = newSeatNumber;
            cout << "Seat number for Passenger ID " << passengerID << " has been updated to " << newSeatNumber << "." << endl;
        }
    } else {                                            // If the ID is not found, then give an error
        cout << "ERROR: Passenger with ID " << passengerID << " not found." << endl;
    }
}

void linked_list::changeFood(int passengerID, const string& newFoodPreference)  // Function for changing requested food
{
    Passenger* passenger = search(passengerID);     // Use search function to find passenger

    if (passenger)                                  // If passenger found, then update food preference
    {
        passenger->menuPreference = newFoodPreference;
        cout << "Food preference for Passenger ID " << passengerID << " has been updated to " << newFoodPreference << "." << endl;
    } else {                                        // If the ID is not found, then give an error
        cout << "ERROR: Passenger with ID " << passengerID << " not found." << endl;
    }
}

void linked_list::copyDatabase()                                                // Function for saving list to a file
{
    ofstream data;              // Used to write data from simulation onto file to save it

    data.open("OUTPUT.txt");    // Program searches for 'OUTPUT.txt' in files

    if(!data.is_open())         // File should be present, but if it is not then give an error
    {
        cout << "\nERROR: Could not find output file\n";
    }

    Passenger* current = head;
        while (current)         // Loop to go through reservations and write them to the file
        {
            data << "First name: " << current->firstName << endl
            << "Last name: " << current->lastName << endl
            << "Address: " << current->address << endl 
            << "Passenger ID: " << current->passengerID << endl
            << "Reservation number: " << current->reservationNo << endl
            << "Telephone number: " << current->telephoneNumber << endl
            << "Seat number: " << current->seatNumber << endl
            << "Menu preference: " << current->menuPreference << endl
            << "---------------------------------------" << endl;
            current = current->next;
        }
}
