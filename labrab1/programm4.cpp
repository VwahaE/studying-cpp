/*
* Лабораторная работа No1
* Исследование комментариев С++:
*
* Программа 4.
* Вычислить ускорение
* Developer: Mochalov E.
*/

/* Подключаем библиотеку для ввода/вывода */
#include <iostream>

/* Подключаем библиотеку манипуляторов форматирования */
#include <iomanip>

/* подключаем пространство имен */
using namespace std;

int main()
{

    cout << "Автомобиль начинает движение из состояния покоя и за время  \n";
    cout << " Введите значения времени (целое число) t = ";

    /* Инициализация переменной времени */
    float ValueTime;
    cin >> ValueTime;
    cout << "секунд он разгоняется до \n";
    cout << " Введите конечную скорость (целое число /"
            "или десятичная дробь разделитель точка) v = ";

    /* Инициализация переменной конечной скорости */
    float ValueSpeedEnd;
    cin >> ValueSpeedEnd;
    cout << "м/с. С каким ускорением двигался автомобиль?\n\n";

    /* Инициализация переменной начальной скорости */
    float ValueSpeedStart(0);

    /* Инициализация переменной ускорения */
    float ValueSpeedUp;

    /* расчет ускорения */
    ValueSpeedUp = (ValueSpeedEnd - ValueSpeedStart) / ValueTime;

    // Вывод на экран решения

    /* используем флаг форматирования (Выравнивание по левой границе) */
    cout.setf( ios::left);

    // использование манипуляторов форматирования
    // /t - табуляция по горизонтали.
    cout << setw(18)<< "\t Дано:" ;
    cout << setw(5) << "|";
    cout << setw(20) << "\tРешение:" << endl;

    cout << "\t v = " << ValueSpeedEnd << setw(10) << " (м/с)" << "|";
    cout  << setw(5) << "\t a = ( v - v0 )/t ;" << endl;

    cout << "\t v0 = " << ValueSpeedStart << setw(10) << " (м/с)" << "|";
    cout << "\t a = " << "( " << ValueSpeedEnd << " - " << ValueSpeedStart << ")/" << ValueTime <<";\n";

    cout << "\t t = " << ValueTime << setw(11) << " (с)" << "|";
    cout << "\t a = " << ValueSpeedUp << " м/c.\n";

    // устанавливает символ заполнитель тире
    cout.fill('-');

    // задает ширину поля 18 символов
    cout.width(18);
    cout << "\t" << "|\n";

    // устанавливает символ заполнитель пробел
    cout.fill(' ');
    cout << setw(18)<< "\t a - ?(м/c) " << "|\n";
    cout << "\nОтвет: Автомобиль двигался с ускорением a = " << ValueSpeedUp << " м/c.\n";

    return 0;
}