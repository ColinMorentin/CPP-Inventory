#include "pch.h"
// compiling speed
#include <iostream>
// input/output operations
#include <fstream>
// file manipulation
#include <cstdlib>
// access to std library functions
#include <limits>
// used to flush input stream buffer quick fix
#include <iomanip>
//enables tools to manipulate display
#include <string>
// string manipulation
#include "hardware.h"
// custom class

using namespace std;
// enables standard use of input and output commands

void generateInventory();
// creates 100 empty records for item inventory
void addItem();
// add an item to inventory
int getChoice();
// prompts user for their action in the program
int updateChoice();
// choice user makes to update inventory item
void displayItems();
// display all items in the record
void deleteItem();
// remove an item from the record
void updateItem();
// update an item in the record

void inputError();
//error message for bad input
void outputLine(ostream&, const hardwareInventory&);
// output an item to the terminal
void tableHeader();
//outputs table header for inventory

int main()
{
	generateInventory();
	// generate 100 empty fields for the inventory

	int choice{ 0 };
	// variable holding user's choice

	choice = getChoice();
	// get the user's choice

	while (choice != 0)
		// continue looping until the termination character is given
	{
		switch (choice)
			// branching based upon choice
		{
			case 1:
				// if 1 is selected perform these actions
			{
				addItem();
				// add an item to the inventory
				break;
				// exit branching
			}
			case 2:
				// if 2 is selected perform these actions
			{
				displayItems();
				// display all items to the user
				break;
				// exit branching
			}
			case 3:
				// if three is selected perform these actions
			{
				deleteItem();
				// remove an item from inventory
				break;
				// exit branching
			}
			case 4:
				// if four is selected perform these actions
			{
				updateItem();
				// make a change to an existing item
				break;
				// exit branching
			}
			default:
			{
				cout << "Invalid choice, try again!" << endl;
			}
		}

		choice = getChoice();
		// get the user's next decision
	}

	return 0;
	// terminate the program
}
void generateInventory()
{
	ofstream inventoryOut("hardware.dat", ios::out | ios::binary);
	//creating a reference object to hardware.dat
	// enabling output to said file in binary


	if (!inventoryOut)
	{
		cerr << "File could not be opened" << endl;
		exit(EXIT_FAILURE);
	}
	// procedure to perform to ensure that the correct file referencing
	// is enabled otherwise an error message is displayed and program is 
	// terminated


	hardwareInventory blankInventory = { 0, "", 0, 0.0 };
	// creating an object of the custom class hardware Inventory

	for (int i{ 0 }; i < 100; ++i)
		// generates 100 empty slots of inventory
	{
		inventoryOut.write(reinterpret_cast <const char*>(&blankInventory),
			sizeof(hardwareInventory));
		// converting the pointer to type char so they can be saved as bytes
	}

	inventoryOut.close();
	// close the reference objects association with the data file
}

void addItem()
// function to add an item to the inventory
{
	fstream inventoryStream("hardware.dat", ios::in | ios::out | ios::binary);
	// creating a reference object to hardware.dat
	// enabling input and output to said file in binary

	if (!inventoryStream)
	{
		cerr << "File could not be opened" << endl;
		exit(EXIT_FAILURE);
	}
	// procedure to perform to ensure that the correct file referencing
	// is enabled otherwise an error message is displayed and program is 
	// terminated

	int recordNumber;
	// the number the tool is in the file
	string toolName;
	// the name of the tool
	int quantity;
	// the number of tools in stock
	double cost;
	// the price of the tool
	system("CLS");
	// clear terminal of text
	while (
		(cout << "Enter a record number" 
		<< " (1 to 100, 0 to end input)\n")
		&&
		// requesting input from user for file addition
		!(cin >> recordNumber))
		// failed input occurs
	{
		inputError();
		// output error and repeat getting data
	}
	// reading input from user

	while (recordNumber > 0 && recordNumber <= 100)
		// continue if it is within the valid range of records
	{
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		// flushing input buffer to remove errors associated with getting input
		while (
			(cout << "Enter tool name\n") &&
			// prompt user for rest of data for custom class object
			!getline(cin, toolName)) 
			// if incorrect input is given
		{
			inputError();
			// error message repeat getting data from the user
		}
		while (
			(cout << "Enter quantity\n") &&
			// prompt user for data
			!(cin >> quantity))
			// invalid entry is given
		{
			inputError();
			// output error clear buffer repeat getting input data
		}
		while((cout << "Enter cost\n") &&
			// prompt user
			!(cin >> cost))
			// invalid entry is given
		{
			inputError();
			//out error clear buffers repeat getting data
		}
		// get data from user

		hardwareInventory newTool{ recordNumber, toolName, quantity, cost };
		// create custom class object with provided data from user

		inventoryStream.seekp(
			(newTool.getRecordNumber() - 1) * sizeof(hardwareInventory));
		// seek out the position in file for writing by getting the record number
		// -1 for array configuration, and getting the accurate size of the 
		// custom class to know the length of the object

		inventoryStream.write(
			reinterpret_cast<const char*>(&newTool), sizeof(hardwareInventory));
		// writing the address of the new tool as a char so it can be saved in bytes
		while(
			(cout << "Enter a record number (1 to 100, 0 to end input)\n") &&
			// prompt user
			!(cin >> recordNumber))
			// invalid data is given
		{
			inputError();
			// output error, clear buffers, repeat 
		}

		cout << "\n";
		// prompting user for more input
	}

	inventoryStream.close();
	// terminate file association

}

