#ifndef MAINMENUSTATE_H
#define MAINMENUSTATE_H

#include "button.hpp"
#include "button.cpp"
#include "state.hpp"
#include "state.cpp"
#include "sorting_state.cpp"
#include "sorting_state.hpp"

class MainMenuState : public State
{
public:
	MainMenuState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::string root_filepath, std::stack<State*>* states, sf::Event *Event);
	virtual ~MainMenuState();
	virtual void updateInput(const float& dt);
	virtual void endState();
	virtual void update(const float& dt);
	virtual void render(sf::RenderTarget* target = nullptr);
	void updateButtons();
	void renderButtons(sf::RenderTarget* target = nullptr);
private:
	sf::RenderWindow* window_;
	std::string root_filepath_;
	sf::Texture backgroundTexture_;
	sf::RectangleShape background_;
	sf::RectangleShape backgroundText_;
	sf::Text backgroundTextUsingFont_;
	sf::Font font_;
	std::map<std::string, Button*> buttons_;
	float windowX_;
	float windowY_;
	sf::Event *Event_;
	sf::Clock timer_;
	sf::Int32 timerMax_;
	sf::Clock pressTimer_;
	sf::Int32 pressTimerMax_;
	void initVariables();
	void initBackground();
	void initKeyBinds();
	void initFonts();
	void initButtons();
	const bool getTimer();
	const bool getPressTimer();
};

#endif