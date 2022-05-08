#include "shapes.hh"
#include "test.hh"
#include "command.hh"

#include <iostream>
#include <string>

const std::string prompt = "shpdrwr>";

void loop();

int main()
{
    loop();
}

void loop()
{
    Shapes shapes;
    CommandReceiver cmdReceiver(shapes);
    while (!cmdReceiver.shouldExit())
    {
        std::cout << prompt;
        const unsigned int bufferSize = 100u;
        char buf[bufferSize];
        std::cin.getline(buf, bufferSize);
        
        std::string cmdFullStr(buf, bufferSize);

        std::vector<std::string> tokens = parseUserInput(cmdFullStr);
        if (tokens.empty())
        {
            std::cout << "Failed to parse user input!\n";
            continue;
        }

        const std::string cmdName = tokens[0];
        std::vector<std::string> args;
        for (auto i = 1; i < tokens.size(); i++)
        {
            args.push_back(tokens[i]);
        }

        Command* cmd = createCommand(cmdReceiver, cmdName, args);
        if (!cmd)
        {
            std::cout << "Failed to create a command!\n";
            continue;
        }
        if (!cmd->execute())
        {
            std::cout << "Command execution failed!\n";
        }
        delete cmd;
    }
}
