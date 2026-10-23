# Airline-Reservation-Simulation
=----------------Airline Reservation System Simulator-----------------=

The Airline Reservation System Simulator is a C++ program that performs the minimal functions that a reservation system used by an employee of an airline company would typically use. It is intended to get users familiar with the basic functions of such a program.

The program stores passenger information in the form of a linked list. The list contains the following information on each passenger:

	* First name		(Stored as string)
	* Last name		(Stored as string)
	* Address		(Stored as string)
	* Passenger ID		(Stored as int)
	* Reservation number	(Stored as int)
	* Telephone number	(Stored as string)
	* Seat number		(Stored as int)
	* Menu preference	(Stored as string)

The program itself is interacted with using a menu function, which contains a list of options for the user to select. These options are: add passenger reservation, remove reservation, print list of passengers, search list of passengers, change passenger seat, change passenger food, and copy data to database.

The database the information is stored in is a file named "OUTPUT.txt". For this function to work, do not alter the title of or delete the file "OUTPUT.txt". To see changes to the database file, close it and then reopen it. The output file will automatically delete its contents and replace itself with the current full list of passengers upon running the copy database command. Copying to the database is recommended to retain data after the program is closed, but remember that what is saved is overwritten each time the copy command is run.
