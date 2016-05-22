//
//  main.cpp
//  laba#1
//
//  Created by Denis on 13.03.16.
//  Copyright © 2016 DenisM. All rights reserved.
//

#include <iostream>
#include <string>
#include <stdlib.h>
#include <sstream>
#include <fstream>
#include <unistd.h>
#include <stdio.h>
#include <getopt.h>

using namespace std;

string ReadFile( string *file_name){
    //string *stroka;
    setlocale(LC_ALL,"Russian");
    string s;
    string ss;
    cout<<"Read of file...\n";
    ifstream in;
    //in.open("/Users/denis/Desktop/KMZ/laba1/laba#1/laba#1/main.cpp");
    in.open(*file_name);
    while (!in.eof()) {
        getline(in,s);
        ss = ss + "\n" + s;
    }
    //s[s.length()-1]='\0';
    cout<<"Text of file (Текст файла) : \n"<< ss <<endl;
    in.close();
    cout<<"Reading complete! (Текст прочитан) \n";
    return ss;
}

void Encription( string s, string key, char **tabula_recta ){
    string key_on_s = "";
    bool flag;
    int registr = 0; //Регистр символа
    string result = ""; //Строка - результат
    int x = 0, y = 0; //Координаты нового символа из таблицы Виженера
    char dublicat; //Дубликат прописной буквы
    cout<<"Encryption (Зашфровка) ...\n";
    //Формирование строки, длиной шифруемой, состоящей из повторений ключа
    for (int i = 0; i < s.length(); i++)
    {
        key_on_s += key[i % key.length()];
    }
    //Шифрование при помощи таблицы
    for (int i = 0; i < s.length(); i++)
    {
        //Если нешифруемый символ
        if (((int)(s[i]) < 65) || ((int)(s[i]) > 122))
            result += s[i];
        else
        {
            //Поиск в первом столбце строки, начинающейся с символа ключа
            int l = 0;
            flag = false;
            //Пока не найден символ
            while ((l < 26) && (flag == false))
            {
                //Если символ найден
                if (key_on_s[i] == tabula_recta[l][0])
                {
                    //Запоминаем в х номер строки
                    x = l;
                    flag = true;
                }
                l++;
            }
            //Уменьшаем временно регистр прописной буквы
            if (((int)(s[i]) <= 90) && ((int)(s[i]) >= 65))
            {
                dublicat = (char)((int)(s[i]) + 32);
                registr = 1;
            }
            else
            {
                registr = 0;
                dublicat = s[i];
            }
            l = 0;
            flag = false;
            //Пока не найден столбец в первой строке с символом строки
            while ((l < 26) && (flag == false))
            {
                if (dublicat == tabula_recta[0][l])
                {
                    //Запоминаем номер столбца
                    y = l;
                    flag = true;
                }
                l++;
            }
            //Увеличиваем регистр буквы до прописной
            if (registr == 1)
            {
                //Изменяем символ на первоначальный регистр
                dublicat = char((int)(tabula_recta[x][y]) - 32);
                result += dublicat;
            }
            else
                result += tabula_recta[x][y];
        }
    }
    cout<<"Кодирование завершено!\n";
    cout<<"Результат:" <<result <<endl;
}

void Decryption( string s, string key,char **tabula_recta){
    string key_on_s = "";
    bool flag;
    int registr = 0; //Регистр символа
    string result = ""; //Строка - результат
    int x = 0, y = 0; //Координаты нового символа из таблицы Виженера
    char dublicat; //Дубликат прописной буквы
    
    cout<<"Decryption (Дешифровка) ...\n";
    for (int i = 0; i < s.length(); i++)
    {
        key_on_s += key[i % key.length()];
    }
    //Дешифрование при помощи таблицы
    for (int i = 0; i < s.length(); i++)
    {
        //Если недешифруемый символ
        if (((int)(s[i]) < 65) || ((int)(s[i]) > 122))
            result += s[i];
        else
        {
            //Поиск в первом столбце строки, начинающейся с символа ключа
            int l = 0;
            flag = false;
            //Пока не найден символ
            while ((l < 26) && (flag == false))
            {
                //Если символ найден
                if (key_on_s[i] == tabula_recta[l][0])
                {
                    //Запоминаем в х номер строки
                    x = l;
                    flag = true;
                }
                l++;
            }
            //Уменьшаем временно регистр прописной буквы
            if (((int)(s[i]) <= 90) && ((int)(s[i]) >= 65))
            {
                dublicat = (char)((int)(s[i]) + 32);
                registr = 1;
            }
            else
            {
                registr = 0;
                dublicat = s[i];
            }
            l = 0;
            flag = false;
            //Пока не найден столбец в x строке с символом строки
            while ((l < 26) && (flag == false))
            {
                if (dublicat == tabula_recta[x][l])
                {
                    //Запоминаем номер столбца
                    y = l;
                    flag = true;
                }
                l++;
            }
            //Увеличиваем регистр буквы до прописной
            if (registr == 1)
            {
                //Изменяем символ на первоначальный регистр
                dublicat = char((int)(tabula_recta[0][y]) - 32);
                result += dublicat;
            }
            else
                result += tabula_recta[0][y];
        }
    }
    cout<<"Дешифровка завершена!\n";
    cout<<"Результат: "<<result<<endl;
}

//int main(int argc, const char * argv[]) {
int main (int argc, char **argv){
    setlocale(LC_ALL, "Russian");
    string alfabet = "abcdefghijklmnopqrstuvwxyz"; //Алфавит латиницы
    string key = ""; //Строка - ключ
    int shift = 0;
    char **tabula_recta = new char *[26]; //Таблица Виженера

    string stroka;
    string file;
    
    bool vid1 = false;
    bool vid2 = false;
    
    //Формирование таблицы Виженера на алфавите латиницы
    for (int i=0;i<26;i++)
        tabula_recta[i] = new char [26];
    
    //Формирование таблицы
    for (int i = 0; i < 26; i++)
        for (int j = 0; j < 26; j++)
        {
            shift = j + i;
            if (shift >= 26) shift = shift % 26;
            tabula_recta[i][j] = alfabet[shift];
        }
    
    int c = 0;
    while ((c = getopt(argc, argv, "k:f:ed"))!= -1) {
        switch (c) {
            case 'k':
                //key = "kot";
                key = optarg;
                break;
            case 'f':
                file = optarg;
                break;
            case 'e':{
                vid1 = true;
                //stroka = ReadFile(&file);
                //Encription(stroka, key, tabula_recta);
                break;
            }
            case 'd':{
                vid2 = true;
                //stroka = ReadFile(&file);
                //Decryption(stroka, key, tabula_recta);
                break;
            }
            case '?':
                if (optopt == 'k' || optopt == 'f')
                    fprintf (stderr, "Option -%c requires an argument.\n", optopt);
                else if (isprint (optopt))
                    fprintf (stderr, "Unknown option `-%c'.\n", optopt);
                else
                    fprintf (stderr, "Unknown option character `\\x%x'.\n", optopt);
                return 1;
            default:
                printf("Неизвестная опция");
                break;
        }
    }
    
    if (vid1 == true && vid2 == true)
        printf("Ключ -e и -d нельзя вводить вместе");
    
    if (vid1 == true) {
        stroka = ReadFile(&file);
        Encription(stroka, key, tabula_recta);
    } else {
        stroka = ReadFile(&file);
        Decryption(stroka, key, tabula_recta);
    }
    printf("\t программа завершила свою работу.\n");
    printf("\t The end!\n");
    
    return 0;
}
