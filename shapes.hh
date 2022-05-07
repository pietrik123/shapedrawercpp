#ifndef SHAPES_HH
#define SHAPES_HH


class Shape
{
public:
    virtual void draw() {}
};

class Rectangle : public Shape
{
private:
    int m_a, m_b;
public:
    Rectangle(int a, int b) : m_a {a}, m_b {b} {}
    int get_a() const { return m_a; }
    void set_a(int a) { m_a = a; }
    int get_b() const {  return m_b; }
    void set_b(int b) { m_b = b; }

    void draw() override;
};

class Triangle : public Shape
{
private:
    int m_a, m_h;
public:
    Triangle(int a, int h) : m_a {a}, m_h {h} {}

    int get_a() const { return m_a; }
    void set_a(int a) { m_a = a; }
    int get_h() const { return m_h; }
    void set_h(int h) { m_h = h; }

    void draw() override;

};

void drawRectangle(const Rectangle* rect);
void drawTriangle(const Triangle* tr);

#endif

