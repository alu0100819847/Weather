#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include <locale.h>

#include"FileManager.h"
#include"Weather.h"
#include"Filter.h"

bool checkParameters(int argc) {
	if(argc != 4){
		fprintf(stderr, "Wrong Number of Parameters\n Usage: weather[.exe] <City> <yyyy/mm/dd> <Celcius/Farenheit>\n");
		return false;
	}
	return true;
}

int main(int argc, char *argv[]){
	char *locale = setlocale(LC_ALL, "");
	if(!checkParameters(argc)){
		return 1;
	}
	FileManager fileManager;
	fileManager = initFile(fileManager);
	while(fileManager.state != End){
		fileManager = manageFile(fileManager);
		Weather weather = createWeather(fileManager.newLine);
		if(filterCity(weather.ciudad, argv[1]) && filterDate(weather.fecha, argv[2])){
			weather = temperatureScale(weather, argv[3]);
			printWeather(weather);
			fileManager.state = End;
		}
	}
	return 0;	
}




