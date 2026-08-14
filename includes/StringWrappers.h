#pragma once
#include <cwchar>
#include <cstring>
#include <cstdio>
#include <cstdarg>

class StringWrappers {
public:
    static size_t StringLength(const char* str);
    static size_t StringLength(const wchar_t* str);

    static int StringCompare(const char* str1, const char* str2);
    static int StringCompare(const wchar_t* str1, const wchar_t* str2);

    static int StringCompareN(const char* str1, const char* str2, size_t count);
    static int StringCompareN(const wchar_t* str1, const wchar_t* str2, size_t count);

    static void StringCopy(char* dest, size_t destSize, const char* src);
    static void StringCopy(wchar_t* dest, size_t destSize, const wchar_t* src);

    static void StringCopyN(char* dest, size_t destSize, const char* src, size_t count);
    static void StringCopyN(wchar_t* dest, size_t destSize, const wchar_t* src, size_t count);

    static int StringFormat(char* buffer, size_t bufferSize, const char* format, ...);
    static int StringFormat(wchar_t* buffer, size_t bufferSize, const wchar_t* format, ...);

    static int StringScan(const char* buffer, const char* format, ...);
    static int StringScan(const wchar_t* buffer, const wchar_t* format, ...);

    static void ConvertNarrowToWide(const char* src, wchar_t* dest, size_t destSize, int srcSize = -1);
    static void ConvertWideToNarrow(const wchar_t* src, char* dest, size_t destSize, int srcSize = -1);
};
