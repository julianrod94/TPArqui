section .text

GLOBAL sysCaller


sysCaller:
	int 80h
	ret



