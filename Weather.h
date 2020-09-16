
typedef struct {
	int fecha;
	char ciudad[40];
	float temperaturaMaxima;
	float temperaturaMinima;
	float precipitacion;
	float nubosidad;
}Weather;

Weather createWeather(char inputData[]);

void printWeather(Weather weather);

Weather temperatureScale(Weather weather, char* scale);

float celciusToFarenheit(float celcius);

char* checkWhitespace(char* string);

int parseDate(char* dateString);

bool filterDate(int date, int registered);

bool filterCity(char city[], char registered[]);
