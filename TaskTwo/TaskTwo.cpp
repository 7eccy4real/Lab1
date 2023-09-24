/*
1.1) int* ptr = (int*)malloc(sizeof(int)) - int* ptr = new int
2) int* ptrArr = (int*)malloc(sizeof(int) * N) - int* ptrArr = new int[N]
3) free(ptr) - delete ptr
4) free(ptrArr) - delete[] ptrArr
2.В С++ необходимо ли освобождать динамическую память ?
 Да, оператором delete.
3.Можно ли освободить одну и ту же выделенную память дважды ?
 Нет, это приводит к недокументированному поведению.
4.Можно ли освободить невыделенную память ?
 Нет.
*/

#include <iostream>
int** createFibonacciTriangle(int rows) {
    int** triangle = new int* [rows];
    for (int i = 0; i < rows; i++) {
        triangle[i] = new int[i + 1];
        triangle[i][0] = 1;
        triangle[i][i] = 1;
        for (int j = 1; j < i; j++) {
            *(triangle[i] + j) = *(triangle[i - 1] + j - 1) + *(triangle[i - 1] + j);
        }
    }
    return triangle;
}

void printFibonacciTriangle(int** triangle, int rows) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j <= i; j++) {
            std::cout << *(*(triangle + i) + j) << " ";
        }
        std::cout << std::endl;
    }
}

void deleteFibonacciTriangle(int** triangle, int rows) {
    for (int i = 0; i < rows; i++) {
        delete[] triangle[i];
    }
    delete[] triangle;
}

int main() {
    setlocale(LC_ALL, "Russian");
    int rows;

    std::cout << "Введите количество строк: ";
    std::cin >> rows;

    int** fibonacciTriangle = createFibonacciTriangle(rows);

    printFibonacciTriangle(fibonacciTriangle, rows);

    deleteFibonacciTriangle(fibonacciTriangle, rows);

    return 0;
}