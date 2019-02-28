// $Id: sigsegv.c,v 1.2 2006/05/15 16:58:19 emmanuel Exp $

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

char *p;

void hand() { 
  printf("signal SIGSEGV recu\n");
  printf(" p a comme valeur %u\n",p);
  exit(0);
}

int main() {
  signal(SIGSEGV,hand);
  p=(char *)sbrk(512);
  printf("valeur initiale du point de rupture : %u\n",p);
  printf("valeur du point de rupture apres sbrk : %u\n",sbrk(0));
  while(1)
    *p++='a';
  return 0;
}
