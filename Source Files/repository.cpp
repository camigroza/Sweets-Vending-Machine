#include "repository.h"
#include "entity_validator.h"

Repository::Repository()
{
}

Repository::Repository(const Repository& r)
{
	this->elems = r.elems;
}

Repository& Repository::operator=(const Repository& r)
{
	if (this != &r)
		this->elems = r.elems;
	return *this;
}

bool Repository::operator==(const Repository& r)
{
	for (int i = 0; i < this->getSize(); i++)
		if (!(this->elems[i] == r.elems[i])) return false;
	return true;
}

int Repository::getSize()
{
	return (int)this->elems.size();
}

vector<Entity> Repository::getAll()
{
	return this->elems;
}

void Repository::add(const Entity& e)
{
	EntityValidator validator(e); 
	validator.valideaza();
	this->elems.push_back(e);
}

int Repository::remove(const Entity& e)
{
	vector<Entity>::iterator it = std::find(elems.begin(), elems.end(), e);
	if (it != elems.end())
	{
		elems.erase(it);
		return 1;
	}
	return 0;
}

int Repository::update(const Entity& veche, const Entity& noua)
{
	vector<Entity>::iterator it = std::find(elems.begin(), elems.end(), veche);
	if (it != elems.end())
	{
		*it = noua;
		return 1;
	}
	return 0;
}

int Repository::search(const Entity& e)
{
	for (int i = 0; i < elems.size(); i++)
		if (elems[i] == e) return i;
	return -1;
}

bool Repository::searchByCode(int _cod)
{
	for (Entity& crt : elems)
		if (crt.getCod() == _cod) return true;
	return false;
}

Entity& Repository::findByCode(int _cod)
{
	for (Entity& e : elems)
		if (e.getCod() == _cod) return e;
}