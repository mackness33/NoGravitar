#include "ground.hpp"

//---------------CONSTRUCTORS---------------
ground::ground(float w, float h, sf::Color c){
  int sectionY = h * (settings::MAX_GROUND_HEIGHT - settings::MIN_GROUND_HEIGHT);
  sf::Vector2f *lastPoint = nullptr, *actualPoint = nullptr;

  numVertex = utility::RandInt(10, 5);
  offsetY = settings::MIN_GROUND_HEIGHT;
  length = w / numVertex;

  int *tri = nullptr, *sad = nullptr;
  int *boob = nullptr, *zoof = nullptr;

  lastPoint = new sf::Vector2f(10, 10/*(h - utility::RandFloat(sectionY, offsetY))*/);
  tri = new int(0);
  boob = new int(0);
  zoof = new int(0);

  std::cout << "NUMVERTEX" << numVertex << ": " << numVertex << std::endl;

  for(int i = 1, lastPos = 0; i < numVertex; i++, lastPos += length, *lastPoint = *actualPoint, *tri = *sad){
    float x = utility::RandInt(length, lastPos), y = h - utility::RandFloat(sectionY, offsetY);

    //actualPoint = nullptr;
    actualPoint = new sf::Vector2f(x, y);
    sad = new int(i);
    std::cout << "Position x" << i << ": " << x << std::endl;
    //*actualPoint = sf::Vector2f(utility::RandInt(length, lastPos), h - utility::RandFloat(sectionY, offsetY));
    line *L = new line(*lastPoint, *actualPoint);
    if(i > 1)
      L->setptrA(lines.back()->getptrB());

    std::cout << "Position y" << i << ": " << y << std::endl;
    lines.push_back(L);
  }
  std::cout << "ERROR GRUOND" << std::endl;

  line *temp = lines[0];
  std::cout << "Position x0: " << temp->getA().x << std::endl;
  std::cout << "Position y0: " << temp->getA().y << std::endl;

  for (int i = 0; i < lines.size(); i++){
    temp = lines[i];
    std::cout << "Position x" << i+1 << ": " << temp->getB().x << std::endl;
    std::cout << "Position y" << i+1 << ": " << temp->getB().y << std::endl;
  }

  body = new shape<sf::VertexArray>(numVertex, lines);
  std::cout << "FORGING GROUND" << std::endl;
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

bool ground::intersects (drawable* obj){
  //sf::FloatRect objBound = obj->getEssence()->getBounds();
  //int posObj = objBound.left, numLine = 0;


  //bool monotony =
  //if(posObj % numVertex != (posObj + obj.width) % numVertex ){

  //}


}

bool ground::intersectionPoint(sf::Vector2f* pnt, line* sect, bool monotony){}

void ground::Draw (sf::RenderWindow* window){
  body->Draw(window);
}

std::string ground::Class(){
  return "ground";
}
