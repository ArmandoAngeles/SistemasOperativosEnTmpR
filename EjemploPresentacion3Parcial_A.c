#include <sys/ipc.h>	/*ipc*/
#include <sys/msg.h>	/*msgget*/
#include <sys/types.h>	/*msgget*/
#include <stdlib.h>	/*exit*/
#include <stdio.h>	/*printf*/
#include <string.h>	/*strcpy*/
#define TAM 128

typedef struct msgbuf {
	long	tipo;
	char	texto[TAM];
} mensaje;

main()
{
	int msgflg = IPC_CREAT | 0666; key_t key; size_t buf_length; int msqid; mensaje sbuf;
	key = 5678;
	printf("Creando cola de mensajes: msgget(%i,%o)\n",key, msgflg);
	if((msqid = msgget(key, msgflg)) < 0){
		perror("msgget");
		exit(1);
	}
	else
		printf("Cola creada con exito: msqid = %d\n",msqid);
	sbuf.tipo = 1 ;
	strcpy(sbuf.texto, "Fernando Idex");//Mensaje a enviar
	buf_length = strlen(sbuf.texto) + 1;
	if (msgsnd(msqid, &sbuf, buf_length, msgflg) < 0){
		printf("%d, %ld, %s, %ld\n", msqid, sbuf.tipo, sbuf.texto, buf_length);
		perror("msgsnd");
		exit(1);
	}
	else
		printf("Mensaje: ' %s ' Enviado\n", sbuf.texto);
	exit(0);
}