int getChoice()
// gets the users decision for the program
{
	int choice{ 0 };
	// the users choice
	while (
		(cout << "\n"<< setw(14) << "MAIN MENU\n"
		<< "Enter your choice!\n"
		<< "1 - add a new tool\n"
		<< "2 - list all items\n"
		<< "3 - delete a record\n"
		<< "4 - update a record\n"
		<< "0 - exit the program\n") && 
		// given users options
		!(cin >> choice))
		// invalid option is given
	{
		inputError();
		// output error, clear buffer, clear flags, repeat process
	}
	
	return choice;
	// returns users input to main
}

void displayItems()
// display all items in inventory
{

	hardwareInventory Item;
	// creating a default hardware item

	ifstream itemIn("hardware.dat", ios::in | ios::binary);
	// creates object to reference hardware.dat
	// enables file to be read in binary

	if (!itemIn)
	{
		cerr << "File could not be opened" << endl;
		exit(EXIT_FAILURE);
	}

	// ensures file association or the program terminates with
	// an error message

	system("CLS");
	// clear the screen

	itemIn.seekg(0);
	// sets file pointer to the  beginning of the file

	tableHeader();
	// displays header of inventory table

	itemIn.seekg(0);
	// ensures file pointer is at the start

	itemIn.read(reinterpret_cast<char*>(&Item), sizeof(hardwareInventory));
	// cast items for reading 

	while (itemIn && !itemIn.eof())
		// continue while there is something to read and you haven't reached
		// the end of the file
	{
		if (Item.getRecordNumber() != 0)
			// skip items holding the default constructor
		{
			outputLine(cout, Item);
			// displays items for the user
		}

		itemIn.read(reinterpret_cast<char*>(&Item), sizeof(hardwareInventory));
		// casts items for reading
	}

	itemIn.close();
	// end file association

}

void deleteItem()
// delete a record
{

	fstream deleteInventory("hardware.dat", ios::in | ios::out | ios::binary);
	// creating a reference object to hardware.dat
	// enabling input and output to said file in binary

	if (!deleteInventory)
	{
		cerr << "File could not be opened" << endl;
		exit(EXIT_FAILURE);
	}
	// ensures file association or the program terminates with
	// an error message

	int recordNumber = 0;
	// record to be deleted
	while(
		(cout << "Enter a record to deleted\n") &&
		// prompt user
		!(cin >> recordNumber))
		// invalid input is given
	{
		inputError();
		// prompt error, clear buffer, clear flags, repeat getting data
	}

	deleteInventory.seekg((recordNumber - 1) * sizeof hardwareInventory);
	// move file pointer to location of the requested item
	hardwareInventory deleteItem;
	// empty custom class to store requested data
	deleteInventory.read(
		reinterpret_cast<char*>(&deleteItem), sizeof(hardwareInventory)
	);
	// store requested data in the new object

	if (deleteItem.getRecordNumber() != 0)
		// continue if the object isn't a blank object
	{
		hardwareInventory blankItem;
		// blank custom class object
		deleteInventory.seekp((recordNumber - 1) * sizeof(hardwareInventory));
		// move file pointer to the location of the item to be deleted
		deleteInventory.write(
			reinterpret_cast<const char*>(&blankItem), sizeof(hardwareInventory));
		// write blank item over the item that is to be deleted
	}

}

