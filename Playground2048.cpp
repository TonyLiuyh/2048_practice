//
// Created by apple on 2020/4/21.
//

#include "Playground2048.h"
#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>

#ifndef WIN
#define CLEAR_LINE "\33[2K"
#define PREV_LINE "\033[F"
#else
#define CLEAR_LINE ""
#define PREV_LINE ""
#endif

Playground2048::Playground2048(int width, int height)
    : matrix(new int*[height])
    , width(width)
    , height(height)
    , score(0) {
    srand(time(nullptr));
    for (int i = 0; i < height; ++i) {
        matrix[i] = new int[width];
        for (int j = 0; j < width; ++j) {
            matrix[i][j] = 0;
        }
    }
}

Playground2048::~Playground2048() {
    for (int i = 0; i < height; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

void Playground2048::Play() {
    std::cout << std::endl;
    while (true) {
        std::string token;
        while (NextStep()) {
            Show();
            bool moved = false;
            std::cout << "\n" << PREV_LINE << "Enter direction(W/A/S/D): ";
            while (!moved) {
                std::getline(std::cin, token);
                if (token.empty()) {
                    std::cout << PREV_LINE << "Enter direction(W/A/S/D): ";
                    continue;
                }
                char dir = token[0];
                if (dir == 'W' || dir == 'w') {
                    moved = Move(Playground2048::UP);
                } else if (dir == 'A' || dir == 'a') {
                    moved = Move(Playground2048::LEFT);
                } else if (dir == 'S' || dir == 's') {
                    moved = Move(Playground2048::DOWN);
                } else if (dir == 'D' || dir == 'd') {
                    moved = Move(Playground2048::RIGHT);
                } else {
                    std::cout << PREV_LINE << CLEAR_LINE << "Invalid direction. Re-enter(W/A/S/D): ";
                    continue;
                }
                if (!moved) {
                    std::cout << PREV_LINE << CLEAR_LINE << "Cannot move. Re-enter(W/A/S/D): ";
                }
            }
            std::cout << PREV_LINE << CLEAR_LINE;
            for (int i = 0; i < 10; ++i) {
                std::cout << PREV_LINE;
            }
            std::cout << CLEAR_LINE;
        }

        Show();

        std::cout << "Game over. Your score: " << GetScore() << ". Play again(Y/N)? ";

        std::getline(std::cin, token);
        if (token.empty() || (token[0] != 'Y' && token[0] != 'y')) {
            break;
        } else {
            std::cout << PREV_LINE << CLEAR_LINE;
            for (int i = 0; i < 10; ++i) {
                std::cout << PREV_LINE;
            }
            std::cout << CLEAR_LINE;
            Reset();
        }
    }
}

bool Playground2048::Move(Playground2048::Direction direction) {
    bool moved = false;
    if (direction == Playground2048::UP) {
        for (int col = 0; col < width; ++col) {
            bool merged = false;
            for (int row = 1; row < height; ++row) {
                if (matrix[row][col] == 0) {
                    continue;
                }
                int firstEmptyRow = 0;
                while (firstEmptyRow < height && matrix[firstEmptyRow][col] != 0) {
                    ++firstEmptyRow;
                }
                int newRow = row;
                if (firstEmptyRow < row) {
                    std::swap(matrix[firstEmptyRow][col], matrix[row][col]);
                    newRow = firstEmptyRow;
                    moved = true;
                }
                if (!merged && newRow > 0 && matrix[newRow][col] == matrix[newRow - 1][col]) {
                    score += matrix[newRow][col];
                    matrix[newRow - 1][col] *= 2;
                    matrix[newRow][col] = 0;
                    merged = true;
                    moved = true;
                } else {
                    merged = false;
                }
            }
        }
    } else if (direction == Playground2048::DOWN) {
        for (int col = 0; col < width; ++col) {
            bool merged = false;
            for (int row = height - 2; row >= 0; --row) {
                if (matrix[row][col] == 0) {
                    continue;
                }
                int firstEmptyRow = height - 1;
                while (firstEmptyRow >= 0 && matrix[firstEmptyRow][col] != 0) {
                    --firstEmptyRow;
                }
                int newRow = row;
                if (firstEmptyRow > row) {
                    std::swap(matrix[firstEmptyRow][col], matrix[row][col]);
                    newRow = firstEmptyRow;
                    moved = true;
                }
                if (!merged && newRow < height - 1 &&
                        matrix[newRow][col] == matrix[newRow + 1][col]) {
                    score += matrix[newRow][col];
                    matrix[newRow + 1][col] *= 2;
                    matrix[newRow][col] = 0;
                    merged = true;
                    moved = true;
                } else {
                    merged = false;
                }
            }
        }
    } else if (direction == Playground2048::LEFT) {
        for (int row = 0; row < height; ++row) {
            bool merged = false;
            for (int col = 1; col < width; ++col) {
                if (matrix[row][col] == 0) {
                    continue;
                }
                int firstEmptyCol = 0;
                while (firstEmptyCol < width && matrix[row][firstEmptyCol] != 0) {
                    ++firstEmptyCol;
                }
                int newCol = col;
                if (firstEmptyCol < col) {
                    std::swap(matrix[row][firstEmptyCol], matrix[row][col]);
                    newCol = firstEmptyCol;
                    moved = true;
                }
                if (!merged && newCol > 0 &&
                        matrix[row][newCol] == matrix[row][newCol - 1]) {
                    score += matrix[row][newCol];
                    matrix[row][newCol - 1] *= 2;
                    matrix[row][col] = 0;
                    merged = true;
                    moved = true;
                } else {
                    merged = false;
                }
            }
        }
    } else {
        for (int row = 0; row < height; ++row) {
            bool merged = false;
            for (int col = width - 2; col >= 0; --col) {
                if (matrix[row][col] == 0) {
                    continue;
                }
                int firstEmptyCol = width - 1;
                while (firstEmptyCol >= 0 && matrix[row][firstEmptyCol] != 0) {
                    --firstEmptyCol;
                }
                int newCol = col;
                if (firstEmptyCol > col) {
                    std::swap(matrix[row][firstEmptyCol], matrix[row][col]);
                    newCol = firstEmptyCol;
                    moved = true;
                }
                if (!merged && newCol < height - 1 &&
                        matrix[row][newCol] == matrix[row][newCol + 1]) {
                    score += matrix[row][newCol];
                    matrix[row][newCol + 1] *= 2;
                    matrix[row][col] = 0;
                    merged = true;
                    moved = true;
                } else {
                    merged = false;
                }
            }
        }
    }
    return moved;
}

bool Playground2048::NextStep() {
    std::vector<std::pair<int, int>> open_slots;

    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            if (matrix[i][j] == 0) {
                open_slots.emplace_back(i, j);
            }
        }
    }

    if (!open_slots.empty()) {
        int position = rand() % open_slots.size();
        int number = rand() % 10 < PROB_4 ? 4 : 2;
        matrix[open_slots[position].first][open_slots[position].second] = number;
        if (open_slots.size() == 1) {
            for (int i = 0; i < height; ++i) {
                for (int j = 0; j < width; ++j) {
                    if (i < height - 1 && matrix[i][j] == matrix[i + 1][j]) {
                        return true;
                    }
                    if (j < width - 1 && matrix[i][j] == matrix[i][j + 1]) {
                        return true;
                    }
                }
            }
            return false;
        } else {
            return true;
        }
    } else {

        return false;
    }
}

