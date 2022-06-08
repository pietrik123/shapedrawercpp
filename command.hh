#ifndef COMMAND_HH
#define COMMAND_HH

#include "shapes.hh"

#include <vector>
#include <string>

using Shapes = std::vector<Shape*>;
using StringArgs = std::vector<std::string>;

class CommandReceiver;

class Command
{
protected:
    StringArgs m_args;
    CommandReceiver& m_receiver;
public:
    Command(CommandReceiver& r, const StringArgs& args);
    virtual bool execute() { return false; }
};

class CreateTriangleCmd : public Command
{
public:
    CreateTriangleCmd(CommandReceiver& r, const StringArgs& args);
    bool execute() override;
};

class CreateRectangleCmd : public Command
{
public:
    CreateRectangleCmd(CommandReceiver& r, const StringArgs& args);
    bool execute() override;
};

class CreateSquareCmd : public Command
{
public:
    CreateSquareCmd(CommandReceiver& r, const StringArgs& args);
    bool execute() override;
};

class ExitCmd : public Command
{
public:
    ExitCmd(CommandReceiver& r, const StringArgs& args);
    bool execute() override;
};

class CommandReceiver
{
private:
    bool m_shouldExit;
    Shapes& m_shapes;
public:
    CommandReceiver(Shapes& shapes);
    bool shouldExit();
    void requestExit();
    void addShape(Shape* s);
};

StringArgs parseUserInput(const std::string& fullCmdStr);

Command* createCommand(CommandReceiver& cmdReceiver, const std::string& cmdName, const StringArgs& args);

#endif
