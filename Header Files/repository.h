#pragma once
#include "entity.h"
#include <vector>
using namespace std;

class Repository {
protected:
	vector<Entity> elems;

public:
	Repository();
	Repository(const Repository& r);
	~Repository() = default;

	Repository& operator=(const Repository& r);
	bool operator==(const Repository& r);

	int getSize();
	vector<Entity> getAll();

	//operatii CRUD
	void add(const Entity& e);
	int remove(const Entity& e);
	int update(const Entity& veche, const Entity& noua);

	/// <summary>
	/// Indica pozitia unei entitati
	/// </summary>
	/// <param name="e"> entitatea cautata </param>
	/// <returns> pozitia entitatii 'e' in vector daca exista, altfel -1 </returns>
	int search(const Entity& e);

	/// <summary>
	/// Indica daca exista o entitate cu un anumit cod
	/// </summary>
	/// <param name="_cod"> codul entitatii de cautat </param>
	/// <returns> true, daca exista o entitate cu codul dat, false in caz contrar </returns>
	bool searchByCode(int _cod);

	/// <summary>
	/// Indica entitatea cu un anumit cod
	/// </summary>
	/// <param name="_cod"> codul entitatii de cautat </param>
	/// <returns> entitatea cu codul dat </returns>
	Entity& findByCode(int _cod);
};