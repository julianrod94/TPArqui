#include "interpreter.h"
#include "stdio.h"
#include "programs.h"


void inputInterpreter(char* message){
	if(stringCompare(message,"help")){
		showHelp();
		return;
	}
	if(stringCompare(message,"piano")){
		piano();
		return;
	}
	if(stringCompare(message,"beep")){
		beep();
	}
	if(stringCompare(message,"stopwatch")){
		stopWatch();
	}
	printf("Command not found, try 'help'");
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

void showHelp(void){
	printf("Este sistema operativo dispone de los siguientes comandos: \n");
	printf("help: este comando muestra el manual de usuario del sistema operativo\n");
	printf("piano: este comando inicia el programa \"piano\" el cual se podra utilizar como el instrumento musical\n");
	printf("printf: este comando imprimira en pantalla la cadena de caracteres que se ingresa luego del comando\n");
	printf("beep: este comando hace sonar el pcspeaker con un sonido de corta duracion\n");
	return;
}

void beep(void){

	return;
}