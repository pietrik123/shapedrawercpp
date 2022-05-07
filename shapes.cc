#include "shapes.hh"

#include <iostream>

void drawRectangle(const Rectangle* rect)
{
    for (auto i = 0; i < rect->a; i++)
    {
        for (auto j = 0; j < rect->b; j++)
        {
            std::cout << "#";
        }
        std::cout << "\n";
    }
    std::cout << "\n\n";
}

void drawTriangle(const Triangle* tr)
{
    for (auto i =0; i < tr->a; i++)
    {
        int n = tr->h * i / tr->a + 1;
        if (i == 0) n = 1;
        if (i == tr->a-1) n = tr->h;
        for (auto j = 0; j < n; j++)
        {
            std::cout << "#";
        }
        std::cout << "\n";
    }
    std::cout << "\n\n";
}
