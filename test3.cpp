#include <iostream>
#include <experimental/filesystem>

//template class object_test<sf::CircleShape>;

int main(){
  std::cout << "Current path is " << std::experimental::filesystem::current_path() << '\n';
  std::string path = std::experimental::filesystem::current_path();
  for (const auto & entry : std::experimental::filesystem::directory_iterator(path + "/img"))
    std::cout << entry.path() << std::endl;

  return 0;
}
