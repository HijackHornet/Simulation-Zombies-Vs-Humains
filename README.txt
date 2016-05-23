# Simulation-Zombies-Vs-Humains #
Par Leo Gigandon & Tristan Rivière
LIF7
////////////////////////////////////////////////////////////////
//DESCRIPTION PROJET////////////////////////////////////////
////////////////////////////////////////////////////////
Simulation zombies vs humains est un logiciel de simulation d'une attaque de zombies dans un batiment clos dans lequel se trouvent de nombreux citoyens et policiers. Les policiers ont pour objectif d'éliminer tout les zombies, les zombies doivent les contaminer, et les citoyens doivent s'enfuire.
L'objectif d'une telle simulation est en réalité la mise en oeuvre de champs d'influence et de propagation du danger autour des personnages. En effet les zombie propagent du danger proche d'eux, danger qui se cumulent en fonction de leur nombre, et les citoyens cherchent donc à se déplacer la ou il y a le moins de danger. De la meme manière, les citoyens propagent un champs qui servira de point de référence pour le déplacement des zombies. Il s'agit d'un mecanisme complexe et non visible intrasequement à l'écran mais qui représente tout l'interet de se projet.

////////////////////////////////////////////////////////////////
//FONCTIONALITEES///////////////////////////////////////////
////////////////////////////////////////////////////////
Interface :
	Tout d'abord vous arrivez sur une interface codé en GTK permetant de choisir différent parametre pour la simulation, à savoir le terrain à utiliser, le nombre de zombies, de citoyens et enfin de policier. Vous disposez alors d'un bouton permetant de lancer la simulation.
	Vous pouvez sinon regler la taille d'un nouveau terrain à créer, puis cliquer sur le bouton de lancement de l'éditeur de terrain.
Simutation : 
	Commandes : Touche Echap pour fermer la fenetre, ou clique sur la croix.
	Initialisation : Le nombre d'entité de chaque type que vous avez choisi se placent aléatoirement sur la carte en respectant contraintes des murs.
	Comportement visible : Il n'y a que deux issue possible, soit les zombies élimines tout les policier et ils ont alors gagné, soit les policier élimines tout les zombies.
	On constate que les citoyens se déplacent le plus près des bord extèrieur du terrain car les zombies se situent généralement au milieu. On arrive alors dans une position d'équilibre car les champs d'influencent forment une cuvette et les zombie ne savent pas dans quel direction aller car il sont entouré de toutes part. C'est une démonstration du fonctionement des champs d'influence, bien que l'on constate donc que leur application ne se pretent pas bien à notre mecanisme de jeu.
Editeur :
	Commandes : Touche echap pour quitter sans sauvegarder, Touche S pour sauvegarder la map et quitter.
	Initialisation : Choix du dossier de sauvegarde et du nom du fichier. On choisi aussi la taille de la map à créer.
	Fonctionalitées : A chaque clique sur un case, on tranforme le sol en mur ou le mur en sol.
////////////////////////////////////////////////////////////////
//ORGANISATION DES DOSSIER//////////////////////////////////
////////////////////////////////////////////////////////
data          : Dossier comportant les fichiers terrain pour le logiciel
  |_Graphics  : Dossier des images utilisés pour l'affichage
src			  : Dossier des fichier C et des entetes
  |_SDL2	  : Dossier des fichier C et des entetes spécifique à l'affichage SDL2 et SDL2_image
obj			  : Dossier des fichier compilés .o
bin			  : Dossier comportant l'executable du projet


////////////////////////////////////////////////////////////////
//COMPILATION///////////////////////////////////////////////
////////////////////////////////////////////////////////
La compilation se fait avec l'outil make. La compilation se fait en ligne de commande en entrant la commande :
   make
Une version debug et une version release stockées dans bin/ sont alors créées.
Pour générer la documentation, entrer la commande :
   make doxygen
La documentation est alors stockée dans doc/html

////////////////////////////////////////////////////////////////
//EXECUTION/////////////////////////////////////////////////
////////////////////////////////////////////////////////
L'execution s'effectue depuis le dossier bin, que cela soit sous Windows ou Linux.
Le programme à executer est Simulation-Humains-Vs-Zombies.exe.
