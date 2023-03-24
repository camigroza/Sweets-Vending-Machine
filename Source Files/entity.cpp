#include "entity.h"
#include <iostream>

Entity::Entity()
{
	this->cod = 0;
	this->nume = "";
	this->pret = 0;
}

Entity::Entity(int c, const string n, double p)
{
	this->cod = c;
	this->setNume(n);
	this->pret = p;
}

Entity::Entity(const Entity& e)
{
	this->cod = e.cod;
	this->setNume(e.nume);
	this->pret = e.pret;
}

void Entity::setCod(int c)
{
	this->cod = c;
}

void Entity::setNume(const string n)
{
	this->nume = n;
}

void Entity::setPret(double p)
{
	this->pret = p;
}

int Entity::getCod()
{
	return this->cod;
}

string Entity::getNume()
{
	return this->nume;
}

double Entity::getPret()
{
	return this->pret;
}

Entity& Entity::operator=(const Entity& e)
{
	if (this != &e)
	{
		this->cod = e.cod;
		this->nume = e.nume;
		this->pret = e.pret;
	}
	return *this;
}

bool Entity::operator==(const Entity& e)
{
	return this->cod == e.cod && this->nume == e.nume && this->pret == e.pret;
}

istream& operator>>(istream& is, Entity& e)
{
	cout << "Dati codul: ";
	int cod;
	is >> cod;
	cout << "Dati numele: ";
	string nume;
	is >> nume;
	cout << "Dati pretul: ";
	double pret;
	is >> pret;
	e.setCod(cod);
	e.setNume(nume);
	e.setPret(pret);
	return is;
}

ostream& operator<<(ostream& os, const Entity& e)
{
	os << "Cod: " << e.cod << "; Nume: " << e.nume << "; Pret: " << e.pret;
	return os;
}
