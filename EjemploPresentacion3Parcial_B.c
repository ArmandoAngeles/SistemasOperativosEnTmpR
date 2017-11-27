#include <sys/ipc.h>	/*IPC*/
#include <sys/msg.h>	/*msgget*/
#include <sys/types.h>	/*msgget*/
#include <stdlib.h>	/*exit*/
#include <stdio.h>	/*printf*/
#include <string.h>	/*strcpy*/
#define	TAM	128

typedef struct msgbuf {
	long	tipo;
	char	texto[TAM];
} mensaje;

main()
{
	int msqid; key_t key; mensaje rbuf;
	key = 5678;
	if((msqid = msgget(key, 0666)) < 0){
		perror("msgget");
		exit(1);
	}
	if(msgrcv(0, &rbuf, TAM, 1, 0) < 0){
		perror("msgrcv");
		exit(1);
	}
	printf("%s\n", rbuf.texto);
	exit(0);
}
