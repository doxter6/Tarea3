# Makefile para compilar main.cpp (C++) y Main.java (Java)

# Configuración para C++
CXX = g++
CXXFLAGS = -Wall -std=c++17
CPP_TARGET = main
CPP_SOURCE = main.cpp

# Configuración para Java
JAVAC = javac
JAVA = java
JAVA_SOURCE = Main.java
JAVA_CLASS = Main

# Regla por defecto (compila ambos)
all: cpp java

# Regla para compilar el programa C++
cpp: $(CPP_SOURCE)
	$(CXX) $(CXXFLAGS) -o $(CPP_TARGET) $(CPP_SOURCE)

# Regla para compilar el programa Java
java: $(JAVA_SOURCE)
	$(JAVAC) $(JAVA_SOURCE)

# Regla para ejecutar el programa C++
run-cpp: cpp
	./$(CPP_TARGET)

# Regla para ejecutar el programa Java
run-java: java
	$(JAVA) $(JAVA_CLASS)

# Limpiar archivos compilados
clean:
	rm -f $(CPP_TARGET) *.class

.PHONY: all cpp java run-cpp run-java clean