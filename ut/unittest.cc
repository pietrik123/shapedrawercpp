#define CATCH_CONFIG_MAIN

#include "shapes.hh"
#include "command.hh"

#include "catch.hpp"

#include <memory>

using Args = std::vector<std::string>;
using CmdPtr = std::unique_ptr<Command>;

TEST_CASE("Simple command test")
{
    Shapes shapes;
    CommandReceiver cmdReceiver(shapes);

    SECTION("Check triangle creation")
    {
        const std::vector<std::string> args {"2", "5"};
        Command* cmd = createCommand(cmdReceiver, "tri", args);
        cmd->execute();
        REQUIRE(shapes.size() == 1);
        delete cmd;
    }
}

TEST_CASE("Tri command test")
{
    Shapes shapes;
    CommandReceiver cmdReceiver(shapes);

    SECTION("To many arguments")
    {
        const Args args {"1","2","3"};
        CmdPtr cmd(createCommand(cmdReceiver, "tri", args));
        REQUIRE(cmd->execute() == false);
        REQUIRE(shapes.size() == 0);
    }

    SECTION("Not enough arguments")
    {
        const Args args {};
        CmdPtr cmd(createCommand(cmdReceiver, "tri", args));
        REQUIRE(cmd->execute() == false);
        REQUIRE(shapes.size() == 0);
    }

    SECTION("Wrong argument type")
    {
        const Args args {"xx", "yy"};
        CmdPtr cmd(createCommand(cmdReceiver, "tri", args));
        REQUIRE(cmd->execute() == false);
        REQUIRE(shapes.size() == 0);
    }
}


