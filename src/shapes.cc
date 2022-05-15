#include "shapes.hh"

#include <iostream>

void drawRectangle(const Rectangle* rect)
{
    for (auto i = 0; i < rect->get_a(); i++)
    {
        for (auto j = 0; j < rect->get_b(); j++)
        {
            std::cout << "#";
        }
        std::cout << "\n";
    }
    std::cout << "\n\n";
}

void drawTriangle(const Triangle* tr)
{
    for (auto i =0; i < tr->get_a(); i++)
    {
        int n = tr->get_h() * i / tr->get_a() + 1;
        if (i == 0) n = 1;
        if (i == tr->get_a()-1) n = tr->get_h();
        for (auto j = 0; j < n; j++)
        {
            std::cout << "#";
        }
        std::cout << "\n";
    }
    std::cout << "\n\n";
}

void Rectangle::draw() 
{
    drawRectangle(this);
}

void Triangle::draw() 
{
    drawTriangle(this);
}
