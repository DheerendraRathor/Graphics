OPENGLLIB= -lGL
GLEWLIB= -lGLEW
GLFWLIB = -lglfw
GLU = -lGLU
SOIL = -lSOIL
LIBS=$(OPENGLLIB) $(GLEWLIB) $(GLFWLIB) $(GLU) $(SOIL)
LDFLAGS=-L/usr/local/lib 
CPPFLAGS=-I/usr/local/include

BIN=toyTransformer
#SRCS=gl_framework.cpp toylogo.cpp draw_rectangle.cpp draw_cube.cpp draw_body.cpp leg.cpp head.cpp arm.cpp
#INCLUDES=gl_framework.hpp draw_rectangle.hpp draw_cube.hpp draw_body.hpp leg.hpp head.hpp arm.hpp

SRCS=*.cpp
INCLUDES=*.hpp

all: $(BIN)
	mkdir -p record


$(BIN): $(SRCS) $(INCLUDES)
	g++ $(CPPFLAGS) $(SRCS) -o $(BIN) $(LDFLAGS) $(LIBS)

clean:
	@rm -f $(BIN)
	@rm -f *.o
	@rm -f *~
	@rm -rf record
	@rm -f keyframes.txt
	@rm -f *.mkv
	@echo "cleaned"
	
video:
	@mogrify -flip -format jpg record/frame_*.ppm
	@ffmpeg -framerate 20 -i record/frame_%04d.jpg -codec copy tt.mkv
	@echo "tt.mkv is created without audio"
	@echo "adding audio"
	@ffmpeg -i tt.mkv -i audio.aac -map 0 -map 1 -codec copy -shortest tt_audio.mkv
	@echo "video with audio is created as tt_audio.mkv"
	
	


