#ifndef ATEXIT_H
#define EXIT_H

#define ATEXIT_FUNCTIONS 32 // Maximum of 32 functions will be registered to run after main ends

static void (*(atexit_function)[ATEXIT_FUNCTIONS])(void);
static int atexit_counter;

void atexit(void *(function)(void));
int __execute_atexit();



#endif