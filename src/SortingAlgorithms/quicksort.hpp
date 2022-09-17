#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <vector>
#include <chrono>
#include <thread>
#include <SFML/Graphics.hpp>

void quicksort(std::vector<std::pair<int,sf::RectangleShape>>& Array, int low, int high, sf::RenderWindow* target);
int partition(std::vector<std::pair<int,sf::RectangleShape>>& Array, int low, int high, sf::RenderWindow* target);


#endif