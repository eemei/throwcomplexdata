#ifndef ErrorObject_H
#define ErrorObject_H

typedef enum{
  ERR_NO_TOKEN,
  ERR_WRONG_TOKEN,
  ERR_ILLEGAL_IDNDENTIFIER,
  ERR_FLOATING_POINT_MALFORMED,
  ERR_DUNNO_WHAT_HAPPEN,
  ERR_NUMBER_NOT_NEGATIVE,
  ERR_NUMBER_NOT_POSITIVE,
  ERR_NOT_MORE_THAN_50,
}ErrorCode;


typedef struct{
  char *errorMsg;
  ErrorCode errorCode;
}ErrorObject;

void throwError(char *message, ErrorCode errCode);
void freeError(ErrorObject *errObj);


#endif // ErrorObject_H