void Playground2048::Show() const {
    std::cout << "     Score: " << score << std::endl;
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            std::cout << "+----";
        }
        std::cout << "+" << std::endl;

        for (int j = 0; j < width; ++j) {
            std::cout << ColorNumber(0);
            std::cout << "|";
            std::cout << ColorNumber(matrix[i][j]);
            if (matrix[i][j] == 0) {
                std::cout << "    ";
            } else if (matrix[i][j] < 10) {
                std::cout << "  " << matrix[i][j] << " ";
            } else if (matrix[i][j] < 100) {
                std::cout << " " << matrix[i][j] << " ";
            } else if (matrix[i][j] < 1000) {
                std::cout << " " << matrix[i][j];
            } else {
                std::cout << matrix[i][j];
            }
        }
        std::cout << ColorNumber(0);
        std::cout << "|" << std::endl;
    }
    for (int j = 0; j < width; ++j) {
        std::cout << "+----";
    }
    std::cout << "+" << std::endl;
}

int Playground2048::GetScore() const {
    return score;
}

void Playground2048::Reset() {
    score = 0;
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            matrix[i][j] = 0;
        }
    }
}

std::string Playground2048::ColorNumber(int num) {
#ifdef WIN
    return "";
#endif
    switch (num) {
        case 4:
            return "\x1b[30;42m";
        case 8:
            return "\x1b[30;43m";
        case 16:
            return "\x1b[37;44m";
        case 32:
            return "\x1b[30;45m";
        case 64:
            return "\x1b[30;46m";
        case 128:
            return "\x1b[37;41m";
        case 256:
            return "\x1b[37;40m";
        case 512:
            return "\x1b[37;42m";
        case 1024:
            return "\x1b[37;43m";
        case 2048:
            return "\x1b[37;46m";
        case 4096:
            return "\x1b[33;41m";
        default:
            return "\x1b[0m";
    }
}