#include <iostream>
#include <fstream>
using namespace std;

class railway {
	public:
	char way[20];
	int number;
	float cost;

	friend ostream& operator<< (ostream &out, railway &rw);
        friend istream& operator>> (istream &in, railway &rw);
        friend ofstream& operator<< (ofstream &fout, railway &rw);
        friend ifstream& operator>> (ifstream &fin, railway &rw);
};
	void look_list(char* dbname);
	void search_by_number(char* dbname);
	void search_by_way(char* dbname);
	void search_by_cost(char* dbname);
	void add_ticket(char* dbname);
	void delete_ticket(char* dbname);
	void edit_ticket(char* dbname);
