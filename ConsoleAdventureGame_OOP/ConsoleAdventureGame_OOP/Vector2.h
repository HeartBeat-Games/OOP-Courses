#pragma once

struct Vector2 {
    int x = 0;
    int y = 0;

    bool operator==(const Vector2& other) const
    {
        return x == other.x &&
            y == other.y;
    }

    Vector2 operator+(const Vector2& other) const
    {
        return Vector2{
            .x = x + other.x,
            .y = y + other.y
        };
    }

    void operator+=(const Vector2 other)
    {
        x += other.x;
        y += other.y;
    }
};

