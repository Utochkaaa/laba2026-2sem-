#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    // поддержка русского языка
    setlocale(LC_ALL, "Russian");
    
    // Создаем вектор символов (только латинские буквы)
    vector<char> charVector = { 'H', 'e', 'l', 'l', 'o', ' ', 'w', 'o', 'r', 'l', 'd' };
    
    // Способ 1: Конвертируем вектор символов в строку с помощью конструктора
    string result1(charVector.begin(), charVector.end());
    
    // Способ 2: Альтернативный способ через цикл
    string result2 = "";
    for (int i = 0; i < charVector.size(); i++) {
        result2 = result2 + charVector[i];
    }
    
    // Выводим вектор символов
    cout << "Вектор символов: ";
    for (int i = 0; i < charVector.size(); i++) {
        cout << charVector[i];
    }
    cout << endl;
    
    // Выводим полученную строку (способ 1)
    cout << "Полученная строка (конструктором): " << result1 << endl;
    
    // Выводим полученную строку (способ 2)
    cout << "Полученная строка (циклом): " << result2 << endl;
    
    // Дополнительно: проверка размера
    cout << "\nРазмер вектора: " << charVector.size() << endl;
    
    // Проверка на пустоту
    if (!charVector.empty()) {
        cout << "Вектор не пустой. Первый символ: " << charVector[0] << endl;
    }
    
    // Добавление нового символа в конец
    charVector.push_back('!');
    cout << "После добавления символа: ";
    for (char c : charVector) {
        cout << c;
    }
    cout << endl;
    
    // Преобразуем обновлённый вектор в строку
    string finalString(charVector.begin(), charVector.end());
    cout << "Итоговая строка: " << finalString << endl;
    
    return 0;
}