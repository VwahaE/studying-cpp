/*
* Лабораторная работа No1
* Исследование комментариев С++:
*
* Программа 5.
* Вычислить радиус круга
* Developer: Mochalov E.
*/

/* Подключаем библиотеку ввода/вывода printf/scanf */
#include <stdio.h>

// устанавливаем константу типа float
const float PI = 3.14;

int main()
{
    //Обычные символы
    printf("Найдите радиус окружности, если длинна окружности равна\n");
    printf("введите длинну окружности :");
    
    // данное именование переменной не сработало
    //float СircumСircle;

    /* объявляем переменную длинна окружности */
    float cCircle;

    //ввод данных в консоли c использованием функции scanf().
    /* cпецификатор %f - десятичное число с плавающей точкой */
    scanf("%f", &cCircle);

    /* объявляем переменную радиус окружности */
    float radius;

    /* производим расчёт радиуса окружности*/
    radius = (cCircle*PI)/(2*PI);

    // Вывод на экран решения
    /* вывод 1 строки с использованием raw-литералов или
     * Escape-последовательности.
     * \n - Перевод строки.
     * \t - Табуляция по горизонтали.
     */
    printf("\n\t\tДано:");
    printf("\t\t|");
    printf("\tРешение:\n");
/*------------------------------------------------------------------*/
    // вывод 2 пустой строки с вертикальной чертой
    printf("\t\t\t\t|\n");
/*------------------------------------------------------------------*/
    printf("\tC = %.2f * PI см.", cCircle);
    printf("\t|");
    printf("\tC = 2*PI*R;\n");
/*------------------------------------------------------------------*/
    /* использование константы, спецификаторы формата %.2f
     * где .2 указывает количество знаков после запятой */
    printf("\tPI = %.2f", PI);
    printf("\t\t|");
    printf("\t2*PI*R = %.2f * PI;\n",cCircle);
/*------------------------------------------------------------------*/
    printf("\t------------------------|");
    printf("\tR = (%.2f * PI)/(2*PI);\n", cCircle);
/*------------------------------------------------------------------*/
    printf("\tНайти: R - ?");
    printf("\t\t|");
    printf("\tR = %.2f см.\n", radius);
/*------------------------------------------------------------------*/
    printf("\n\tОтвет: радиус окружности R = %.2f см.",radius);
    return 0;
}
