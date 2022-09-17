#ifndef INSERTIONSORT_H
#define INSERTIONSORT_H

#include <vector>
#include <chrono>
#include <thread>
#include <SFML/Graphics.hpp>

void insertionsort(std::vector<std::pair<int,sf::RectangleShape>>& Array, int n, sf::RenderWindow* target);
void swap(int& x, int& y);

#endif