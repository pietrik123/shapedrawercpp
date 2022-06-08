#include "shapes.hh"

#include <iostream>

Shape::Shape() : m_ch{ '*' }
{
}

void Shape::setChar(char mark)
{
    m_ch = mark;
}

Rectangle::Rectangle(int sideA, int sideB)
{
    m_a = sideA;
    m_b = sideB;
}
void Rectangle::setDimensions(int sideA, int sideB)
{
    m_a = sideA;
    m_b = sideB;
}
int Rectangle::getSideA()
{
    return m_a;
}
int Rectangle::getSideB()
{
    return m_b;
}

void Rectangle::draw() const
{
    std::cout << std::endl;
    for (auto i = 0; i < m_a; i++)
    {
        for (auto j = 0; j < m_b; j++)
        {
            std::cout << m_ch;
        }
        std::cout << "\n";
    }
    std::cout << "\n\n";
}

Triangle::Triangle(int base, int height)
{
    m_a = base;
    m_h = height;
}

void Triangle::setDimensions(int base, int height)
{
    m_a = base;
    m_h = height;
}

int Triangle::getBase()
{
    return m_a;
}

int Triangle::getHeight()
{
    return m_h;
}

void Triangle::draw() const
{
    std::cout << std::endl;
    for (auto i =0; i < m_a; i++)
    {
        int n = m_h * i / m_a + 1;
        if (i == 0) n = 1;
        if (i == m_a-1) n = m_h;
        for (auto j = 0; j < n; j++)
        {
            std::cout << m_ch;
        }
        std::cout << "\n";
    }
    std::cout << "\n\n";
}

Square::Square(int side)
{
    m_a = side;
}

void Square::setDimension(int side)
{
    m_a = side;
}

int Square::getSide()
{
    return m_a;
}

void Square::draw() const
{
    std::cout << std::endl;
    for (auto i = 0; i < m_a; i++)
    {
        for (auto j = 0; j < m_a; j++)
        {
            std::cout << m_ch;
        }
        std::cout << "\n";
    }
    std::cout << "\n\n";
}