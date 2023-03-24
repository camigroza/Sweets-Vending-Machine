#pragma once
#include "repository.h"

class EntityValidator {
private:
	Entity entitate;

public:
	EntityValidator(const Entity& entitate_);
	~EntityValidator() = default;
	void valideaza();
};