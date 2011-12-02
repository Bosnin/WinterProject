FILE = main.cc
OUT = winter.o

mac: $(FILE)
	g++ -o $(OUT) $(FILE) -I/opt/local/include -L/opt/local/lib -framework OpenGL -framework GLUT -lGLEW

linux: $(FILE)
	g++ -o $(OUT) $(FILE) -I/usr/X11R6/include -L/usr/X11R6/lib -lGL -lGLEW -lglut
