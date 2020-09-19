#ifndef _JSONMANAGER_H
#define _JSONMANAGER_H

#include<stdio.h>
#include <locale.h>

#include"Weather.h"

#define MAX_JSON_SIZE 7



typedef struct {
	Weather weatherList[MAX_JSON_SIZE];
	int size;
} JsonManager; 

int manageData(char *argv[]);

JsonManager addWeather(Weather weather, JsonManager jsonManager);

void printJson(JsonManager jsonManager);


#endif
