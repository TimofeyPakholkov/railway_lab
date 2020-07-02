#include <iostream>
#include <fstream>
#include "railway.hpp"

using namespace std;

int main() {
	int a;
	char dbname[20];
	cout << "Приветствую!";
	Start:
	cout << "Выберите дальнейшее действие:" << endl;
	cout << "1.Перейти к существующему хранилищу данных." << endl;
	cout << "2.Создать новое хранилище данных." << endl;
	cin >> a;
	switch(a) {
		case 1 : cout << "Введите наименование хранилища." << endl;
			cin >> dbname;
			if (fopen(dbname,"r")==NULL) {
				cout << "Данного хранилища не существует." << endl;
				goto Start;
			} break;
		case 2 : cout << "Придумайте и введите наименование хранилища." << endl;
                	cin >> dbname;
                	fopen(dbname,"w"); break;
	}
	Middle:
	cout << "Выберите дальнейшее действие." << endl;
	cout << "1.Просмотреть список Ж/Д билетов." << endl;
	cout << "2.Найти билеты по номеру." << endl;
	cout << "3.Найти билеты по пункту назначения." << endl;
	cout << "4.Найти билеты по стоимости." << endl;
	cout << "5.Добавить новый билет в список." << endl;
	cout << "6.Удалить существующий билет." << endl;
	cout << "7.Отредактировать билет." << endl;
	cin >> a;
	switch(a) {
		case 1 : look_list(dbname); break;
		case 2 : search_by_number(dbname); break;
		case 3 : search_by_way(dbname); break;
		case 4 : search_by_cost(dbname); break;
		case 5 : add_ticket(dbname); break;
		case 6 : delete_ticket(dbname); break;
		case 7 : edit_ticket(dbname); break;
	}
	cout << "Выберите дальнейшее действие." << endl;
	cout << "1.Вернуться в меню выбора базы данных." << endl;
	cout << "2.Вернуться в меню действий над выбранным файлом." << endl;
	cout << "3.Завершить работу." << endl;
	cin >> a;
	switch(a) {
		case 1 : goto Start; break;
		case 2 : goto Middle; break;
		case 3 : break;
	}
}
