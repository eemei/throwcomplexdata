#include "unity.h"
#include "Main.h"
#include "ErrorObject.h"
#include "CException.h"

void setUp(void){}

void tearDown(void){}


void test_dothing(void){
  ErrorObject *err;
  Try{
 doThings();
 TEST_FAIL_MESSAGE("expert ERR_DUNNO_WHAT_HAPPEN TO BE THROWN. but none thrown");
  }Catch(err){                  // throw go to catch 
   TEST_ASSERT_EQUAL_STRING("hey, something is really wrong here", \
                      err->errorMsg);
   TEST_ASSERT_EQUAL (ERR_DUNNO_WHAT_HAPPEN, err->errorCode);
    //printf("error:%s\n", err->errorMsg);
   freeError(err);             // because use malloc so need free 
  }
}

void test_specialAdd_given_minus_5_and_11_should_return_6(void){
  int result = specialAdd(-5,11);
  TEST_ASSERT_EQUAL(6, result);
}

void test_specialAdd_given_7_and_18_should__throw_ERR_NUMBER_NOT_NEGATIVE(void){
  ErrorObject *err;
  Try{
  specialAdd(7,18);
  TEST_FAIL_MESSAGE("expert ERR_NUMBER_NOT_NEGATIVE TO BE THROWN. but none thrown");
  }Catch(err){                  // throw go to catch 
   TEST_ASSERT_EQUAL_STRING("hey something wrong", \
                      err->errorMsg);
   TEST_ASSERT_EQUAL (ERR_NUMBER_NOT_NEGATIVE, err->errorCode);
   freeError(err);               
  }
}




void test_specialAdd_given_7_and_18_should__throw_ERR_NOT_MORE_THAN_50(void){
  ErrorObject *err;
  Try{
  specialAdd(-1,55);
  TEST_FAIL_MESSAGE("expert ERR_NOT_MORE_THAN_50 TO BE THROWN. but none thrown");
  }Catch(err){                  // throw go to catch 
   TEST_ASSERT_EQUAL_STRING("hey something wrong", err->errorMsg);
   TEST_ASSERT_EQUAL (ERR_NOT_MORE_THAN_50, err->errorCode);
   freeError(err);               
  }
}

void test_specialAdd_given_7_and_18_should__throw_ERR_NUMBER_NOT_POSITIVE(void){
  ErrorObject *err;
  Try{
  specialAdd(-7,-18);
  TEST_FAIL_MESSAGE("expert ERR_NUMBER_NOT_POSITIVE TO BE THROWN. but none thrown");
  }Catch(err){                  // throw go to catch 
   TEST_ASSERT_EQUAL_STRING("hey something wrong",err->errorMsg);
   TEST_ASSERT_EQUAL (ERR_NUMBER_NOT_POSITIVE, err->errorCode);
   freeError(err);               
  }
}