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

#include "ConstructorSerializadorAbstracto.h"
#include "Maze.h"

#include <iostream>
using namespace std;

string director(ConstructorSerializadorAbstracto& constructorAbstracto, Maze& maze);

/*
 * 
 */
int main(int argc, char** argv) {
    EnchantedMazeFactory emf;
    BombedMazeFactory bf;
    MazeGame mg1;
    MazeGame mg2;
    /* pedir al usuario el tipo de laberinto */

    // si el usuario escoge laberinto encantado
    mg1.createMaze(&emf);
    cout << mg1.toString() << endl;
    
    // si el usuario escoge laberinto con bombas
    mg2.createMaze(&bf);
    cout << mg2.toString() << endl;

    return 0;
}

