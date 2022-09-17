#ifndef VISUALIZER_H
#define VISUALIZER_H

#include "main_menu_state.hpp"
#include "main_menu_state.cpp"

class Visualizer
{
public:
	Visualizer(std::string& root_filepath);
	virtual ~Visualizer();
	void updateDt();
	void updateSFMLEvents();
	void update();
	void render();
	void run();
private:
	void initWindow();
	void initStates();
	void initKeys();
	std::string root_filepath_;
	sf::RenderWindow *window;
	sf::Event sfEvent;
	sf::ContextSettings windowSettings_;
	float dt;
	sf::Clock dtClock;
	sf::Clock quitclock_;
	std::stack<State*> states; 
	std::map<std::string, int> supportedKeys; 
};

#endif