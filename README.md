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
