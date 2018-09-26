global getc

getc:
	mov ah, 00h
	int 16h
	mov ah, 0
	ret