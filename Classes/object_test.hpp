//OBJECT
//A prototype of a class

class object : public sf::ConvexShape{
  //if there are properties you must set and get them!!!
  private:
    int property;

  public:
    //CONSTRUCTORS
    object(sf::ConvexShape* s, int p/*roperty*/) : sf::ConvexShape(*s){
      this->property = p;

      //you don't need this->build() because it already exist you just need to copy
    }

    object(sf::ConvexShape* s) : sf::ConvexShape(*s){
      this->property = 0;

      //you don't need this->build() because it already exist you just need to copy
    }

    object(int p/*roperty*/){
      this->property = p;

      this->build();
    }

    object(){
      this->property = 0;

      this->build();
    }

    //if there's no property, you don't need get and set!!!
    //GETS
    int getFroperty(){ return this->property;}

    //SETS
    void setFroperty(int p) { this->property = p;}

    //METHODS
    //build the shape of the object
    void build (){
      //you mostly have to write your code here!
      //creo quattro punti per la spezzata chiusa dell'astronave
      this->setPointCount(4);

      this->setPoint(0, sf::Vector2f(0.f, 0.f));
      this->setPoint(1, sf::Vector2f(0.f, 20.f));
      this->setPoint(2, sf::Vector2f(20.f, 20.f));
      this->setPoint(3, sf::Vector2f(20.f, 0.f));

      //creo il contorno della navicella colorata
      this->setOutlineThickness(2.f);
      this->setOutlineColor(sf::Color(000, 255, 000));
      this->setOrigin(10.f, 10.f);
      this->setPosition(80.f, 70.f);
      this->rotate(90);
    }
};
