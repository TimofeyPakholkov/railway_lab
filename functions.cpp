#include <fstream>
#include <iostream>
#include <cstdio>
#include <cstring>
#include "railway.hpp"
using namespace std;

void look_list(char* dbname) {
        char str[100];
	ifstream fp;
	FILE * f;
        fp.open(dbname);
        while(1) {
                if (feof(f)!=0) {
                        break;
                }
                else {
                        fgets(str,100,f);
                        cin >> str;
		}
	}
	fp.close();
}

void search_by_number(char* dbname) {
	struct railway rw;
        ifstream fp;
	FILE * f;
        fp.open(dbname);
        int a;
        cout << "Введите номер билета/билетов, которые хотите найти.\n";
        cin >> a;
        while(1) {
                if (feof(f)!=0) {
                        break;
                }
                else {
                        fp >> rw.way;
			fp >> rw.number;
			fp >> rw.cost;
                        if (rw.number==a) {
                                cout << rw.way << "\t" << rw.cost << "\n";
                        }
                }
        }
	fp.close();
}

void search_by_way(char* dbname) {
        class railway rw;
        ifstream fp;
	FILE * f;
        fp.open(dbname);
        char str[100];
        cout << "Введите пункт назначения билета/билетов, который хотите найти.\n";
        cin >> str;
        while(1) {
                if (feof(f)!=0) {
                        break;
                }
                else {
                        fp >> rw.way;
			fp >> rw.number;
                        fp >> rw.cost;
                        if (strcmp(str,rw.way)==0) {
                                cout << rw.number << "\t" << rw.cost << "\n";
                        }
                }
        }
	fp.close();
}

void search_by_cost(char* dbname) {
        class railway rw;
        ifstream fp;
	FILE * f;
        fp.open(dbname);
        float j;
        cout << "Введите стоимость билета/билетов, который хотите найти.\n";
        cin >> j;
        while(1) {
                if (feof(f)!=0) {
                        break;
                }
                else {
                        fp >> rw.way;
                        fp >> rw.number;
                        fp >> rw.cost;
                        if (rw.cost==j) {
                                cout << rw.way << "\t" << rw.number << "\n";
                        }
                }
        }
	fp.close();
}

void add_ticket(char* dbname) {
        class railway rw;
        ofstream fp;
        fp.open(dbname);
        cout << "Для добавления билета к имеющемуся списку введите пункт назначения, номер билета и его стоимость: \n";
        cin >> rw.way >> rw.number >> rw.cost;
        fp << rw.way << "\n" << rw.number << "\n" << rw.cost << "\n";
	cout << "Билет успешно добавлен.\n";
	fp.close();
}

void delete_ticket(char* dbname) {
        class railway rw;
        class railway *mass;
        int i,k,j;
        k=0;
        ifstream fpc;
	FILE * fc;
        fpc.open(dbname);
        cout << "Введите номер билета, который хотите удалить.\n";
        cin >> j;
        while(1) {
                if (feof(fc)!=0) {
                        break;
                }
                else {
			mass = (struct railway *)malloc((k+1)*sizeof(rw));
                        // fscanf(fpc,"%s\n%d\n%f\n", mass[k].way,&(mass[k].number),&(mass[k].cost));
                        k++;
                }
        }
        fpc.close();
        ofstream fpp;
        fpp.open(dbname);
        for (i=0;i<k;i++) {
                if (mass[i].number!=k) {
                        // fprintf(fpp,"%s\n%d\n%f\n",mass[i].way,mass[i].number,mass[i].cost);
                }
        }
        free(mass);
        fpp.close();
	cout << "Билет успешно удален.\n";
}
