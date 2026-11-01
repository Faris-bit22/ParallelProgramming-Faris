# LAB 02 – Memory Debugging

## Description
The goal of this assignment was to find and fix memory errors in a C program.

I fixed the code by initializing some variables, fixing the for loops to prevent accessing elements outside the array, and freeing the allocated memory using free().

## Testing

I used the Makefile to compile the program and Valgrind to check for memory errors.

I ran this command: make valgrind

## Results

This is the result I got from Valgrind:


HEAP SUMMARY:
in use at exit: 0 bytes in 0 blocks
total heap usage: 1 allocs, 1 frees, 40 bytes allocated

All heap blocks were freed -- no leaks are possible

ERROR SUMMARY: 0 errors from 0 contexts