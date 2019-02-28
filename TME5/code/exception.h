// $Id: exception.h,v 1.1 2006/05/15 16:58:19 emmanuel Exp $ 

#include <setjmp.h>

typedef  char * exception;

typedef struct _ctx_block {
  jmp_buf env;
  exception exn;
  int val;
  int state;
  int found;
  struct _ctx_block *next;
} context_block;

#define  ES_EvalBody 0
#define  ES_Exception 1

extern exception ANY;
extern context_block *exceptionStack;
extern void _RaiseException();



#define RAISE(e,v) _RaiseException(&e,v)

#define TRY \
  {\
    context_block _cb;\
    int state = ES_EvalBody;\
    _cb.next=exceptionStack;\
    _cb.found=0;\
    exceptionStack=&_cb;\
    if (setjmp(_cb.env) != 0) state=ES_Exception;\
    while(1){\
      if (state == ES_EvalBody){
    
#define EXCEPT(e)\
    if (state == ES_EvalBody) exceptionStack=exceptionStack->next;\
    break;\
    }\
    if (state == ES_Exception) \
      if ((_cb.exn == (exception)&e) || (&e == &ANY)) {\
        int exception_value = _cb.val;\
        _cb.found=1;

#define ENDTRY \
   }\
   if (state == ES_EvalBody) {exceptionStack=exceptionStack->next;break;}\
   else {exceptionStack=exceptionStack->next;\
         if (_cb.found == 0) _RaiseException(_cb.exn,_cb.val); else break;}\
   }\
}
