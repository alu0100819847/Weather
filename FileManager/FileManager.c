#include"FileManager.h"

FileManager initFile(FileManager fileManager){
	fileManager.file = fopen(URI, "r");
	fileManager.state = Header;
	return fileManager;
}

FileManager manageFile(FileManager fileManager){
	memset(fileManager.newLine,0,MAX_BUFFER);
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
	int fileChar;
	int counter = 0;
	char checkBlank;
	fileChar=fgetc(fileManager.file);
	fileManager.newLine[counter] = fileChar;
	while(fileChar != EOF && fileChar!= '\n'){
		counter += 1;
		fileChar=fgetc(fileManager.file);
		if(fileChar == checkBlank && checkBlank == ';'){
			fileManager.newLine[counter] = '0';
			counter += 1;
		}
		if(fileChar == '.') {
			fileChar = ',';
		}
		fileManager.newLine[counter] = fileChar;

		checkBlank= fileChar;
		
	}
	if(fileChar == EOF){
		fileManager.state = End;
	}
	return fileManager;
}

FileManager skipData(FileManager fileManager){
	int fileChar;
	fileChar=fgetc(fileManager.file);
	while(fileChar != EOF && fileChar!= '\n'){
		fileChar=fgetc(fileManager.file);
	}
	if(fileChar == EOF){
		fileManager.state = End;
	}
	return fileManager;
}
