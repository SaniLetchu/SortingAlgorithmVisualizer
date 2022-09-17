#include "main_menu_state.hpp"

MainMenuState::MainMenuState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::string root_filepath, std::stack<State*>* states, sf::Event *Event) : State(window, supportedKeys, root_filepath, states)
{
	this->window_ = window;
	this->root_filepath_ = root_filepath;
	this->Event_ = Event;
	this->initVariables();
	this->initFonts();
	this->initKeyBinds();
	this->initButtons();
	this->background_.setSize(sf::Vector2f(window->getSize().x, window->getSize().y));
	this->background_.setFillColor(sf::Color::Black );
	this->backgroundTextUsingFont_.setFont(font_);
	this->backgroundTextUsingFont_.setString("Sorting algorithm\nVisualizer");
	this->backgroundTextUsingFont_.setFillColor(sf::Color::Magenta);
	if (windowX_ > 1920)
		this->backgroundTextUsingFont_.setCharacterSize(120);
	else
		this->backgroundTextUsingFont_.setCharacterSize(90);
	this->backgroundTextUsingFont_.setPosition(windowX_-backgroundTextUsingFont_.getGlobalBounds().width-windowX_/20, windowY_/14);
}

MainMenuState::~MainMenuState()
{
	auto it = this->buttons_.begin();
	for (it = this->buttons_.begin(); it != buttons_.end(); ++it)
	{
		delete it->second;
	}
}

void MainMenuState::initVariables()
{
	windowX_ = static_cast<float>(this->window_->getSize().x);
	windowY_ = static_cast<float>(this->window_->getSize().y);
	this->timer_ .restart();
	this->timerMax_ = 200;
	this->pressTimer_.restart();
	pressTimerMax_ = 100;
}



void MainMenuState::initKeyBinds()
{
	std::ifstream ifs(root_filepath_ + "/src/Config/mainmenustate_keybinds.ini");
	if (ifs.is_open())
	{
		std::string key = "";
		std::string key_name = "";
		while (ifs >> key >> key_name )
		{
			this->keybinds_[key] = this->supportedKeys_->at(key_name);
		}
	}
	ifs.close();
}

void MainMenuState::initFonts()
{
	std::cout << "LOADING FONT" << " " << root_filepath_ << "\n";
	if (!this->font_.loadFromFile(root_filepath_ + "/src/Fonts/Azonix.otf"))
	{
		throw("ERROR::MAINMENUSTATE::UNABLE TO LOAD FONT");
	}
}

void MainMenuState::initButtons()
{
	windowX_ = static_cast<float>(this->window_->getSize().x);
	windowY_ = static_cast<float>(this->window_->getSize().y);
	this->buttons_["QUICKSORT"] = new Button(windowX_/10, windowY_-850, 400, 150, &this->font_, "Quicksort", sf::Color(100, 100, 100, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200), 60, false);
	this->buttons_["BUBBLESORT"] = new Button(windowX_/10, windowY_-650, 400, 150, &this->font_, "Bubble sort", sf::Color(100, 100, 100, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200), 60, false);
	this->buttons_["INSERTIONSORT"] = new Button(windowX_/10, windowY_-450, 400, 150, &this->font_, "Insertion sort", sf::Color(100, 100, 100, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200), 60, false);
	this->buttons_["QUIT"] = new Button(windowX_/10, windowY_-250, 400, 150, &this->font_, "Quit", sf::Color(100, 100, 100, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200), 60, false);
}

const bool MainMenuState::getTimer()
{
	if (this->timer_.getElapsedTime().asMilliseconds() >= this->timerMax_)
	{
		this->timer_.restart();
		return true;
	}
	return false;
}

const bool MainMenuState::getPressTimer()
{
	if (this->pressTimer_.getElapsedTime().asMilliseconds() >= this->pressTimerMax_)
	{
		this->pressTimer_.restart();
		return true;
	}
	return false;
}

void MainMenuState::update(const float& dt)
{
	this->updateMousePosition();
	this->updateInput(dt);
	this->updateButtons();
}

void MainMenuState::render(sf::RenderTarget* target)
{
	if (!target)
	{
		target = this->window_;
	}
	target->draw(this->background_); 
	target->draw(this->backgroundTextUsingFont_);
	this->renderButtons(target);
}

void MainMenuState::updateInput(const float& dt)
{
	this->updateMousePosition();
	this->checkForQuit();
}

void MainMenuState::updateButtons()
{
	for (auto &it : this->buttons_)
	{
		it.second->update(this->mousePosView);
	}
	if (this->buttons_["QUICKSORT"]->isPressed())
	{
		if (getPressTimer())
		{
			this->states->push(new Sorting(this->window_, this->supportedKeys_, this->root_filepath_, this->states, "quicksort"));
		}	
	}
	if (this->buttons_["BUBBLESORT"]->isPressed())
	{
		if (getPressTimer())
		{
			this->states->push(new Sorting(this->window_, this->supportedKeys_, this->root_filepath_, this->states, "bubblesort"));
		}	
	}
	if (this->buttons_["INSERTIONSORT"]->isPressed())
	{
		if (getPressTimer())
		{
			this->states->push(new Sorting(this->window_, this->supportedKeys_, this->root_filepath_, this->states, "insertionsort"));
		}	
	}
	if (this->buttons_["QUIT"]->isPressed())
	{
		if (getPressTimer())
		{
			this->quit_ = true;
		}		
	}
}

void MainMenuState::renderButtons(sf::RenderTarget* target)
{
	for (auto &it : this->buttons_)
	{
		it.second->render(target);
	}
}

void MainMenuState::endState()
{
	std::cout << "Ending main menu state!" << "\n";
}
