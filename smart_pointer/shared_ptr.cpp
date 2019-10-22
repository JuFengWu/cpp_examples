#include<iostream>
#include <memory>
class DemoSharePtr{
  public:
    DemoSharePtr(int inputVar){
      std::cout<<"construct DemoSharePtr!"<<std::endl;
      set_input_var(inputVar);
    }
    ~DemoSharePtr(){
      std::cout<<"free DemoSharePtr!"<<std::endl;
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
  std::shared_ptr<DemoSharePtr> a;  // a is empty
  {
    std::shared_ptr<DemoSharePtr> b =  std::make_shared<DemoSharePtr>(30);  // allocate resource
    a = b;  
    std::cout << "current a value is " << a->get_input_var() << std::endl;
    std::cout << "*a count is "<<a.use_count()<<std::endl; // reference counter: 2
    {
      std::shared_ptr<DemoSharePtr> c = a;  
      c->set_input_var(40);
      std::cout << "*a count is "<<a.use_count()<<std::endl;// reference counter: 3
    }  // c eof, reference counter: 2
  } // b eof, reference counter: 1
  std::cout << "current a value is " << a->get_input_var() << std::endl;
  std::cout << "*a count is "<<a.use_count()<<std::endl;
}
