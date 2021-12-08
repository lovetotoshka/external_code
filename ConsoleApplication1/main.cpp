#include <iostream>
#include "dialog.h"
#include "../StaticLib1/framework.h"


#define __CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#define DEBUG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
#define new DEBUG_NEW
int main()
{
    dialog();
    _CrtDumpMemoryLeaks();
    return 0;
}

