#include <iostream>
#include <bitset>
#include <string>

using namespace std;

// Функция для разбиения строки ip по точкам и заполнения массива из 4 чисел
void parseIP(const string& ip, unsigned char bytes[4]) {
    size_t start = 0, end = 0;
    int index = 0;
    // npos - константа для индикации отсутствия позиции символа
    while ((end = ip.find('.', start)) != string::npos) {
        bytes[index++] = static_cast<unsigned char>(stoi(ip.substr(start, end - start)));
        start = end + 1;
    }
    bytes[index] = static_cast<unsigned char>(stoi(ip.substr(start)));
    // stoi - преобразует строку в целое число
    // substr - извлекает подстроку
}

// Функция для вывода числа в двоичном виде
string toBinary(unsigned char byte) {
    return bitset<8>(byte).to_string();
}

// Функция для побитового AND двух ip
void bitwiseAND(const unsigned char A[4], const unsigned char B[4], unsigned char res[4]) {
    for (int i = 0; i < 4; ++i) {
        res[i] = A[i] & B[i];
    }
}

// Функция для сравнения двух ip, возвращает true если равны
bool compareIPs(const unsigned char A[4], const unsigned char B[4]) {
    for (int i = 0; i < 4; ++i) {
        if (A[i] != B[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    // поддержка русского языка
    setlocale(LC_ALL, "RUS");

    // ip адреса для варианта 29
    string A = "192.168.29.1";
    string B = "172.16.32.11";
    string C = "255.255.255.0";

    // массивы для хранения чисел
    unsigned char Achar[4];
    unsigned char Bchar[4];
    unsigned char Cchar[4];

    // преобразование ip в массивы байт
    parseIP(A, Achar);
    parseIP(B, Bchar);
    parseIP(C, Cchar);

    // вывод числа A в двоичном виде (задание 1)
    cout << "1. Число A (" << A << ") в двоичной системе:" << endl;
    for (int i = 0; i < 4; ++i) {
        cout << toBinary(Achar[i]) << " ";
    }
    cout << endl << endl;

    // вывод числа B в двоичном виде (задание 2)
    cout << "2. Число B (" << B << ") в двоичной системе:" << endl;
    for (int i = 0; i < 4; ++i) {
        cout << toBinary(Bchar[i]) << " ";
    }
    cout << endl << endl;

    // вывод числа C в двоичном виде (задание 3)
    cout << "3. Число C (" << C << ") в двоичной системе:" << endl;
    for (int i = 0; i < 4; ++i) {
        cout << toBinary(Cchar[i]) << " ";
    }
    cout << endl << endl;

    // поразрядное умножение A & C и B & C (задание 4)
    unsigned char resultA[4];  // результат A & C
    unsigned char resultB[4];  // результат B & C

    bitwiseAND(Achar, Cchar, resultA);
    bitwiseAND(Bchar, Cchar, resultB);

    cout << "4. Результат поразрядного умножения A & C:" << endl;
    for (int i = 0; i < 4; ++i) {
        cout << toBinary(resultA[i]) << " ";
    }
    cout << endl;

    cout << "   Результат поразрядного умножения B & C:" << endl;
    for (int i = 0; i < 4; ++i) {
        cout << toBinary(resultB[i]) << " ";
    }
    cout << endl << endl;

    // сравнение результатов (задание 5)
    bool isEqual = compareIPs(resultA, resultB);

    cout << "5. Сравнение результатов (A & C) == (B & C): ";
    cout << (isEqual ? "True" : "False") << endl;

    return 0;
}