void updateItem()
// update a record
{
	fstream updateInventory("hardware.dat", ios::in | ios::out | ios::binary);
	// creating a reference object to hardware.dat
	// enabling input and output to said file in binary

	if (!updateInventory)
	{
		cerr << "File could not be opened" << endl;
		exit(EXIT_FAILURE);
	}
	// ensuring file association and error message is in place

	int recordNumber = 0;
	// record to be updated
	int choice = 12;
	// choice made by the user for updating
	


	// choice made by user for updating
	system("CLS");
	// clear terminal of text
	while (
		(cout << "Enter a record to be updated: \n") &&
		!(cin >> recordNumber))
	{
		inputError();
	}
	// getting data from user for object to be updated

	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	// flushing input buffer to remove error

	updateInventory.seekg((recordNumber - 1) * sizeof(hardwareInventory));
	// putting file pointer to updated object

	hardwareInventory updateItem;
	// empty update Item to be manipulated for updating


	updateInventory.read(reinterpret_cast<char*>(&updateItem), sizeof(hardwareInventory));
	// storing file to be updated into the empty custom class object

	int record = updateItem.getRecordNumber();
	// holds the record number of the tool
	string tool =updateItem.getToolName();
	// name of the tool
	int quantity = updateItem.getQuanity();
	// the # of tools in the inventory
	double price = updateItem.getCost();
	// price of the tool

	cout << "\n "; 
	// extra space for aesthetics 
	tableHeader();
	//outputs table header for inventory
	outputLine(cout, updateItem);
	// outputs current item for update

	
	if (updateItem.getRecordNumber() != 0)
		// continue assuming you aren't working with an empty record
	{
		
		while (choice != 0)
			// continue till termination character is given
		{
			choice = updateChoice();
			// get choice from the user
			
			switch (choice)
				// branching
			{
			case 1:
			{
				while (
					(cout << "\nWhat is the new record number?\n") &&
					!(cin >> record))
				{
					inputError();
				}
				// getting data change 
				updateItem.setRecordNumber(record);
				// updating the item
				cout << endl;
				// creating a newline
				break;
				// terminating branch
			}

			case 2:
			{
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				// flushing input buffer to remove errors
				while (
					(cout << "\nWhat is the new name?\n") &&
					!(getline(cin, tool)))
				{
					inputError();
				}
				// prompting name change data
				updateItem.setToolName(tool);
				//updating item
				cout << endl;
				// creating new line
				break;
				// end branching
			}
			case 3:
			{
				while (
					(cout << "\nWhat is the new quantity>\n") &&
					!(cin >> quantity))
				{
					inputError();
				}
				// get data from the user with input security
				updateItem.setQuanity(quantity);
				// update the new item to the inventory
				cout << endl;
				// create an empty line
				break;
				// exit the branching
			}
			case 4:
			{
				while (
					(cout << "\nWhat is the new cost?\n") &&
					!(cin >> price))
				{
					inputError();
				}
				// get data from the user with input security
				updateItem.setCost(price);
				// update the item with the new price
				cout << endl;
				// create a blank line
				break;
				// terminate branching
			}
			default:
				cout << "\nInvalid Choice, sent to main menu for incompetence!\n" << endl;
				// output if wrong input is given
			}
		}
			tableHeader();
			//outputs table header for inventory
			outputLine(cout, updateItem);
			//outputs updated item
			updateInventory.seekp((record - 1) * sizeof(hardwareInventory));
			// getting items place in memory
			updateInventory.write(
				reinterpret_cast<const char*>(&updateItem), sizeof(hardwareInventory));
			// writing the data in binary
	
		
			
	}
	
	updateInventory.close();
	// end file association

}

void outputLine(ostream& output, const hardwareInventory& record)
// displays items for the user
{
	output << left << setw(11) << record.getRecordNumber()
		// aligning things left, positioning items for printing
		<< setw(16) << record.getToolName() << setw(7) << record.getQuanity()
		// positioning items for printing
		<< setw(13) << setprecision(2) << right << fixed
		// positioning items for printing, bank style printing for floats
		<< showpoint << record.getCost() << endl;
		// display the decimal to the user
}

int updateChoice()
// choice for updating an item
{
	int choice = 0;
	// the users choice
	while (
		(cout << "\nWhat do you wish to change about the item?\n"
			<< "1 - record number\n"
			<< "2 - name\n"
			<< "3 - quantity\n"
			<< "4 - price\n"
			<< "0 - to terminate selection\n") &&
		!(cin >> choice))
	{
		inputError();
	}
	// getting user input with input security
	return choice;
	// return the choice 
}

void inputError()
// necessary for ensuring valid input is given
{
	cout << "\nTHAT IS NOT A VALID ENTRY!\n" << endl;
	// output error
	cin.clear();
	// clear the input buffer
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	// clear flags
}

void tableHeader()
{
	cout << left << setw(11) << "Record #" << setw(16) << "Tool Name"
		<< setw(11) << "Quantity" << setw(10) << right << "Cost\n";
	// table headers for display
}
