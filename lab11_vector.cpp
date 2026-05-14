#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void printVector(const vector<int>& vec, const string& name) {
    cout << name << ": ";
    for (int val : vec) cout << val << " ";
    cout << endl;
}

int main() {
    setlocale(LC_ALL, "Russian");
    vector<int> original;
    int n, value;
    cout << "Введите количество элементов: ";
    cin >> n;
    cout << "Введите " << n << " чисел: ";
    for (int i = 0; i < n; i++) {
        cin >> value;
        original.push_back(value);
    }
    printVector(original, "Исходный вектор");
    int sumPositive = 0, sumNegative = 0;
    for (int val : original) {
        if (val > 0) sumPositive += val;
        else if (val < 0) sumNegative += val;
    }
    int diff = abs(sumPositive - sumNegative);
    cout << "Сумма положительных: " << sumPositive << endl;
    cout << "Сумма отрицательных: " << sumNegative << endl;
    cout << "Модуль разности: " << diff << endl;
    if (diff > 50) {
        cout << "Разность > 50. Создаём новый вектор..." << endl;
        vector<int> newVector;
        for (int val : original) newVector.push_back(-val);
        printVector(newVector, "Новый вектор (с изменённым знаком)");
    } else {
        cout << "Разность <= 50. Новый вектор не создаётся." << endl;
    }
    return 0;
}