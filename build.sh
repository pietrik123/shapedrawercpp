


BUILDDIR=build
SRCDIR=src
MAINEXEC=shapedrawer

mkdir $BUILDDIR

rm $BUILDDIR/*
rm $BUILDDIR/examples/*
rm *.o

echo 'Compiling main sources'
g++ -c $SRCDIR/*.cc -I$SRCDIR
mv *.o $BUILDDIR/
g++ -o $BUILDDIR/$MAINEXEC $BUILDDIR/*.o

echo 'Compiling examples...'
g++ -c $SRCDIR/examples/*.cc -I$SRCDIR
mv *.o $BUILDDIR/examples/ 
g++ -o $BUILDDIR/examples/test $(find $BUILDDIR -maxdepth 1 -iname "*.o" ! -iname "main*") $BUILDDIR/examples/test.o $BUILDDIR/examples/main.o


