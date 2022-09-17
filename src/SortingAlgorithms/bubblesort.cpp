#include "bubblesort.hpp"

void bubblesort(std::vector<std::pair<int,sf::RectangleShape>>& Array, int n, sf::RenderWindow* target)
{
  using namespace std::this_thread;   
  using namespace std::chrono_literals; 
  using std::chrono::system_clock;

  int i, j;
    for (i = 0; i < n - 1; i++) {
      for (j = 0; j < n - i - 1; j++) {
        if (Array[j].first > Array[j + 1].first) {
          swap(Array[j], Array[j + 1]);
          target->clear();
          for (int a = 0; a < Array.size(); a++) {
            Array[a].second.setFillColor(sf::Color::White);
          if(a == j) {
            Array[a].second.setFillColor(sf::Color::Red);
          }
          if(a == j + 1) {
            Array[a].second.setFillColor(sf::Color::Red);
          }
          Array[a].second.setOrigin(Array[a].second.getSize());
          Array[a].second.setPosition((a * target->getSize().x / Array.size()) + (target->getSize().x / Array.size()), 1080);
          target->draw(Array[a].second);
        }
        target->display();
        }
      }
    }
}
 