#ifndef SHAPES_HH
#define SHAPES_HH

struct Rectangle
{
    int a, b;
};

struct Triangle
{
    int a, h;
};

void drawRectangle(const Rectangle* rect);
void drawTriangle(const Triangle* tr);

#endif

