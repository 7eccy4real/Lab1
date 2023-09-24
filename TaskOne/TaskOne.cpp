/*
  1.1) strlen - string::length
  2) strcpy - аналога нет, поэтому пишем (a = b)
  3) strcmp - аналога нет
  4) strcat - someString.append
  5) somestring[index] - someString.at(index)
  6) не имеет точного аналога (возможно использовать strcat)  - push_back
  7) не имеет аналога - pop_back

  2.Строки в C - массив элементов char с null-байтом в окончании
  Строки в C++ - обЪект класса string с динамической памятью
  */

#include <iostream>
#include <string>

int main() {
    setlocale(LC_ALL, "Russian");
    std::string input;
    std::cout << "Введите строку: ";
    std::getline(std::cin, input);
    std::string cleanedInput;
    for (char c : input) {
        if (!std::isspace(c) && !std::ispunct(c)) {
            cleanedInput += c;
        }
    }
    for (int i = 0; i < cleanedInput.length() - 1; i++) {
        for (int j = 0; j < cleanedInput.length() - i - 1; j++) {
            if (cleanedInput[j] > cleanedInput[j + 1]) {
                char temp = cleanedInput[j];
                cleanedInput[j] = cleanedInput[j + 1];
                cleanedInput[j + 1] = temp;
            }
        }
    }
    std::cout << "Результат: " << cleanedInput << std::endl;
    return 0;
}