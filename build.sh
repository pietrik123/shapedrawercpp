rm *.o
rm shapedrawer
g++ -c -o test.o test.cc
g++ -c -o main.o main.cc
g++ -c -o shapes.o shapes.cc
g++ -o shapedrawer shapes.o test.o main.o
