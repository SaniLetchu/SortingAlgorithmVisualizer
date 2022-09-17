#ifndef STATE_H
#define STATE_H

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <stack>
#include <map>
#include <vector>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class State
{
public:
	State(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::string root_filepath, std::stack<State*>* states);
	virtual ~State();
	virtual void checkForQuit();
	const bool& getQuit() const;
	virtual void endState() = 0;
	virtual void updateInput(const float& dt) = 0;
	virtual void update(const float& dt) = 0;
	virtual void render(sf::RenderTarget* target = nullptr) = 0;
	virtual void updateMousePosition();
	bool quit_ = false;
protected:
	sf::RenderWindow* window_;
	std::map<std::string, int>* supportedKeys_;
	std::stack<State*>* states;
	std::map<std::string, int> keybinds_;
	std::string root_filepath_;
	sf::Vector2i mousePosScreen;
	sf::Vector2i mousePosWindow;
	sf::Vector2f mousePosView;
	virtual void initKeyBinds() = 0;
private:
};

#endif