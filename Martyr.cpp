#include "Martyr.h"
Martyr::Martyr(string paramName, string paramAge, string paramLocation, string paramDateOfDeath, string paramGender)
{
	Name = paramName;
	Age = paramAge; 
	Location=paramLocation;
	DateOfDeath=paramDateOfDeath;
	Gender = paramGender;
}

Martyr::Martyr(const Martyr& obj) {
	Name = obj.Name;
	Age = obj.Age;
	Location = obj.Location;
	DateOfDeath = obj.DateOfDeath;
	Gender = obj.Gender;
}

Martyr::~Martyr(){}

Martyr& Martyr:: operator=(const Martyr& obj) {
	Name = obj.Name; 
	Age = obj.Age;
	Location = obj.Location;
	DateOfDeath = obj.DateOfDeath; 
	Gender = obj.Gender;
	return *this;
}
	

void Martyr::setName(string param) { Name = param; }
string Martyr::getName() { return Name; }

void Martyr::setAge(string param) { Age = param; }
string Martyr::getAge() { return Age; }

void Martyr::setLocation(string param) { Location = param; }
string Martyr::getLocation() { return Location; }

void Martyr::setDateOfDeath(string param) { DateOfDeath = param; }
string Martyr::getDateOfDeath()const { return DateOfDeath; }

void Martyr::setGender(string param) { Gender = param; }
string Martyr::getGender() { return Gender; }

