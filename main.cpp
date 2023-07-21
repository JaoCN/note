#include <stdio.h>
#include "include/file.h"

int main(int argc, char const *argv[])
{
    printf("time is %s %s\n", __DATE__, __TIME__);

    // 获取目录
    TCHAR user_file_path[MAX_PATH];
    char file_list[100];
    get_save_path(user_file_path);
    get_file_list(user_file_path, file_list);



    return 0;
}


