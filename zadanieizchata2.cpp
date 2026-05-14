#include <iostream>
#include <list>

using namespace std;

int main() {

    setlocale(LC_ALL, "Russian");

    // создание и заполнение списка
    list<double> numbers = { -5, 10, -15, 20, -25, 30 };

    // вычисление суммы положительных элементов
    double sumPositive = 0;
    for (auto it = numbers.begin(); it != numbers.end(); ++it) { // цикл для перебора всех элементов numbers
        if (*it > 0) { // проверка, является ли элемент положительным
            sumPositive += *it; // добавляет положительный элемент к сумме
        }
    }

    cout << "Наши числа: ";
    for (const auto& num : numbers) { // вывод всех чисел из numbers
        cout << num << " ";
    }
    cout << endl; // пропуск строчки для красоты

    cout << "Сумма положительных элементов: " << sumPositive << endl; // вывод итогового значения

    return 0;
}