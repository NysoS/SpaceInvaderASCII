# SpaceInvade

## Threshold 0

Création de l'architecture en séparent les dans des fichies distanct et en séparent la partie Engine de la partie Game

### class InputEvent

* Ajout de la class InputEvent
* Cette class permet la création d'évenement sur une entrée clavier, ainsi que d'assigné une fonction de callback

### class GameObject

* Ajout d'un ID unique ainsi d'un Getter qui servira pour la detection de collision

### Class PlayField
* Remplacement du vector gameObjects par deux vector<GameObject>:
	1 Le premier va permettre d'afficher tous les gameObjects ajoutés dans le niveau
	2 Le second va permettre à la fin d'une frame, de supprimer tous les gameObjects qui doivent être supprimés
* Ajout de 2 Getter constant sur les deux vectors précédement ajouté
* Ajout de la méthode RemoveAllGameObject, qui permet de vide les la memoire
* Dans la fonction Update, on récupère une copie constant du tableau d'ajout des gameObjects

### Class AlienLaser

* On check si le joueur retourné, est pas un pointer null
* On Détruie le laser si il y a collision avec le joueur et on stop la partie

### Class PlayerLaser

* On récupère une liste de gameObject du type "AlienLaser"
* On Vérifie la collision entre le PlayerLaser et l'AlienLaser
* On récupère une liste de gameObject du type "AkuebtShip"
* On vérifie la collision entre le PlayerLaser et l'AlienShip
* Si il y a collision pour les deux, on ajoute le gameObject dans la liste à supprimer

### Class Alien

* Remplacement du delete m_objType -> delete[] m_objType
* On ajoute une vérification pour etre sur que le joueur retourné, n'est pas un pointer null
* On stop la partie si il ya une collision
* Remplacement de la ligne d'initialisation du AlienLaser

### Class PlayerShip

* Remplacement du delete m_objType -> delete[] m_objType
* Ajout d'un system d'input 
* Remplacement de la ligne d'initialisation du PlayerLaser
* Ajout d'une méthode Move qui est appelée via une fonction de callback

### int main()
* Remplacement de la ligne d'initialisation des Aliens
* Modification de la pos.x -> pos.y
* Ajout d'un system de poolEvent, permettant de comsummer tous les entrées clavier saisie par l'utilisateur

## Threshold 1

* Création de l'architecture du projet en séparent les fichiers cpp et le fichier d'entete
* Ajout des fonctions Start, Update, Destroy
* Déplacer la logique dans les bonnes fonctions

* Ajout de la librairie SFML, pour inclure la gestion des Inputs

### Class InputAction

* Création de la class InputAction, permetant de définir une action, sur un imput

### Class InputController

* AddInputsAxis: elle permet d'ajouter une fonction de callback sur une action souhaitée
* AddInputsAction: Similaire à la première, la différence c'est qu'elle ne prend pas de paramètre
* ConsumeInputAxis: Permet de lire lancer la fonction de callback selon l'input choisie
* ConsumeInputAction: Similaire à ConsumeInputAxis

### Class InputManager

* Création d'un singleton, pour l'utiliser nimporte ou
* Init: Permet de faire le lien entre l'input clavier et l'action souhaitée
* BindAxis: Permet d'associer une fonction de callback sur une action
* BindAction: Similaire à BindAxis

### KeyboardDefaultBinding.h

Permet d'associer une touche clavier, sur une action

### Alien

* Ajout de la fonction Start

### PlayerShip

* Ajout de la fonction Start, On bind les actions du joueur avec une fonction de callback
* Ajout de l'inputController
* Ajout des fonctions de callback pour les actions du joueur, Move & Shoot

### int main()

* Création de l'instance de l'InputManager
* Ajout de l'inputController sur le player
* Remplacement de la loop de jeu par la loop de SFML