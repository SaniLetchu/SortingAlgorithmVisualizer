#include "quicksort.hpp"

void swap(int& x, int& y)
{
	int temp = x;
	x =  y;
	y = temp;
	return;
}

void quicksort(std::vector<std::pair<int,sf::RectangleShape>>& Array, int low, int high, sf::RenderWindow* target) {
	if (low < high)
	{
		int pi = partition(Array, low, high, target);
		quicksort(Array, low, pi - 1, target);
		quicksort(Array, pi + 1, high, target);
	}
}

int partition(std::vector<std::pair<int,sf::RectangleShape>>& Array, int low, int high, sf::RenderWindow* target) {
  using namespace std::this_thread;   
  using namespace std::chrono_literals; 
  using std::chrono::system_clock;

	int size = Array.size();
	int pivot = Array[high].first;
	int i = (low - 1);

	for (int j = low; j <= high - 1; j++)
	{
		if (Array[j].first <= pivot)
		{
      sleep_for(1ms);
			i++;
      swap(Array[i], Array[j]);
      target->clear();
      for (int a = 0; a < Array.size(); a++) {
        Array[a].second.setFillColor(sf::Color::White);
        if(a == j) {
          Array[a].second.setFillColor(sf::Color::Red);
        }
        if(a == i) {
          Array[a].second.setFillColor(sf::Color::Red);
        }
        Array[a].second.setOrigin(Array[a].second.getSize());
        Array[a].second.setPosition((a * target->getSize().x / Array.size()) + (target->getSize().x / Array.size()), 1080);
        target->draw(Array[a].second);
      }
      target->display();
		}
	}
	swap(Array[i + 1], Array[high]);
  target->clear();
  for (int a = 0; a < Array.size(); a++) {
    Array[a].second.setFillColor(sf::Color::White);
    if(a == high) {
      Array[a].second.setFillColor(sf::Color::Red);
    }
    if(a == i + 1) {
      Array[a].second.setFillColor(sf::Color::Red);
    }
    Array[a].second.setOrigin(Array[a].second.getSize());
    Array[a].second.setPosition((a * target->getSize().x / Array.size()) + (target->getSize().x / Array.size()), 1080);
    target->draw(Array[a].second);
  }
  target->display();
	return (i + 1);
}