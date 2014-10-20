//
//  main.c
//  Syntax_research
//
//  Created by Kate Polyakova on 10/12/14.
//  Copyright (c) 2014 Kate Polyakova. All rights reserved.
//

#include <stdio.h>
#include <math.h>

float distanceBetweenPoints(float x1, float y1, float x2, float y2); // объявление функции для вычисления расстояния между точками (задача 1)
int IsPointInsideCircly(float xa, float ya, float xo, float yo, float radius); // объявление функции, которая будет проверять попадает ли заданная точка внутрь круга (задача 2)
int CountSimilarDigits (int number); // объявление функции, которая будет проверять, есть ли среди цифр заданного трехзначного числа одинаковые цифры и возвращать количество одинаковых цифр (задача 3)
void MaxMinDigits (int number); // объявление функции, которая будет показывать наименьшую и наибольшую цифры, входящие в состав заданного трехзначного натурального числа (задача 4)
int Quarter (float x, float y); // объявление функции, которая будет определять номер четверти плоскости, в которой находится точка с координатами x и y (задача 5)

int main ()
{
    // А (x1, y1), B (x2, y2)
    float x1=0.0;
    float y1=5.0;
    float x2=2.0;
    float y2=8.0;
    
    float d = distanceBetweenPoints(x1, y1, x2, y2); // переприсвоение вещественному числу d результата работы функии, вычисляющей расстояния между точками (задача 1)
    
    printf("A (%.1f;%.1f), B (%.1f;%.1f)\n",x1, y1, x2, y2);
    printf("distance=%f\n\n",d);
    
    // A (xa, ya), центр окружности (xo, yo), радиус окружности radius
    
    IsPointInsideCircly(11.0, 4.0, 3.0, 7.0, 4.0); // вызов функции, провяряющей попадает ли заданная точка внутрь круга (задача 2)
    IsPointInsideCircly(1.0, 4.0, 3.0, 4.0, 5.0); // вызов функции, провяряющей попадает ли заданная точка внутрь круга с другими параметрами (задача 2)
    
    int digitsCount = CountSimilarDigits (836); //  присвоение целочисленному числу digitsCount результата работы функии, проверяющей, есть ли среди цифр заданного трехзначного числа одинаковые цифры и возвращающей количество одинаковых цифр (задача 3)
    printf("одинаковых цифр:%d\n", digitsCount);
    
    MaxMinDigits (836); // вызов функции, которая будет показывать наименьшую и наибольшую цифры, входящие в состав заданного трехзначного натурального числа (задача 4)
    
    digitsCount = CountSimilarDigits (595);
    printf("одинаковых цифр:%d\n", digitsCount);
    MaxMinDigits (595);
    
    digitsCount = CountSimilarDigits (444);
    printf("одинаковых цифр:%d\n", digitsCount);
    MaxMinDigits (444);
    
    Quarter (7, 6); // вызов функции, определяющей номер четверти плоскости, в которой находится точка задача 5)
    Quarter (7, -6); // еще раз вызов этой функции с другими координатами (задача 5)
    Quarter (-7, -6);
    Quarter (-7, 6);
    Quarter (0, -6);
    Quarter (-7, 0);
    
    return 0;
}


float distanceBetweenPoints(float x1, float y1, float x2, float y2) // выполнение функции вычисления расстояния между точками (задача 1)
{
    float d = sqrtf(powf((x2-x1),2)+powf((y2-y1),2));
    
    return d;
}


int IsPointInsideCircly(float xa, float ya, float xo, float yo, float radius) // реализация функции, которая будет проверять попадает ли заданная точка внутрь круга (задача 2)
{
    int result;
    printf ("центр окружности О (%.1f;%.1f), радиус:%.1f€\n", xo, yo, radius);
            
    float checkRadius = distanceBetweenPoints(xa, ya, xo, yo);
    
    if (radius > checkRadius)
    {
        result=1;
        printf ("точка A (%.1f;%.1f) находится внутри круга\n\n", xa, ya);
    }
    else
    {
        result=0;
        printf ("точка A (%.1f;%.1f) находится за пределами круга\n\n", xa, ya);
    }
    return result;
}

int CountSimilarDigits (int number) // выполнение функции, которая будет проверять, есть ли среди цифр заданного трехзначного числа одинаковые цифры и возвращать количество одинаковых цифр (задача 3)
{
    int Result=0;
    
    int digit1 = number%10; // получаю остаток от деления на 10, т.е. последнюю цифру числа
    int digit2 = (number/10)%10; // делю на 10 - получаю двухзначное число, и потом получаю остаток от деления на 10, т.е. среднюю цифру числа
    int digit3 = number/100; // делю на 100 - получаю первую цифру числа
    
    if ((digit1 == digit2) && (digit2 == digit3))
    {
        Result=3;
    }
    else if ((digit1 == digit2)||(digit2 == digit3)||(digit1 == digit3))
    {
        Result=2;
    }
    else
    {
        Result=0;
    }
    
    printf("%d\t%d\t%d\t\n",digit3, digit2, digit1);
    
    return Result;
}

void MaxMinDigits (int number) // выполнение функции, которая будет показывать наименьшую и наибольшую цифры, входящие в состав заданного трехзначного натурального числа (задача 4)
{
    int d1 = number%10;
    int d2 = (number/10)%10;
    int d3 = number/100;
    
    int Max=0;
    int Min=0;
    
    if (d1>=d2 && d1>=d3)
    {
        Max = d1;
    }
    else if (d2>=d1 && d2>=d3)
    {
        Max = d2;
    }
    else
    {
        Max = d3;
    };
    
    
    if (d1<=d2 && d1<=d3)
    {
        Min = d1;
    }
    else if (d2<=d1 && d2<=d3)
    {
        Min = d2;
    }
    else
    {
        Min = d3;
    };
    
    printf ("Max число:%d\nMin число:%d\n\n", Max, Min);
}

int Quarter (float x, float y) // выполнение функции, которая будет определять номер четверти плоскости, в которой находится точка с координатами x и y (задача 5)
{
    // printf("Координаты точки:x=%.1f\ty=%.1f\n",x ,y);
    
    int result;
    
    if (x>0 && y>0)
        
    {
        result = 1;
    }
    else if (x>0 && y<0)
    {
        result = 2;
    }
    else if (x<0 && y<0)
    {
        result = 3;
    }
    else  if(x<0 && y>0)
    {
        result = 4;
    }
    
    else  if((x==0)&&(y!=0))
    {
        result = 0;
        printf("Точка c координатами (%.1f;%.1f) принадлежит оси x\n", x, y);
    }
    else //if ((x!=0)&&(y==0))
    {
        result = 0;
        printf("Точка с координатами (%.1f;%.1f) принадлежит оси y\n", x, y);
    };
    
    if (result>0)
    {
      printf("Точка с координатами (%.1f;%.1f) находится в четверти:%d\n", x, y, result);
    }
    
    return result;
    
}



