/**********************
 * Частота повторений *
 *********************/

#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream file("input.txt");
    std::ifstream file("C:\Users\Кирилл\Desktop\KemGu\Programming\Repetition rate\input.txt"); 
    if (!file) {
        std::cerr << "Ошибка: не удалось открыть файл input.txt\n";
        return 1;
    }

    // Читаем файл целиком
    std::string text((std::istreambuf_iterator<char>(file)),
                     std::istreambuf_iterator<char>());
    file.close();

    int letters[26] = {0};      // a-z
    int bigrams[26][26] = {0};  // биграммы

    for (size_t i = 0; i < text.length(); ++i) {
        char current = text[i];

        // Проверяем, что текущий символ — латинская буква
        if (std::isalpha(current) && std::tolower(current) >= 'a' && std::tolower(current) <= 'z') {
            int idx1 = std::tolower(current) - 'a';
            letters[idx1]++;

            // Проверяем следующий символ для биграммы
            if (i + 1 < text.length()) {  // Граница: не выходить за пределы строки
                char next = text[i + 1];
                if (std::isalpha(next) && std::tolower(next) >= 'a' && std::tolower(next) <= 'z') {
                    int idx2 = std::tolower(next) - 'a';
                    bigrams[idx1][idx2]++;
                }
            }
        }
    }

    // Вывод букв
    std::cout << "Частота букв:\n";
    for (int i = 0; i < 26; ++i) {
        if (letters[i] > 0) {
            std::cout << char('a' + i) << ": " << letters[i] << "\n";
        }
    }

    // Вывод биграмм
    std::cout << "\nЧастота двухбуквенных сочетаний:\n";
    for (int i = 0; i < 26; ++i) {
        for (int j = 0; j < 26; ++j) {
            if (bigrams[i][j] > 0) {
                std::cout << char('a' + i) << char('a' + j) << ": " << bigrams[i][j] << "\n";
            }
        }
    }

    return 0;
}
