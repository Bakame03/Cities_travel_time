# Fichier de configuration du projet Qt

# ici on precise A Qt les outils qu'on veut utiliser
# 'core' c'est la base, 'gui' c'est pour l'interface graphique (fenêtres, boutons).
QT += core gui

# Dans l'ancienne version Qt 4, les boutons et fenêtres étaient inclus d'office dans le module gui
# À partir de Qt 5 (et Qt 6), les créateurs de Qt ont fait le ménage 
# et ont déplacé les éléments graphiques dans un tout nouveau module séparé appelé widgets.
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

# Le nom du programme final qu'on veut créer (l'exécutable)
TARGET = Cities_travel_time

# On précise que c'est une application (app) et pas une simple bibliothèque
TEMPLATE = app

# c++11 : ici il we have to use le C++ moderne (norme 2011), Les outils de Qt ont absolument besoin 
# de cette version pour fonctionner, sinon ils ne comprennent pas le code
# console : et ici on garde le terminal ouvert en arrière-plan pour voir nos std::cout
CONFIG += c++11 console

# et ici on met la liste des fichiers .cpp (les Sources)
SOURCES += \
    main.cpp \
    reseau.cpp

# et ici on met la liste des fichiers .hpp 
HEADERS += \
    reseau.hpp