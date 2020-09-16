#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include <locale.h>
#include<time.h>
#include"Weather.h"

Weather createWeather(char inputData[]) {
	Weather weather;
	int counter = 0;
	char delim[] = ";";
	char *ptr = strtok(inputData, delim);
	char tempDate[12];
	while(ptr != NULL){
		if(counter == 0) {
			strcpy(tempDate, ptr);
		}
		if(counter == 1) {
			strcpy(weather.ciudad, ptr);
			strcpy(weather.ciudad, checkWhitespace(weather.ciudad));
		}
		if(counter == 2) {
			weather.temperaturaMaxima = atof(ptr);
		}
		if(counter == 3) {
			weather.temperaturaMinima = atof(ptr);
		}
		if(counter == 4) {
			weather.precipitacion = atof(ptr);
		}
		if(counter == 5) {
			weather.nubosidad = atof(ptr);
			weather.fecha = parseDate(tempDate);
		}
		ptr = strtok(NULL, delim);
		counter += 1;
	}
	return weather;	
}

void printWeather(Weather weather){
	struct tm* t;
	time_t time = weather.fecha;
	t = gmtime(&time);
	printf("{'fecha': '%.4d/%.2d/%.2d', 'temperaturaMinima': %.3f, 'temperaturaMaxima': %.3f, 'precipitacion': %.2f},\n" ,t->tm_year+1900,t->tm_mon, t->tm_mday, weather.temperaturaMinima, weather.temperaturaMaxima, weather.precipitacion);
}

Weather temperatureScale(Weather weather, char* scale){
	if(strcmp("Farenheit", scale) == 0){
		weather.temperaturaMaxima = celciusToFarenheit(weather.temperaturaMaxima);
		weather.temperaturaMinima = celciusToFarenheit(weather.temperaturaMinima);
	}
	return weather;
}

float celciusToFarenheit(float celcius){
	return celcius*(9/5)+32;	
}

char* checkWhitespace(char* string){
	while(string[0] == ' '){
		string += 1;
	}
	int size = strlen(string) -1;
	while(string[size] == ' '){
		string[size] = '\0';
		size -= 1;
	}
	return string;
}

int parseDate(char* dateString){
	struct tm t;
	t.tm_sec    = 0;
	t.tm_min    = 0;
	t.tm_hour   = 0;
	int counter = 0;
	char delim[] = "/";
	char *ptr = strtok(dateString, delim);
	while(ptr != NULL){
		if(counter == 0) {
			t.tm_year   = atoi(ptr) - 1900;
		}
		if(counter == 1) {
			t.tm_mon    = atoi(ptr)-1;
		}
		if(counter == 2) {
			t.tm_mday   = atoi(ptr);
		}
		counter += 1;
		ptr = strtok(NULL, delim);
	}
	return mktime(&t);
}

bool filterCity(char city[], char registered[]) {
	return strcmp(city, registered) == 0;
}

bool filterDate(int date, int registered) {
	return difftime(date, registered) <= 0;
}


/*
				struct tm* t;
				t = gmtime(&i);
				printf("\n%d/%d/%d",t->tm_year+1900,t->tm_mon, t->tm_mday);
*/
