#include "ground.hpp"

//---------------CONSTRUCTORS---------------
//TODO: checks on the line to check on
ground::ground(float w, float h, sf::Color c){
  int sectionY = h * (information::MAX_GROUND_HEIGHT - information::MIN_GROUND_HEIGHT);

  numVertex = utility::RandInt(8, 5);
  offsetY = information::MIN_GROUND_HEIGHT;
  length = w / (numVertex - 1);

  sf::Vector2f *lastPoint = nullptr, *actualPoint = nullptr;
  lastPoint = new sf::Vector2f(0, (h - utility::RandFloat(sectionY, offsetY)));

  line *L = nullptr;

  for(int i = 1, lastPos = length; i < numVertex-1; i++, lastPos += length, *lastPoint = *actualPoint){
    actualPoint = new sf::Vector2f(lastPos /*utility::RandInt(length, lastPos)*/, h - utility::RandFloat(sectionY, offsetY));

    L = new line(*lastPoint, *actualPoint);

    //std::cout << "here Bob!" << std::endl;
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

  utility::deleteVector(lines);

  if(!!body)
    delete body;

  body = nullptr;
}


//---------------GETS---------------
std::vector<line*> ground::getLines() { return lines; }
shape<sf::VertexArray>* ground::getShape() { return body; }
sf::VertexArray* ground::getDrawable() { return body->getBody(); }
sf::FloatRect ground::GetGlobalBounds() { return body->getBody()->getBounds(); }

//---------------SETS---------------



//---------------METHODS---------------
bool ground::intersects(drawable* obj){
  sf::FloatRect objBound = obj->GetGlobalBounds();
  int sectLeft = objBound.left / length, sectRight = (objBound.left + objBound.width) / length;     //BUG: Can't be divided with length
  bool checkLeft = (objBound.left >= 0 && sectLeft >= 0 && sectLeft < lines.size()-1), checkRight = (objBound.left + objBound.width >= 0 && sectRight >= 0 && sectRight < lines.size()-1);

  if(checkLeft || checkRight){
    sf::Vector2f left = utility::left(obj), right = utility::right(obj), top = utility::top(obj), bottom = utility::bottom(obj);
    line *ptr1 = new line(left, bottom), *ptr2 = new line(right, bottom), *ptr3 = new line(left, top), *ptr4 = new line(right, top);
      if(lines[sectRight]->doIntersect(ptr1) || lines[sectRight]->doIntersect(ptr2) || lines[sectRight]->doIntersect(ptr3) || lines[sectRight]->doIntersect(ptr4))
        return true;

    if(checkRight && sectLeft != sectRight)
      if(lines[sectLeft]->doIntersect(ptr1) || lines[sectLeft]->doIntersect(ptr2) || lines[sectLeft]->doIntersect(ptr3) || lines[sectLeft]->doIntersect(ptr4))
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
