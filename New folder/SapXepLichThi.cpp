#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int N, M;
    std::cout << "Enter the number of classes and the number of exam rooms: ";
    std::cin >> N >> M;

    std::vector<int> classes(N);
    std::vector<int> rooms(M);

    std::cout << "Enter the number of students in each class:\n";
    for (int i = 0; i < N; ++i) {
        std::cin >> classes[i];
    }

    std::cout << "Enter the capacity of each exam room:\n";
    for (int i = 0; i < M; ++i) {
        std::cin >> rooms[i];
    }

    std::sort(classes.begin(), classes.end(), std::greater<int>());
    std::sort(rooms.begin(), rooms.end(), std::greater<int>());

    int roomIndex = 0;
    for (int i = 0; i < N; ++i) {
        if (roomIndex < M && rooms[roomIndex] >= classes[i]) {
            rooms[roomIndex] -= classes[i];
        } else {
            roomIndex++;
            if (roomIndex >= M) {
                std::cout << "Not enough rooms to accommodate all classes.\n";
                return 0;
            }
            rooms[roomIndex] -= classes[i];
        }
    }

    std::cout << "Minimum number of rooms used: " << roomIndex + 1 << std::endl;

    return 0;
}
