CXX=g++
CXXFLAGS=-g -Wall

# La cible principale (l'exécutable final)
# pour la commande : g++ -o test main.o reseau.o
test: main.o reseau.o
	$(CXX) $(CXXFLAGS) -o test main.o reseau.o

# La compilation de main.o
# pour la commande : g++ -c main.cpp
main.o: main.cpp reseau.hpp
	$(CXX) $(CXXFLAGS) -c main.cpp

# La compilation de reseau.o
# pour la commande : g++ -c reseau.cpp
reseau.o: reseau.cpp reseau.hpp
	$(CXX) $(CXXFLAGS) -c reseau.cpp

# Nettoyer le projet (supprimer les .o et test)
clean:
	rm -f main.o reseau.o test

# Compiler puis exécuter directement
run: test
	./test

# Pour dire à Make que "clean" et "run" ne sont pas des noms de fichiers
.PHONY: clean run