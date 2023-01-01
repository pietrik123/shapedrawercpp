INCL_DEPS = shapes.hh command.hh

all: shapedrawer unittest examples

shapedrawer: main.o shapes.o command.o
	$(CXX) -o shapedrawer $^

unittest: shapes.o command.o ut/unittest.o
	$(CXX) -o unittest $^

examples: test.o examples.o shapes.o examples.o
	$(CXX) -std=c++14 -o examples $^

%.o: %.cc $(INCL_DEPS)
	$(CXX) -c -std=c++14 -o $@ $<

ut/%.o: ut/%.cc $(INCL_DEPS)
	$(CXX) -c -std=c++14 -o $@ $< -ICatch2/single_include/catch2 -I.

.PHONY: clean
clean:
	rm -f *.o ut/*.o  shapedrawer unittest examples 

