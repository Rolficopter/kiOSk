global getc

getc:
	mov eah, 00h
	int 16h
	mov ah, 0
	ret