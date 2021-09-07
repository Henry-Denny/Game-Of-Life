Game-Of-Life.exe : ./src/*.cpp
	g++ -o ./bin/Game-Of-Life.exe ./src/*.cpp ./bin/*.dll -I ./include