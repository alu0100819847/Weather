#include<stdlib.h>
#include"FileManager.h"

FileManager initFile(FileManager fileManager){
	fileManager.file = fopen(URI, "r");
	fileManager.state = Header;
	return fileManager;
}

FileManager manageFile(FileManager fileManager){
	memset(fileManager.newLine,0,200);
	if(fileManager.state == Header){
		fileManager = skipData(fileManager);
		fileManager.state = Reading;
	}
	if(fileManager.state == Reading){
		fileManager = getData(fileManager);
	}
	if(fileManager.state == End){
		fclose(fileManager.file);
	}
	return fileManager;
}

FileManager getData(FileManager fileManager){
	int c;
	int counter = 0;
	c=fgetc(fileManager.file);
	fileManager.newLine[counter] = c;
	while(c != EOF && c!= '\n'){
		counter += 1;
		c=fgetc(fileManager.file);
		fileManager.newLine[counter] = c;
	}
	if(c == EOF){
		fileManager.state = End;
	}
	return fileManager;
}

FileManager skipData(FileManager fileManager){
	int c;
	c=fgetc(fileManager.file);
	while(c != EOF && c!= '\n'){
		c=fgetc(fileManager.file);
	}
	if(c == EOF){
		fileManager.state = End;
	}
	return fileManager;
}

