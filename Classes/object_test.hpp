//OBJECT
//A prototype of a class

class object : public sf::ConvexShape{
  //if there are field you must set and get them!!!
  private:
    int field;

  public:
    //CONSTRUCTORS
    object(sf::ConvexShape* s, int f/*ield*/) : sf::ConvexShape(*s){
      this->field = f;

      //you don't need this->build() because it already exist you just need to copy
    }

    object(sf::ConvexShape* s) : sf::ConvexShape(*s){
      this->field = 0;

      //you don't need this->build() because it already exist you just need to copy
    }

    object(int f/*ield*/){
      this->field = f;

      this->build();
    }

    object(){
      this->field = 0;

      this->build();
    }

    //if there's no field, you don't need get and set!!!
    //GETS
    int getField(){ return this->field;}

    //SETS
    void setField(int f) { this->field = f;}

    //METHODS
    //build the shape of the object
    void build (){
      //you mostly have to write your code here!
    }
};
