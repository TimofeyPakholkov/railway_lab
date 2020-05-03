#include <iostream>
#include <fstream>

class railway {
	public:
	char way[20];
	int number;
	float cost;
};

void look_list(char* dbname);
void search_by_number(char* dbname);
void search_by_way(char* dbname);
void search_by_cost(char* dbname);
void add_ticket(char* dbname);
void delete_ticket(char* dbname);

