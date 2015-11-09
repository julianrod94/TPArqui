#include "interpreter.h"
#include "stdio.h"
#include "programs.h"


void inputInterpreter(char* message){
	if(message[0] == 0){
		return;
	}
	if(stringCompare(message,"help")){
		showHelp();
		return;
	}else if(stringCompare(message,"piano")){
		piano();
		return;
	}else if(stringCompare(message,"beep")){
		beep();
	}else if(stringCompare(message,"stopwatch")){
		stopWatch();
	}else if(stringCompare(message,"musicplayer")){
		playMusic();
	}else if(stringCompare(message,"clear")){
		clearShell();
	}else{
		printf("Command '");
		printf(message);
		printf("' not found, try 'help'\n");
	}
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
	printf("\n");
	printf("help: este comando muestra el manual de usuario del sistema operativo\n");
	printf("\n");
	printf("piano: este comando inicia el programa \"piano\" el cual se podra utilizar como el instrumento musical\n");
	printf("\n");
	printf("beep: este comando hace sonar el pcspeaker con un sonido de corta duracion\n");
	printf("\n");
	printf("stopwatch: este comando iniciara un cronometro el cual puede parar cuando lo desee\n");
	printf("\n");
	printf("musicplayer: este comando reproduce musica por el speaker\n");
	printf("\n");
	return;
}

void beep(void){

	return;
}