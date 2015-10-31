EXTERN syscallHandler
GLOBAL syscaller


syscaller:
	int 80h
	ret



