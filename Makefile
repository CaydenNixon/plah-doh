FLAGS = g++ -Wall -Og

rwildcard=$(wildcard $1$2) $(foreach d,$(wildcard $1*),$(call rwildcard,$d/,$2))
SOURCES := $(call rwildcard,./,*.cpp)

SFML_ROOT_STATIC = C:\CPP_libs\SFML\SFML
SFML_INCLUDE_STATIC = -I "$(SFML_ROOT_STATIC)/include"
SFML_LIBRARY_STATIC = -L "$(SFML_ROOT_STATIC)/lib"

WINDOWS_STD_LINK_STATIC = -static-libstdc++ \
    -static-libgcc

WINDOWS_SFML_LINK_STATIC = -DSFML_STATIC \
	-lsfml-window-s \
    -lsfml-graphics-s \
    -lsfml-audio-s \
    -lsfml-system-s \
    -lopengl32 \
    -lwinmm \
    -lgdi32 \
    -lfreetype \
    -lopenal32 \
    -lflac \
    -lvorbisenc \
    -lvorbisfile \
    -lvorbis \
    -logg

EXECUTABLE = plahdoh

all:
	$(FLAGS) $(SOURCES) $(SFML_INCLUDE_STATIC) $(SFML_LIBRARY_STATIC) -o $(EXECUTABLE) \
	-static \
	$(WINDOWS_STD_LINK_STATIC) \
	$(WINDOWS_SFML_LINK_STATIC) 