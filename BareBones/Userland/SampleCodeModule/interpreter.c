#include <stdint.h>
#define TRUE 1
#define FALSE 0
/*TODO*/
/*para mi esta mal, hay que hacer algo para que espere a que se vayan introdujendo las letras*/
/*Duda con los int y uint64 poronga*/
void scanf(char* buffer){
	int i=0;
	char* source;
	source =(char*) read();
	while(source[i]!='/n'){
		buffer[i] = source[i];
		i++;
	}
	return;
}


void inputInterpreter(char* message){
	if(stringCompare(message,"help")){
		showHelp();
		return;
	}
	if(stringComapre(message,"piano")){
		startPiano();
		return;
	}
	ncPrint("Command not found, try 'help'");
	return;
}


uint64_t stringCompare(char* str1, char* str2){
	int i = 0;

	for (i = 0; str1[i]!=0 && str2[i]!=0; ++i)
	{
		if(str1[i]!=str2[i]){
			return FALSE; 
		}
	}
	if(str1[i]!=0 || str2[i]!=0){
		return FALSE;
	}
	return TRUE;
}