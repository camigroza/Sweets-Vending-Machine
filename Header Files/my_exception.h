#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class MyException : public exception {
private:
	vector<string> erori;

public:
	MyException(vector<string> erori_)
	{
		for (int i = 0; i < erori_.size(); i++)
			this->erori.push_back(erori_[i]);
	}
	vector<string> getErori()
	{
		return this->erori;
	}
};