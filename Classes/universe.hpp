//UNIVERSE
//Class that handle everything that concerne the top of the window

/*

*/
#define PI 3.14159265

class universe{
  private:
    //sf::Texture texture;
    //sf::Sprite background;
    spaceship
    sf::RenderWindow *window;
    sf::FloatRect *boundingBox;
    sf::RectangleShape bound;       //FOR TESTING ONLY
    sf::Vector2f *position;
    sf::Vector2f *size;

  public:
    //CONSTRUCTORS
    universe(sf::RenderWindow* win){
      window = win;

      // Setting bounding box
      size = new sf::Vector2f(win->getSize().x, win->getSize().y * 9/10);
      position = new sf::Vector2f(0, win->getSize().y/10);
      boundingBox = new sf::FloatRect(*position, *size);
      bound.setPosition(*position);
      bound.setSize(*size);
      bound.setFillColor(sf::Color(0, 0, 255));

      /*
      //texture.create((unsigned int)size->x, (unsigned int)size->y);
      if(!texture.loadFromFile("img/universe.png"))
        std::cout << "Error in load images" << std::endl;
      else
        std::cout << "PERFECT!" << std::endl;

      background.setTexture(texture);
      //background.setTextureRect(sf::IntRect(300, 300, 500, 300));
      background.setColor(sf::Color::Blue);
      background.setPosition(*position);
      //background.scale(200, 200);
      //sprite.setSize(0, 0);
      */
    }

    //GETS
    //sf::Texture getTexture(){ return this->background.getTexture();}
    //sf::Sprite getBackground(){ return this->background;}

    //SETS
    //void setTexture(sf::Texture t){ this->background.setTexture(t);}
    //void setBackground(sf::Sprite b){ this->background = b;}

    //---------------METHODS---------------

    //DRAW
    void Draw (/*sf::RenderWindow* window*/){
      std::cout << "Draw of Universe" << std::endl;
      window->draw(bound);
      //window->draw(background);
      std::cout << "END draw universe" << std::endl;
    }
};
