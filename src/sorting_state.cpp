#include "sorting_state.hpp"

Sorting::Sorting(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::string root_filepath, std::stack<State*>* states, std::string sorting_method) : State(window, supportedKeys, root_filepath, states)
{
	srand((unsigned int)time(NULL));
	this->AMOUNT_OF_NUMS_TO_GENERATE = rand()%401+50;
	this->sorting_method_ = sorting_method;
	if(sorting_method == "insertionsort") {
		AMOUNT_OF_NUMS_TO_GENERATE = 50;
	}
	if(sorting_method == "bubblesort") {
		AMOUNT_OF_NUMS_TO_GENERATE = 70;
	}
	this->root_filepath_ = root_filepath;
	this->initKeyBinds();
	this->initVariables();
	this->backgroundColor_.setSize(sf::Vector2f(window_->getSize().x, window_->getSize().y + 1500));
	this->backgroundColor_.setFillColor(sf::Color::Black);
	if(sorting_method_ == "quicksort") {
		quicksort(this->Array, 0, Array.size() - 1, this->window_);
	}
	if(sorting_method_ == "insertionsort") {
		insertionsort(this->Array, this->Array.size(), this->window_);
	}
	if(sorting_method_ == "bubblesort") {
		bubblesort(this->Array, this->Array.size(), this->window_);
	}
	for (int a = 0; a < Array.size(); a++) {
    Array[a].second.setFillColor(sf::Color::White);
  }
}

Sorting::~Sorting()
{
	Array.clear();
}

void Sorting::initKeyBinds()
{
	std::ifstream ifs(root_filepath_ + "/src/Config/mainmenustate_keybinds.ini");
	if (ifs.is_open())
	{
		std::string key = "";
		std::string key_name = "";
		while (ifs >> key >> key_name )
		{
			this->keybinds_[key] = this->supportedKeys_->at(key_name);
			std::cout << key_name << "\n";
		}
	}
	ifs.close();
}

void Sorting::initVariables()
{
	windowX_ = static_cast<float>(this->window_->getSize().x);
	windowY_ = static_cast<float>(this->window_->getSize().y);

  const int maxSizeY = windowY_;
  for (int i = 0; i < AMOUNT_OF_NUMS_TO_GENERATE; i++) {
    std::pair <int,sf::RectangleShape> pair (i, sf::RectangleShape(sf::Vector2f(windowX_ / AMOUNT_OF_NUMS_TO_GENERATE, maxSizeY / AMOUNT_OF_NUMS_TO_GENERATE * (i + 1))));
    Array.push_back(pair);
  }
  std::random_shuffle(&Array[0], &Array[AMOUNT_OF_NUMS_TO_GENERATE]);
}

void Sorting::update(const float& dt)
{
	this->updateMousePosition();
	this->updateInput(dt);
	sf::Time elapsed = greenTimer_.getElapsedTime();
	if(elapsed.asMilliseconds() > 2 && currentGreen < Array.size()) {
		greenTimer_.restart();
		Array[currentGreen].second.setFillColor(sf::Color::Green);
		currentGreen = currentGreen + 1;
	}
}

void Sorting::render(sf::RenderTarget* target)
{
	if (!target)
	{
		target = this->window_;
	}
	target->draw(this->backgroundColor_);
  for (int i = 0; i < AMOUNT_OF_NUMS_TO_GENERATE; i++) {
    this->Array[i].second.setOrigin(this->Array[i].second.getSize());
    this->Array[i].second.setPosition((i * windowX_ / AMOUNT_OF_NUMS_TO_GENERATE) + (windowX_ / AMOUNT_OF_NUMS_TO_GENERATE), 1080);
    target->draw(this->Array[i].second);
  }
}

void Sorting::updateInput(const float& dt)
{
	this->checkForQuit();
}

void Sorting::endState()
{
	sf::View view = this->window_->getDefaultView();
	this->window_->setView(view);
	std::cout << "Ending quicksort state!" << "\n";
}