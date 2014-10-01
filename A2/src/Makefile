OPENGLLIB= -lGL
GLEWLIB= -lGLEW
GLFWLIB = -lglfw
GLU = -lGLU
LIBS=$(OPENGLLIB) $(GLEWLIB) $(GLFWLIB) $(GLU)
LDFLAGS=-L/usr/local/lib 
CPPFLAGS=-I/usr/local/include

BIN=toylogo
#SRCS=gl_framework.cpp toylogo.cpp draw_rectangle.cpp draw_cube.cpp draw_body.cpp leg.cpp head.cpp arm.cpp
#INCLUDES=gl_framework.hpp draw_rectangle.hpp draw_cube.hpp draw_body.hpp leg.hpp head.hpp arm.hpp

SRCS=*.cpp
INCLUDES=*.hpp

all: $(BIN)


$(BIN): $(SRCS) $(INCLUDES)
	g++ $(CPPFLAGS) $(SRCS) -o $(BIN) $(LDFLAGS) $(LIBS)

clean:
	rm -f $(BIN)
	rm -f *.o
	rm -f *~


