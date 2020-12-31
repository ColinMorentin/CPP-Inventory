#include "pch.h"
#include <string>
#include "hardware.h"

hardwareInventory::hardwareInventory(int record, const string& name, int quant, double cost)
{
	setRecordNumber(record);
	setToolName(name);
	setQuanity(quant);
	setCost(cost);
}
// default constructor 

void hardwareInventory::setRecordNumber(int record)
{
	recordNumber = record;
}
// setter method records

void hardwareInventory::setToolName(const string& name)
{
	size_t length{ name.size() };
	length = (length < 15 ? length : 14);
	name.copy(toolName, length);
	toolName[length] = '\0';

}
// setter method for toolName

void hardwareInventory::setQuanity(int quant)
{
	quantity = quant;
}
// setter method for quantity

void hardwareInventory::setCost(double costValue)
{
	cost = costValue;
}
// setter method for cost

int hardwareInventory::getRecordNumber()const
{
	return recordNumber;
}
// getter method for record

string hardwareInventory::getToolName() const
{
	return toolName;
}
// getter method for tool name

int hardwareInventory::getQuanity() const
{
	return quantity;
}
// getter method for quantity

double hardwareInventory::getCost() const
{
	return cost;
}
// getter method for cost
