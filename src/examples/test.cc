#include "test.hh"
#include "shapes.hh"

#include <memory>
#include <vector>

void test1()
{
    const std::vector<Triangle> triangles
    {
        {3,3}, {5,5}, {5,2}, {2,5}
    };

    const std::vector<Rectangle> rectangles
    {
        {5,5}, {2,5}, {5,2}
    };

    for (auto& t : triangles)
    {
        drawTriangle(&t);
    }

    for (auto& r : rectangles)
    {
        drawRectangle(&r);
    }
}

void test2()
{
    std::vector<std::unique_ptr<Shape>> shapes;

    shapes.push_back(std::unique_ptr<Shape>(new Triangle(3,3)));
    shapes.push_back(std::unique_ptr<Shape>(new Triangle(5,5)));
    shapes.push_back(std::unique_ptr<Shape>(new Triangle(5,2)));
    shapes.push_back(std::unique_ptr<Shape>(new Triangle(2,5)));

    shapes.push_back(std::unique_ptr<Shape>(new Rectangle(5,5)));
    shapes.push_back(std::unique_ptr<Shape>(new Rectangle(2,5)));
    shapes.push_back(std::unique_ptr<Shape>(new Rectangle(5,2)));

    for (auto& s : shapes)
    {
        s->draw();
    }

    /*for (auto s : shapes)
    {
        delete s;   
    }*/
}

