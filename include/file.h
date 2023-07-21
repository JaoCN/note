#if !defined(UNICODE)
#define UNICODE
#endif

#if !defined(_UNICODE)
#define _UNICODE
#endif

#include <windows.h>
#include <tchar.h>
#include <shlobj.h>
#include <stdio.h>

int get_save_path(TCHAR *file_path);
int get_file_list(TCHAR *file_path, char *file_list);
