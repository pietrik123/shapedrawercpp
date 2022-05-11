#ifndef SHAPES_HH
#define SHAPES_HH

class Shape
{
    public:
    virtual void draw() const = 0;
};

class Rectangle : public Shape
{
    public:
    Rectangle(int sideA, int sideB);
    ~Rectangle() {}
    void setDimension(int sideA, int sideB);
    int getSideA();
    int getSideB();
    void draw() const override;
    private:
    int m_a, m_b;
};

class Triangle : public Shape
{
    public:
    Triangle(int base, int height);
    ~Triangle() {}
    void setDimension(int base, int height);
    int getBase();
    int getHeight();
    void draw() const override;
    private:
    int m_a, m_h;
};

#endif

