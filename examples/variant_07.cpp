#include "arraylib.h"

#include <cstddef>
#include <iomanip>
#include <iostream>

int main() {
    int grades[] = {4, 5, 3, 4, 5, 5, 4, 3, 4, 5};
    const std::size_t n = sizeof(grades) / sizeof(grades[0]);

    std::cout << std::fixed << std::setprecision(2);

    std::cout << "Количество дисциплин: " << n << '\n';
    std::cout << "Исходные оценки:";
    for (std::size_t i = 0; i < n; ++i) {
        std::cout << ' ' << grades[i];
    }
    std::cout << '\n';

    // Подсчёт условий, которых нет в библиотеке, делаем циклом
    int fives = 0;
    int below_four = 0;
    for (std::size_t i = 0; i < n; ++i) {
        if (grades[i] == 5) {
            ++fives;
        }
        if (grades[i] < 4) {
            ++below_four;
        }
    }

    std::cout << "Средняя оценка: " << arr_average(grades, n) << '\n';
    std::cout << "Максимальная оценка: " << arr_max(grades, n) << '\n';
    std::cout << "Минимальная оценка: " << arr_min(grades, n) << '\n';
    std::cout << "Количество пятёрок: " << fives << '\n';
    std::cout << "Количество оценок ниже 4: " << below_four << '\n';
    std::cout << "Медиана оценок: " << arr_median(grades, n) << '\n';

    return 0;
}
