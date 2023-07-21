#include "include/file.h"

int get_save_path(TCHAR *file_path) {
    TCHAR my_documents_path[MAX_PATH];
    char user_documents_save_path[MAX_PATH];
    HRESULT result = SHGetFolderPath(NULL, CSIDL_PERSONAL, NULL, SHGFP_TYPE_CURRENT, my_documents_path);
    if (result != S_OK) {
        fprintf(stderr, "Failed to get My Documents folder path.\n");
        return 1;
    }
    // wprintf(L"My Documents folder path: %ls\n", my_documents_path);
    _tcscat(my_documents_path, _T("\\note\\"));
    printf("My Documents folder path: %ls\n", my_documents_path);
    // WideCharToMultiByte(CP_ACP, 0, my_documents_path, -1, user_documents_save_path, MAX_PATH, NULL, NULL);

    // printf("User Documents Path is %s\n", user_documents_save_path);
    _tcscpy(file_path, my_documents_path);
    // file_path = my_documents_path;
    return 0;
}

int get_file_list(TCHAR *file_path, char *file_list) {
    printf("path is %ls\n", file_path);
    WIN32_FIND_DATA pNextInfo;
    HANDLE hFile = FindFirstFile(_tcscat(file_path, _T("*")), &pNextInfo);
    if (hFile == INVALID_HANDLE_VALUE) {
        printf("Failed to open directory: %ls\n", file_path);
    }

    do {
        if (pNextInfo.cFileName[0] == '.')
            continue;
        if (pNextInfo.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
            printf("[DIR]");
        } else {
            printf("[File]");
        }

        wprintf(L"%ls\n", pNextInfo.cFileName);
    } while(FindNextFile(hFile, &pNextInfo));

    return 0;
}