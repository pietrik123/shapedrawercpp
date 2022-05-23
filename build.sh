echo "Clearing object files"
rm *.o
rm shapedrawer examples unittest

echo "Compiling sources"
g++ -c -o test.o test.cc
g++ -c -o command.o command.cc
g++ -c -o shapes.o shapes.cc
g++ -c -o main.o main.cc
g++ -c -o examples.o examples.cc

echo "Linking shapedrawer"
g++ -o shapedrawer shapes.o command.o main.o

echo "Linking examples"
g++ -o examples shapes.o test.o examples.o

echo "Building tests"
g++ -c -o unittest.o ut/unittest.cc -I./ -ICatch2/extras/
g++ -c -o catch.o Catch2/extras/catch_amalgamated.cpp -ICatch2/extras/

echo "Linking tests"
g++ -o unittest catch.o unittest.o shapes.o command.o
