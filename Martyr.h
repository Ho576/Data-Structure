#pragma once
#include <iostream>
#include <string>
using namespace std;

class Martyr {
private:
	string Name, Age, Location, DateOfDeath, Gender;
public:
	Martyr(string paramName="", string paramAge = "", string paramLocation = "", string paramDateOfDeath = "", string paramGender = "");
	Martyr(const Martyr &obj);
	~Martyr();
	Martyr& operator=(const Martyr& obj);

	void setName(string param);
	string getName();
	void setAge(string param);
	string getAge();
	void setLocation(string param);
	string getLocation();
	void setDateOfDeath(string param);
	string getDateOfDeath()const;
	void setGender(string param);
	string getGender();

	bool  operator>(const Martyr& other) const {
		return Name > other.Name;
	}
};
