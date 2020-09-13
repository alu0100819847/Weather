#include<stdbool.h>
#include<stdio.h>
#include<string.h>
#include<wchar.h>
#define URI "data/Meteologica_vacante_ProgramadorC_20200901_datos.csv"

typedef enum{
	Header,
	Reading,
	End
} State;

typedef struct {
	FILE *file;
	State state;
	char newLine[100];
}FileManager;

FileManager initFile(FileManager fileManager);

FileManager manageFile(FileManager fileManager);

FileManager getData(FileManager fileManager);

FileManager skipData(FileManager fileManager);
