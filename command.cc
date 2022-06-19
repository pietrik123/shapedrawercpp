#include "command.hh"

#include <cstdlib>
#include <cctype>
#include <iostream>


Command::Command(CommandReceiver& r, const StringArgs& args) : m_receiver {r}, m_args {args} {}

CreateTriangleCmd::CreateTriangleCmd(CommandReceiver& r, const StringArgs& args) 
    : Command(r, args)
{
}

bool CreateTriangleCmd::execute()
{
    if (m_args.size() < 2u)
    {
        return false;
    }
    int a = std::atoi(m_args[0].c_str());
    int h = std::atoi(m_args[1].c_str());
    if (a == 0 || h == 0)
    {
        return false;
    }
    Triangle* tri = new Triangle(a,h);
    m_receiver.addShape(tri);
    tri->draw();
    return true;
}

void CreateTriangleCmd::printGeneralHelp() const
{
    std::cout << "tri\n";
    std::cout << "Creates a triangle shape, saves it in memory and draws it on the screen\n";
}

void CreateTriangleCmd::printDetailedHelp() const
{
    printGeneralHelp();
    std::cout << "Syntax: tri <dim_a> <dim_h>\n";
    std::cout << "Arguments:\ndim_a, dim_h - triangle legs lengths of type unsigned integer\n";
}

CreateRectangleCmd::CreateRectangleCmd(CommandReceiver& r, const StringArgs& args) : Command (r, args)
{
}

bool CreateRectangleCmd::execute()
{
    if (m_args.size() < 2u)
    {
        return false;
    }
    int a = std::atoi(m_args[0].c_str());
    int h = std::atoi(m_args[1].c_str());
    if (a == 0 || h == 0)
    {
        return false;
    }
    Rectangle* rect = new Rectangle(a,h);
    m_receiver.addShape(rect);
    rect->draw();
    return true;
}

void CreateRectangleCmd::printGeneralHelp() const
{
    std::cout << "rect\n";
    std::cout << "Creates a rectangle shape, saves it in memory and draws it on the screen\n";
}

void CreateRectangleCmd::printDetailedHelp() const
{
    printGeneralHelp();
    std::cout << "Syntax: rect <dim_a> <dim_b>\n";
    std::cout << "Arguments:\ndim_a, dim_b - lengths of rectangle sides of type unsigned integer\n";
}

CreateSquareCmd::CreateSquareCmd(CommandReceiver& r, const StringArgs& args) : Command (r, args)
{
}

bool CreateSquareCmd::execute()
{
    if (m_args.size() < 1u)
    {
        return false;
    }
    int a = std::atoi(m_args[0].c_str());
    if (a == 0)
    {
        return false;
    }
    Square* square = new Square(a);
    m_receiver.addShape(square);
    square->draw();
    return true;
}

void CreateSquareCmd::printGeneralHelp() const
{
    std::cout << "square\n";
    std::cout << "Creates a square shape, saves it in memory and draws it on the screen\n";
}

void CreateSquareCmd::printDetailedHelp() const
{
    printGeneralHelp();
    std::cout << "Syntax: square <dim_a>\n";
    std::cout << "Arguments:\ndim_a - length of square side of type unsigned integer\n";
}

CreateListShapesCmd::CreateListShapesCmd(CommandReceiver& r, const StringArgs& args) : Command(r, args)
{
}

bool CreateListShapesCmd::execute()
{
    Shapes& shapesVector = m_receiver.getShapesVector();
    std::cout << "\n";
    for (size_t i = 0; i < shapesVector.size(); i++)
    {
        std::cout << i + 1 << "> ";
        shapesVector[i]->printInfo();
        std::cout << "\n";
    }
    std::cout << "\n";
    return true;
}

void CreateListShapesCmd::printGeneralHelp() const
{
    std::cout << "list-shapes\n";
    std::cout << "Prints out shapes which are stored in memory\n";
}
void CreateListShapesCmd::printDetailedHelp() const
{
    printGeneralHelp();
    std::cout << "Syntax: list-shapes\n";
}

DrawCmd::DrawCmd(CommandReceiver& r, const StringArgs& args) : Command(r, args)
{
}

bool DrawCmd::execute()
{
    Shapes& shapesVector = m_receiver.getShapesVector();
    std::cout << "\n";
    if (m_args.size() < 1u)
    {
        return false;
    }
    if (m_args[0] == "all")
    {
        for (size_t i = 0; i <shapesVector.size(); i++)
        {
            std::cout << i + 1 << "> ";
            shapesVector[i]->printInfo();
            std::cout << "\n";
            shapesVector[i]->draw();
        }
    }
    else
    {
        int x = std::atoi(m_args[0].c_str());
        if (x == 0 || x > shapesVector.size())
        {   
            std::cout << "Invalid shape number!";
            return false;
        }
        else
        {
            std::cout << x << "> ";
            shapesVector[x - 1]->printInfo();
            std::cout << "\n";
            shapesVector[x - 1]->draw();
        }
    }
    return true;
}

