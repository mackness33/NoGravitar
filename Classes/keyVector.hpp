//KEYVECTOR
//Class key

class keyVector{
private:
  sf::Keyboard::Key key;
  bool transformation;

public:
  //CONSTRUCTORS
  keyVector(sf::Keyboard::Key k/*ey*/, bool t/*ransfomation*/){
    this->key = k;
    this->transformation = t;
  }

  keyVector(){
    this->key = sf::Keyboard::Unknown;
    this->transformation = false;
  }

  //copy constructor
  keyVector(const keyVector& V){
    this->key = V.key;
    this->transformation = V.transformation;
  }

  //OPERATORS
  keyVector& operator=(const keyVector& V){
    this->key = V.key;
    this->transformation = V.transformation;

    return *this;
  }

  //GETS
  sf::Keyboard::Key getKey(){ return this->key;}
  bool getTransformation(){ return this->transformation;}

  //SETS
  void setKey(sf::Keyboard::Key k) { this->key = k;}
  void setTransformation(bool t) { this->transformation = t;}

  //METHODS
  //the method understand which key has been pressed and sets the boolean for the smoothness of the trasformation
  void isUsed(sf::Keyboard::Key key1, sf::Keyboard::Key key2){
    if(sf::Keyboard::isKeyPressed(key1) || sf::Keyboard::isKeyPressed(key2)){
      this->transformation = true;

      if(sf::Keyboard::isKeyPressed(key1))
        this->key = key1;            //KEY1
      else
        this->key = key2;            //KEY2
    }
  }

};
