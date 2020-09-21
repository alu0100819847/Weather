#ifndef _FILEMANAGER_H
#define _FILEMANAGER_H

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

#define URI "data/Meteologica_vacante_ProgramadorC_20200901_datos.csv"
#define MAX_BUFFER 100

/* 
 * Enum: State
 * -----------
 * Define los distintos estados para la lectura de un fichero.
 *
 *  Header: Indica que se esta leyendo la cabecera.
 *  Reading: Indica que está leyendo los datos del fichero.
 *  End: Indica que se ha acabado de leer el fichero.
 *
 */

typedef enum{
	Header,
	Reading,
	End
} State;

/*
 * Struct: FileManager
 * -------------------
 * Recoge los datos para la lectura del fichero.
 *
 *  file: Es un puntero a la posición de lectura del fichero.
 *  state: Registra el estado de lectura en el que se encuentra el fichero.
 *  newLine: Contiene la ultima línea leida del fichero.
 *
 */
typedef struct {
	FILE *file;
	State state;
	char newLine[MAX_BUFFER];
}FileManager;

/* 
 * Function: initFile
 * ------------------
 * Inicializa la estructura Filemanager, habriendo el fichero e indicando el estado inicial "Header".
 *
 * fileManager: estructura FileManager con la que trabajará el programa
 *
 * returns: devuelve la estructura FileManager inicializada
 *
 */
FileManager initFile(FileManager fileManager);

/* 
 * Function: manageFile
 * --------------------
 * Se encarga del manejo del fichero actuando en función del estado del fileManager
 *
 * fileManager: estructura FileManager que está encargada de manejar el fichero.
 *
 * returns: devuelve la estructura FileManager actualizada.
 *
 */
FileManager manageFile(FileManager fileManager);

/* 
 * Function: getData
 * -----------------
 * Se encarga de extraer una nueva línea de datos del fichero.
 *
 * fileManager: estructura FileManager que está encargada de manejar el fichero.
 *
 * returns: devuelve la estructura FileManager actualizada. Contendrá una nueva línea extraida del fichero.
 *
 */
FileManager getData(FileManager fileManager);

/* 
 * Function
 * --------
 * Se encarga de pasar por una línea del fichero sin extraer su información.
 *
 * fileManager: estructura FileManager que está encargada de manejar el fichero.
 *
 * returns: devuelve la estructura FileManager actualizada. fileManager habrá saltado una línea del fichero. 
 *
 */
FileManager skipData(FileManager fileManager);

#endif
