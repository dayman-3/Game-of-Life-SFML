#include <SFML/Graphics.hpp>

#define CELL_SIZE 5
#define WIDTH 1200
#define HEIGHT 1000
#define A_WIDTH WIDTH / CELL_SIZE
#define A_HEIGHT HEIGHT / CELL_SIZE

class Game
{
    private:
        bool** array;
        bool** next;

        sf::Image image;
        sf::Texture texture;
        sf::Sprite board;

    public:

        Game(sf::RenderWindow& window);
        Game(sf::RenderWindow& window, bool** inputArray);
        ~Game();

        void randomState();
        void randomArray();
        int count_cells(int x, int y);
        void nextState();
        void imageFromArray();
        void update(sf::RenderWindow& window);
};