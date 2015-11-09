
static char buffer[256]={0};

void startShell(void){
	clearShell();
	printf("\n");
	while(1){
		printf("$>");
		readLine(buffer,256);
		inputInterpreter(buffer);
		printf("\n");

	}
}