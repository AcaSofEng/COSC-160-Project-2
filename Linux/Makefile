tree_vector_benchmark_debug: tree_vector.h main.cpp
	mkdir -p bin/Debug
	mkdir -p obj/Debug
	g++-12 -pedantic-errors -pedantic -Wfatal-errors -Wextra -Wall -std=c++17 -fPIC -Og -g -c main.cpp -o obj/Debug/main.o
	g++-12 -o bin/Debug/tree_vector_benchmark obj/Debug/main.o -static-libstdc++ -static

tree_vector_benchmark_release: tree_vector.h main.cpp
	mkdir -p bin/Release
	mkdir -p obj/Release
	g++-12 -pedantic-errors -pedantic -Wfatal-errors -Wextra -Wall -std=c++17 -fPIC -fomit-frame-pointer -fexpensive-optimizations -flto -O3 -c main.cpp -o obj/Release/main.o
	g++-12 -o bin/Release/tree_vector_benchmark obj/Release/main.o -static-libstdc++ -static -flto -s

tree_vector_benchmark: tree_vector.h main.cpp
	make tree_vector_benchmark_debug
	make tree_vector_benchmark_release
