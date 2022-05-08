rm *.o
rm shapedrawer examples
g++ -c -o test.o test.cc
g++ -c -o command.o command.cc
g++ -c -o shapes.o shapes.cc
g++ -c -o main.o main.cc
g++ -c -o examples.o examples.cc
g++ -o shapedrawer shapes.o command.o main.o
g++ -o examples shapes.o test.o examples.o
