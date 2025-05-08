#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

int main() {
    std::vector<std::pair<std::string, int>> students = {
        {"Alice", 85},
        {"Bob", 92},
        {"Charlie", 78},
        {"Diana", 95},
        {"Eve", 88}
    };

    std::sort(students.begin(), students.end(), [](const auto& a, const auto& b) {
        return b.second < a.second;
    });

    std::cout << "Ranked List of Students:" << std::endl;
    for (const auto& student : students) {
        std::cout << student.first << " - " << student.second << std::endl;
    }

    return 0;
}