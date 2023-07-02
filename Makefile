DEBUG_FLAG = -g
RELEASE_FLAG = -s -static -O3
PATH_RELEASE = build/release
PATH_DEBUG = build/debug

all: debug release
debug: $(PATH_DEBUG)/debug.exe
release: $(PATH_RELEASE)/release.exe

$(PATH_DEBUG)/debug.exe: include/*.h src/main.cpp
	g++ $(DEBUG_FLAG) src/main.cpp -I include -o $(PATH_DEBUG)/debug.exe

$(PATH_RELEASE)/release.exe: include/*.h src/main.cpp
	g++ $(RELEASE_FLAG) src/main.cpp -I include -o $(PATH_RELEASE)/release.exe