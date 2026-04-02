
#include <stdio.h>
#include <setjmp.h>
#include <signal.h>

jmp_buf buf;

void handler(int sig)
{
    if (SIGINT == sig)
    {
        printf("now got a SIGINT signal\n");
        longjmp(buf, 1); // 风险很大，可能会打断主程序中正在访问的资源，如内存分配、外设访问
        // 没有到达
        printf("%s %d\n", __FILE__, __LINE__);
    }
}

int main()
{
    signal(SIGINT, handler);
    if (setjmp(buf))
    {
        printf("longjmp back to main\n");
        // return 0;
    }
    else
    {
        printf("first time to setjmp\n");
    }

    printf("%s %d\n", __FILE__, __LINE__);

loop:
    goto loop;

    return 0;
}
