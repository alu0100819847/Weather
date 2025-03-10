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
			strcpy(weather.city, ptr);
			strcpy(weather.city, checkWhitespace(weather.city));
		}
		if(counter == 2) {
			weather.maxTemperature = atof(ptr);
		}
		if(counter == 3) {
			weather.minTemperature = atof(ptr);
		}
		if(counter == 4) {
			weather.precipitation = atof(ptr);
		}
		if(counter == 5) {
			weather.cloudiness = atof(ptr);
		}
		ptr = strtok(NULL, delim);
		counter += 1;
	}
	weather.date = parseDate(tempDate);
	return weather;	
}

void printWeather(Weather weather){
	struct tm* t;
	time_t time = weather.date;
	t = gmtime(&time);
	printf("{'fecha': '%.4d/%.2d/%.2d', 'temperaturaMinima': %.3f, 'temperaturaMaxima': %.3f, 'precipitacion': %.2f},\n" ,t->tm_year+1900,t->tm_mon+1, t->tm_mday, weather.minTemperature, weather.maxTemperature, weather.precipitation);
}

Weather temperatureScale(Weather weather, char* scale){
	if(strcmp("Farenheit", scale) == 0){
		weather.maxTemperature = celciusToFarenheit(weather.maxTemperature);
		weather.minTemperature = celciusToFarenheit(weather.minTemperature);
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
	t.tm_sec    = 1;
	t.tm_min    = 1;
	t.tm_hour   = 1;
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
	return checkValidDate(mktime(&t), t.tm_mday);
}

bool filterCity(char city[], char registered[]) {
	return strcmp(city, registered) == 0;
}

bool filterDate(int date, int registered) {
	return difftime(date, registered) <= 0;
}

int checkValidDate(int time, int day){
	struct tm* t;
	time_t time_structure = time;
	t = gmtime(&time_structure);
	if(t->tm_mday == day){
		return time;
	}
	return 0;
}

