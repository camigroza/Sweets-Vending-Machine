#pragma once
#include "service.h"

class UI {
private:
	Service service;
	void adauga_produs();
	void sterge_produs();
	void modifica_produs();
	void afiseaza_produse();
	void afiseaza_bani();
	void achizitioneaza_produs();
	void sort_by_price();

public:
	UI();
	UI(const Service& s);
	~UI() = default;

	void runMenu();
};