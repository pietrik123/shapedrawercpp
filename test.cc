#include "test.hh"
#include "shapes.hh"

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
       t.draw();
    }

    for (auto& r : rectangles)
    {
        r.draw();
    }
}

void test2()
{
    std::vector<Shape*> shapes;
    
    std::vector<Triangle> triangles
    {
        {3,3}, {5,5}, {5,2}, {2,5}
    };

    std::vector<Rectangle> rectangles
    {
        {5,5}, {2,5}, {5,2}
    };



    for (int i = 0; i < triangles.size(); i++)
    {
    shapes.push_back(&triangles[i]);
    }

    for (int i = 0; i < rectangles.size(); i++)
    {
    shapes.push_back(&rectangles[i]);
    }

    for (auto& s : shapes)
    {
        s->draw();
    }
}