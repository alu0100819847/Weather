#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"Weather.h"

Weather createWeather(char inputData[]) {
	Weather weather;
	int counter = 0;
	char delim[] = ";";
	char *ptr = strtok(inputData, delim);
	while(ptr != NULL)
	{
		if(counter == 0) {
			strcpy(weather.fecha, ptr);
		}
		if(counter == 1) {
			strcpy(weather.ciudad, ptr);
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
		}
		ptr = strtok(NULL, delim);
		counter++;
	}
	return weather;	
}

void printWeather(Weather weather){
	printf("\n{'temperaturaMinima': %.2f, 'temperaturaMaxima': %.2f, 'precipitacion': %.2f}", weather.temperaturaMinima, weather.temperaturaMaxima, weather.precipitacion);
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

