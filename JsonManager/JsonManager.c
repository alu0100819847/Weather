#include"JsonManager.h"
#include"../FileManager/FileManager.h"

JsonManager addWeather(Weather weather, JsonManager jsonManager){
	jsonManager.weatherList[jsonManager.size] = weather;
	jsonManager.size +=1;
	return jsonManager;
}

int manageData(char *argv[]){
	FileManager fileManager;
	fileManager = initFile(fileManager);
	JsonManager jsonManager;
	if(fileManager.file == NULL){
		fprintf(stderr, "File Not Found\n");
		return 404;
	}
	jsonManager.size = 0;
	int search = parseDate(argv[2]);
	if(search == 0){
		fprintf(stderr, "Wrong Date\n Usage: weather[.exe] <City> <yyyy/mm/dd> <Celcius/Farenheit>\n");
		return 1;
	}
	while(fileManager.state != End){
		fileManager = manageFile(fileManager);
		Weather weather = createWeather(fileManager.newLine);
		if(filterCity(weather.city, argv[1]) && filterDate(search, weather.date) && jsonManager.size < MAX_JSON_SIZE){
			weather = temperatureScale(weather, argv[3]);
			jsonManager = addWeather(weather, jsonManager);
		}
	}
	printJson(jsonManager);
	return 0;
}


void printJson(JsonManager jsonManager){
	setlocale(LC_NUMERIC, "en_US.UTF-8");
	printf("[\n");
	int counter;
	for(counter = 0; counter< jsonManager.size; counter +=1){
		printWeather(jsonManager.weatherList[counter]);
	}
	printf("]\n");
}
