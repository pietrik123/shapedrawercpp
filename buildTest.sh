
./build.sh

rm ut/*.o
rm ut/unittest

echo 'Compiling tests'
echo 'Compiling catch'
g++ -c -o catch.o  Catch2/extras/*.cpp -ICatch2/extras
echo 'Compiling unittests'
g++ -c -o ut.o  ut/*.cc -ICatch2/extras -Isrc/
g++ -o ut/unittest ut.o catch.o $(find build/ -maxdepth 1 -iname "*.o" ! -iname "main*")
mv *.o ut/

