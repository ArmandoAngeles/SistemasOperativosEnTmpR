#esta es la primera parte del programa se separaron en dos archivos .s
#aqui se genera la funcion, se compilan los dos ya sea con un att32_one_src
#o con un makeFile, puedes editar ambos facilmente para que compile los dos archivos
#y al finalizar ya solo corres los archivos con el ./att o el ./Power, dependiendo
#la forma en la que se halla utilizado, yo  modifique el att32

.section .data
.section .text
.globl power
.type power, @function

power:
pushl %ebp			#save old base pointer
movl %esp, %ebp			#make stack pointer the base pointer
subl $4, %esp			#get room for our local storage 
movl 8(%ebp), %ebx		#put second argument in %eax
movl 12(%ebp), %ecx		#put second argument in %ecx
movl %ebx, -4(%ebp)		#sotrage current result
power_loop_start:
cmpl $1, %ecx			#if the power is 1, we are done
je end_power	
movl -4(%ebp), %eax		#move the current result into %eax
imull %ebx, %eax		#multuply the current result by the base number
movl %eax, -4(%ebp)		#storage the current result 
decl %ecx			#decrase the power
jmp power_loop_start		#run for the next power

end_power:
movl -4(%ebp), %eax		#return value goes in %eax
movl %ebp, %esp			#restore the stack pointer
popl %ebp			#restore the base pointer
ret
