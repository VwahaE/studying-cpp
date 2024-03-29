/*
* Лабораторная работа No1
* Исследование комментариев С++:
*
* Программа 2.
* Developer: Mochalov E.
*/

/* Подключаем библиотеку для ввода/вывода */
#include <iostream>

/* Подключаем библиотеку манипуляторов форматирования */
#include <iomanip>

/* подключаем пространство имен */
using namespace std;

// main - главная функция с которой начинается исполнение программы
int main(){

    // задает ширину поля 80 символов
    cout.width(80);

    // устанавливает символ заполнитель тире
    cout.fill('-');

    // вывод пустой строки с заполнителем
    cout << "" << endl;

    cout.fill(' ');
    cout << setw(5) <<"";
    cout.fill('*');
    cout << setw(5) <<"";

    cout.fill(' ');
    cout.width(30);
    cout << "ТУСУР";
    cout.width(30);
    cout << "";

    cout.fill('*');
    cout << setw(5) <<"";
    cout.fill(' ');
    cout << setw(5) <<"" << endl;

    // перевод каретки на новую строку
    cout << "\n\n\n\n";

    /* используем флаг форматирования (Выравнивание по левой границе) */
    cout.setf(ios::left);
    
    // использование манипуляторов форматирования
    /* setw(n) - определяет ширину поля вывода в n символов */
    cout << setw(50) <<"";
    cout << setw(20) << "Факультет: Доп. Образование" << endl;
    cout << setw(50) <<"";
    cout << setw(20) << "Группа: 315" << endl;
    cout << setw(50) <<"";
    cout << setw(20) << "Студент: Мочалов Евгений" << endl;

    // снятия флага
    cout.unsetf(ios::left);
    cout << "\n";
    cout << setw(42) << "Томск 2024" << endl;
    cout.width(80);
    cout.fill('-');
    cout << "" << endl;
    return 0;
}
