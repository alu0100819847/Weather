
typedef struct {
	char fecha[12];
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

char* checkWhitespace(char* srting);
