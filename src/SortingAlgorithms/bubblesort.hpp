#ifndef BUBBLESORT_H
#define BUBBLESORT_H

#include <vector>
#include <chrono>
#include <thread>
#include <SFML/Graphics.hpp>

void bubblesort(std::vector<std::pair<int,sf::RectangleShape>>& Array, int n, sf::RenderWindow* target);

#endif