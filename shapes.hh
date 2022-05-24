#ifndef SHAPES_HH
#define SHAPES_HH

class Shape
{
    public:
        Shape();
        virtual void draw() const = 0;
        void setChar(char mark);
    protected:
        char m_ch;
};

class Rectangle : public Shape
{
    public:
        Rectangle(int sideA, int sideB);
        ~Rectangle() {}
        void setDimensions(int sideA, int sideB);
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
        void setDimensions(int base, int height);
        int getBase();
        int getHeight();
        void draw() const override;
    private:
        int m_a, m_h;
};

class Square : public Shape
{
    public:
        Square(int side);
        ~Square() {}
        void setDimension(int side);
        int getSide();
        void draw() const override;
    private:
        int m_a;
};

#endif