
#include "header.hpp"


void Display::display(){
    window.clear(sf::Color::White);

    //ひとつ前の状態
    for(int i = 0; i < ROW; ++i){
        for(int j = 0; j < COL; ++j){
            if(field[i][j] == 1){
                sf::RectangleShape cell(sf::Vector2f(BLOCK_SIZE, BLOCK_SIZE));
                cell.setPosition(j * BLOCK_SIZE, i * BLOCK_SIZE);
                sf::Color Color = ColorList[field_color[i][j]];
                if(i == ROW - 1 || j == 0 || j == COL - 1){
                    cell.setFillColor(Color);
                }else{
                    cell.setFillColor(Color);
                }
                window.draw(cell);
            }
        }
    }
}

void Display::draw_grid(){
    sf::Color grid_color = sf::Color::Black;
    for(int i = 0; i < WINDOW_WIDTH; i +=BLOCK_SIZE){
        sf::Vertex line[] = {
            sf::Vertex(sf::Vector2f(i, BLOCK_SIZE), grid_color),
            sf::Vertex(sf::Vector2f(i, WINDOW_HEIGHT - BLOCK_SIZE), grid_color)
        };
        window.draw(line, 4, sf::Lines);
    }

    for(int j = 0; j < WINDOW_HEIGHT; j +=BLOCK_SIZE){
        sf::Vertex line[] = {
            sf::Vertex(sf::Vector2f(BLOCK_SIZE, j), grid_color),
            sf::Vertex(sf::Vector2f(WINDOW_WIDTH - BLOCK_SIZE, j), grid_color)
        };
        window.draw(line, 4, sf::Lines);
    }
}