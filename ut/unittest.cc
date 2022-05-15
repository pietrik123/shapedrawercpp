#include "shapes.hh"
#include "command.hh"

#include "catch_amalgamated.hpp"

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
