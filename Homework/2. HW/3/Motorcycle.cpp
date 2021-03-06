#include "Motorcycle.h"
#include <cstring>
#include <iostream>

Motorcycle::Motorcycle() : Vehicle()
{
	type = new char{ '\0' };
}

Motorcycle::Motorcycle(const Motorcycle & rhs) : Vehicle(rhs)
{
	this->type = new char[strlen(rhs.type) + 1];
	strcpy(this->type, rhs.type);
}

Motorcycle::Motorcycle(const char *make, const char *model, const char *color, const int &year, const int &mileage, const char* type) : Vehicle(make, model, color, year, mileage)
{
	this->type = new char[strlen(type) + 1];
	strcpy(this->type, type);
}

Motorcycle & Motorcycle::operator=(const Motorcycle & rhs)
{
	Vehicle::operator=(rhs);

	if (this != &rhs)
	{
		setType(rhs.type);
	}
	return *this;
}

Motorcycle::~Motorcycle()
{
	delete[] type;
}

void Motorcycle::setType(const char * type)
{
	delete[] this->type;
	this->type = new char[strlen(type) + 1];
	strcpy(this->type, type);
}

const char * Motorcycle::getType()
{
	return type;
}

void Motorcycle::details() const
{
	std::cout << "Make: " << getMake() << '\n';
	std::cout << "Model: " << getModel() << '\n';
	std::cout << "Color: " << getColor() << '\n';
	std::cout << "Year: " << getYear() << '\n';
	std::cout << "Mileage: " << getMileage() << '\n';
	std::cout << "Type:" << type << "\n\n";
}
