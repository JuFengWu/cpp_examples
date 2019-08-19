#include <iostream>

void leak_fuction(){
	int *ptr = (int *)malloc(3); 
}

void invaild_memory_access_array(){
	int arr[3] = {1,2,3};
	//invaild read
	std::cout<<"arr[3] is "<<arr[3]<<std::endl;
	//invaild write
	arr[3] = 0;//it will directly show core dump
}
void invaild_memory_access(){
	int *arr = new int[3];
	std::cout<<"arr[3] is "<<arr[3]<<std::endl;
	arr[3] = 0;
}
void invaild_memory_free(){
	int *arr = new int[3];
	std::cout<<"free first times"<<std::endl;
	delete arr;
	std::cout<<"free second times"<<std::endl;
	delete arr;
}

int main(){
	leak_fuction();
	invaild_memory_access();
	invaild_memory_free();
}
