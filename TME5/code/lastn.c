// lastn.c

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "exception.h"


struct cons {int car; struct cons *cdr;};
typedef struct cons *liste_entier;

liste_entier cons(int a, liste_entier l)
{liste_entier r;
 r=(liste_entier)(malloc(sizeof(struct cons)));
 r->car=a;
 r->cdr=l;
 return r;
}
liste_entier append(liste_entier l1,liste_entier l2)
{
 if (l1 == NULL) return l2;
 else 
  return (cons(l1->car,append(l1->cdr,l2)));
}

liste_entier intervalle(int a, int b)
{ if (a > b) return NULL;
  else return cons(a,intervalle(a+1,b));
}

void print_liste(liste_entier l)
{
  printf("[ "); 
  while (l) 
   {printf("%d ",l->car);
    l=l->cdr;
   }
  printf("]\n");
}

exception Found;
exception Not_found;

int lastn_aux1(liste_entier l, int n)
{
  if (l == NULL) return 0;
  else 
  { int r;
    r = lastn_aux1(l->cdr,n);
    if (r == n) {RAISE (Found,l->cdr);return 0;}
    else return (r+1);
  }
}

liste_entier lastn_aux2(liste_entier l, int n)
{ 
  if (lastn_aux1(l,n) == n) RAISE(Found,l);
  else RAISE (Not_found,l);
  return NULL;
}

liste_entier lastn(liste_entier l, int n)
{ liste_entier r;
  TRY
    r = lastn_aux2(l,n);
  EXCEPT(Found)
    printf("Exception Found recuperee\n");
    r=(liste_entier)exception_value;
  EXCEPT(Not_found)
    printf("Exception Not_found recuperee\n");
    printf("liste trop courte \n");
    r=(liste_entier)exception_value;
  ENDTRY
  return r;
}

int main(int argc, char *argv[])
{int n;
 int x;
 liste_entier l,l2;

 if (argc == 2)
  {fprintf(stderr,"pas d'arguments\n"); exit (1);}
 else
 { x = atoi(argv[1]);
   n = atoi(argv[2]);
   l = intervalle(1,x);
   print_liste(l);
   printf("les %d derniers elements de ",x);
   print_liste(l);
   printf(" = ");
   l2=lastn(l,n);
   print_liste(l2);
 }
 return 0;
}
