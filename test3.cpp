#include <iostream>
#include <experimental/filesystem>
#include <string>
#include "Classes/line.hpp"

//template class object_test<sf::CircleShape>;

int main(){
  line *L = new line(sf::Vector2f(0, 0), sf::Vector2f(200, 200));
  line *temp = new line(sf::Vector2f(90, 80), sf::Vector2f(80, 90));

  /*if(L->intersection(sf::Vector2f(50, 50)))
    std::cout << "Intersezione!" << std::endl;
  else
    std::cout << "Error!" << std::endl;
*/
  sf::Vector2f result = L->intersection(*temp);
  if(result.x >= 0 && result.y >= 0){
    std::cout << "Intersezione!" << std::endl;
    std::cout << "X: " << result.x << std::endl;
    std::cout << "Y: " << result.y << std::endl;
  }
  else
    std::cout << "Error!" << std::endl;

/*
  if(temp->intersection(sf::Vector2f(100, 100)))
    std::cout << "Intersezione!" << std::endl;
  else
    std::cout << "Error!" << std::endl;
*/
  return 0;
}

/*
int main()
{
    char str[] = "Geeks-for-Geeks";

    // Returns first token
    char *token = strtok(str, "-");

    // Keep printing tokens while one of the
    // delimiters present in str[].
    while (token != NULL)
    {
        printf("%s\n", token);
        token = strtok(NULL, "-");
    }

    return 0;
}
*/
