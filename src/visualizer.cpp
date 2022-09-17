#include "visualizer.hpp"

float WINDOW_WIDTH = 1920;
float WINDOW_HEIGHT = 1080;

Visualizer::Visualizer(std::string& root_filepath)
{
	root_filepath_ = root_filepath;
	this->initWindow();
	this->initKeys();
	this->initStates();
}

Visualizer::~Visualizer()
{
	delete this->window;
	while (!this->states.empty())
	{
		delete this->states.top();
		this->states.pop();
	}
}

void Visualizer::initWindow()
{
	sf::VideoMode window_bounds = sf::VideoMode::getDesktopMode();
	window_bounds.width = WINDOW_WIDTH;
	window_bounds.height = WINDOW_HEIGHT;
	this->windowSettings_.antialiasingLevel = 0;
	this->window = new sf::RenderWindow(window_bounds, "SortingAlgorithmVisualizer", sf::Style::Titlebar | sf::Style::Close, this->windowSettings_);
	this->window->setFramerateLimit(120);
	this->window->setVerticalSyncEnabled(0);
}

void Visualizer::initKeys()
{
	std::ifstream ifs(root_filepath_ + "/src/Config/keys.ini");
	if (ifs.is_open())
	{
		std::string key = "";
		int key_value = 0;
		while (ifs >> key >> key_value)
		{
			this->supportedKeys[key] = key_value;
		}
	}
	ifs.close();
}

void Visualizer::initStates()
{
	this->states.push(new MainMenuState(this->window, &this->supportedKeys, this->root_filepath_, &this->states, &this->sfEvent));
}

void Visualizer::updateDt()
{
	this->dt = this->dtClock.restart().asSeconds();
}
	
void Visualizer::updateSFMLEvents()
{
	while (this->window->pollEvent(this->sfEvent))
	{
		if(this->sfEvent.type == sf::Event::Closed)
			this->window->close();
	}
}

void Visualizer::update()
{
	this->updateSFMLEvents();
	sf::Time elapsed = quitclock_.getElapsedTime();
	if (!this->states.empty())
	{
		this->states.top()->update(this->dt);
		if (this->states.top()->getQuit()) {
			this->states.top()->quit_ = false;
			if(1 < elapsed.asSeconds()) {
				this->states.top()->endState();
				delete this->states.top();
				this->states.pop();
				quitclock_.restart();
			}
		}
	}
	else
	{
		this->window->close();
	}
}

void Visualizer::render()
{
	this->window->clear();
	if (!this->states.empty())
		this->states.top()->render();

	this->window->display();
}

void Visualizer::run()
{
	while (this->window->isOpen())
	{
		this->updateDt();
		this->update();
		this->render();
	}
}