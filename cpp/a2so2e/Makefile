# Compiler
CXX = g++
CXXFLAGS = -Wall 

# Files
STATIC_SRC = static.cpp static_exclude.cpp
SHARED_SRC = shared.cpp
E_SRC = e.cpp

# Targets
STATIC_LIB = libstatic.a
SHARED_OBJ = shared.o
SHARED_LIB = libshared.so
E_OBJ = e.o
EXEC = final_executable

all: $(EXEC)

# Compile static.cpp to a static library (.a)
$(STATIC_LIB): $(STATIC_SRC)  
	# $(CXX) $(CXXFLAGS) -fvisibility=hidden -c static.cpp -o static.o
	# $(CXX) $(CXXFLAGS) -fvisibility=hidden -c static_exclude.cpp -o static_exclude.o
	$(CXX) $(CXXFLAGS) -c static.cpp -o static.o
	$(CXX) $(CXXFLAGS) -c static_exclude.cpp -o static_exclude.o
	ar rcs $@ static.o static_exclude.o

# Compile shared.cpp to an object file
$(SHARED_OBJ): $(SHARED_SRC)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Link shared.o and static library to create the shared object (.so)
$(SHARED_LIB): $(SHARED_OBJ) $(STATIC_LIB)
	# $(CXX) -shared -o $@ $(SHARED_OBJ) -L. -Wl,--whole-archive -lstatic -Wl,--no-whole-archive
	# $(CXX) -shared -o $@ $(SHARED_OBJ) -L. -lstatic
	$(CXX) -shared -o $@ $(SHARED_OBJ)

# Compile e.cpp to an object file
$(E_OBJ): $(E_SRC)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Link e.o with the shared library to create the final executable
$(EXEC): $(E_OBJ) $(SHARED_LIB)
	$(CXX) -o $@ $(E_OBJ) -L. -lshared -lstatic
	# $(CXX) -o $@ $(E_OBJ) -L. -lshared

clean:
	rm -f *.o $(STATIC_LIB) $(SHARED_LIB) $(EXEC)

