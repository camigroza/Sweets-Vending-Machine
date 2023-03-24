#pragma once
#include "repository.h"
#include<map>
#include<vector>

class Service {
private:
	Repository repo;
	map<int, int> coins;

public:
	Service();
	Service(const Repository& r);
	Service(const Repository& r, const map<int, int> m);
	~Service() = default;

	void setCoins(map<int, int> m);
	Repository& getRepo();
	void addEntity(int cod, string nume, double pret);
	int removeEntity(int cod);
	int updateEntity(int cod_vechi, string nume_vechi, double pret_vechi,
		int cod_nou, string nume_nou, double pret_nou);
	vector<Entity> getAll();
	Service& operator=(const Service& s);

	map<int, int> getCoins();
	void addCoins(int value, int how_many);
	int removeCoins(int value, int how_many);

	/// <summary>
	/// Indica daca se poate da rest cu bancnotele disponibile
	/// </summary>
	/// <param name="rest"> restul care trebuie dat </param>
	/// <param name="values"> un dictionar (key: valoarea bancnotei, value: numarul de bancnote) </param>
	/// <returns> true, daca se poate da rest, false in caz contrar </returns>
	bool enoughMoneyToGiveBack(int rest, map<int, int>& values);

	vector<Entity> sortAscendentByPrice();
	vector<Entity> sortDescendentByPrice();

};