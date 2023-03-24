#pragma once
#include <string>
using namespace std;

class Entity {
private:
	int cod;
	string nume;
	double pret;

public:
	//constructori si destructor
	Entity();
	Entity(int c, const string n, double p);
	Entity(const Entity& e);
	~Entity() = default;

	//setteri
	void setCod(int c);
	void setNume(const string n);
	void setPret(double p);

	//getteri
	int getCod();
	string getNume();
	double getPret();

	//overload la operatori
	Entity& operator=(const Entity& e);
	bool operator==(const Entity& e);
	friend istream& operator>>(istream& is, Entity& e);
	friend ostream& operator<<(ostream& os, const Entity& e);
};