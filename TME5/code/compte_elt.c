// $Id: compte_elt.c,v 1.1 2006/05/15 16:58:19 emmanuel Exp $

#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

struct cons {int car; struct cons *cdr;};
typedef struct cons *liste_entier;

liste_entier cons(int a, liste_entier l) {
 liste_entier r;
 r=(liste_entier)(malloc(sizeof(struct cons)));
 r->car=a;
 r->cdr=l;
 return r;
}

liste_entier intervalle(int a, int b) { 
  if (a > b) return NULL;
  else return cons(a,intervalle(a+1,b));
}

int compteur=0;

int compte(liste_entier l) { 
  sleep(1);
  if (l == NULL) return 0;
  else {
    compteur++;
    return 1 + compte(l->cdr);
  }
}

void hand() { 
  printf(" deja compt\'es %d\n",compteur);
  signal(SIGINT,hand); 
}

int main(int argc, char *argv[]) {
 int r;
 int x;
 if (argc == 1) { fprintf(stderr,"pas d'arguments\n"); exit (1);}
 else { 
   signal(SIGINT,hand);
   x = atoi(argv[1]);
   r = compte(intervalle(1,x));
   printf("%d elements\n",r);
 }
}
