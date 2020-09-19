#ifndef _FILEMANAGER_H
#define _FILEMANAGER_H

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

#define URI "data/Meteologica_vacante_ProgramadorC_20200901_datos.csv"
#define MAX_BUFFER 100

typedef enum{
	Header,
	Reading,
	End
} State;

typedef struct {
	FILE *file;
	State state;
	char newLine[MAX_BUFFER];
}FileManager;

FileManager initFile(FileManager fileManager);

FileManager manageFile(FileManager fileManager);

FileManager getData(FileManager fileManager);

FileManager skipData(FileManager fileManager);

#endif
