GLOBAL turnOnSound
GLOBAL turnOffSound


turnOnSound:

mov al, 182         ;Prepares the speaker
out 43h, al 

mov rax, rdi        ; Copies the parameter value to rax (the frequency)


out 42h, al         ; Output low byte.
mov al, ah
out 42h, al         ; Output high byte.

in al, 61h
or al, 3            ; Set bits 1 and 0. (Both last bits must be set to 1)
out 61h, al         ; Send new value.
ret                 ; Returns



turnOffSound:

in al, 61h
and al, -4          ; Reset bits 1 and 0. (Both last bits must be set to 0)
out 61h, al         ; Send new value.
ret                 ; Returns