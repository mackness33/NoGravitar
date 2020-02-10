//------------DELETES------------
template <typename T> void utility::deleteList(std::list<T*>& objects){
  std::cout << "size: " << objects.size() << std::endl;
  for (auto obj = objects.begin(); obj != objects.end(); ){
    std::cout << "what's the prob?" << std::endl;
    std::cout << "It does the bullet exist? " << ((!!(*obj)) ? "Yes" : "Nope") << std::endl;
    if(!!(*obj))
      delete *obj;

    std::cout << "is dat right!" << std::endl;

    *obj = nullptr;
    obj = objects.erase(obj);
  }

  objects.clear();
  std::cout << "THE END" << std::endl;
}

template <typename T> void utility::deleteVector(std::vector<T*>& objects){
  for (auto obj = objects.begin(); obj != objects.end(); ){
    if(!!*obj)
      delete *obj;

    *obj = nullptr;
    obj = objects.erase(obj);
  }

  objects.clear();
}
//------------METHOD------------
