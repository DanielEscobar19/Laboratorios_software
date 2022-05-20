/* 
 * File:   main.cpp
 * Author: calderon
 *
 * Created on 1 de junio de 2012, 06:01 PM
 */

#include <cstdlib>
#include "EnchantedMazeFactory.h"
#include "BombedMazeFactory.h"
#include "MazeGame.h"

// #include "ConstructorSerializadorAbstracto.h"
#include "Maze.h"

#include <iostream>
using namespace std;

// string director(ConstructorSerializadorAbstracto& constructorAbstracto, Maze& maze);

/*
 * 
 */
int main(int argc, char** argv) {
    EnchantedMazeFactory enchantedFactory;
    BombedMazeFactory BombedFactory;
    MazeGame mazeGame1;
    MazeGame mazeGame2;
    /* pedir al usuario el tipo de laberinto */

    int opcionDeUsuario = 0;
    cout << "\nSeleccione el tipo de laberinto" << endl;
    cout << "1. Laberinto encantado" << endl;
    cout << "2. Laberinto con bombas" << endl;
    cout << " > ";
    cin >> opcionDeUsuario;

    while(true) {
        if (opcionDeUsuario >= 1 && opcionDeUsuario <= 2) {
            if (opcionDeUsuario == 1) {
                cout << "--------------------------------------" << endl;
                // si el usuario escoge laberinto encantado
                mazeGame1.createMaze(&enchantedFactory);  // 7 rooms. Cada room con 2 puertas.
                cout << mazeGame1.toString() << endl;
            }
            else {
                cout << "--------------------------------------" << endl;
                // si el usuario escoge laberinto con bombas
                mazeGame2.createMaze(&BombedFactory);  // 7 rooms. Cada room con 2 puertas.
                cout << mazeGame2.toString() << endl;
            }
            break;
        }
        else {
            cout << "Ingrese 1 o 2\n > ";
            cin >> opcionDeUsuario;
        }
    }
    return 0;
}

// string director(ConstructorSerializadorAbstracto& constructorAbstracto, Maze& maze) {
//     return "";
// }