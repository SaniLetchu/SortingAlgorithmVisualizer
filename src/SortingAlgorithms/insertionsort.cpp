#include "insertionsort.hpp"

void insertionsort(std::vector<std::pair<int,sf::RectangleShape>>& Array, int n, sf::RenderWindow* target)
{
  using namespace std::this_thread;   
  using namespace std::chrono_literals; 
  using std::chrono::system_clock;

  int i, key, j; 
  for (i = 1; i < n; i++)
  { 
    key = Array[i].first; 
    j = i - 1; 
    while (j >= 0 && Array[j].first > key)
    { 
      swap(Array[j + 1], Array[j]);
      target->clear();
      for (int i = 0; i < Array.size(); i++) {
        Array[i].second.setFillColor(sf::Color::White);
        if(i == j) {
          Array[i].second.setFillColor(sf::Color::Red);
        }
        if(i == j + 1) {
          Array[i].second.setFillColor(sf::Color::Red);
        }
        Array[i].second.setOrigin(Array[i].second.getSize());
        Array[i].second.setPosition((i * target->getSize().x / Array.size()) + (target->getSize().x / Array.size()), 1080);
        target->draw(Array[i].second);
      }
      target->display();
      j = j - 1; 
    } 
    Array[j + 1].first = key; 
  } 
} 