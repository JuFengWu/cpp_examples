#include <iostream>
#include <string>

void test_throw_1(){
  throw "error string1";
}

void test_throw_2(){
  std::string buffAsStdStr = "a string exception";
  throw buffAsStdStr;
}

void add_some_and_throw(){
  std::string buffAsStdStr = "XXX! ";
  try{
    test_throw_2();
  }
  catch(std::string errString){
    throw buffAsStdStr + errString;
  }
  
}

int main(){
  std::cout<<"try exception start"<<std::endl;
  try {
    test_throw_1();
  } catch(const char* errString){
    std::cout<<"the throw error string is "<<errString<<std::endl;
  }
  std::cout<<"--------end test 1--------"<<std::endl;
  
  try{
    test_throw_2();
  } catch(std::string errString){
    std::cout<<"the throw error string is "<<errString<<std::endl;
  }
  std::cout<<"--------end test 2--------"<<std::endl;
  try{
    test_throw_2();
  } catch(...){
    std::cout<<"get all error1!"<<std::endl;
  }
  std::cout<<"--------end test 3--------"<<std::endl;
  try{
    test_throw_1();
  } catch(...){
    std::cout<<"get all error2!"<<std::endl;
  }
  std::cout<<"--------end test 4--------"<<std::endl;
  try{
    test_throw_1();
  } catch(std::string errString){
    std::cout<<"catch string"<<std::endl;
  } catch(...){
    std::cout<<"catch type is not correct!"<<std::endl;
  }
  std::cout<<"--------end test 5--------"<<std::endl;

  try{
    add_some_and_throw();
  } catch(std::string errString){
    std::cout<<"the throw error string is "<<errString<<std::endl;
  }
  return 0;
}
