#include "music.h"
#include "time.h"
#include "stdio.h"
#include "string.h"

static void welcomeMessage(char * programName, char * initialMessage) {

	printf("Bienvenido a %s\n\n%s", programName, initialMessage);
}

static void printByeByeMessage() {
	printf("Hasta luego\n");
}

void piano(void) {
	clearShell();
	welcomeMessage("piano","Puede tocar con el teclado utilizando las teclas alfabeticas.\nPara salir presione ESC o Q\n");
	pianoPlay();
	printByeByeMessage();

}

void echo(void) {

	welcomeMessage("echo","Ingrese texto: ");
	char string [1024];
	readLine(string, 1024);
	printf("%s\n", string);
	printByeByeMessage();
}


void stopWatch() {

	welcomeMessage("stop watch","Presione E para empezar. Para deternlo, presione cualquier tecla.\nPara salir presione Q\n");
	int counter = 0;
	char option;
	do {
		printf("Ingrese una opcion: ");
		option = getchar();
		while (getchar() != '\n'); /* cleans buffer */
		if (option == 'e' || option == 'E') {
			printf("\n\n\n");
			do {
				printf("%d\t", counter);
				sleep(1000);
				counter++;
				int flag = (int)askIfThereWasInput(); 
				if (flag) {
					printf("\nEl cronometro fue detenido. Ingrese que desea hacer (E para continuar, R para resetear, o Q para salir): ");
					do {
						
						option = getchar();
						while (getchar() != '\n'); /* cleans buffer */
					
						if (option == 'r' || option == 'R') {
							counter = 0;	
							printf("El cronometro fue reseteado. Presione enter para volver a empezar\n");
							while (getchar() != '\n');
							printf("\n\n\n");
						
						} else if (option == 'E' || option == 'e') {
							printf("\nContinua...\n");
						} else if (option != 'q' && option != 'q') {
							printf("Opcion invalida. Intente nuevamente\nIngrese una opcion:");
						}
					} while ( !(option == 'E' || option == 'e' || option == 'r' || option == 'R' || option == 'q' || option == 'Q'));
				}
			} while (option != 'q' && option != 'Q');
		} else if (option != 'q' && option != 'Q') {
			printf("Opcion inválida. Intente nuevamente\n");
		}
	} while ( option != 'q' && option != 'Q');
	printByeByeMessage();
}


void playMusic(void) {
	
	char option=2;
	char * options ="1- Mario Bros. Theme\n2- Tetris theme\n3- Happy-Birthday\n";
 
	welcomeMessage("play music","Para salir presione Q\n");
	printf("Seleccione una de las siguientes opciones:\n%s\n", options);	
	
	tMusicNote tetrisMusic[256] ={ 	
		{3619, 188}, {4831, 188}, {4560, 188}, {4063, 375}, {4560, 188}, {4831, 188}, {5423, 375},
		{5423, 188}, {4560, 188}, {3619, 375}, {4063, 188}, {4560, 188}, {4831, 375},
		{4831, 188}, {4560, 188}, {4063, 375}, {3619, 375}, {4560, 375}, {5423, 375}, {5423, 938},
		{4063, 188}, {4063, 188}, {3416, 188}, {2711, 375}, {3043, 188}, {3419, 188}, {3619, 563},
		{4560, 188}, {3619, 375}, {4063, 188}, {4560, 188}, {4831, 375},
		{4831, 188}, {4560, 188}, {4063, 375}, {3619, 375}, {4560, 375}, {5423, 375}, {5423, 938},
	{0, 0} };


	do {

		int i;
		while (i < 256 && tetrisMusic[i].note != 0 && tetrisMusic[i].duration != 0){

			automaticPlay(tetrisMusic[i++]);
		}


	} while (option != 'Q' && option != 'q');
}









