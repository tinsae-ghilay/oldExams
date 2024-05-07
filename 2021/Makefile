# source files
# no need to explain a wildcard in name and sign
files = $(wildcard *.cpp)
# object files instead of listing them.
# this way we have our make file always working,
# so long as files are in the same folder
# then substitute the .cpp part of $(files) with .o
objects = $(patsubst %.cpp,%.o,$(files))

#g++ commands
# g++
CPPFLAG = g++
# C++ version to compile to
CVFLAG = -std=c++23
# error handling flags
CEFLAG = -Wall -Werror

# rules
all: robot

# create executable from object files
robot: $(objects)
	$(CPPFLAG) $(CVFLAG) $(CEFLAG) -g -o robot $(objects)

# create object files from source files
%.o: %.cpp
	$(CPPFLAG) $(CVFLAG) $(CEFLAG) -g -c $< -o $@

# clean 
.PHONY:clean
clean:
	rm -f robot *.o