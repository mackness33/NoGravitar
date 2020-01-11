#include "ground.hpp"

//---------------CONSTRUCTORS---------------
ground::ground(float w, float h, sf::Color c){
  int sectionY = h * (information::MAX_GROUND_HEIGHT - information::MIN_GROUND_HEIGHT);

  numVertex = utility::RandInt(10, 5);
  offsetY = information::MIN_GROUND_HEIGHT;
  length = w / (numVertex - 1);

  sf::Vector2f *lastPoint = nullptr, *actualPoint = nullptr;
  lastPoint = new sf::Vector2f(0, (h - utility::RandFloat(sectionY, offsetY)));

  line *L = nullptr;

  for(int i = 1, lastPos = length; i < numVertex-1; i++, lastPos += length, *lastPoint = *actualPoint){
    actualPoint = new sf::Vector2f(lastPos /*utility::RandInt(length, lastPos)*/, h - utility::RandFloat(sectionY, offsetY));

    L = new line(*lastPoint, *actualPoint);

    std::cout << "here Bob!" << std::endl;
    if(i > 1)
      L->setptrA(lines.back()->getptrB());

    lines.push_back(L);
  }

  actualPoint = new sf::Vector2f(w, (h - utility::RandFloat(sectionY, offsetY)));
  L = new line(*lastPoint, *actualPoint);
  L->setptrA(lines.back()->getptrB());
  lines.push_back(L);

  body = new shape<sf::VertexArray>(numVertex, lines);
  //std::cout << "FORGING GROUND" << std::endl;
}

ground::~ground(){
  std::cout << "DELETING GROUND" << std::endl;

  delete body;
  body = nullptr;
}


//---------------GETS---------------
shape<sf::VertexArray>* ground::getLine() { return body; }
sf::VertexArray* ground::getDrawable() { return body->getBody(); }
sf::FloatRect ground::GetGlobalBounds() { return body->getBody()->getBounds(); }

//---------------SETS---------------



//---------------METHODS---------------
bool ground::intersects(drawable* obj){
  sf::FloatRect objBound = obj->GetGlobalBounds();
  bool intersect = false;
  sf::Vector2f left = utility::left(obj), right = utility::right(obj), top = utility::top(obj), bottom = utility::bottom(obj);
  line *ptr1 = new line(left, bottom), *ptr2 = new line(right, bottom), *ptr3 = new line(left, top), *ptr4 = new line(right, top);
  int sectLeft = objBound.left / length, sectRight = (objBound.left + objBound.width) / length;     //BUG: Can't be divided with length

  if(sectLeft != sectRight){
    //std::cout << "IM IN THE FIRST PART" << std::endl;
    if(lines[sectRight]->doIntersect(ptr1) || lines[sectRight]->doIntersect(ptr2) || lines[sectRight]->doIntersect(ptr3) || lines[sectRight]->doIntersect(ptr4))
      return true;

    if(lines[sectLeft]->doIntersect(ptr1) || lines[sectLeft]->doIntersect(ptr2) || lines[sectLeft]->doIntersect(ptr3) || lines[sectLeft]->doIntersect(ptr4))
      return true;
  }
  else{
    //std::cout << "IM IN THE SECOND PART" << std::endl;
    //f::Vector2f point = lines[sectLeft]->doIntersect(ptr);
    //std::cout << "LEFT intersection: " << std::endl;
    //std::cout << "LEFT intersection point y in first: " << point.y << std::endl;
    //std::cout << "LEFT intersection point x in first: " << point.x << std::endl;
    //if(point != sf::Vector2f(-1, -1))

    //ptr->swap();
    //ptr->setA(right);

    //sf::Vector2f point = lines[sectRight]->doIntersect(ptr);
    //std::cout << "RIGHT intersection: " << std::endl;
    //std::cout << "RIGHT intersection point y in first: " << point.y << std::endl;
    //std::cout << "RIGHT intersection point x in first: " << point.x << std::endl;
    //if(point != sf::Vector2f(-1, -1))
    //if(lines[sectRight]->doIntersect(ptr) || bottom.y >= lines[sectRight]->getA().y)
      //return true;
    if(lines[sectRight]->doIntersect(ptr1) || lines[sectRight]->doIntersect(ptr2) || lines[sectRight]->doIntersect(ptr3) || lines[sectRight]->doIntersect(ptr4))
      return true;
  }

  return false;
}

void ground::Draw (sf::RenderWindow* window){
  body->Draw(window);
}

std::string ground::Class(){
  return "ground";
}
