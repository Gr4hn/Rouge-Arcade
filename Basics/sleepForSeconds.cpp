#include "sleepForSeconds.h"

using namespace std;

void sleepForSeconds(int seconds) {
#ifdef _WIN32
    Sleep(seconds * 1000);
#else
    sleep(seconds);
#endif
}
