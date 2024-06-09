#include <iostream>
#include <vector>    // std::vector
#include <list>      // std::list
#include <algorithm> // std::transform
#include <random>
#include <ctime>

// прямой порядок вывода контейнера типа vector
void printRevers(std::vector<int>& stack,
                 std::vector<int>::reverse_iterator beg,
                 std::vector<int>::reverse_iterator end){
    for (auto p{ beg };  p != end; ++p)
        std::cout << *p << ' ';
}

// обратный порядок вывода контейнера типа vector
void printForward(std::vector<int> &stack,
                  std::vector<int>::iterator beg,
                  std::vector<int>::iterator end){

    for (auto p{ beg };  p != end; ++p)
        std::cout << *p << ' ';
}

//глобальная переменная счетчик
int counter(0);

//Функция, которая будет передаваться в алгоритм
void print(int i) {
    //просто выводит параметр на экран
    std::cout << i << " ";
}

// Функция, чёт / не чёт
int isReplace (int const& a, int &b) {
    counter++;
    if (counter % 2){
        return b;
    }
    return a;
}

void vecMix(std::vector<int> &v, std::list<int> &l){
    std::cout<< "\n\tmyVector: ";

    // Алгоритм for_each для обхода контейнера
    std::for_each(v.begin(), v.end(), print);
    std::cout<< "\n\tmyList: ";
    std::for_each(l.begin(), l.end(), print);
    /*
     * Подготавливаем размер для "Смешанного вектора"
     * и при необходимости меняем размер myVector
    */
    int sizeMix(0);
    if(v.size() >= l.size()) sizeMix = v.size();
    else {
        sizeMix = l.size();
        v.resize( v.size()+(l.size() - v.size()));
    }
    //Инициализируем смешанный вектор
    std::vector<int> mixVec(sizeMix);

    // Копирует элементы из список в смешанный вектор
    std::copy(l.begin(),l.end(), mixVec.begin());
    // Меняем местами элементы в смешанном векторе
    for(int j = 1; j < mixVec.size(); j += 2)
    {
        if(j < mixVec.size()) {
            int temp = mixVec[j];
            mixVec[j] = mixVec[j - 1];
            mixVec[j - 1] = temp;
        }
    }

    // Используем std::transform перегрузку, которая принимает два диапазона входных итераторов
    std::transform(mixVec.begin(), mixVec.end(), v.begin(), mixVec.begin(), isReplace);
    std::cout<< "\n\tСмешанный вектор: ";
    std::for_each(mixVec.begin(), mixVec.end(), print);
    std::cout <<"\n";
}

int main() {
    int task(1);
    /******************************* Задание 2 ***************************************/
    std::cout << "\tЗадание "<< ++task <<"\n\n";
    std::cout << "Введите целое число N (значение должно быть от 1 до 1000): ";
    unsigned int N;
    std::cin >> N;
    bool isRightNumber = false;
    while(isRightNumber == false){

        if(std::cin.fail() || (N < 1 || N > 1000) || (!(int)N)){

            // Очищаем ввод пользователя
            std::cin.clear();

            // Ввод должен игнорироваться предел равен максимуму
            // основным условием, которое следует учитывать, является только '\n'
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Чило N введено не верно! Введите заново: ";
            std::cin >> N;
        }
        else {
            // std::cout << "Чило N = "<< N <<" введено верно!";
            // std::array<int, N> mas {};

            isRightNumber = true;
        }
    }
    std::default_random_engine gen(time(NULL));
    std::uniform_int_distribution<int> dist(-10,10);
    std::vector<int> myVector;
    //заполняем в цикле контейнер vector случайными числами
    for (int i = 0; i < N; ++i){
        myVector.push_back(dist(gen));
    }

    std::cout << "Содержимое контейнера:\n";
    for(int &ar : myVector){
        std::cout << ar << " ";
    }
    std::cout << "\n\n";
    std::sort(myVector.begin(), myVector.end());

    // объявляем итератор
    std::vector<int>::iterator newVec;

    // Удаляем все последовательно повторяющиеся элементы из диапазона
    // [myVector.begin(), myVector.end()]
    newVec = std::unique(myVector.begin(), myVector.end());

    // удаляем промежуток элементов с итераторами newVec и end.
    myVector.erase(newVec, myVector.end());

    std::cout << "Уникальных чисел: " << myVector.size() <<"\n";

    /******************************* Задание 3 ***************************************/
    std::cout << "\tЗадание "<< ++task <<"\n\n";

    // инициализация контейнера типа vector
    std::vector<int> data;

    // Заполнение в цикле for от 0 до 10
    for(int i = 0; i < 10; ++i){
        data.push_back(i);
    }

    // вывод в консоль
    std::cout << "\n";
    std::cout << "Содержимое контейнера Forward:\n";
    printForward(data, data.begin(), data.end());
    std::cout << "\n";
    std::cout << "Содержимое контейнера Revers:\n";
    printRevers(data, data.rbegin(), data.rend());
    std::cout << "\n";
    std::cout << "\n";
    /******************************* Задание 4 ***************************************/
    std::cout << "\tЗадание "<< ++task <<"\n\n";
    int input_v , m, n;
    std::vector<int> myVector1;
    std::cout<< "\n\tBведите размер вектора (myVector): ";
    std::cin >> m;
    std::cout<< "\n\tBведите вектор(myVector): ";

    // Заполняем вектор myVector
    for(int i = 0; i< m; i++){
        std::cin >> input_v;
        myVector1.push_back(input_v);
    }
    std::cout<<"\n";
    std::cout<< "\n\tВведите размер списка(myList): ";
    std::cin >> n;
    int input_l;
    std::list<int> myList;
    std::cout<< "\n\tВведите список: ";

    // Заполняем список myList
    for(int i = 0; i< n; i++){
        std::cin >> input_l;
        myList.push_back(input_l);
    }

    vecMix(myVector1, myList);

    return 0;
}
