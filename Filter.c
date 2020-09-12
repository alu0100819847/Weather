#include<stdbool.h>
#include<string.h>
#include"Filter.h"


bool filterCity(char city[], char registered[]){
	return strcmp(city, registered) == 0;
}

bool filterDate(char date[], char registered[]){
	return strcmp(date, registered) == 0;
}
