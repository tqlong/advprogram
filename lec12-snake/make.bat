set OBJS=main.cpp Snake.cpp Game.cpp Gallery.cpp SDL_utils.cpp
set OBJ_NAME=main.exe
set COMPILER_FLAGS=-std=c++11 
set LINKER_FLAGS=-lmingw32 -lSDL2main -lSDL2 -lSDL2_image
set INCLUDE_DIR=-ID:\setup\SDL2-2.0.5\x86_64-w64-mingw32\include\SDL2 -ID:\setup\SDL2_image-2.0.1\x86_64-w64-mingw32\include\SDL2
set LIB_DIR=-LD:\setup\SDL2-2.0.5\x86_64-w64-mingw32\lib -LD:\setup\SDL2_image-2.0.1\x86_64-w64-mingw32\lib

g++ %COMPILER_FLAGS% %INCLUDE_DIR% %LIB_DIR% %OBJS% %LINKER_FLAGS% -o %OBJ_NAME%
