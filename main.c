#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
 
 
int main(int argc, char *argv[]){
	FILE *file;
	int c;
	char uri[] = "data/Meteologica_vacante_ProgramadorC_20200901_datos.csv";
	char input[200];
	file = fopen(uri, "rt");
	bool header = true;
	char counter = 0;
	while((c=fgetc(file))!=EOF){
		if(c=='\n'){
			if(!header){
				printf("\n%s", input);
			}
			header = false;
			memset(input,0,200);
			counter= 0;
		}
		else{
			input[counter] = c;
			counter += 1;
		}
	}
	printf("\n%s", input);
	fclose(file);
	return 0;
}
