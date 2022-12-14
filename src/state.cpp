#include "state.hpp"

State::State(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::string root_filepath, std::stack<State*>* states)
{
	this->root_filepath_ = root_filepath;
	this->window_ = window;
	this->supportedKeys_ = supportedKeys;
	this->states = states;
}

State::~State()
{

}

void State::checkForQuit()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds_.at("CLOSE"))))
	{
		this->quit_ = true;
	}
}

const bool& State::getQuit() const
{
	return this->quit_;
}

void State::updateMousePosition()
{
	this->mousePosScreen = sf::Mouse::getPosition();
	this->mousePosWindow = sf::Mouse::getPosition(*this->window_);
	this->mousePosView = this->window_->mapPixelToCoords(sf::Mouse::getPosition(*this->window_));
}
