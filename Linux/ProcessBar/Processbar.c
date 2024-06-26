#include "Processbar.h"
#include <string.h>
#include <unistd.h>

//void ForTest()
//{
//    printf("test\n");
//    printf("test\n");
//    printf("test\n");
//    printf("test\n");
//    printf("test\n");
//    printf("test\n");
//}

#define Length 101
#define Style '='
const char* label = "|/-\\";
//version 1
//void ProcBar()
//{
//    char bar[Length];
//    memset(bar, '\0', sizeof(bar));
//    size_t len = strlen(label);
//    int cnt = 0;
//    while(cnt <= 100)
//    {
//        printf("[%-100s][%3d%%][%c]\r", bar, cnt, label[cnt % len]);
//        fflush(stdout);
//        bar[cnt] = Style;
//        cnt++;
//        usleep(20000);
//    }
//    printf("\n");
//
//}

void ProcBar(double total, double current)
{
    char bar[Length];
    memset(bar, '\0', sizeof(bar));
    size_t len = strlen(label);

    int cnt = 0;
    double rate = (current * 100.0) / total; 
    int loop_count = (int)rate;
    while(cnt <= loop_count)
    {
        bar[cnt] = Style;
        cnt++;
    }
    printf("[%-100s][%.1lf%%][%c]\r", bar, rate, label[cnt % len]);
    fflush(stdout);
}

