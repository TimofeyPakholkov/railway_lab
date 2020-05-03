#include <iostream>
#include <fstream>
#include "railway.hpp"

using namespace std;

int main() {
	int a;
	char dbname[20];
	cout << "Приветствую!";
	Start:
	cout << "Выберите дальнейшее действие:\n";
	cout << "1.Перейти к существующему хранилищу данных.\n";
	cout << "2.Создать новое хранилище данных.\n";
	cin >> a;
	switch(a) {
		case 1 : cout << "Введите наименование хранилища.\n";
			cin >> dbname;
			if (fopen(dbname,"r")==NULL) {
				cout << "Данного хранилища не существует.\n";
				goto Start;
			} break;
		case 2 : cout << "Придумайте и введите наименование хранилища.\n";
                	cin >> dbname;
                	fopen(dbname,"w"); break;
	}
	Middle:
	cout << "Выберите дальнейшее действие.\n";
	cout << "1.Просмотреть список Ж/Д билетов.\n";
	cout << "2.Найти билеты по номеру.\n";
	cout << "3.Найти билеты по пункту назначения.\n";
	cout << "4.Найти билеты по стоимости.\n";
	cout << "5.Добавить новый билет в список.\n";
	cout << "6.Удалить существующий билет.\n";
	cin >> a;
	switch(a) {
		case 1 : look_list(dbname); break;
		case 2 : search_by_number(dbname); break;
		case 3 : search_by_way(dbname); break;
		case 4 : search_by_cost(dbname); break;
		case 5 : add_ticket(dbname); break;
		case 6 : delete_ticket(dbname); break;
	}
	cout << "Выберите дальнейшее действие.\n";
	cout << "1.Вернуться в меню выбора базы данных.\n";
	cout << "2.Вернуться в меню действий над выбранным файлом.\n";
	cout << "3.Завершить работу.\n";
	cin >> a;
	switch(a) {
		case 1 : goto Start; break;
		case 2 : goto Middle; break;
		case 3 : break;
	}
}
