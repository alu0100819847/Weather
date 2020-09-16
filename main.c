#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include <locale.h>

#include"FileManager.h"
#include"Weather.h"

bool checkParameters(int argc, char* argv[]) {
	if(argc != 4){
		fprintf(stderr, "Wrong Parameters\n Usage: weather[.exe] <City> <yyyy/mm/dd> <Celcius/Farenheit>\n");
		return false;
	}
	if(strcmp(argv[3], "Celcius") != 0 && strcmp(argv[3], "Farenheit") != 0){
		fprintf(stderr, "Wrong Temperature Scale\n Usage: weather[.exe] <City> <yyyy/mm/dd> <Celcius/Farenheit>\n");
		return false;	
	}
	return true;
}

int main(int argc, char *argv[]){
	char *locale = setlocale(LC_ALL, "");
	if(!checkParameters(argc, argv)){
		return 1;
	}
	FileManager fileManager;
	fileManager = initFile(fileManager);
	int search = parseDate(argv[2]);
	while(fileManager.state != End){
		fileManager = manageFile(fileManager);
		Weather weather = createWeather(fileManager.newLine);
		if(filterCity(weather.ciudad, argv[1]) && filterDate(search, weather.fecha)){
			weather = temperatureScale(weather, argv[3]);
			printWeather(weather);
		}
	}
	return 0;	
}




