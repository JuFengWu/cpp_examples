## This is some C++ examples

##### The first example is valgrind_liinux_memory_leak. It is linux memory leak example.

In this project, those functions have some problems about memory leak, we can use `valgrind` to check those memory leak.

1. Type `` make `` to build thise project 
2. Type ``valgrind --leak-check=full ./test_memory_leak.out``, it will show where have problem.
3. ##### Attention:  In some ubuntu 16.04 OS, I found it will show up that it still have reachable block due to gcc bug. So, before using this program, you should make sure it again.
