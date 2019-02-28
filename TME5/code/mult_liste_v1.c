// $Id: mult_liste_v1.c,v 1.1 2006/05/15 16:58:19 emmanuel Exp $


#include <stdlib.h>
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

liste_entier append(liste_entier l1, liste_entier l2) {
  liste_entier r;
  if (l1 == NULL) return l2;
  else 
    return (cons(l1->car,append(l1->cdr,l2)));
}

liste_entier intervalle(int a, int b) { 
  if (a > b) return NULL;
  else return cons(a,intervalle(a+1,b));
}

int compteur=0;

int mult_liste_v1(liste_entier l) { 
  compteur++;
  if (l == NULL) return 1;
  else return l->car*mult_liste_v1(l->cdr);
}
 
int mult_liste(liste_entier l) { 
  int r;
  compteur=0;
  r=mult_liste_v1(l);
  printf("calcul en %d etapes : ",compteur);
  return r;
}


void print_liste(liste_entier l) {
  printf("[ "); 
  while (l) {
    printf("%d ",l->car);
    l=l->cdr;
  }
  printf("]\n");
}


int main(int argc, char *argv[]) {
  int r;
  int x;
  if (argc == 1)
   { fprintf(stderr,"pas d'arguments\n"); exit (1); }
  else { 
    x = atoi(argv[1]);
    r = mult_liste(intervalle(1,x));
    printf("fact %d = %d\n",x,r);
    r = mult_liste(append(intervalle(1,x),cons(0,intervalle(1,x))));
    printf("produit de [1..%d]@[0..%d]=%d\n",x,x,r);
  }
  return 0;
}
