/*
Data Structures
Program 3 Airline Reservation Simulator

    This program simulates the management of a reservation manager for the imaginary airline
company Bluesky. First, the program presents a menu of options the user can select. These
options are add passenger, remove passenger, print the list of passengers, search for a
specific passenger, change preferred seat, change preferred food, and lastly copy list of
passengers to a file. The program will loop through the selection menu and user options until
the user inputs 0 at the menu interface.
*/
#include "reservation.h"
#include <iostream>

using namespace std;

int main()
{
	reservation bluesky;
	bluesky.start( );
	
	return 0;
}
