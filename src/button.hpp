#ifndef BUTTON_H
#define BUTTON_H

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <sstream>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

enum button_states{BUTTON_IDLE = 0, BUTTON_HOVER, BUTTON_ACTIVE};

class Button
{
public:
	Button(float x, float y, float width, float height, sf::Font* font, std::string text,
	sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor, int text_size, bool box);
	~Button();
	const bool isPressed() const;
	void update(const sf::Vector2f mousePos);
	void render(sf::RenderTarget* target);
	void changeText(std::string text);

private:
	sf::Font* font_;
	sf::RectangleShape shape_;
	sf::Text buttonText_;
	int text_size_;
	bool boxBoolean_;
	sf::Color idleColor_;
	sf::Color hoverColor_;
	sf::Color activeColor_;
	short unsigned buttonState_;
};

#endif
