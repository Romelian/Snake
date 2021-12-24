#include <iostream>
#include <vector>
#include <chrono>
#include <thread>
#include <Windows.h>
#include "vector2.h"

void Clear() // From https://stackoverflow.com/a/52895729/15175683
{
#if defined _WIN32
    system("cls");
    //clrscr(); // including header file : conio.h
#elif defined(__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
    system("clear");
    //std::cout<< u8"\033[2J\033[1;1H"; //Using ANSI Escape Sequences
#elif defined(__APPLE__)
    system("clear");
#endif
}
int Wrap(int value, int upper_bound)
{
    if (value < 0)
        return upper_bound - 1;

    return value % upper_bound;
}

int main(int argc, char *argv[])
{

    std::vector<vector2<int>> snake{vector2(0, 0)};
    constexpr vector2 map_size(16, 5); 
    char display[map_size.x][map_size.y];
    vector2 food_position(rand() % map_size.x, rand() % map_size.y);
    vector2 forward_velocity(1, 0);
    while (true)
    {
        // Display
        for (int y = 0; y < map_size.y; y++)
        {
            for (int x = 0; x < map_size.x; x++)
            {
                vector2<int> map_position(x, y);
                // Food Display
                if (map_position == food_position)
                {
                    std::cout << " ";
                }
                // Snake Display
                else
                {
                    for (size_t i = 0; i < snake.size(); i++)
                    {
                        if (snake[i] == map_position)
                        {
                            std::cout << " ";
                            goto cnt;
                        }
                    }
                    std::cout << "O";
                cnt:;
                }
            }
            std::cout << std::endl;
        }
        std::cout << "Size: " << snake.size() << std::endl; // Display Snake Size
        std::cout << "Position: " << snake.front() << std::endl; // Display Snake Head Position

        // Food Update
        if (snake.front() == food_position)
        {
            snake.push_back(vector2<int>(0, 0)); // Actually it will be overwritten in Tail Update
            food_position = vector2(rand() % map_size.x, rand() % map_size.y);
        }

        // Tail Update
        for (int i = snake.size() - 1; i >= 1; i--)
        {
            snake[i] = snake[i - 1];
        }

        // Input
        if (GetKeyState('D') & 0x8000)
        {
            forward_velocity = vector2(1, 0);
        }
        else if (GetKeyState('A') & 0x8000)
        {
            forward_velocity = vector2(-1, 0);
        }
        else if (GetKeyState('W') & 0x8000)
        {
            forward_velocity = vector2(0, -1);
        }
        else if (GetKeyState('S') & 0x8000)
        {
            forward_velocity = vector2(0, 1);
        }

        // Move Update
        snake.front() = (snake.front() + forward_velocity).op(map_size, Wrap);

        //Delay
        using namespace std::chrono_literals;
        std::this_thread::sleep_for(10ns);
        std::this_thread::sleep_until(std::chrono::system_clock::now() + 1s);
        Clear();
    }
    return 0;
}