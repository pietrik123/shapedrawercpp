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
    m_receiver.addShape(new Triangle(a,h));
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

    // std::cout << "Chars: ";
    for (auto i=0u; i < inputSize; i++)
    {
        // std::cout << "[" << static_cast<int>(fullCmdStr[i]) << " : " << fullCmdStr[i]  << "], ";
        char c = fullCmdStr[i];
        if (std::isalnum(c) != 0)
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
    // std::cout << "\n";

    // std::cout << "Tokens: ";
    // for (auto& t : tokens) std::cout << t << ", ";
    // std::cout << "\n";

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
