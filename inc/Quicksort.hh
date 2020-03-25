#pragma once
#include <iostream>
#include <cmath>
#include <iomanip>
#include <time.h>
#include <fstream>
#include <chrono>
#include "Vector.hh"
#include "Matrix.hh"

/*!
 * \brief Funkcja realizuje sortowanie obiektow Vector sposobem QuickSort
 * 
 * Funkcja dziala rekurencyjnie w celu podzialu na coraz mniejsze tablice
 * \param[in] Vec Obiekt klasy Vector ktory zostanie posortowany
 * \param[in] i_Left Skrajny lewy indeks tablicy do posortowania, przy pierwszym wywolaniu jest to 0
 * \param[in] i_Right Skrajny prawy indeks tablicy, poczatkowo jest to rozmiar Vectora
 */

template<class Type>
void QuickSort(Vector<Type> &Vec, int i_Left, int i_Right)
{
    int i = i_Left; //przypisanie granic tablic do nowych zmiennych
    int j = i_Right;
    int PositionPivot = (i + j) / 2; //najoptymalniejsze rozmieszczenie pivota
    int Pivot = Vec[PositionPivot]; //zadeklarowanie zmiennej Pivot z ktora poszczegolne komorki beda porownywane
    int Temp;                       //zmienna pomocnicza

    while (i <= j)
    {
        while (Vec[i] < Pivot)      //Przesun w prawo granice lewa
        {
            i++;
        }
        while (Vec[j] > Pivot) //Przesun w lewo granice prawa
        {
            j--;
        } 
        if (i <= j)               //Jesli granice sa poprawne
        {
            Temp = Vec[i];
            Vec[i] = Vec[j];
            Vec[j] = Temp;
            i++;
            j--;
        }
    }
    if (j > i_Left){QuickSort(Vec, i_Left, j);}  //jesli prawa aktualna granica jest nadal wieksza od lewej oryginalnej to wywolaj
    if (i < i_Right){QuickSort(Vec, i, i_Right);} //analogicznie
}
/*!
 * \brief Funkcja egzekwujaca wykonanie algorytmu QuickSort
 * 
 * Do funkcji jest przekazywany obiekt klasy Matrix
 * Pobieramy z niego wymiar macierzy jak i wektora
 * Odliczamy czas
 * Zapisujemy
 * Wywolujemy funkcje pokazujaca statystyki na std:cout
 * \param[in] Mat - Referencja do Macierzy ktora ma zostac posortowana
 */
template<class Type>
void ExecutionQuickSort(Matrix<Type> &Mat)
{
    chrono::steady_clock Clock;
    int DimMatrix = Mat.GetX_Dime();
    int DimVector = Mat[0].GetY_Dime();          //Zakladamy ze rozmiar jest taki sam
    int i;
    auto Start = Clock.now(); 
    for(i=0;i<DimMatrix;i++)
    {
        QuickSort(Mat[i],0,DimVector); //wywolujemy dla wszystkich komorek macierzy
    }
    auto End = Clock.now();
    auto Time_delay = static_cast<chrono::duration<double>>(End - Start);
    ShowStatistic(QuickType,Mat,Time_delay);   //wyswietlamy statystyke
}



