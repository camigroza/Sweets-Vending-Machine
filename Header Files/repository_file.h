#pragma once
#include "repository.h"

class RepoFile : public Repository {
private:
	string filename;

public:
	RepoFile();
	RepoFile(const string f_name);
	~RepoFile();

	void addAndSave(const Entity& e);
	void removeAndSave(const Entity& e);
	void updateAndSave(const Entity& veche, const Entity& noua);

	void saveToFile();
};