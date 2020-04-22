//
// Created by apple on 2020/4/21.
//

#ifndef INC_2048_PRACTICE_PLAYGROUND2048_H
#define INC_2048_PRACTICE_PLAYGROUND2048_H

#include <string>

class Playground2048 {
public:
    enum Direction {
        UP,
        RIGHT,
        DOWN,
        LEFT
    };

    explicit Playground2048(int width = WIDTH, int height = HEIGHT);

    ~Playground2048();

    void Play();

private:
    static const int WIDTH = 4, HEIGHT = 4;
    static const int PROB_4 = 3;

    static std::string ColorNumber(int num);

    // returns whether the moving is valid
    bool Move(Direction direction);

    // returns whether the game ends
    bool NextStep();

    int GetScore() const;

    void Show() const;

    void Reset();

    int** matrix;

    int width;

    int height;

    int score;
};


#endif //INC_2048_PRACTICE_PLAYGROUND2048_H
