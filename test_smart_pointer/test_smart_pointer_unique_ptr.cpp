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

class DemoUniquePtr : public Base{
  public:
    DemoUniquePtr(int inputVar){
      std::cout<<"construct DemoUniquePtr!"<<std::endl;
      set_input_var(inputVar);
    }
    ~DemoUniquePtr(){
      std::cout<<"free DemoUniquePtr!"<<std::endl;
    }
    int get_input_var() override {
      return _inputVar;
    }
    void set_input_var(int inputVar) override {
      _inputVar = inputVar;
    }
};

void test1_function(std::unique_ptr<DemoUniquePtr> ptr){
  std::cout<<"inside function 1 the ptr value is "<<ptr->get_input_var()<<std::endl;
  ptr->set_input_var(30);
}

void test1(){
  std::cout<<"---begin test1---"<<std::endl;
  std::unique_ptr<DemoUniquePtr> demoUniquePtr = std::make_unique<DemoUniquePtr>(20);
  test1_function(std::move(demoUniquePtr));
  //std::cout<<"outside function the ptr value is "<<demoUniquePtr->get_input_var()<<std::endl;
  //up will crash, because the pointer is passed into the function by std::move
}

void test2_function(std::unique_ptr<DemoUniquePtr>& uniqPtr){
  std::cout<<"inside function 2 the ptr is "<<uniqPtr->get_input_var()<<std::endl;
  uniqPtr->set_input_var(30);
}

void test2(){
  std::cout<<"--- begin test2---"<<std::endl;
  std::unique_ptr<DemoUniquePtr> demoUniquePtr = std::make_unique<DemoUniquePtr>(20);
  test2_function(demoUniquePtr);
  std::cout<<"outside function the ptr value is "<<demoUniquePtr->get_input_var()<<std::endl;
}

std::unique_ptr<Base> test3_function(std::unique_ptr<Base> uniqPtr){
  std::cout<<"inside function 3 the ptr is "<<uniqPtr->get_input_var()<<std::endl;
  uniqPtr->set_input_var(30);
  return uniqPtr;
}

void test3(){
  std::cout<<"---begin test3(polymorphism)---"<<std::endl;
  auto demoUniquePtr = test3_function(std::make_unique<DemoUniquePtr>(20));
  std::cout<<"outside function the ptr value is "<<demoUniquePtr->get_input_var()<<std::endl;
}

void test4_function(DemoUniquePtr& obj){
  std::cout<<"inside function 4 the ptr is "<<obj.get_input_var()<<std::endl;
  obj.set_input_var(30);
}

void test4(){
  std::cout<<"---begin test4(the best way to pass, the compatibility is best)---"<<std::endl;
  std::unique_ptr<DemoUniquePtr> demoUniquePtr = std::make_unique<DemoUniquePtr>(20);
  test4_function(*demoUniquePtr);
  test4_function(*demoUniquePtr.get());// this is the same as up
  std::cout<<"outside function the ptr value is "<<demoUniquePtr->get_input_var()<<std::endl;
}

void test5_function(DemoUniquePtr* uniqPtr){
  std::cout<<"inside function 3 the ptr is "<<uniqPtr->get_input_var()<<std::endl;
  DemoUniquePtr copyValue(123); 
  copyValue = *uniqPtr;
  std::cout<<"copy uniPtr values is "<<copyValue.get_input_var()<<std::endl;
  uniqPtr->set_input_var(30);
}

void test5(){
  std::cout<<"---begin test5(also the good way, the compatibility is also good)---"<<std::endl;
  std::unique_ptr<DemoUniquePtr> demoUniquePtr = std::make_unique<DemoUniquePtr>(20);
  test5_function(demoUniquePtr.get());
  std::cout<<"outside function the ptr value is "<<demoUniquePtr->get_input_var()<<std::endl;
}

void test6(){
  std::cout<<"---begin test6(the other ways to create smart pointer)---"<<std::endl;
  DemoUniquePtr test(123);
  std::unique_ptr<DemoUniquePtr> demoUniquePtr = std::make_unique<DemoUniquePtr>(test);
  std::cout<<"function the ptr value is "<<demoUniquePtr->get_input_var()<<std::endl;
}

int main(){
  test1();
  test2();
  test3();
  test4();
  test5();
  test6();
  std::cout<<"-----end test------"<<std::endl;
}