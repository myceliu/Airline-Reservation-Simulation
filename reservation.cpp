#include "reservation.h"
#include <fstream>

reservation::reservation()              // Constructor for reservation
{
    id = 0;
}

char reservation::menu()                // Menu function that displays user interface
{
    string choice;

    cout << "--------------------------------------------------------";
    cout << "\n\tBluesky Airline Reservation Management Menu\n"
         << "\t [1]\tEnter a reservation\n"
         << "\t [2]\tCancel a reservation\n"
         << "\t [3]\tPrint a passenger list\n"
         << "\t [4]\tSearch for a passenger\n"
         << "\t [5]\tChange Reservation Seat\n"
         << "\t [6]\tChange Reservation Food\n"
         << "\t [7]\tCopy data\n"
         << "\t [0]\tEXIT\n"
         << "\nSelect menu option: ";
    cin >> choice;
    cout << "-----------------------------------------------------\n";
    
    return choice[0];           // Return user's selection from the menu
}

void reservation::start()               // Function for starting the program
{
    bool done = false;

    do {
        char choice = menu();                                   // Use user's selection to decide which switch case to perform
        switch(choice) {
            case '1': insert(); break;
            case '2': remove(); break;
            case '3': print(); break;
            case '4': search(); break;
            case '5': changeSeat(); break;
            case '6': changeFood(); break;
            case '7': copyDatabase(); break;
            case '0': done = true; break;
            default: cout << "ERROR: INVALID INPUT" << endl;    // Give an error if an unrecognized input is found
        }
    } while(!done);                                             // Go through loop until bool condition is met
    cout << "\nThank you for using my simulation." << endl;
}

void reservation::insert()              // Function for inserting a new passenger into the list
{
    Passenger newPassenger;
                                                // Take passenger information one line at a time
    cout << "Enter first name: ";
    cin >> newPassenger.firstName;              // First name
    cout << "Enter last name: ";
    cin >> newPassenger.lastName;               // Last name (used to sort list)
    cout << "Enter address: "; 
    cin.ignore();                               // cin.ignore included to ensure getline command functions properly
    getline(cin, newPassenger.address);         // Street address
    cout << "Enter passenger ID: ";
    cin >> newPassenger.passengerID;            // Passenger ID
    cout << "Enter reservation number: ";
    cin >> newPassenger.reservationNo;          // Reservation number
    cout << "Enter telephone number: ";
    cin >> newPassenger.telephoneNumber;        // Phone number
    cout << "Enter seat number: ";
    cin >> newPassenger.seatNumber;             // Seat number
    cout << "Enter menu preference: "; 
    cin.ignore();                               // cib.ignore() used for similar reasons as before
    getline(cin, newPassenger.menuPreference);  // Menu request

    mine.insertPassenger(newPassenger);         // All passenger information is obtained, insert passenger into list
    cout << "\nPassenger added successfully.\n";
}

void reservation::remove()              // Function for removing a passenger by ID
{
    int passengerID;
    
    cout << "Enter the passenger ID to cancel reservation: ";
    cin >> passengerID;

    Passenger* passenger = mine.search(passengerID);        // Use search function to find passenger's ID

    if (passenger != nullptr) {                             // If passenger is found, then remove their reservation
        mine.removePassenger(passengerID);
        cout << "Reservation for passenger ID " << passengerID << " has been canceled." << endl;
    } else {                                                // Give an error if the passenger is not found
        cout << "ERROR: Passenger with ID " << passengerID << " not found." << endl;
    }
}

void reservation::print()               // Function for printing full list of passengers
{
    mine.printList();       // Use the linked_list printList function to show the list
}

void reservation::search()              // Function for searching for a specific passenger by ID
{
    int passengerID;
    
    cout << "Enter the passenger ID to search: ";
    cin >> passengerID;

    Passenger* passenger = mine.search(passengerID);    // Use search function again to look for passenger's ID

    if (passenger != nullptr) {                         // Report that the passenger has been found and give their name
        cout << "Passenger found: " << passenger->firstName << " " << passenger->lastName << "\n";
    } else {                                            // Give an error showing that passenger was not found
        cout << "ERROR: Passenger with ID " << passengerID << " not found.\n";
    }
}

void reservation::changeSeat()          // Function for changing passenger seat
{
    int passengerID, newSeatNumber;
    
    cout << "Enter passenger ID: ";
    cin >> passengerID;                                 // Obtain passenger ID
    cout << "Enter new seat number: ";                  // Obtain new requested seat
    cin >> newSeatNumber;
    
    mine.changeSeat(passengerID, newSeatNumber);        // Use linked_list change seat function to perform the seat change
}

void reservation::changeFood()          // Function for changing passenger food preference
{
    int passengerID;
    string newFoodPreference;
    
    cout << "Enter passenger ID: ";
    cin >> passengerID;                                 // Obtain passenger ID
    cout << "Enter new food preference: ";
    cin.ignore();
    getline(cin, newFoodPreference);                    // Use getline to obtain new food preference
    
    mine.changeFood(passengerID, newFoodPreference);    // Use linked_list function to update food preference
}

void reservation::copyDatabase()        // Function for copying list onto an external file 
{
    mine.copyDatabase();                                // Use linked_list function to copy the database
    cout << "Database copied to file 'OUTPUT.txt'.\n";
}
