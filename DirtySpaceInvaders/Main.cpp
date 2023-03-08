#include "ConsoleRenderer.h"

#include <random>
#include <thread>
#include <memory>
#include <string>
#include <conio.h>
#include <iostream>
#include <functional>
#include <thread>

#include <Engine/Mathf/Vector.h>
#include "Engine\Gameplay\GameObjects\GameObject.h"
#include <Game/GameObjects/Alien.h>
#include <Game/GameObjects/PlayerShip.h>
#include <Engine/Gameplay/World/PlayField.h>

#include <Engine/Input/Input.h>
#include <Engine/Input/InputEvent.h>
#include <Engine/Input/InputManager.h>

#include <SFML/Graphics.hpp>

std::default_random_engine rGen;
typedef std::uniform_int_distribution<int> intRand;
typedef std::uniform_real_distribution<float> floatRand;

bool StartGame = false;

int main()
{
	rGen.seed(1);

	Vector2D size(80, 28);
	Renderer consoleRenderer(size);
	PlayField world(size);

	intRand xCoord(0, (int)size.x- 2);
	intRand yCoord(0, 10);

	// Populate aliens
	for (int k = 0; k < 20; k++)
	{
		Alien* a = new Alien("AlienShip"); //Change reference to pointer
		a->SetPos((float)xCoord(rGen), (float)yCoord(rGen));
		a->SetSprite(RaiderSprites::RS_Alien);
		world.AddObject(a);
	}

	InputManager::GetInputManagerInstance()->Init();

	// Add player
	PlayerShip* p = new PlayerShip("PlayerShip");
	p->SetInputController();
	p->SetPos(40, 27);
	p->SetSprite(RaiderSprites::RS_Player);
	world.AddObject(p);

	StartGame = true; //Add variable pour lancer la boucle de jeu

	sf::RenderWindow window(sf::VideoMode(80, 80), "My window");

	world.Start();

	// on fait tourner le programme tant que la fenêtre n'a pas été fermée
	while (window.isOpen())
	{
		world.Update();

		// on traite tous les évènements de la fenêtre qui ont été générés depuis la dernière itération de la boucle
		sf::Event event;
		while (window.pollEvent(event))
		{
			// fermeture de la fenêtre lorsque l'utilisateur le souhaite
			if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				window.close();

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::N)) {
				std::cout << "AH" << "--" ;
			}
		}

		

		RenderItemList rl;
		for (auto it : world.GameObjects())
		{
			RenderItem a = RenderItem(Vector2D(it->GetPos()), it->GetSprite());
			rl.push_back(a);
		}

		consoleRenderer.Update(rl);
		world.RemoveAllGameObject();
		window.clear();
	}
	world.ClearGame();
	return 0;

	//old
	/*while (StartGame) //Le jeu tourne tant que la variable est egal a true
	{
		world.Update();

		InputEvent Event;
		while (world.PollEvent(Event))
		{
			if (Event.Type == InputEvent::Close)
				StartGame = false;

			if (Event.Type == InputEvent::KeyPressed) {
				std::cout << " Key pressed" << "\n";
			}
		}

		RenderItemList rl;
		for (auto it : world.GameObjects())
		{
			RenderItem a = RenderItem(Vector2D(it->GetPos()), it->GetSprite());
			rl.push_back(a);
		}

		consoleRenderer.Update(rl);
		world.RemoveAllGameObject();

		// Sleep a bit so updates don't run too fast
		std::this_thread::sleep_for(std::chrono::nanoseconds(1));
	}

	world.ClearGame();*/
}