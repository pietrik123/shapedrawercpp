all: shapedrawer unittest examples

shapedrawer: main.o shapes.o command.o
	$(CXX) -o shapedrawer $^

unittest: shapes.o command.o ut/unittest.o
	$(CXX) -o unittest $^

examples: test.o examples.o shapes.o examples.o
	$(CXX) -o examples $^

%.o: %.cc
	$(CXX) -c -o $@ $<

ut/%.o: ut/%.cc
	$(CXX) -c -o $@ $< -ICatch2/single_include/catch2/ -I./

.PHONY: clean
clean:
	rm -f *.o ut/*.o  shapedrawer unittest examples 

