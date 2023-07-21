#include "include/file.h"

int get_save_path(char *file_path) {
    wchar_t my_documents_path[MAX_PATH];
    char user_documents_save_path[MAX_PATH];
    HRESULT result = SHGetFolderPathW(NULL, CSIDL_PERSONAL, NULL, SHGFP_TYPE_CURRENT, my_documents_path);
    if (result != S_OK) {
        fprintf(stderr, "Failed to get My Documents folder path.\n");
        return 1;
    }
    // wprintf(L"My Documents folder path: %ls\n", my_documents_path);
    wcscat(my_documents_path, L"\\note\\");
    WideCharToMultiByte(CP_ACP, 0, my_documents_path, -1, user_documents_save_path, MAX_PATH, NULL, NULL);

    printf("User Documents Path is %s\n", user_documents_save_path);
    file_path = user_documents_save_path;
    return 0;
}