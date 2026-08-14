#include "../includes/StringWrappers.h"
#include <windows.h>
#include <stdarg.h>

size_t StringWrappers::StringLength(const char* str) {
    return strlen(str);
}

size_t StringWrappers::StringLength(const wchar_t* str) {
    return wcslen(str);
}

int StringWrappers::StringCompare(const char* str1, const char* str2) {
    return strcmp(str1, str2);
}

int StringWrappers::StringCompare(const wchar_t* str1, const wchar_t* str2) {
    return wcscmp(str1, str2);
}

int StringWrappers::StringCompareN(const char* str1, const char* str2, size_t count) {
    return strncmp(str1, str2, count);
}

int StringWrappers::StringCompareN(const wchar_t* str1, const wchar_t* str2, size_t count) {
    return wcsncmp(str1, str2, count);
}

void StringWrappers::StringCopy(char* dest, size_t destSize, const char* src) {
    strcpy_s(dest, destSize, src);
}

void StringWrappers::StringCopy(wchar_t* dest, size_t destSize, const wchar_t* src) {
    wcscpy_s(dest, destSize, src);
}

void StringWrappers::StringCopyN(char* dest, size_t destSize, const char* src, size_t count) {
    strncpy_s(dest, destSize, src, count);
}

void StringWrappers::StringCopyN(wchar_t* dest, size_t destSize, const wchar_t* src, size_t count) {
    wcsncpy_s(dest, destSize, src, count);
}

int StringWrappers::StringFormat(char* buffer, size_t bufferSize, const char* format, ...) {
    va_list args;
    int result;
    va_start(args, format);
    result = vsprintf_s(buffer, bufferSize, format, args);
    va_end(args);
    return result;
}

int StringWrappers::StringFormat(wchar_t* buffer, size_t bufferSize, const wchar_t* format, ...) {
    va_list args;
    int result;
    va_start(args, format);
    result = vswprintf_s(buffer, bufferSize, format, args);
    va_end(args);
    return result;
}

int StringWrappers::StringScan(const char* buffer, const char* format, ...) {
    va_list args;
    int result;
    va_start(args, format);
    result = vsscanf_s(buffer, format, args);
    va_end(args);
    return result;
}

int StringWrappers::StringScan(const wchar_t* buffer, const wchar_t* format, ...) {
    va_list args;
    int result;
    va_start(args, format);
    result = vswscanf_s(buffer, format, args);
    va_end(args);
    return result;
}

void StringWrappers::ConvertNarrowToWide(const char* src, wchar_t* dest, size_t destSize, int srcSize) {
    if (!src || !dest || destSize == 0) return;
    MultiByteToWideChar(CP_ACP, 0, src, srcSize, dest, destSize);
    dest[destSize - 1] = L'\0';
}

void StringWrappers::ConvertWideToNarrow(const wchar_t* src, char* dest, size_t destSize, int srcSize) {
    if (!src || !dest || destSize == 0) return;
    WideCharToMultiByte(CP_ACP, 0, src, srcSize, dest, destSize, NULL, NULL);
    dest[destSize - 1] = '\0';
}
