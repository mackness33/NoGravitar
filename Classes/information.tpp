//std::vector<file<T>*> information::images = {};             //30%
//std::vector<file<sf::Font>*> information::fonts = {};             //30%

template <typename T> const void information::loadFiles(std::string path, std::vector<file<T>*> &array){
  file<T> *temp = nullptr;
  for (const auto & entry : std::experimental::filesystem::directory_iterator(path)){
    temp = new file<T>();
    temp->object = new T();
    temp->name = information::filenameFromPath(entry.path());

    std::cout << temp->name << std::endl;
    if (temp->object->loadFromFile(entry.path()))
      array.push_back(temp);

  }
}
