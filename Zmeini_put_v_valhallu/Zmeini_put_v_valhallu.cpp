
#include <iostream>
#include <conio.h> 

using namespace std;

class Snake {
public:
    int x;
    int y;
    int xx = 3;
    int yy = 5;
    int tailLength = 0; 
};
class Food {
public:
    int x;
    int y;
};
void generateFood(Food& food, Snake& snake, const int width, const int height) {
    food.x = rand() % width;
    food.y = rand() % height;

    
    while (food.x == snake.x && food.y == snake.y) {
        food.x = rand() % width;
        food.y = rand() % height;
    }
}



int main()
{
    Food food;
    
    
    
    Snake snake;
    snake.x = 0;
    snake.y = 0 ;

    setlocale(LC_ALL, "Russian");
    const int width = 20;
    const int height = 20;
    char pole[width][height];

    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            pole[i][j] = '.';
        }
    }
    generateFood(food, snake, width, height);

    while (true) {
        system("cls");
        pole[food.y][food.x] = '@';
        
        

        
      

       

        

        
        int tailX[100] = {snake.x - 1}; 
        int tailY[100] = {snake.y};
        pole[snake.y][snake.x ] = 'X';
        for (int i=0; i < snake.tailLength; i++) {
            pole[tailY[i]][tailX[i]] = 'O';
        }

        
        
        
        

      
        
        for (int i = 0; i < width; i++) {
            for (int j = 0; j < height; j++) {
                cout << pole[i][j] << " ";

                
            }
            cout << endl;
        }

       
        char key = _getch();

        
        switch (key) {
        case '8': 
            snake.y--;
            pole[snake.y + 1][snake.x] = '.';
            break;
        case '4': 
            snake.x = snake.x--;
            pole[snake.y][snake.x + 1] = '.';
            break;
        case '6': 
            snake.x++;
            pole[snake.y][snake.x - 1] = '.';
            
            break;
        case '2': 
            snake.y = snake.y++;
            pole[snake.y - 1 ][snake.x] = '.';
            break;
        }
        if (snake.x == food.x && snake.y == food.y) {
            generateFood(food, snake, width, height);
            snake.tailLength++;
           
            

            
        }
  
        if (snake.x < 0 || snake.x >= width || snake.y < 0 || snake.y >= height) {
            cout << "Вы проиграли!" << endl;
            return 0;
        }
        
        for (int i = 0; i < snake.tailLength; i++) {
            if (snake.x == tailX[i] && snake.y == tailY[i]) {
                cout << "Вы проиграли!" << endl;
                return 0;
            }
        }
    }

        
        
    
}

    

    


