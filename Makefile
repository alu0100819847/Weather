OBJETOS=main.o ./FileManager/FileManager.o ./JsonManager/JsonManager.o ./Weather/Weather.o
CFLAGS=-I./FileManager -I./JsonManager -I./Weather

weather: $(OBJETOS)
	cc $(OBJETOS) -o weather
	
./JsonManager/JsonManager.o: ./JsonManager/JsonManager.c ./Weather/Weather.h ./FileManager/FileManager.h

./FileManager/FileManager.o: ./FileManager/FileManager.c

./Weather/Weather.o: ./Weather/Weather.c

main.o: main.c ./JsonManager/JsonManager.h
