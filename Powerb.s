#Manejamos el programa en dos, se estructura .s e iniciamos start aqu, generamos
#los valores de la ecuacion, y se manda a llamar a la funcion power generada en el otro
#programa Powerb.s
.section .data
.section .text
.globl _start

_start:
pushl $3		#Push second argument
pushl $2		#Push first argument
call power		#Call the function
addl $8, %esp		#move the stack pointer back
pushl %eax		#Save the first answer before, calling the next function
pushl $2		#PUSH SECOND ARGUMENT
pushl $5		#push first argument

call power		#call the function
addl $8, %esp		#move the stack pointer back
popl %ebx		
addl %eax, %ebx		#add them together, the result is in %ebx
movl $1, %eax		#exit (%ebx is returned)
int $0x80
