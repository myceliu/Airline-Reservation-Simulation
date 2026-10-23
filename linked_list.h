#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_
#include <iostream>
#include <string>
using namespace std;

struct Passenger        // Struct for passenger node
{
    string firstName;
    string lastName;
    string address;
    int passengerID;
    int reservationNo;
    string telephoneNumber;
    int seatNumber;
    string menuPreference;
    Passenger* next;
    Passenger(string fName = "", string lName = "", string addr = "", int pID = 0, int resNo = 0, string tel = "", int seatNo = 0, string menuPref = "", Passenger* nxt = nullptr);
};


class linked_list 
{
public:
    linked_list();                                                      // Constructor for linked_list
    ~linked_list();                                                     // Deconstructor for linked list
    bool insertPassenger(const Passenger& newPassenger);                // Function for adding a passenger to the list
    bool removePassenger(int passengerID);                              // Function for removing a passenger from the list
    Passenger* search(int passengerID);                                 // Function for searching for a passenger in the list
    void printList();                                                   // Function for printing the list
    void changeSeat(int passengerID, int newSeatNumber);                // Function for changing reserved seat
    void changeFood(int passengerID, const string& newFoodPreference);  // Function for changing requested food
    void copyDatabase();                                                // Function for saving list to a file

private:
    Passenger* head; 
};

#endif
