#include <iostream>
#include <experimental/filesystem>
#include "Classes/line.hpp"

//template class object_test<sf::CircleShape>;

int main(){
  line *L = new line(sf::Vector2f(1, 1), sf::Vector2f(3, 3));
  line *temp = new line(sf::Vector2f(1, 3), sf::Vector2f(3, 1));

  if(L->intersection(sf::Vector2f(2, 2)))
    std::cout << "Intersezione!" << std::endl;
  else
    std::cout << "Error!" << std::endl;

  sf::Vector2f result = L->intersection(*temp);
  if(result.x >= 0 && result.y >= 0){
    std::cout << "Intersezione!" << std::endl;
    std::cout << "X: " << result.x << std::endl;
    std::cout << "Y: " << result.y << std::endl;
  }
  else
    std::cout << "Error!" << std::endl;

  return 0;
}
