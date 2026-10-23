#ifndef RESERVATION_H_
#define RESERVATION_H_

#include <iostream>
#include <fstream>	
#include <cstdlib>
using namespace std;
#include "linked_list.h"	

class reservation
{
	public:
		reservation();			// Constructor for reservation
		
        char menu();			// Menu function that displays user interface
		void start();			// Function for starting the program
		void insert();			// Function for inserting a new passenger
		void remove();			// Function for removing a passenger by ID
		void print();			// Function for printing list of passengers
		void search();			// Function for searching for a specific passenger by ID
		void changeSeat();		// Function for changing passenger seat
		void changeFood();		// Function for changing passenger food preference
		void copyDatabase();	// Function for copying list onto an external file
	private:
		linked_list mine;
		int id;	
};

#endif
