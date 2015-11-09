#include "music.h"
#include "time.h"
#include "stdio.h"
#include "string.h"

static void welcomeMessage(char * programName, char * initialMessage) {

	printf("Bienvenido a %s\n\n%s", programName, initialMessage);
}

void piano(void) {

	welcomeMessage("piano","Puede tocar con el teclado utilizando las teclas alfabeticas.\nPara salir presione ESC o Q\n");
	pianoPlay();

}

void echo(void) {

	welcomeMessage("echo","Ingrese texto: ");
	char string [1024];
	readLine(string, 1024);
	printf("%s\n", string);
}


void stopWatch() {

	welcomeMessage("stop watch","Presione E para empezar, P para parar o R para resetear\nPara salir presione Q\n");
	int counter = 0;
	char option;
	do {
		printf("Ingrese una opcion: ");
		option = getchar()
		while (getchar() != '\n'); /* cleans buffer */
		if (option == 'e' || option == 'E') {
			printf("\n\n\n");
			do {
				if (option == 'e' || option == 'E') {
					printf("%d\t", counter);
					sleep(1000);
					counter++;
				} else if (option == 'P' || option == 'p') {
					printf("El cronometro fue detenido. Presione E para continuar o R para resetea\n");
					;
				} else if (option == 'R' || option == 'R') {
					counter = 0;
					printf("El cronometro fue reseteado. Presione E para volver a empezar\n")
				}
				if (askIfThereWasInput()) {
					option = getchar();
					while (getchar() != '\n'); /* cleans buffer */
					if (option == 'e' || option == 'E') {
						printf("\n\n\n");
					}
				}
			} while (option == 'q' || option == 'Q')
		} else if (option != 'q' && option != 'Q') {
			printf("Opcion inválida. Intente nuevamente\n")
		}
	} while ( option != 'q' && option != 'Q');

}


void playMusic(void) {

	char * options ="1- Mario Bros. Theme\n2- Tetris theme\n3- Happy-Birthday\n"
	welcomeMessage("play music","Para salir presione Q\n");
	printf("Seleccione una de las siguientes opciones:\n%s\n", options);

}









