FILE = main.cc
OUT = winter.o
FINAL = main.cc model.o

mac: $(FILE) model.o
	g++ -o $(OUT) $(FINAL) -I/opt/local/include -L/opt/local/lib -framework OpenGL -framework GLUT -lGLEW

linux: $(FILE) model.o
	g++ -o $(OUT) $(FINAL) -I/usr/X11R6/include -L/usr/X11R6/lib -lGL -lGLEW -lglut -lGLU

model.o: model.h model.cc
	g++ -c model.cc

clean:
	rm *.o
