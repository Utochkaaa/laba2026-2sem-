#include <iostream>
#include <map>
#include <string>
#include <sstream>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    
    int rows, cols;
    
    cout << "Введите количество строк и столбцов: ";
    cin >> rows >> cols;
    
    // Выделение памяти под матрицу
    int** matrix = new int*[rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[cols];
    }
    
    cout << "Введите элементы матрицы:" << endl;
    for (int i = 0; i < rows; i++) {
        cout << "Строка " << i + 1 << ": ";
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }
    
    // map автоматически сортируется по ключу
    map<string, int> dataMap;
    
    for (int i = 0; i < rows; i++) {
        stringstream rowStr;
        int sum = 0;
        
        for (int j = 0; j < cols; j++) {
            rowStr << matrix[i][j];
            if (j < cols - 1) rowStr << " ";
            sum += matrix[i][j];
        }
        
        dataMap[rowStr.str()] = sum;
    }
    
    // Вывод результата
    cout << "\nРезультат (сортировка по ключу):" << endl;
    for (auto& pair : dataMap) {
        cout << "Ключ: \"" << pair.first << "\" -> Сумма: " << pair.second << endl;
    }
    
    // Освобождение памяти
    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
    
    return 0;
}