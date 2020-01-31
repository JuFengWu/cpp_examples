#include <memory>
#include <iostream>

class Base{
  public:
    Base(){
      std::cout<<"this is base"<<std::endl;
    }
    ~Base(){
      std::cout<<"free base"<<std::endl;
    }
    virtual int get_input_var() = 0;
    virtual void set_input_var(int inputVar) = 0;
    protected:
      int _inputVar; 
}; 

class DemoSharedPtr : public Base{
  public:
    DemoSharedPtr(int inputVar){
      std::cout<<"construct DemoSharedPtr!"<<std::endl;
      set_input_var(inputVar);
    }
    ~DemoSharedPtr(){
      std::cout<<"free DemoSharedPtr!"<<std::endl;
    }
    int get_input_var() override {
      return _inputVar;
    }
    void set_input_var(int inputVar) override {
      _inputVar = inputVar;
    }
};

void test1_function(std::shared_ptr<DemoSharedPtr> ptr){
  std::cout<<"inside function 1 the ptr value is "<<ptr->get_input_var()<<std::endl;
  ptr->set_input_var(30);
}

void test1(){
  std::cout<<"---begin test1---"<<std::endl;
  std::shared_ptr<DemoSharedPtr> demoSharedPtr =  std::make_shared<DemoSharedPtr>(20);
  test1_function(demoSharedPtr); // shared pointer can use this, but unique pointer can not use it
  std::cout<<"outside function the ptr value is "<<demoSharedPtr->get_input_var()<<std::endl;
  //test1_function(std::move(demoSharedPtr));
  //std::cout<<"outside function the ptr value is "<<demoSharedPtr->get_input_var()<<std::endl;
  // up will crash, because it use move to pass the value, and originl is void
}

void test2_function(std::shared_ptr<DemoSharedPtr> &ptr){
  std::cout<<"inside function 1 the ptr value is "<<ptr->get_input_var()<<std::endl;
  ptr->set_input_var(30);
}

void test2(){
  std::cout<<"--- begin test2---"<<std::endl;
  std::shared_ptr<DemoSharedPtr> demoSharedPtr = std::make_unique<DemoSharedPtr>(20);
  test2_function(demoSharedPtr);
  std::cout<<"outside function the ptr value is "<<demoSharedPtr->get_input_var()<<std::endl;
}

void test3_function(std::shared_ptr<Base> sharedPtr){
  std::cout<<"inside function 3 the ptr is "<<sharedPtr->get_input_var()<<std::endl;
  sharedPtr->set_input_var(30);
}

void test3(){
  std::cout<<"---begin test3(polymorphism)---"<<std::endl;
  std::shared_ptr<DemoSharedPtr> demoSharedPtr = std::make_unique<DemoSharedPtr>(20);
  test3_function(demoSharedPtr);
  std::cout<<"outside function the ptr value is "<<demoSharedPtr->get_input_var()<<std::endl;
}

void test4_function(std::shared_ptr<Base> &sharedPtr){
  std::cout<<"inside function 4 the ptr is "<<sharedPtr->get_input_var()<<std::endl;
  sharedPtr->set_input_var(30);
}

void test4(){
  std::cout<<"---begin test4(polymorphism)---"<<std::endl;
  std::shared_ptr<DemoSharedPtr> demoSharedPtr = std::make_unique<DemoSharedPtr>(20);
  //test4_function(demoSharedPtr);
  //std::cout<<"outside function the ptr value is "<<demoSharedPtr->get_input_var()<<std::endl;
  //polymorphism can not be reference , it will have error
}

void test5_function(DemoSharedPtr& obj){
  std::cout<<"inside function 5 the ptr is "<<obj.get_input_var()<<std::endl;
  obj.set_input_var(30);
}

void test5(){
  std::cout<<"---begin test5(the best way to pass, the compatibility is best)---"<<std::endl;
  std::unique_ptr<DemoSharedPtr> demoSharedPtr = std::make_unique<DemoSharedPtr>(20);
  test5_function(*demoSharedPtr);
  test5_function(*demoSharedPtr.get());// this is the same as up
  std::cout<<"outside function the ptr value is "<<demoSharedPtr->get_input_var()<<std::endl;
}

void test6_function(DemoSharedPtr* sharedPtr){
  std::cout<<"inside function 6 the ptr is "<<sharedPtr->get_input_var()<<std::endl;
  DemoSharedPtr copyValue(123); 
  copyValue = *sharedPtr;
  std::cout<<"copy uniPtr values is "<<copyValue.get_input_var()<<std::endl;
  sharedPtr->set_input_var(30);
}

void test6(){
  std::cout<<"---begin test5(also the good way, the compatibility is also good)---"<<std::endl;
  std::unique_ptr<DemoSharedPtr> demoSharedPtr = std::make_unique<DemoSharedPtr>(20);
  test6_function(demoSharedPtr.get());
  std::cout<<"outside function the ptr value is "<<demoSharedPtr->get_input_var()<<std::endl;
}

void test7(){
  std::cout<<"---begin test6(the other ways to create smart pointer)---"<<std::endl;
  DemoSharedPtr test(123);
  std::unique_ptr<DemoSharedPtr> demoSharedPtr = std::make_unique<DemoSharedPtr>(test);
  std::cout<<"function the ptr value is "<<demoSharedPtr->get_input_var()<<std::endl;
}

int main(){
  test1();
  test2();
  test3();
  test4();
  test5();
  test6();
  test7();
}