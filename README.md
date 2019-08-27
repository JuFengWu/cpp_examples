## This is some C++ examples

##### The first example is valgrind_liinux_memory_leak. It is linux memory leak example.

In this project, those functions have some problems about memory leak, we can use `valgrind` to check those memory leak.

It is install and run steps: 
1. Type `` make `` to build this project 
2. Type ``valgrind --leak-check=full ./test_memory_leak.out``, it will show where have problems.
3. ##### Attention:  In some ubuntu 16.04 OS, I found it will show up that it still have reachable block due to gcc bug. So, before using this program, you should make sure it again.

##### The second example is rule_of_five.

In this project, it shows up rule of five and when will those functions(copy/move constructure/assignment) be called.

It is install and run steps: 
1. Type ``make`` to build this project
2. Type ``./rule_of_five.out``, it will show up copy/move constructure/assignment be called time.


##### The third example is makefile.
In this project, it shows up how to use make to buid a project and generate test execution file

> __NOTE__: 
In this example, it use google test. So make sure your computer installed google test.

The run steps is simple:
1. Type ``make`` to build the project, it will generate a execution file and a test execution file
2. Type ``./main.out`` will execute the file; type ``./test.out`` will execute test file
3. You can go to test folder and type ``make`` to build test file alnoe, and type ``./test.out`` t orun test
4. Threr is a file ``use_gcc_build_cmd``, copy this file line and paste on terminal, it will build test execute file.
