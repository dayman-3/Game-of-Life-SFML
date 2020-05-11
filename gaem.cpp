#include "gaem.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

/**
 * Creates a game in a specified SFML window
 **/ 
Game::Game(sf::RenderWindow& window) {
    array = new bool*[A_HEIGHT];
    for (int i = 0; i < A_HEIGHT; i++) {
        *(array + i) = new bool[A_WIDTH];
    }
    next = new bool*[A_HEIGHT];
    for (int i = 0; i < A_HEIGHT; i++) {
        *(next + i) = new bool[A_WIDTH];
    }

    image.create(WIDTH, HEIGHT);
    texture.loadFromImage(image);
    board.setTexture(texture);
    window.draw(board);
}

/**
 * Deletes the state of the board from the heap
 **/ 
Game::~Game() {
    for (int i = 0; i < A_HEIGHT; i++) {
        delete[] array[i];
    }
    delete[] array;

    for (int i = 0; i < A_HEIGHT; i++) {
        delete[] next[i];
    }
    delete[] next;
}

/**
 *  Set image to random state
 **/
void Game::randomState() {
    randomArray();
    imageFromArray();
}

/**
 * Set array to random state
 **/
void Game::randomArray() {
    srand(time(0));
    for (int x = 0; x < A_WIDTH; x++) {
        for (int y = 0; y < A_HEIGHT; y++) {
            array[y][x] = rand()%2 == 0;
        } 
    }
}

/**
 * Update the image to whatever the array is set to
 **/
void Game::imageFromArray() {
    for (int x = 0; x < WIDTH; x+=CELL_SIZE)
    {
        for (int y = 0; y < HEIGHT; y+=CELL_SIZE)
        {
            int array_x = x / CELL_SIZE;
            int array_y = y / CELL_SIZE;
            sf::Color cell = array[array_y][array_x] ? sf::Color::Black : sf::Color::White;
            for (int yi = 0; yi < CELL_SIZE; yi++)
            {
                for (int xi = 0; xi < CELL_SIZE; xi++)
                {
                    image.setPixel(x+xi, y+yi, cell);
                }   
            }
        }        
    }    
} 

/**
 *  Update the image to the next state
 **/
void Game::nextState() {
    for (int y = 0; y < A_HEIGHT; y++) {
        for (int x = 0; x < A_WIDTH; x++) {
            int count = count_cells(x, y);
            if (array[y][x]) {
                next[y][x] = count == 2 || count == 3;
            } else {
                next[y][x] = count == 3;
            }
        }
    }
    for (int y = 0; y < A_HEIGHT; y++) {
        for (int x = 0; x < A_WIDTH; x++) {
            array[y][x] = next[y][x];
        }
    }
    for (int y = 0; y < HEIGHT; y+=CELL_SIZE) {
        for (int x = 0; x < WIDTH; x+=CELL_SIZE) {
            int array_x = x / CELL_SIZE;
            int array_y = y / CELL_SIZE;
            sf::Color colour = array[array_y][array_x] ? sf::Color::Black : sf::Color::White;
            for (int yi = 0; yi < CELL_SIZE; yi++) {
                for (int xi = 0; xi < CELL_SIZE; xi++) {
                    image.setPixel(x+xi, y+yi, colour);
                }
            }
        }
    }
}

/**
 * Count how many live cells are around a point on the board
 **/
int Game::count_cells(int x, int y) {
    int count = 0;\
    if (x > 0 && x < A_WIDTH-1 && y > 0 && y < A_HEIGHT-1) {
        if (array[y-1][x-1]) count++;
        if (array[y-1][x]) count++;
        if (array[y-1][x+1]) count++;
        if (array[y][x+1]) count++;
        if (array[y+1][x+1]) count++;
        if (array[y+1][x]) count++;
        if (array[y+1][x-1]) count++;
        if (array[y][x-1]) count++;
    }
    return count;
}

/**
 * Draw image to window
 **/
void Game::update(sf::RenderWindow& window) {
    texture.loadFromImage(image);
    board.setTexture(texture);
    window.draw(board);
}