#include <iostream>
#include <conio.h>
#include <afxres.h>

using namespace std;

enum Direction { STOP , LEFT , RIGHT , UP , DOWN } ;
Direction dir = STOP ;
bool GameOver ;
const int height = 20 ;
const int width = 40 ;
int score ;
int length = 1 ;
int snake [ height * width ] [ 2 ] =  { width / 2 , height / 2 } ;
pair < int , int > fruit ( rand() % width , rand() % height ) ;

void update_snake(){
    for( int i = length ; i > 0 ; --i ){
        snake[i][0] = snake[i-1][0] ;
        snake[i][1] = snake[i-1][1] ;
    }
}

void newFruit(){
    fruit.first = rand() % width ;
    if( fruit.first == 0 )
        fruit.first ++ ;
    fruit.second = rand() % height ;
    if( fruit.second == 0 )
        fruit.second ++ ;
    score += 10 ;
    if( length < ( height * width ) / 2 )
        ++length ;
}

void draw(){
    system("cls");
    for( int i = 0 ; i < height + 2 ; ++i ){
        for( int j = 0 ; j < width + 2 ; ++j ){
            if( j == 0 || j == width + 1 || i == 0 || i == height + 1 )
                cout << '#' ;
            else if( j == snake[0][0] && i == snake[0][1] )
                cout << 'O' ;
            else if( j == fruit.first && i == fruit.second )
                cout << 'X' ;
            else{
                bool print = false ;
                for( int k = 1 ; k < length ; ++k )
                    if( i == snake[k][1] && j == snake[k][0] ){
                        cout << 'o' ;
                        print = true ;
                    }
                if( print == false )
                    cout << ' ' ;
            }
        }
        cout << endl ;
    }
    cout << endl << "Score  :  " << score << endl ;
}

void input(){
    if( _kbhit() ){
        switch ( _getch() ){
            case 'A' :
            case 'a' :
                if( dir == RIGHT )
                    break ;
                dir = LEFT ;
                break ;
            case 'D' :
            case 'd' :
                if( dir == LEFT )
                    break ;
                dir = RIGHT ;
                break ;
            case 'W' :
            case 'w' :
                if( dir == DOWN )
                    break ;
                dir = UP ;
                break ;
            case 'S' :
            case 's' :
                if( dir == UP )
                    break ;
                dir = DOWN ;
                break ;
            case 'X' :
            case 'x' :
                GameOver = true ;
                break ;
            default:
                break ;
        }
    }
}

void logic(){
    update_snake();
    switch ( dir ){
        case LEFT :
            --snake[0][0] ;
            break ;
        case RIGHT :
            ++snake[0][0] ;
            break ;
        case UP :
            --snake[0][1] ;
            break ;
        case DOWN :
            ++snake[0][1] ;
            break ;
    }
    if( snake[0][0] == 0 || snake[0][0] == width + 1 || snake[0][1] == 0 || snake[0][1] == height + 1 )
        GameOver = true ;
    for( int a = 1 ; a < length ; ++a )
        if( snake[a][0] == snake[0][0] && snake[a][1] == snake[0][1] )
            GameOver = true ;
    if( snake[0][0] == fruit.first && snake[0][1] == fruit.second )
        newFruit() ;

}

void Over(){
    for( int i = 0 ; i < height +2 ; ++ i ) {
        for (int j = 0 ; j < width + 2 ; ++j)
            if (i == 0 || i == height + 1)
                if (j == 0 || j == width + 1)
                    cout << '#' ;
                else
                    cout << '-' ;
            else if ( j == 0 || j == width + 1 )
                cout << '|' ;
            else if (i == height / 2 && j == ((width / 2) - 4)) {
                cout << "GAME OVER" ;
                j += 8 ;
            } else
                cout << ' ' ;
        cout << endl ;
    }
}

void run(){
    while( GameOver == false ){
        draw() ;
        Sleep( ( 10 >(50 - length) ? 10 : ( 50 - length ) ) );
        input() ;
        logic() ;
    }
    Over() ;
    _getch() ;
}

int main() {
    run() ;
    return 0 ;
}