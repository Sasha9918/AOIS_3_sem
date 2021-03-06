// aois6.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

class movie {
	vector <string> name, producer;
	vector <int> key;
public:
	movie();
	~movie() {}//ф-и опр ключей, вставки, удаления, поиска
	void keyz();
	void search(string s);
	void insert(string a, string b);
	void del_one(string s);
	void show();
};

int main() {//поиск и удаление по ключам, а не по цифрам
	movie go;
	go.keyz();
	go.show();
	cout << "Trying to find a series \"Mr.Robot\"" << endl;
	go.search("Mr.Robot");
	cout << "Inserting a series \"Mr.Robot\"" << endl;
	go.insert("Mr.Robot", "Esmail");
	cout << "Trying to find a series \"Mr.Robot\"" << endl;
	go.search("Mr.Robot");
	go.show();
	cout << "Deleting the film \"Fight club\"" << endl;
	go.del_one("Fight_club");
	go.show();
	return 0;
}

movie::movie() {
	ifstream in("fp.txt");
	string a, b;
	if (!in.is_open()) {
		cout << "Error" << endl;
		return;
	}
	while (!in.eof()){
		in >> a >> b;
		name.push_back(a); producer.push_back(b);
	}
}

void movie::keyz() {
	string temp;
	char t;
	for (int i = 0; i < name.size(); i++) {
		int k = 0;
		temp = name[i];
		for (int j = 0; j < temp.size(); j++) {
			t = temp[j];
			k += int(t);
		}
		key.push_back(k);
	}
}

void movie::search(string s) {
	int k = 0;
	for (int j = 0; j < s.size(); j++)
		k += int(s[j]);
	bool is = false;
	for (int i = 0; i < key.size(); i++) {
		if (k == key[i]) {
			cout << name[i] << " - " << producer[i] << endl;
			is = true;
		}
	}
	if (!is)
		cout << "There is no such film" << endl;
}

void movie::insert(string a, string b) {
	int k = 0;
	name.push_back(a); producer.push_back(b);
	for (int j = 0; j < a.size(); j++) 
		k += int(a[j]);
	key.push_back(k);
	cout << "The element was inserted" << endl << endl;
}

void movie::del_one(string s) {
	int k = 0;
	for (int j = 0; j < s.size(); j++)
		k += int(s[j]);
	bool is = false;
	for (int i = 0; i < key.size(); i++) {
		if (k == key[i]) {
			name.erase(name.begin() + i); producer.erase(producer.begin() + i);
			is = true;
		}
	}
	if (!is)
		cout << "There is no such film" << endl;
}

void movie::show() {
	int n = 0;
	for (int i = 0; i < name.size(); i++)
		cout << n++ << ". " << name[i] << " - " << producer[i] << ". Key:" << key[i] << endl;
	cout << endl;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
