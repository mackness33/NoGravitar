#include "ground.hpp"
#include "utility.hpp"

//---------------CONSTRUCTORS---------------
ground::ground(float w, float h, sf::Color c) : numVertex(utility::RandInt(information::GROUND_RAND_VERTEX, information::GROUND_MIN_NUM_VERTEX)), offsetY(information::MIN_GROUND_HEIGHT){
  length = w / (numVertex - 1);
  this->setup(w, h);
  body = new shape<sf::VertexArray>(numVertex, lines);
}

ground::~ground(){
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


//---------------METHODS---------------
void ground::setup(float w, float h){
  int sectionY = h * (information::MAX_GROUND_HEIGHT - information::MIN_GROUND_HEIGHT);
  sf::Vector2f *lastPoint = nullptr, *actualPoint = nullptr;                                  //pointer to maintain data regarding the last and actual line created
  line *L = nullptr;

  lastPoint = new sf::Vector2f(0, (h - utility::RandFloat(sectionY, offsetY)));

  for(int i = 1, lastPos = length; i < numVertex-1; i++, lastPos += length, *lastPoint = *actualPoint){
    actualPoint = new sf::Vector2f(lastPos, h - utility::RandFloat(sectionY, offsetY));

    L = new line(*lastPoint, *actualPoint);

    //collect the last point with the actual
    if(i > 1)
      L->setptrA(lines.back()->getptrB());

    lines.push_back(L);
  }

  //last line to be created
  actualPoint = new sf::Vector2f(w, (h - utility::RandFloat(sectionY, offsetY)));
  L = new line(*lastPoint, *actualPoint);
  L->setptrA(lines.back()->getptrB());
  lines.push_back(L);
}

bool ground::intersects(drawable* obj){
  sf::FloatRect objBound = obj->GetGlobalBounds();
  int sectLeft = objBound.left / length, sectRight = (objBound.left + objBound.width) / length;
  bool checkLeft = (objBound.left >= 0 && sectLeft >= 0 && sectLeft < lines.size()-1), checkRight = (objBound.left + objBound.width >= 0 && sectRight >= 0 && sectRight < lines.size());

  //check whether it is inside of the playground
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
