#include "repository_file.h"
#include <fstream>

RepoFile::RepoFile()
{
}

RepoFile::RepoFile(const string f_name)
{
	this->filename = f_name;
	ifstream f(f_name);
	while (!f.eof())
	{
		int cod;
		string nume;
		double pret;
		f >> cod >> nume >> pret;
		if (nume != "")
		{
			Entity e(cod, nume, pret);
			this->elems.push_back(e);
		}
	}
	f.close();
}

RepoFile::~RepoFile()
{
	fstream f(filename);
	if (f.is_open())
		f.close();
}

void RepoFile::addAndSave(const Entity& e)
{
	this->add(e);
	this->saveToFile();
}

void RepoFile::removeAndSave(const Entity& e)
{
	this->remove(e);
	this->saveToFile();
}

void RepoFile::updateAndSave(const Entity& veche, const Entity& noua)
{
	this->update(veche, noua);
	this->saveToFile();
}

void RepoFile::saveToFile()
{
	ofstream g(this->filename);
	for (Entity e : elems)
		g << e << endl;
	g.close();
}
