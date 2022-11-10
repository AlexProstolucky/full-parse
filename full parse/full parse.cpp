#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include<windows.h>
#include<psapi.h>
#include <wininet.h>
#include "nlohmann\json.hpp"
#pragma comment(lib, "Wininet.lib")
using namespace std;
using namespace nlohmann;
bool checkINTERNET()
{
    char url[256];
    strcat(url, "http://170.187.134.184");
    bool isconnect = InternetCheckConnectionA(url, FLAG_ICC_FORCE_CONNECTION, 0);
    if (!isconnect) return 0;
    return 1;
}

void loading() 
{
    system("Color 0B");
    char x = 219;
    cout << "\n\n\n\n\n\n\n\n\n\n";
    cout << "\t\t\t\t\tLoading...";
    for (size_t i = 0; i < 35; i++)
    {
        cout << x;
        if (i < 10) Sleep(500);
        if (i >= 10 && i < 30) Sleep(300);
        if (i >= 30) Sleep(50);
    }
    cout << "\n\n\n\n\n\n\n\n\n\n";
    system("Color 7");
    system("cls");
}


int main()
{
    json course;
    json cripto;

    if (checkINTERNET()) 
    {
        system("start parce_course.exe");
        system("start cripto.exe");
    }


    loading();
    try {
        fstream file;
        file.open("Course/course.json");
        file >> course;
        file.close();

        file.open("Cripto/cripto.json");
        file >> cripto;
        file.close();
        cout << "Loading and parse ended";
    }
    catch (...) 
    {
        cout << "File not found!" << endl;
    }
}