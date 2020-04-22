#include <iostream>
#include "Playground2048.h"

int main() {
    Playground2048 play;
    std::cout << std::endl;
    while (play.NextStep()) {
        play.Show();
        std::string token;
        bool moved = false;
        std::cout << "\n" << "\033[F" << "Enter direction(W/A/S/D): ";
        while (!moved) {
            std::getline(std::cin, token);
            if (token.empty()) {
                std::cout << "\033[F" << "Enter direction(W/A/S/D): ";
                continue;
            }
            char dir = token[0];
            if (dir == 'W' || dir == 'w') {
                moved = play.Move(Playground2048::UP);
            } else if (dir == 'A' || dir == 'a') {
                moved = play.Move(Playground2048::LEFT);
            } else if (dir == 'S' || dir == 's') {
                moved = play.Move(Playground2048::DOWN);
            } else if (dir == 'D' || dir == 'd') {
                moved = play.Move(Playground2048::RIGHT);
            } else {
                std::cout << "\033[F" << "\33[2K\r" << "Invalid direction. Re-enter(W/A/S/D): ";
                continue;
            }
            if (!moved) {
                std::cout << "\033[F" << "\33[2K\r" << "Cannot move. Re-enter(W/A/S/D): ";
            }
        }
        std::cout << "\033[F" << "\33[2K";
        for (int i = 0; i < 10; ++i) {
            std::cout << "\033[F";
        }
    }

    play.Show();

    std::cout << "Game over. Your score: " << play.GetScore() << "\n" << std::endl;

    return 0;
}