#define CATCH_CONFIG_MAIN

#include "shapes.hh"
#include "command.hh"

#include <catch2/catch_test_macros.hpp>

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


TEST_CASE("getShapeStr tests")
{
    SECTION("Rectanglesi shapes")
    {
	Rectangle r1{2, 5};
	const std::string expected1 = "**\n**\n**\n**\n**\n";
	REQUIRE(expected1 == r1.getShapeStr());

	Rectangle r2{5, 2};
	const std::string expected2 = "*****\n*****\n";
	REQUIRE(expected2 == r2.getShapeStr());

	Rectangle r3{5,5};
	const std::string expected3 = "*****\n*****\n*****\n*****\n*****\n";
	REQUIRE(expected3 == r3.getShapeStr());

	Rectangle r4{1,1};
	const std::string expected4 = "*\n";
	REQUIRE(expected4 == r4.getShapeStr());
    }

    SECTION("Triangles shapes")
    {
        // {3,3}, {5,5}, {5,2}, {2,5}
	Triangle t1{3,3};
	const std::string expected1 = "*\n**\n***\n";
	REQUIRE(expected1 == t1.getShapeStr());

	Triangle t2{5,5};
	const std::string expected2 = "*\n**\n***\n****\n*****\n";
	REQUIRE(expected2 == t2.getShapeStr());
	
	Triangle t3{5,2};
	const std::string expected3 = "*\n*****\n";
	REQUIRE(expected3 == t3.getShapeStr());
		
	Triangle t4{2,5};
	const std::string expected4 = "*\n*\n**\n**\n**\n";
	REQUIRE(expected4 == t4.getShapeStr());
	
	Triangle t5{1,1};
	const std::string expected5 = "*\n";
	REQUIRE(expected5 == t5.getShapeStr());
	
	Triangle t6{5,3};
	const std::string expected6 = "*\n***\n*****\n";
	REQUIRE(expected6 == t6.getShapeStr());

	Triangle t7{10,1};
	const std::string expected7 = "*\n";
	REQUIRE(expected7 == t7.getShapeStr());
	
	Triangle t8{10,2};
	const std::string expected8 = "*\n**********\n";
	REQUIRE(expected8 == t8.getShapeStr());
    }

    SECTION("Square shapes")
    {
	Square s1{1};
	const std::string expected1 = "*\n";
	REQUIRE(expected1 == s1.getShapeStr());

	Square s2{3};
	const std::string expected2 = "***\n***\n***\n";
	REQUIRE(expected2 == s2.getShapeStr());
    }
}

