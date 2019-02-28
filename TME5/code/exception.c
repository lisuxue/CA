// $Id: exception.c,v 1.1 2006/05/15 16:58:19 emmanuel Exp $
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "exception.h"

context_block *exceptionStack = NULL;

exception ANY;

void _RaiseException(exception e, int v)
{
  if (exceptionStack == NULL) 
  {fprintf(stderr,"Uncaught exception\n");
   exit(0);
  }
  else {
   exceptionStack->val=v;
   exceptionStack->exn=e;
   longjmp(exceptionStack->env,ES_Exception);
  }
}
