#ifndef HARDWARE_H
#define HARDWARE_H
#include <string>
using std::string;

class hardwareInventory
	// custom class definition
{
public:

	hardwareInventory(int = 0, const string& = "",
		int = 0, double = 0.0);
	// default constructor

	//setters 
	void setRecordNumber(int);
	void setToolName(const string&);
	void setQuanity(int);
	void setCost(double);

	//getters

	int getRecordNumber() const;
	string getToolName() const;
	int getQuanity() const;
	double getCost() const;

private:
	int recordNumber = 0;
	// the number the tool is in the file
	char toolName[15];
	// the name of the tool
	int quantity;
	// the number of tools in stock
	double cost;
	// the price of the tool
};

#endif
