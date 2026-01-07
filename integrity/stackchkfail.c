/* When a function is called, place a canary value on the stack. 
Before the function returns, check if this value has been changed. 
If it has ("stackchkfail"), it means something has overwritten the stack, and the program is immediately aborted. */

__attribute__((noreturn)) void __stack_chk_fail(void)
{


    __builtin__unreachable();
}