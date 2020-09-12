#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#include<string.h>
#include"Weather.h"
 
int main(int argc, char *argv[]){
	FILE *file;
	int c;
	char uri[] = "data/Meteologica_vacante_ProgramadorC_20200901_datos.csv";
	char input[200];
	Weather weather;
	file = fopen(uri, "rt");
	bool header = true;
	char counter = 0;
	while((c=fgetc(file))!=EOF){
		if(c=='\n'){
			if(!header){
				weather = createWeather(input);
				printWeather(weather);
			}
			header = false;
			memset(input,0,200);
			counter= 0;
		}
		else{
			if(c==','){
				c = '.';
			}
			input[counter] = c;
			counter += 1;
		}
	}
	weather = createWeather(input);
	printWeather(weather);
	fclose(file);
	return 0;
}
