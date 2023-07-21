#include <stdio.h>
#include "include/file.h"

int main(int argc, char const *argv[])
{
    printf("time is %s %s\n", __DATE__, __TIME__);

    // 获取目录
    char user_file_path[MAX_PATH];
    get_save_path(user_file_path);

    return 0;
}


