#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

bool isInArray(int* arr, int size, int value) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == value) return true;
    }
    return false;
}

void printMatrix(int** matr, int rows, int cols, const string& name) {
    cout << name << ":" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matr[i][j] << "\t";
        }
        cout << endl;
    }
}

void printArray(int* arr, int size, const string& name) {
    cout << name << ": ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    setlocale(LC_ALL, "Russian");
    srand(time(0));
    int m, n, k, minVal, maxVal;
    cout << "Введите M (строки), N (столбцы), K (размер N): ";
    cin >> m >> n >> k;
    cout << "Введите min и max для случайных чисел: ";
    cin >> minVal >> maxVal;
    int** M = new int*[m];
    for (int i = 0; i < m; i++) M[i] = new int[n];
    int* N = new int[k];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            M[i][j] = minVal + rand() % (maxVal - minVal + 1);
        }
    }
    for (int i = 0; i < k; i++) {
        N[i] = minVal + rand() % (maxVal - minVal + 1);
    }
    cout << "\n=== Исходные данные ===" << endl;
    printMatrix(M, m, n, "Матрица M");
    printArray(N, k, "Массив N");
    int replaceCount = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (isInArray(N, k, M[i][j])) {
                M[i][j] = 0;
                replaceCount++;
            }
        }
    }
    cout << "\n=== Результат ===" << endl;
    cout << "Количество замен: " << replaceCount << endl;
    printMatrix(M, m, n, "Матрица M после замен");
    for (int i = 0; i < m; i++) delete[] M[i];
    delete[] M;
    delete[] N;
    return 0;
}