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
            std::cout << "\n";
        }
    }
    else
    {
        int x = std::atoi(m_args[0].c_str());
        if (x == 0 || x > shapesVector.size())
        {   
            std::cout << "Invalid shape number!\n";
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

ExitCmd::ExitCmd(CommandReceiver& r, const StringArgs& args) : Command(r, args)
{
}

bool ExitCmd::execute()
{
    m_receiver.requestExit();
    return true;
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
    else if (cmdName == "listshapes")
    {
        return new CreateListShapesCmd(receiver, args);
    }
    else if (cmdName == "draw")
    {
        return new DrawCmd(receiver, args);
    }
    else if (cmdName == "exit")
    {
        return new ExitCmd(receiver, args);
    }
    else
    {
        std::cout << "Invalid command\n";
        return nullptr;
    }
}

StringArgs parseUserInput(const std::string& fullCmdStr)
{
    StringArgs tokens;
    std::string token = "";
    size_t inputSize = fullCmdStr.size();

    for (auto i=0u; i < inputSize; i++)
    {
        char c = fullCmdStr[i];
        if (0 != std::isalnum(c))
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
