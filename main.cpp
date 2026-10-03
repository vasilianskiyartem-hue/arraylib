#include <iostream>
#include <cstddef>
#include <algorithm>
#include <vector>

int arr_sum(const int* arr, std::size_t n) {
    int s = 0;
    for (std::size_t i = 0; i < n; i++) s += arr[i];
    return s;
}

int arr_max(const int* arr, std::size_t n) {
    if (n == 0) return 0;
    int m = arr[0];
    for (std::size_t i = 1; i < n; i++) if (arr[i] > m) m = arr[i];
    return m;
}

int arr_min(const int* arr, std::size_t n) {
    if (n == 0) return 0;
    int m = arr[0];
    for (std::size_t i = 1; i < n; i++) if (arr[i] < m) m = arr[i];
    return m;
}

double arr_average(const int* arr, std::size_t n) {
    if (n == 0) return 0.0;
    return static_cast<double>(arr_sum(arr, n)) / n;
}

int arr_count_positive(const int* arr, std::size_t n) {
    int c = 0;
    for (std::size_t i = 0; i < n; i++) if (arr[i] > 0) c++;
    return c;
}

int arr_count_negative(const int* arr, std::size_t n) {
    int c = 0;
    for (std::size_t i = 0; i < n; i++) if (arr[i] < 0) c++;
    return c;
}

int arr_count_zero(const int* arr, std::size_t n) {
    int c = 0;
    for (std::size_t i = 0; i < n; i++) if (arr[i] == 0) c++;
    return c;
}

int arr_product(const int* arr, std::size_t n) {
    int p = 1;
    for (std::size_t i = 0; i < n; i++) p *= arr[i];
    return p;
}

double arr_median(const int* arr, std::size_t n) {
    if (n == 0) return 0.0;
    std::vector<int> v(arr, arr + n);   // копия, чтобы не менять оригинал
    std::sort(v.begin(), v.end());
    if (n % 2 == 1) return v[n / 2];
    return (v[n / 2 - 1] + v[n / 2]) / 2.0;
}

int main() {
    int data[] = {5, 3, 8, 1, 9, 2};
    std::size_t n = 6;
    std::cout << "Sum: " << arr_sum(data, n) << '\n';
    std::cout << "Max: " << arr_max(data, n) << '\n';
    std::cout << "Min: " << arr_min(data, n) << '\n';
    std::cout << "Average: " << arr_average(data, n) << '\n';
    std::cout << "Positive: " << arr_count_positive(data, n) << '\n';
    std::cout << "Negative: " << arr_count_negative(data, n) << '\n';
    std::cout << "Zero: " << arr_count_zero(data, n) << '\n';
    std::cout << "Product: " << arr_product(data, n) << '\n';
    std::cout << "Median: " << arr_median(data, n) << '\n';
    return 0;
}
