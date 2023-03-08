# SpaceInvade

## Threshold 0

Cr�ation de l'architecture en s�parent les dans des fichies distanct et en s�parent la partie Engine de la partie Game

### class InputEvent

* Ajout de la class InputEvent
* Cette class permet la cr�ation d'�venement sur une entr�e clavier, ainsi que d'assign� une fonction de callback

### class GameObject

* Ajout d'un ID unique ainsi d'un Getter qui servira pour la detection de collision

### Class PlayField
* Remplacement du vector gameObjects par deux vector<GameObject>:
	1 Le premier va permettre d'afficher tous les gameObjects ajout�s dans le niveau
	2 Le second va permettre � la fin d'une frame, de supprimer tous les gameObjects qui doivent �tre supprim�s
* Ajout de 2 Getter constant sur les deux vectors pr�c�dement ajout�
* Ajout de la m�thode RemoveAllGameObject, qui permet de vide les la memoire
* Dans la fonction Update, on r�cup�re une copie constant du tableau d'ajout des gameObjects

### Class AlienLaser

* On check si le joueur retourn�, est pas un pointer null
* On D�truie le laser si il y a collision avec le joueur et on stop la partie

### Class PlayerLaser

* On r�cup�re une liste de gameObject du type "AlienLaser"
* On V�rifie la collision entre le PlayerLaser et l'AlienLaser
* On r�cup�re une liste de gameObject du type "AkuebtShip"
* On v�rifie la collision entre le PlayerLaser et l'AlienShip
* Si il y a collision pour les deux, on ajoute le gameObject dans la liste � supprimer

### Class Alien

* Remplacement du delete m_objType -> delete[] m_objType
* On ajoute une v�rification pour etre sur que le joueur retourn�, n'est pas un pointer null
* On stop la partie si il ya une collision
* Remplacement de la ligne d'initialisation du AlienLaser

### Class PlayerShip

* Remplacement du delete m_objType -> delete[] m_objType
* Ajout d'un system d'input 
* Remplacement de la ligne d'initialisation du PlayerLaser
* Ajout d'une m�thode Move qui est appel�e via une fonction de callback

### int main()
* Remplacement de la ligne d'initialisation des Aliens
* Modification de la pos.x -> pos.y
* Ajout d'un system de poolEvent, permettant de comsummer tous les entr�es clavier saisie par l'utilisateur

## Threshold 1

* Cr�ation de l'architecture du projet en s�parent les fichiers cpp et le fichier d'entete
* Ajout des fonctions Start, Update, Destroy
* D�placer la logique dans les bonnes fonctions

* Ajout de la librairie SFML, pour inclure la gestion des Inputs

### Class InputAction

* Cr�ation de la class InputAction, permetant de d�finir une action, sur un imput

### Class InputController

* AddInputsAxis: elle permet d'ajouter une fonction de callback sur une action souhait�e
* AddInputsAction: Similaire � la premi�re, la diff�rence c'est qu'elle ne prend pas de param�tre
* ConsumeInputAxis: Permet de lire lancer la fonction de callback selon l'input choisie
* ConsumeInputAction: Similaire � ConsumeInputAxis

### Class InputManager

* Cr�ation d'un singleton, pour l'utiliser nimporte ou
* Init: Permet de faire le lien entre l'input clavier et l'action souhait�e
* BindAxis: Permet d'associer une fonction de callback sur une action
* BindAction: Similaire � BindAxis

### KeyboardDefaultBinding.h

Permet d'associer une touche clavier, sur une action

### Alien

* Ajout de la fonction Start

### PlayerShip

* Ajout de la fonction Start, On bind les actions du joueur avec une fonction de callback
* Ajout de l'inputController
* Ajout des fonctions de callback pour les actions du joueur, Move & Shoot

### int main()

* Cr�ation de l'instance de l'InputManager
* Ajout de l'inputController sur le player
* Remplacement de la loop de jeu par la loop de SFML