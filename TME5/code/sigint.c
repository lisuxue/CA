// $Id: sigint.c,v 1.1 2006/05/15 16:58:19 emmanuel Exp $

#include <stdio.h>
#include <signal.h>

void hand_int(int sig){ 
  printf("Pas d'interruption ^C active\n");
  printf("Taper ^\\ si vous d\'esirez sortir du programme\n");
  signal(SIGINT,hand_int);
}

main () { 
  int i;
  int c=0;
  signal(SIGINT,hand_int);
  printf("un programme qui boucle, essayer ^C pour l'arreter\n");
  while (1) {
    i++;
    if ((i % 100000) == 0) {c++;printf("."); fflush(stdout);}
  }
}
