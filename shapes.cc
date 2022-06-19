#include "shapes.hh"

#include <iostream>
#include <cmath>

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
    std::cout << getShapeStr();
}

void Rectangle::printInfo() const
{
    std::cout << "Rectangle : " << m_a << ", " << m_b << "\n";
}

std::string Rectangle::getShapeStr() const
{
    const auto SIZE = (m_a + 1) * m_b;
    std::string shapeString(SIZE, m_ch);
    
    for(auto i = m_a; i <= SIZE; i+= m_a + 1)
        shapeString[i] = '\n';
    
    return shapeString;
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
    std::cout << getShapeStr();
}

void Triangle::printInfo() const
{
    std::cout << "Triangle : " << m_a << ", " << m_h << "\n";
}

std::string Triangle::getShapeStr() const
{
    if(m_h == 1)
	return "*\n";

    std::string shapeString;
    double diff = static_cast<double>(m_a-1)/(m_h-1);

    for (auto i = 0; i < m_h; i++)
    {
        shapeString += std::string(2 + round(i*diff), m_ch);
        shapeString[shapeString.size() - 1] = '\n';
    }

    return shapeString;
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
    std::cout << getShapeStr();
}

void Square::printInfo() const
{
    std::cout << "Square : " << m_a << "\n";
}

std::string Square::getShapeStr() const
{
    const auto SIZE = m_a * (m_a + 1);
    std::string shapeString(SIZE, m_ch);
    
    for(auto i = m_a; i <= SIZE; i+= m_a + 1)
        shapeString[i] = '\n';
    
    return shapeString;
}

