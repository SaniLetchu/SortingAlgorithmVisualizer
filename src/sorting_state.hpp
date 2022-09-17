#ifndef MAPSELECTOR_H
#define MAPSELECTOR_H

#include "state.hpp"
#include "SortingAlgorithms/quicksort.hpp"
#include "SortingAlgorithms/quicksort.cpp"
#include "SortingAlgorithms/insertionsort.hpp"
#include "SortingAlgorithms/insertionsort.cpp"
#include "SortingAlgorithms/bubblesort.hpp"
#include "SortingAlgorithms/bubblesort.cpp"
#include <filesystem>
#include <vector>
#include <algorithm>
#include <ctime>

class Sorting : public State
{
public:
	Sorting(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::string root_filepath, std::stack<State*>* states, std::string sorting_method);
	virtual ~Sorting();
	virtual void updateInput(const float& dt);
	virtual void endState();
	virtual void update(const float& dt);
	virtual void render(sf::RenderTarget* target = nullptr);
	void initVariables();
private:
	std::string root_filepath_;
	float windowX_;
	float windowY_;
	int AMOUNT_OF_NUMS_TO_GENERATE;

	sf::Clock greenTimer_;
	int currentGreen = 0;

	std::string sorting_method_;
	sf::RectangleShape backgroundColor_;
	void initKeyBinds();
  std::vector<std::pair<int,sf::RectangleShape>> Array;
};

#endif