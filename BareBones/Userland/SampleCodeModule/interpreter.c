#include "interpreter.h"


void inputInterpreter(char* message){
	if(stringCompare(message,"man")){
		showHelp();
		return;
	}
	if(stringCompare(message,"piano")){
		startPiano();
		return;
	}
	if(stringCompare(message,"beep")){
		beep();
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
	printf("man: este comando muestra el manual de usuario del sistema operativo\n");
	printf("piano: este comando inicia el programa \"piano\" el cual se podra utilizar como el instrumento musical\n");
	printf("printf: este comando imprimira en pantalla la cadena de caracteres que se ingresa luego del comando\n");
	printf("beep: este comando hace sonar el pcspeaker con un sonido de corta duracion\n");
	return;
}

void shellRead(char* buffer){
	uint64_t character = 0;
	int i = 0;
	while(character = getchar()!='\n' && i<255){
		if(character!=0){
			buffer[i] = (char) character;
			i++;
			putchar(character);
		}
	}
	return;
}
void beep(void){
	return;
}
void startPiano(void){
	uint64_t note = 0;
	while(note=getchar() !='q'){

	}
	return;
}