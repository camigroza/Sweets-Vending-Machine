#include <iostream>
#include "entity.h"
#include "repository.h"
#include "tests.h"
#include "service.h"
#include "user_interface.h"
using namespace std;

int main()
{
	allTests();
	Repository repo;
	Service service(repo);
	UI ui(service);
	ui.runMenu();

	return 0;
}