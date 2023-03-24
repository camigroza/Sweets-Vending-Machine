#include "service.h"
#include <algorithm>
#include "entity_validator.h"

Service::Service()
{
}

Service::Service(const Repository& r)
{
	this->repo = r;
}

Service::Service(const Repository& r, const map<int, int> m)
{
	this->repo = r;
	this->coins = m;
}

void Service::setCoins(map<int, int> m)
{
	this->coins = m;
}

Repository& Service::getRepo()
{
	return this->repo;
}

void Service::addEntity(int cod, string nume, double pret)
{
	Entity e(cod, nume, pret);
	this->repo.add(e);
}

int Service::removeEntity(int cod)
{
	if (this->repo.searchByCode(cod) == false)
		throw string("Nu exista nici un produs cu codul dat!\n");
	Entity e = this->repo.findByCode(cod);
	return this->repo.remove(e);
}

int Service::updateEntity(int cod_vechi, string nume_vechi, double pret_vechi, int cod_nou, string nume_nou, double pret_nou)
{
	Entity ev(cod_vechi, nume_vechi, pret_vechi);
	Entity en(cod_nou, nume_nou, pret_nou);
	EntityValidator validator(en);
	validator.valideaza();
	return this->repo.update(ev, en);
}

vector<Entity> Service::getAll()
{
	return this->repo.getAll();
}

Service& Service::operator=(const Service& s)
{
	if (this != &s)
	{
		this->repo = s.repo;
		this->coins = s.coins;
	}
	return *this;
}

map<int, int> Service::getCoins()
{
	return this->coins;
}

void Service::addCoins(int value, int how_many)
{
	map<int, int>::iterator it;
	it = coins.find(value);
	if (it != coins.end())
		it->second += how_many;
	else coins.insert(pair<int, int>(value, how_many));
}

int Service::removeCoins(int value, int how_many)
{
	map<int, int>::iterator it;
	it = coins.find(value);
	if (it != coins.end())
	{
		if (it->second < how_many) return 0;
		it->second -= how_many;
	}
	return 0;
}

bool Service::enoughMoneyToGiveBack(int rest, map<int, int>& values)
{
	int coin, how_many;
	int x;
	if (rest == 0) return true;
	map<int, int>::reverse_iterator it;
	for (it = this->coins.rbegin(); it != this->coins.rend(); ++it)
	{
		coin = it->first;
		how_many = it->second;
		if (coin <= rest)
		{
			x = rest / coin;
			if (x > how_many) x = how_many;
			values.insert(pair<int, int>(coin, x));
			rest -= coin * x;
		}
	}
	if (rest == 0) return true;
	else
	{
		values.clear();
		return false;
	}
}

bool ascendentPrice(Entity& e1, Entity& e2)
{
	return e1.getPret() < e2.getPret();
}

bool descendentPrice(Entity& e1, Entity& e2)
{
	return e1.getPret() > e2.getPret();
}

vector<Entity> Service::sortAscendentByPrice()
{
	vector<Entity> all = this->getAll();
	std::sort(all.begin(), all.end(), ascendentPrice);
	return all;
}

vector<Entity> Service::sortDescendentByPrice()
{
	vector<Entity> all = this->getAll();
	std::sort(all.begin(), all.end(), descendentPrice);
	return all;
}
