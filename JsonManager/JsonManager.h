#ifndef _JSONMANAGER_H
#define _JSONMANAGER_H

#include<stdio.h>
#include <locale.h>

#include"../Weather/Weather.h"

#define MAX_JSON_SIZE 7


/* 
 * Struct: JsonManager
 * --------------------
 * Define la lista que almacenará los datos de los distintos días. 
 *
 *   weatherList: Array que contendrá todos los datos que deseamos devolver. Provisionalmente se elige un tamaño de 7 elementos para esta lista.
 *   size: Número de elementos que tiene guardados la lista.
 *
 */
typedef struct {
	Weather weatherList[MAX_JSON_SIZE];
	int size;
} JsonManager; 

/* 
 * Function: manageData
 * --------------------
 * Controla el funcionamiento principal del procesado del fichero, declarando las estructuras principales y encargandose de 
 * recopilar cada linea que coincida con los parámetros de entrada.
 *
 *   *argv[]: contiene los parametros de entrada del programa, conteniendo la ciudad, fecha y escala de temperatura con los que trabajaremos.
 *
 * returns. 
 *		404. File Not Found: No se ha encontrado el fichero. 
 *		  1. Wrong Date: Fecha incorrecta.
 *		  0. OK.
 *
 */
int manageData(char *argv[]);

/* 
 * Function: addWeather
 * --------------------
 * Incluye un nuevo dato Weather a la estructura JsonManager
 *
 *   weather. Nuevo elemento a incorporar a jsonManager.
 *   jsonManager. Estructura Jsonmanager con la que estamos registrando los datos deseados.
 * 
 * returns. Devuelve una estructura Jsonmanager actualizada con los nuevos datos.
 */
JsonManager addWeather(Weather weather, JsonManager jsonManager);

/* 
 * Function printJson
 * ------------------
 * Se encarga de mostrar por pantalla los datos incluidos dentro de la estructura Jsonmanager
 *
 *   jsonManager. Estructura JsonManager que será mostrada por pantalla.
 *
 */
void printJson(JsonManager jsonManager);


#endif
