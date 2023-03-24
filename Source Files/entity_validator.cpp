#include "entity_validator.h"
#include <vector>
#include "my_exception.h"
using namespace std;

EntityValidator::EntityValidator(const Entity& entitate_)
{
	this->entitate = entitate_;
}

void EntityValidator::valideaza()
{
	vector<string> erori;
	if (this->entitate.getNume() == "") erori.push_back("Numele produsului trebuie sa fie un string nenul!");
	if (this->entitate.getPret() <= 0) erori.push_back("Pretul produsului trebuie sa fie un numar strict pozitiv!");

	if (erori.size() != 0)
	{
		throw MyException(erori);
	}
}
