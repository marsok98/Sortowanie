#pragma once
#include <iostream>
#include <cmath>
#include <iomanip>
#include <time.h>
#include <chrono>
#include <fstream>
#include "Vector.hh"
#include "Matrix.hh"


/*!
 * \brief Funkcja wykonujaca algorytm sortowania introspektywnego 
 * 
 * Glebokosc rekurencji jest liczona na zewnatrz i od niej zalezy skutecznosc algorytmu
 * Poczatkowo wywolujemy algorytm sortowania szybkiego, lecz po przekroczeniu progu,
 * zostaje wywolany algorytm sortowania przez kopcowanie
 * 
 * \param[in] Vec Obiekt klasy Vector ktory zostanie posortowany
 * \param[in] Length Skrajny prawy indeks tablicy do posortowania, przy pierwszym wywolaniu jest rowny dlugosci wektora
 * \param[in] DepthOfRecursive glebokosc rekurencji do ktorej algorytm wykonuje sortowanie szybkie
 */
template<class Type>
void IntroSort (Vector<Type> &Vec, int Length, int DepthOfRecursive)
{
  if(DepthOfRecursive>0)
  {
    DepthOfRecursive--;
    QuickSort(Vec,0,Length);
  }
  else
  {
    HeapSort(Vec,Length);
    return;
  }
  
}

/*!
 * \brief Funkcja egzekwujaca wykonanie algorytmu IntroSort
 * 
 * Do funkcji jest przekazywany obiekt klasy Matrix
 * Pobieramy z niego wymiar macierzy jak i wektora
 * Liczymy glebokosc rekurencji
 * Odliczamy czas
 * Zapisujemy
 * Wywolujemy funkcje pokazujaca statystyki na std:cout
 * \param[in] Mat - Referencja do Macierzy ktora ma zostac posortowana
 */
template<class Type>
void ExecutionIntroSort(Matrix<Type> &Mat)
{
    chrono::steady_clock Clock;
    int DimMatrix = Mat.GetX_Dime();
    int DimVector = Mat[0].GetY_Dime();         
    int i;
    int Depth = (int)floor(2*log(DimVector)/M_LN2);
    auto Start = Clock.now(); 
    for(i=0;i<DimMatrix;i++)
    {
        IntroSort(Mat[i],DimVector,Depth);
    }
    auto End = Clock.now();
    auto Time_delay = static_cast<chrono::duration<double>>(End - Start);
    ShowStatistic(IntroType,Mat,Time_delay);


}