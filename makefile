TARGET = life.exe
CC = g++
CFLAGS = -Wall -DSFML_STATIC
INCLUDEPATH = -I SFMLWinGCCStatic\SFML\include
LIBPATH = -L SFMLWinGCCStatic\SFML\lib
LIBS = -lsfml-graphics-s -lsfml-window-s -lsfml-system-s -lopengl32 -lwinmm -lgdi32 -lfreetype
OBJ = main.o gaem.o

$(TARGET) : $(OBJ)
	$(CC) $(OBJ) $(CFLAGS) $(INCLUDEPATH) $(LIBPATH) $(LIBS) -o life.exe

main.o : main.cpp gaem.hpp
	$(CC) main.cpp -c $(CFLAGS) $(INCLUDEPATH) $(LIBPATH) $(LIBS)

gaem.o : gaem.cpp gaem.hpp
	$(CC) gaem.cpp -c $(CFLAGS) $(INCLUDEPATH) $(LIBPATH) $(LIBS)

clean :
	rm $(TARGET) $(OBJ)