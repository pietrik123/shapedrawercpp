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
        drawTriangle(&t);
    }

    for (auto& r : rectangles)
    {
        drawRectangle(&r);
    }
}

