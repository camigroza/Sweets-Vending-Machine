#include "entity.h"
#include "tests.h"
#include <assert.h>
#include <string.h>
#include <iostream>
#include "repository.h"
#include "repository_file.h"
#include "service.h"
#include <fstream>
using namespace std;

void test_entity()
{
	Entity e1;
	e1.setCod(123);
	e1.setNume("aaa");
	e1.setPret(10);
	assert(e1.getCod() == 123);
	assert(e1.getNume() == "aaa");
	assert(e1.getPret() == 10);

	Entity e2(456, "bbb", 20);
	assert(e2.getCod() == 456);
	assert(e2.getNume() == "bbb");
	assert(e2.getPret() == 20);

	Entity e3(e1);
	assert(e3 == e1);
	e3 = e2;
	assert(!(e3 == e1));
	assert(e3 == e2);
}

void test_repository()
{
	Entity e1(123, "aaa", 10);
	Entity e2(456, "bbb", 20);
	Entity e3(789, "ccc", 30);
	Repository r1;
	r1.add(e1);
	r1.add(e2);
	assert(r1.findByCode(123) == e1);
	assert(r1.findByCode(456) == e2);
	assert(r1.searchByCode(123) == true);
	assert(r1.searchByCode(456) == true);
	assert(r1.searchByCode(777) == false);
	assert(r1.getAll()[0] == e1);
	assert(r1.getAll()[1] == e2);
	assert(r1.search(e1) == 0);
	assert(r1.search(e2) == 1);
	assert(r1.search(e3) == -1);
	r1.add(e3);
	assert(r1.searchByCode(789) == true);
	assert(r1.search(e3) == 2);
	Repository r2(r1);
	assert(r1 == r2);
	Repository r3;
	r3 = r1;
	assert(r3 == r1);
	r1.remove(e1);
	assert(r1.search(e1) == -1);
	assert(r1.search(e2) == 0);
	assert(r1.search(e3) == 1);
	r1.update(e3, e1);
	assert(r1.search(e2) == 0);
	assert(r1.search(e3) == -1);
	assert(r1.search(e1) == 1);
}

void test_service()
{
	Entity e1(123, "aaa", 10);
	Entity e2(456, "bbb", 20);
	Entity e3(789, "ccc", 30);
	Repository r1;
	r1.add(e1);
	Service s1(r1);
	assert(s1.getRepo() == r1);
	Service s2 = s1;
	assert(s2.getRepo() == s1.getRepo());
	s1.addEntity(456, "bbb", 20);
	s1.addEntity(789, "ccc", 30);
	assert(s1.getAll().size() == 3);
	assert(s1.getAll()[0] == e1);
	assert(s1.getAll()[1] == e2);
	assert(s1.getAll()[2] == e3);
	s1.removeEntity(123);
	assert(s1.getAll().size() == 2);
	s1.updateEntity(456, "bbb", 20, 123, "aaa", 10);
	assert(s1.getAll()[0] == e1);

	map<int, int> m;
	m.insert(pair<int, int>(10, 10));
	m.insert(pair<int, int>(50, 2));
	m.insert(pair<int, int>(5, 20));
	vector<int> x;
	Service s3(r1, m);
	assert(s3.getCoins() == m);
	assert(s3.getCoins()[10] = 10);
	assert(s3.getCoins()[50] = 2);
	assert(s3.getCoins()[5] = 20);
	s3.addCoins(10, 2);
	assert(s3.getCoins()[10] == 12);
	s3.addCoins(1, 100);
	assert(s3.getCoins()[1] == 100);
	s3.removeCoins(1, 100);
	assert(s3.getCoins()[1] == 0);
	s3.removeCoins(10, 90);
	assert(s3.getCoins()[10] == 12);

	map<int, int> mm;
	map<int, int> M;
	mm.insert(pair<int, int>(10, 1));
	mm.insert(pair<int, int>(50, 2));
	mm.insert(pair<int, int>(5, 2));
	Repository rr;
	Service ss(rr, mm);
	assert(ss.enoughMoneyToGiveBack(2, M) == false);
	assert(ss.enoughMoneyToGiveBack(10, M) == true);
	assert(M[10] == 1);
	assert(ss.enoughMoneyToGiveBack(20, M) == true);
	assert(M[10] == 1);
	assert(M[5] == 2);
	assert(ss.enoughMoneyToGiveBack(22, M) == false);
	assert(ss.enoughMoneyToGiveBack(0, M) == true);
	assert(M.size() == 0);
	assert(ss.enoughMoneyToGiveBack(50, M) == true);
	assert(M[50] == 1);
	assert(ss.enoughMoneyToGiveBack(55, M) == true);
	assert(M[50] == 1);
	assert(M[5] == 1);

	Entity e11(123, "aaa", 10);
	Entity e22(456, "bbb", 20);
	Entity e33(789, "ccc", 30);
	Repository r11;
	r11.add(e11);
	r11.add(e22);
	r11.add(e33);
	Service s11(r11);
	assert(s11.sortAscendentByPrice()[0] == e11);
	assert(s11.sortAscendentByPrice()[1] == e22);
	assert(s11.sortAscendentByPrice()[2] == e33);
	assert(s11.sortDescendentByPrice()[0] == e33);
	assert(s11.sortDescendentByPrice()[1] == e22);
	assert(s11.sortDescendentByPrice()[2] == e11);
}

void test_repo_file()
{
	fstream f;
	f.open("test_produse.txt", ios::out);

	Entity e1(123, "aaa", 10);
	Entity e2(456, "bbb", 20);
	RepoFile rf("test_produse.txt");
	rf.addAndSave(e1);
	rf.addAndSave(e2);
	assert(rf.getSize() == 2);
	assert(rf.search(e1) == 0);
	assert(rf.search(e2) == 1);
	rf.removeAndSave(e1);
	assert(rf.search(e1) == -1);
	rf.updateAndSave(e2, e1);
	assert(rf.search(e1) == 0);
}

void allTests()
{
	test_entity();
	test_repository();
	test_service();
	test_repo_file();
	cout << "Toate testele au trecut cu succes!\n";
}