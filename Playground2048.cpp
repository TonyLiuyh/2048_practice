//
// Created by apple on 2020/4/21.
//

#include "Playground2048.h"
#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>

Playground2048::Playground2048(int width, int height)
    : matrix(new int*[height])
    , width(width)
    , height(height)
    , score(0) {
    srand(time(0));
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

void Playground2048::Show() {
    std::cout << "     Score: " << score << std::endl;
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            std::cout << "+----";
        }
        std::cout << "+" << std::endl;

        for (int j = 0; j < width; ++j) {
            std::cout << "\x1b[0m" << "|";
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
        std::cout << "\x1b[0m" << "|" << std::endl;
    }
    for (int j = 0; j < width; ++j) {
        std::cout << "+----";
    }
    std::cout << "+" << std::endl;
}

int Playground2048::GetScore() {
    return score;
}

std::string Playground2048::ColorNumber(int num) {
    if (num == 4) {
        return "\x1b[30;42m";
    } else if (num == 8) {
        return "\x1b[30;43m";
    } else if (num == 16) {
        return "\x1b[37;44m";
    } else if (num == 32) {
        return "\x1b[30;45m";
    } else if (num == 64) {
        return "\x1b[30;46m";
    } else if (num == 128) {
        return "\x1b[37;41m";
    } else if (num == 256) {
        return "\x1b[30;40m";
    } else if (num == 512) {
        return "\x1b[37;42m";
    } else if (num == 1024) {
        return "\x1b[37;43m";
    } else if (num == 2048) {
        return "\x1b[37;46m";
    } else if (num == 4096) {
        return "\x1b[37;41m";
    } else {
        return "\x1b[0m";
    }
}