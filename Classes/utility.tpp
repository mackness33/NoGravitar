//------------DELETES------------
template <typename T> void utility::deleteList(std::list<T*>& objects){
  for (auto obj = objects.begin(); obj != objects.end(); ){
    if(!!*obj)
      delete *obj;

    *obj = nullptr;
    obj = objects.erase(obj);
  }

  objects.clear();
}
//------------METHOD------------
