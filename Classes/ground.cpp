#include "ground.hpp"

//---------------CONSTRUCTORS---------------
ground::ground(float w, float h, sf::Color c){
  int sectionY = h * (settings::MAX_GROUND_HEIGHT - settings::MIN_GROUND_HEIGHT);
  sf::Vector2f *lastPoint = nullptr, *actualPoint = nullptr;
  line *L = nullptr;

  numVertex = 6;//utility::RandInt(10, 5);
  offsetY = settings::MIN_GROUND_HEIGHT;
  length = w / (numVertex - 1);

  lastPoint = new sf::Vector2f(0, (h - utility::RandFloat(sectionY, offsetY)));

  std::cout << "NUMVERTEX" << numVertex << ": " << numVertex << std::endl;

  for(int i = 1, lastPos = length; i < numVertex-1; i++, lastPos += length, *lastPoint = *actualPoint){
    actualPoint = new sf::Vector2f(/*utility::RandInt(length, lastPos)*/ lastPos, h - utility::RandFloat(sectionY, offsetY));

    L = new line(*lastPoint, *actualPoint);

    if(i > 1)
      L->setptrA(lines.back()->getptrB());

    lines.push_back(L);

    sf::Vector2f A = lines[i-1]->getA();
    sf::Vector2f B = lines[i-1]->getB();
    std::cout << "lines : " << i-1 << " -> X: " << A.x << std::endl;
    std::cout << "lines : " << i-1 << " -> Y: " << A.y << std::endl;
    std::cout << "lines : " << i-1 << " -> X: " << B.x << std::endl;
    std::cout << "lines : " << i-1 << " -> Y: " << B.y << std::endl;

  }

  actualPoint = new sf::Vector2f(w, (h - utility::RandFloat(sectionY, offsetY)));
  L = new line(*lastPoint, *actualPoint);
  L->setptrA(lines.back()->getptrB());
  lines.push_back(L);
  sf::Vector2f A = lines[3]->getA();
  sf::Vector2f B = lines[3]->getB();
  std::cout << "lines : " << 3 << " -> X: " << A.x << std::endl;
  std::cout << "lines : " << 3 << " -> Y: " << A.y << std::endl;
  std::cout << "lines : " << 3 << " -> X: " << B.x << std::endl;
  std::cout << "lines : " << 3 << " -> Y: " << B.y << std::endl;

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


  //TODO: Implementation "intersection line-line and line-point"
  if(sectLeft != sectRight){
    std::cout << "IM IN THE FIRST PART" << std::endl;
    if(lines[sectRight]->doIntersect(ptr1) || lines[sectRight]->doIntersect(ptr2) || lines[sectRight]->doIntersect(ptr3) || lines[sectRight]->doIntersect(ptr4))
      return true;

    if(lines[sectLeft]->doIntersect(ptr1) || lines[sectLeft]->doIntersect(ptr2) || lines[sectLeft]->doIntersect(ptr3) || lines[sectLeft]->doIntersect(ptr4))
      return true;
    //TODO: Need to check also between the Left and Left + Width
  }
  else{
    std::cout << "IM IN THE SECOND PART" << std::endl;
    std::cout << "monotony: " << (lines[sectLeft]->getSlope() >= 0) << std::endl;
    if(lines[sectLeft]->getSlope() >= 0){
      //f::Vector2f point = lines[sectLeft]->doIntersect(ptr);
      std::cout << "LEFT intersection: " << std::endl;
      //std::cout << "LEFT intersection point y in first: " << point.y << std::endl;
      //std::cout << "LEFT intersection point x in first: " << point.x << std::endl;
      //if(point != sf::Vector2f(-1, -1))
      if(lines[sectLeft]->doIntersect(ptr1) || lines[sectLeft]->doIntersect(ptr2) || lines[sectLeft]->doIntersect(ptr3) || lines[sectLeft]->doIntersect(ptr4))
        return true;
    }else{
      //ptr->swap();
      //ptr->setA(right);

      //sf::Vector2f point = lines[sectRight]->doIntersect(ptr);
      std::cout << "RIGHT intersection: " << std::endl;
      //std::cout << "RIGHT intersection point y in first: " << point.y << std::endl;
      //std::cout << "RIGHT intersection point x in first: " << point.x << std::endl;
      //if(point != sf::Vector2f(-1, -1))
      //if(lines[sectRight]->doIntersect(ptr) || bottom.y >= lines[sectRight]->getA().y)
        //return true;
      if(lines[sectRight]->doIntersect(ptr1) || lines[sectRight]->doIntersect(ptr2) || lines[sectRight]->doIntersect(ptr3) || lines[sectRight]->doIntersect(ptr4))
        return true;
    }

  }


  return false;
  //return this->template intersects(obj); }
}

bool ground::getMonotony(int sect){
  //sf::Vector2f* A = lines[sect].getA();
  //sf::Vector2f* B = lines[sect].getB();

  //if(A.y <= B.y)
    //return true;
  return false;
}

void ground::Draw (sf::RenderWindow* window){
  body->Draw(window);
}

std::string ground::Class(){
  return "ground";
}
