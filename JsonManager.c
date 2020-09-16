#include<stdio.h>
#include <locale.h>

#include"JsonManager.h"
#include"FileManager.h"

JsonManager addWeather(Weather weather, JsonManager jsonManager){
	jsonManager.weatherList[jsonManager.size] = weather;
	jsonManager.size +=1;
	return jsonManager;
}

int manageData(char *argv[]){
	FileManager fileManager;
	fileManager = initFile(fileManager);
	JsonManager jsonManager;
	jsonManager.size = 0;
	int search = parseDate(argv[2]);
	while(fileManager.state != End){
		fileManager = manageFile(fileManager);
		Weather weather = createWeather(fileManager.newLine);
		if(filterCity(weather.ciudad, argv[1]) && filterDate(search, weather.fecha) && jsonManager.size < MAX_JSON_SIZE){
			weather = temperatureScale(weather, argv[3]);
			jsonManager = addWeather(weather, jsonManager);
		}
	}
	printJson(jsonManager);
	return 0;
}



void printJson(JsonManager jsonManager){
	struct lconv * lc = localeconv();
	lc->decimal_point = ".";
	printf("[\n");
	int counter;
	for(counter = 0; counter< jsonManager.size; counter +=1){
		printWeather(jsonManager.weatherList[counter]);
	}
	printf("]\n");
}