void DrawCmd::printGeneralHelp() const
{
    std::cout << "draw\n";
    std::cout << "Draw shape (or shapes) on the console screen\n";
}

void DrawCmd::printDetailedHelp() const
{
    printGeneralHelp();
    std::cout << "Syntax:\n"
            << "draw <all>\n"
            << "draw <shape_id>\n";
    std::cout << "Arguments:\n"
            << "all - tells the program that is should draw all shapes which are stored in memory\n"
            << "shape_id - id of the shape which may be taken by \"list-shapes\" command\n";
}

SetStyleCmd::SetStyleCmd(CommandReceiver&r, const StringArgs& args) : Command(r, args)
{
}

bool SetStyleCmd::execute()
{
    Shapes& shapesVector = m_receiver.getShapesVector();
    std::cout << "\n";   
    std::string shapeStyleString = m_args[1];
    char shapeStyleChar = shapeStyleString[0];
    
    if (m_args.size()< 2u)
    {
        return false;
    }
    if (shapeStyleString.size() > 1)
    {
        std::cout << "Shape character style should be single character";
        return false;
    }
    if (m_args[0] == "all")
    {
        for (size_t i = 0; i < shapesVector.size(); i++)
        {
            shapesVector[i]->setChar(shapeStyleChar);
        }
    }
    else 
    {
        int x = std::atoi(m_args[0].c_str());
        if (x == 0 || x > shapesVector.size())
        {
            std::cout << "Invalid shape number!";
            return false;
        }
        else
        {
            shapesVector[x-1]->setChar(shapeStyleChar);
        }
    }
    return true;
}

void SetStyleCmd::printGeneralHelp() const
{
    std::cout << "set-style\n";
    std::cout << "Sets ascii character with witch a shape is drawn\n";
}

void SetStyleCmd::printDetailedHelp() const
{
    printGeneralHelp();
    std::cout << "Syntax:\n"
            << "set-style <all> <character>\n"
            << "set-style <shape_id> <character>\n";
    std::cout << "Arguments:\n"
            << "all - changes the style of all shapes stored in program memory\n"
            << "shape_id - identifier of a shape of which style is set up, the id can be taken by \"list-shapes\" command\n"
            << "character - ascii character with which the shape will be drawn\n";
}

ExitCmd::ExitCmd(CommandReceiver& r, const StringArgs& args) : Command(r, args)
{
}

bool ExitCmd::execute()
{
    m_receiver.requestExit();
    return true;
}

void ExitCmd::printGeneralHelp() const
{
    std::cout << "exit\n";
    std::cout << "Shall terminate the shapedrawer process\n";
}

void ExitCmd::printDetailedHelp() const
{
    printGeneralHelp();
}

Command* createCommand(CommandReceiver& receiver, const std::string& cmdName, const StringArgs& args)
{
    if (cmdName == "tri")
    {
        return new CreateTriangleCmd(receiver, args);
    }
    else if (cmdName == "rect")
    {
        return new CreateRectangleCmd(receiver, args);
    }
    else if (cmdName == "square")
    {
        return new CreateSquareCmd(receiver, args);
    }
    else if (cmdName == "list-shapes")
    {
        return new CreateListShapesCmd(receiver, args);
    }
    else if (cmdName == "draw")
    {
        return new DrawCmd(receiver, args);
    }
    else if (cmdName == "set-style")
    {
        return new SetStyleCmd(receiver, args);
    }
    else if (cmdName == "exit")
    {
        return new ExitCmd(receiver, args);
    }
    else
    {
        std::cout << "\nInvalid command\n";
        return nullptr;
    }
}

StringArgs parseUserInput(const std::string& fullCmdStr)
{
    StringArgs tokens;
    std::string token = "";
    size_t inputSize = fullCmdStr.size();

    for (auto i = 0u; i < inputSize; i++)
    {
        char c = fullCmdStr[i];
        if (c > 32 && c < 127)
        {
            token += c;
        }
        if ((c == ' ' || c == 0) && token != "")
        {
            tokens.push_back(token);
            token = "";
        }
        if (c == 0) break;
    }
    return tokens;
}

CommandReceiver::CommandReceiver(Shapes& shapes) : m_shapes {shapes},  m_shouldExit {false}
{
}

void CommandReceiver::requestExit()
{
    m_shouldExit = true;
}

bool CommandReceiver::shouldExit()
{
    return m_shouldExit;
}

void CommandReceiver::addShape(Shape* s)
{
    if (s)
    {
        m_shapes.push_back(s);
    }
}

Shapes& CommandReceiver::getShapesVector()
{
    return m_shapes;
}
