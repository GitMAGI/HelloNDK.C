#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

#include "custom/log.h"
#include "custom/util.h"

#if defined _WIN64 || defined _WIN32
    #include <Windows.h>
#else
    #include <unistd.h>
#endif

int main(int argc, char* argv[]){
#if defined _WIN64 || defined _WIN32
    // disable buffering, we want logs immediately
    // even line buffering (setvbuf() with mode _IOLBF) is not sufficient
    setbuf(stdout, NULL);
    setbuf(stderr, NULL);
#endif
    struct timeval st, et;
    getTick(&st);

	infoLog("Application starting ...");

    // Fake Sleep
    #if defined _WIN64 || defined _WIN32
        Sleep(1123);
    #else
        usleep(1123);
    #endif

    end:
    getTick(&et);
    infoLog("Application Completed. ETA %s", getETA(st, et));

    return 0;
}