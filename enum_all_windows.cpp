#include <iostream>
#include <iomanip>
#include <sstream>
#include <ctime>

#include <Windows.h>
#include <Windowsx.h>
#include <commctrl.h>


BOOL CALLBACK print_window_details(HWND hwnd, LPARAM lParam);


void print_windows_info(HWND parent=NULL, int level=0)
{
    if (parent==NULL)
    {
        EnumWindows(&print_window_details, 0);
    }
    else
    {
        EnumChildWindows(parent, &print_window_details, level+1);
    }
}


BOOL CALLBACK print_window_details(HWND hwnd, LPARAM lParam)
{
    int level = (int)lParam;

    TCHAR name[256];
    TCHAR title[156];
    GetClassName(hwnd, name, 256);
    int r = GetWindowText(hwnd, title, 256);
    if (r == 0)
    {
        std::wcout << level << " HWND: " << hwnd << "\t" << "Name: " << name << std::endl;
    }
    else
    {
        std::wcout << level << " HWND: " << hwnd << "\t" << "Name: " << name << "\t" << "Title: " << title << std::endl;
    }
    std::wcout.flush();

    print_windows_info(hwnd, level);
    return TRUE;
}


int main()
{
    print_windows_info();
    return 0;
}
