#include "interpreter.h"
void scanf(char* buffer){
	int i=0;
	uint64_t source;
	while((source = sysCaller(READ,-1,-1,-1,-1,-1,-1)) !='\n'){
		buffer[i] = (char) source;
		i++;
	}
	return;
}


void inputInterpreter(char* message){
	if(stringCompare(message,"help")){
	//	showHelp();
		return;
	}
	if(stringCompare(message,"piano")){
	//	startPiano();
		return;
	}
	//ncPrint("Command not found, try 'help'");
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