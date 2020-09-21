#ifndef _WEATHER_H
#define _WEATHER_H

#include<stdbool.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

/* 
 * Struct Weather 
 * --------------
 * Se encarga de registrar los datos del clima ( fecha, ciudad, temperatura maxima, temperatura minima, precipitaciones y humedad)
 * 
 *   date: Registra la fecha en segundos.
 *   city: Registra el nombre de la ciudad.
 *   maxTemperature. Registra la temperatura maxima.
 *   minTemperature. Registra la temperatura minima.
 *   precipitation. Registra las precipitaciones.
 *   cloudiness. Registra la nubosidad.
 *   
 */
 
typedef struct {
	int date;
	char city[40];
	float maxTemperature;
	float minTemperature;
	float precipitation;
	float cloudiness;
}Weather;

/* 
 * Function: createWeather
 * -----------------------
 * A partir de una cadena de caracteres, parsea la información para construir una estructura Weather con datos operables.
 *
 *   inputData: Cadana de caracteres que contiene la información que deseamos parsear.
 *   
 * returns. Devuelve una estrucutra Weather con datos operables.
 *
 */
Weather createWeather(char inputData[]);

/* Function: printWeather 
 * --------------------
 * Muestra por pantalla los datos deseados de una estructura Weather.
 *
 *  {'fecha': 'yyyy/mm/dd', 'temperaturaMinima': xx.xxx, 'temperaturaMaxima': xx.xxx, 'precipitacion': x.xx}
 *  
 *
 */
void printWeather(Weather weather);

/* 
 * Function: temperatureScale 
 * --------------------------
 * Comprueba que la escala de temperatura coincide con la señalada.
 *
 *  weather. Estructura weather con los datos con los que estamos trabajando.
 *  scale. Cadena de caracteres que contiene la escala que queremos. Por defecto la escala es Celcius.
 *   
 *
 * returns. Devuelve una estructura Weather con la escala de temperatura actualizada.
 */
Weather temperatureScale(Weather weather, char* scale);

/* 
 * Function: celciusToFarenheit 
 * ----------------------------
 * Realiza la transformación de temperatura entre la escala Celcius y la Farenheit
 *
 *  celcius. Temperatura en escala Celcius 
 *   
 * returns. Devuelve la temperatura en escala Farenheit.
 *
 */
float celciusToFarenheit(float celcius);

/* 
 * Function: checkWhitespace 
 * -------------------------
 * Comprueba que no exista espacio al inicio y al final de una cadena.
 * Ej. char* string = "  Madrid  "
 *    checkWhitespace(string) -> return -> "Madrid"
 *   
 *   string. Cadena que deseamos comprobar si tiene espacios en blanco.
 *
 * returns. Devuelve la cadena sin espacios en blanco al comienzo y al final.
 */
char* checkWhitespace(char* string);

/* 
 *  Function: parseDate
 * --------------------
 * Parsea una cadena de caracteres devolviendo la fecha en segundos.
 * Hace uso de checkValidDate para comprobar si la fecha introducida es correcta.
 *
 *   dateString. Carena de caracteres que contiene la fecha.
 *   
 * returns. Devuelve la fecha en segundos desde el inicio del tiempo Unix.
 *	    Fecha invalida. Devolverá 0.
 *
 */
int parseDate(char* dateString);

/* 
 * Function filterDate 
 * -------------------
 * Comprueba si una fecha es posterior a otra.
 *
 *   date. Fecha utilizada como condición. Se devolverán "true" para todas aquellas iguales o a continuación a esta.
 *   registered. Fecha leida del fichero. Si es igual o posterior a date, se devolvera "true"
 *   
 * return. Devuelve un tipo bool verdadero si la fecha date pasa el filtro y false si no lo pasa.
 *
 */
bool filterDate(int date, int registered);

/* 
 *  Function: filterCity
 * ---------------------
 * Comprueba si las dos ciudades coinciden.
 * 
 *   city. Ciudad utilizada como condición.
 *   registered. Ciudad leida del fichero.
 *
 * returns. Si ambas cadenas coinciden, devuelve true. En caso contrario, devuelve false.   
 *
 */
bool filterCity(char city[], char registered[]);

/* 
 * Function checkValidDate
 * ------------------------
 * Comprueba si una fecha es válida.
 *
 *   time. Contiene la fecha a comprobar en segundos desde el principio del tiempo Unix. 
 *   day. Contiene el dia del mes que se ha guardado previo a la transformación al formato Unix.
 *
 * returns. Si al recuperar el formato inicial de la fecha, esta es distinta a la original, devuelve 0.
 *	    En caso de que al recuperar al formato inicial la fecha coincida, devuelve el parámetro de entrada time.
 *
 */
int checkValidDate(int time, int day);
#endif
