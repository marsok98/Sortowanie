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
 * \brief Funkcja scalajaca majaca zastowanie w sortowaniu przez scalanie
 * 
 * Funkcja rozbija na 2 tablice, lewa i prawa a nastepnie scala
 * \param[in] Vec Obiekt klasy Vector ktory zostanie scalony
 * \param[in] i_Left Skrajny lewy indeks lewej tablicy do posortowania, przy pierwszym wywolaniu jest to 0
 * \param[in] i_Right Skrajny prawy indeks drugiej tablicy, poczatkowo jest to rozmiar Vectora
 * \param[in] m Koniec lewej tablicy i poczatek prawej
 */

template<class Type>
void Merge(Vector<Type> &Vec, int i_Left, int m, int i_Right) 
{ 

    int idx;
    int jdx;
    int kdx;
    int Dime1 = m - i_Left + 1; //od prawego indeksu odejmujemy lewy i dodajemy 1
    int Dime2 =  i_Right - m;  //od prawego indeksu prawej tablicy odejmujemy jej lewy
  
    Vector<Type> LeftTempVec;
    Vector<Type> RightTempVec;
    LeftTempVec.CreateColumn(Dime1);  //tworzymy te dwie sub tablice
    RightTempVec.CreateColumn(Dime2);
  
    for (idx = 0; idx < Dime1; idx++)  //przepisujemy dopoki nie dojdziemy do konca lewej tablicy
    {
        LeftTempVec[idx] = Vec[i_Left + idx];
    }
    for (jdx = 0; jdx < Dime2; jdx++) //przepisujemy dopoko nie dojdzieym do konca prawej tablicy
    {
         RightTempVec[jdx] = Vec[m + 1 + jdx]; 
    } 
 
  
    idx = 0;              //ponownie zerujemy indeksy
    jdx = 0;
    kdx = i_Left;
    while (idx < Dime1 && jdx < Dime2)  //dwa warunki spelnione
    { 
        if (LeftTempVec[idx] <= RightTempVec[jdx])  //nastepuej przepisywanie do oryginalnej talibcy
        { 
            Vec[kdx] = LeftTempVec[idx]; 
            idx++; 
        } 
        else
        { 
            Vec[kdx] = RightTempVec[jdx]; 
            jdx++; 
        } 
        kdx++; 
    } 
  
   
    while (idx < Dime1)            //jesli aktualny indeks lewej tablicy jest mniejszy to przepisz tylko lewa tablice
    { 
        Vec[kdx] = LeftTempVec[idx]; 
        idx++; 
        kdx++; 
    } 
  
   
    while (jdx < Dime2)     //jesli aktualny indeks prawej tablicy jest mniejszy to przepisz tylko prawa tablice
    { 
        Vec[kdx] = RightTempVec[jdx]; 
        jdx++; 
        kdx++; 
    } 
} 


/*!
 * \brief Funkcja wykonujaca algorytm sortowania przez scalania
 * 
 * \param[in] Vec Obiekt klasy Vector ktory zostanie scalony
 * \param[in] i_Left Skrajny lewy indeks lewej tablicy do posortowania, przy pierwszym wywolaniu jest to 0
 * \param[in] i_Right Skrajny prawy indeks drugiej tablicy, poczatkowo jest to rozmiar Vectora
 */
template<class Type>
void MergeSort(Vector<Type> &Vec, int i_Left, int i_Right) 
{ 
    if (i_Left < i_Right)   //jesli lewy jest mniejsze od prawego
    { 
        int m = i_Left+(i_Right-i_Left)/2; //wyznaczenie granicy pomiedzy tablicami

        MergeSort(Vec, i_Left, m);  //wywolanie dla lewej polowy tablicy
        MergeSort(Vec, m+1, i_Right); //wywylanie dla prawej polowy tablicy
  
        Merge(Vec, i_Left, m, i_Right);  //scalenie po sortowaniu
    } 
}

/*!
 * \brief Funkcja egzekwujaca wykonanie algorytmu MergeSort
 * 
 * Do funkcji jest przekazywany obiekt klasy Matrix
 * Pobieramy z niego wymiar macierzy jak i wektora
 * Odliczamy czas
 * Zapisujemy
 * Wywolujemy funkcje pokazujaca statystyki na std:cout
 * \param[in] Mat - Referencja do Macierzy ktora ma zostac posortowana
 */
template<class Type>
void ExecutionMergeSort(Matrix<Type> &Mat) //analogicznie do Exucution innnych algorytmow
{
    chrono::steady_clock Clock;
    int DimMatrix = Mat.GetX_Dime();
    int DimVector = Mat[0].GetY_Dime();          
    int i;
    auto Start = Clock.now(); 
    for(i=0;i<DimMatrix;i++)
    {
        MergeSort(Mat[i],0,DimVector);
    }
    auto End = Clock.now();
    auto Time_delay = static_cast<chrono::duration<double>>(End - Start);
    ShowStatistic(MergeType,Mat,Time_delay);
}