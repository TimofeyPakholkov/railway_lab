#include <fstream>
#include <iostream>
#include <cstdio>
#include <cstring>
#include "railway.hpp"
using namespace std;

void look_list(char* dbname) {
        class railway rw;
	ifstream fp(dbname);
	cout << "Список билетов:\n" << "Путь\t" << "Номер\t" << "Цена" << endl;
        while(fp >> rw.way) {
		fp >> rw.number >> rw.cost;
		cout << rw.way << '\t' << rw.number << '\t' << rw.cost << endl;
	}
	fp.close();
}

void search_by_number(char* dbname) {
	class railway rw;
        ifstream fp(dbname);
        int a;
        cout << "Введите номер билета/билетов, которые хотите найти." << endl;
        cin >> a;
        while(fp >> rw.way) {
		fp >> rw.number >> rw.cost;
		if (rw.number==a) {
			cout << rw.way << '\n' << rw.cost << endl;
		}
	}
	fp.close();
}

void search_by_way(char* dbname) {
        class railway rw;
        ifstream fp(dbname);
        char str[100];
        cout << "Введите пункт назначения билета/билетов, который хотите найти." << endl;
        cin >> str;
        while(fp >> rw.way) {
		fp >> rw.number >> rw.cost;
                if (strcmp(str,rw.way)==0) {
                	cout << rw.number << '\n' << rw.cost << endl;
 		}
	}
	fp.close();
}

void search_by_cost(char* dbname) {
        class railway rw;
        ifstream fp(dbname);
        float j;
        cout << "Введите стоимость билета/билетов, который хотите найти." << endl;
        cin >> j;
        while(fp >> rw.way) {
        	fp >> rw.number >> rw.cost;
                if (rw.cost==j) {
                	cout << rw.way << '\n' << rw.number << endl;
                }
        }
	fp.close();
}

void add_ticket(char* dbname) {
        class railway rw;
        ofstream fp(dbname, ios::app);
        cout << "Для добавления билета к имеющемуся списку введите пункт назначения, номер билета и его стоимость:" << endl;
        cin >> rw.way >> rw.number >> rw.cost;
        fp << rw.way << '\n' << rw.number << '\n' << rw.cost << endl;
	cout << "Билет успешно добавлен." << endl;
	fp.close();
}

void delete_ticket(char* dbname) {
	int i,j,k;
	char str[100];
        k=0;
        ifstream fpc(dbname);
        cout << "Введите номер билета, который хотите удалить." << endl;
        cin >> j;
	while(!fpc.eof()) {
        	fpc >> str;
        	k++;
        }
	k=(k-1)/3;
	fpc.clear();
	fpc.seekg(0);
	railway* mass = new railway[k];
	for (i=0;i<(k);i++) {
		fpc >> mass[i].way >> mass[i].number >> mass[i].cost;
	}
        fpc.close();
        ofstream fpp(dbname);
        for (i=0;i<k;i++) {
                if (mass[i].number!=j) {
                        fpp << mass[i].way << '\n' << mass[i].number << '\n' << mass[i].cost << '\n';
                }
        }
        delete[] mass;
        fpp.close();
	cout << "Билет успешно удален." << endl;
}

void edit_ticket(char* dbname) {
	int i,j,k;
	bool p=0;
        char str[100];
        k=0;
        ifstream fpc(dbname);
        cout << "Введите номер билета, который хотите отредактировать." << endl;
        cin >> j;
        while(!fpc.eof()) {
                fpc >> str;
                k++;
        }
        k=(k-1)/3;
        fpc.clear();
        fpc.seekg(0);
        railway* mass = new railway[k];
        for (i=0;i<(k);i++) {
                fpc >> mass[i].way >> mass[i].number >> mass[i].cost;
        }
        fpc.close();
        ofstream fpp(dbname);
        for (i=0;i<k;i++) {
                if (mass[i].number!=j) {
                        fpp << mass[i].way << '\n' << mass[i].number << '\n' << mass[i].cost << '\n';
                }
		else {
			cout << "Введите новый путь, номер и стоимость билета." << endl;
			cin >> mass[i].way >> mass[i].number >> mass[i].cost;
			fpp << mass[i].way << '\n' << mass[i].number << '\n' << mass[i].cost << '\n';
			p=1;
		}
        }
	if (!p) {
		cout << "Билета с таким номером нет." << endl;
	}
        delete[] mass;
        fpp.close();
        cout << "Билет успешно отредактирован." << endl;
}
