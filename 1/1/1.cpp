#include <iostream>
#include <string>

using namespace std;

template <typename T>
int linearSearch(T arr[], int n, const T& key) {
    for (int i = 0; i < n; ++i) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1;
}

int main() {
    setlocale(LC_ALL, "ru");

    int intArr[] = { 10, 23, 45, 70, 11, 15 };
    int intSize = sizeof(intArr) / sizeof(intArr[0]);
    int intKey = 70;
    int intResult = linearSearch(intArr, intSize, intKey);
    cout << "Поиск числа " << intKey << " в массиве int:" << endl;
    if (intResult != -1) {
        cout << "Элемент найден под индексом: " << intResult << endl;
    }
    else {
        cout << "Элемент не найден." << endl;
    }
    double doubleArr[] = { 3.14, 2.71, 1.41, 1.73 };
    int doubleSize = sizeof(doubleArr) / sizeof(doubleArr[0]);
    double doubleKey = 1.41;

    int doubleResult = linearSearch(doubleArr, doubleSize, doubleKey);
    cout << "Поиск числа " << doubleKey << " в массиве double:" << endl;
    if (doubleResult != -1) {
        cout << "Элемент найден под индексом: " << doubleResult << endl;
    }
    else {
        cout << "Элемент не найден." << endl;
    }

    return 0;
}