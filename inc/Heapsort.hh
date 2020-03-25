#pragma once
#include <iostream>
#include <cmath>
#include <iomanip>
#include <time.h>
#include <fstream>
#include "Vector.hh"



/*!
 * \brief Funkcja ktora  modyfikuje kopiec, wywolywana przez funkcje sortujaca
 * 
 * \param[in] Vec Obiekt klasy Vector ktory zostanie zbadany w celu zrobienia kopca
 * \param[in] Length dlugosc do ktorej ma byc wykonywana operacja
 * \param[in] PreviousRoot - indeks korzenia ktory byl poprzednio
 */
template<class Type>
void ConvertHeap(Vector<Type> &Vec, int Length, int PreviousRoot)
{
    int CurrentRoot = PreviousRoot;          //dopisanie do aktualnego korzenia
    int i_Left = 2 * PreviousRoot + 1;       //lewy indeks
    int i_Right = 2 * PreviousRoot + 2;     //prawy indeks

    if (i_Left < Length && Vec[i_Left] > Vec[CurrentRoot])   //wyznaczenie nowego indeksu korzenia
        CurrentRoot = i_Left;

    if (i_Right < Length && Vec[i_Right] > Vec[CurrentRoot]) // analogicznie
        CurrentRoot = i_Right;

    if (CurrentRoot != PreviousRoot)            //jesli one nie sa takie same, 
    {
        swap(Vec[PreviousRoot], Vec[CurrentRoot]); //to zamien

        ConvertHeap(Vec, Length, CurrentRoot);    //kontynujemy az beda takie same, przez rekurencje
    }
}
/*!
 * \brief Funkcja wykonujaca algorytm sortowania przez kopcowanie
 * 
 * \param[in] Vec Obiekt klasy Vector ktory zostanie scalony
 * \param[in] Length dlugosc do ktorej ma byc wykonywana operacja, poczatkowo rozmiar obiektu klasy Vector
 */
template<class Type>
void HeapSort(Vector<Type> &Vec, int Length)
{
    for (int i = Length / 2 - 1; i >= 0; i--)
        ConvertHeap(Vec, Length, i);

    for (int i = Length - 1; i >= 0; i--)
    {
        swap(Vec[0], Vec[i]);
        ConvertHeap(Vec, i, 0);
    }
}