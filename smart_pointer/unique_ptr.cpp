#include<iostream>
#include <memory>
class DemoUniquePtr{
  public:
    DemoUniquePtr(int inputVar){
      std::cout<<"construct DemoUniquePtr!"<<std::endl;
      set_input_var(inputVar);
    }
    ~DemoUniquePtr(){
      std::cout<<"free DemoUniquePtr!"<<std::endl;
    }
    int get_input_var(){
      return _inputVar;
    }
    void set_input_var(int inputVar){
      _inputVar = inputVar;
    }
  private:
    int _inputVar;
};

int main(){
  std::unique_ptr<int> a( new int(10) );
  int b = *a;
  std::cout<<"b is "<<b<<std::endl;
  std::unique_ptr<DemoUniquePtr> demoUniquePtr = std::make_unique<DemoUniquePtr>(20);
  std::cout<<"input var is "<<demoUniquePtr->get_input_var()<<std::endl;
}
