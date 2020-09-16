#define MAX_JSON_SIZE 7
#include"Weather.h"

typedef struct {
	Weather weatherList[MAX_JSON_SIZE];
	int size;
} JsonManager; 

int manageData(char *argv[]);

JsonManager addWeather(Weather weather, JsonManager jsonManager);

void printJson(JsonManager jsonManager);
