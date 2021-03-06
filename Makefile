OBJS = main.o game.o ball.o platform.o
CXX = g++
CXXFLAGS = -Wall -std=c++14
LDLIBS = -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system

main: $(OBJS)
	$(CXX) -o main $(OBJS) $(LDLIBS) $(LDFLAGS)

clean:
	$(RM) main $(OBJS)
