#include "Main.h"
#include "ErrorObject.h"
#include "CException.h"
#include <malloc.h>

int shouldFail =1;

void doThings(){
  ErrorObject *err; // pointer 
  // Try{
  doSomething();
  // }Catch(err){    // throw go to catch 
    // printf("error:%s\n", err->errorMsg);
    // freeError(err); // because use malloc so need free 
  // }
}

int doSomething(){
 // ErrorObject *errObj= malloc(sizeof(ErrorObject));
    
  if(shouldFail){
    throwError("hey, something is really wrong here", \
                ERR_DUNNO_WHAT_HAPPEN );
  }
    return 1;
}

/* 
* add two number . the first number must be negative
* the second number must be positive no more than 50
*
*
**/
int specialAdd (int negVal, int posVal){ 
int result= 0;
  if (negVal > 0){  
  throwError ("hey something wrong",ERR_NUMBER_NOT_NEGATIVE);
  }
  if (posVal > 50){
  throwError ("hey something wrong",ERR_NOT_MORE_THAN_50);
  }
  if (posVal < 0 ){
  throwError ("hey something wrong",ERR_NUMBER_NOT_POSITIVE);
  }
  result = negVal + posVal;
  return result;
}