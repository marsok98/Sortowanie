#pragma once
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <time.h>
#include <fstream>
using namespace std;


/*!
 * \brief  Klasa modeluje pojecie tablicy jednowymiarowej - wektora
 *
 *  Szablon Vector to szablon przedstawiający tablice dowolnego typu
 * W klasie Vector przechowywane są funkcje  metody klasy
 */
template<class Type>
class Vector
{
  /*!
   * \brief Pole opisujace wskaznik na dowolny typ z szablonu
   * 
   */
  Type *Column;
  /*!
    * \brief Pole opisujące rozmiar tablicy (ilosc elementow)
    * 
   */
  int Y_Dime;
  /*!
    * \brief Pole opisujace wskaznik na aktualny element
    */
  Type *CurrentElement = NULL;

public:
    /*!
     * \brief Przeciazenie operatora [] (modyfikacja wartosci)
     *
     * Funkcja przeciążająca operator [], zwraca aktualny element,
     * wywolana z argumentem typu int. Mozna zmieniac wartosci
     */
  Type &operator [] (int i)      {return CurrentElement[i];}
    /*!
     * \brief Przeciazenie operatora [] (brak modyfikacja wartosci)
     *
     * Funkcja przeciążająca operator [], zwraca aktualny element
     * wywolana z argumentem typu int. Nie ozna zmieniac wartosci
     */
  Type operator [] (int i)const {return CurrentElement[i];}
  /*!
    * \brief Funkcja zwracająca wskaźnik do aktualnego elementu
    * 
    */
  Type* ReturnWsk(){return CurrentElement;}
  /*!
    * \brief Funkcja przesuwajaca wskaznik na aktualny element
    * 
    */
  void AddWsk(int value){CurrentElement+=value;}
  /*!
    * \brief Funkcja zwracająca wymiar tablicy
    * 
    */
  int GetY_Dime(){return Y_Dime;}
  /*!
    * \brief Konstruktor bez parametryczny
    * 
    * Wpisuje zera
    * 
    */
  Vector()
  {
    Column = NULL;
    this->Y_Dime = 0;
  }
  /*!
    * \brief Konstruktor parametryczny  
    * 
    */
  Vector(int Y_Dime)
  {
    Column = new Type[Y_Dime];
    this->Y_Dime = Y_Dime;
  }
  /*!
    * \brief Dekostruktor
    * 
    * Usuwa z pamieci wskazniki Column
    */
  ~Vector()
  {
    delete [] Column;
  }
  /*!
    * \brief Konstruktor kopiujacy
    * 
    * Zdefiniowany w celu sprawniejszego kopiowania
    */
  Vector(const Vector &Wek)
  {
    for (int i = 0; i < Y_Dime; i++) 
    {
        Column[i] = Wek[i];
    }
  }
  /*!
    * \brief Funkcja ktora inicjuje wskazniki i tworzy tablice
    * 
    * Utworzona w celu latwiejszego tworzenia obiektow klasy Vector w klasach nadrzędnych
    */
  void CreateColumn(int Y_Dime)
  {
    this->Y_Dime = Y_Dime;
    Column = new Type[Y_Dime];
    CurrentElement = Column;
  }
  /*!
    * \brief Funkcja ktora wypelnia tablice losowymi wartosciami
    * 
    * 
    */
  void RandomTables()
  {
    int i;
    for(i=0;i<Y_Dime;i++)
    {
      Column[i]= rand()%(Y_Dime+i);
    }
  }
  /*!
    * \brief Funkcja wypelniajaca tablice w uporzadkowany sposob 
    * 
    * Wypelnia tablice uporzadkowanymi elementami w Percent %
    * Reszta jest wypelniana wartosciami losowymi
    */
  void PercentSortTables(double Percent)
  {

    int NumberElemSort = static_cast<int>(0.01*Percent * (double)Y_Dime);
    int i;
    for(i=0;i<Y_Dime;i++)
    {
      if(i<NumberElemSort)
      {
        Column[i] = i;
      }
      else
      {
        Column[i] = rand()%(Y_Dime+i);
      }

    }
  }
  /*!
    * \brief Funkcja wyswietlajaca na std::cout wszystkie elemenenty tej tablicy
    */
  void ToScreen()
  {
    int i;
    for(i=0;i<Y_Dime;i++)
    {
      cout<<Column[i]<<" ";
    }
    cout<<endl;
  }
  /*!
   * \brief Funkcja uzupelniajaca tablice odwrotnie, posortowane malejaco
   * 
   */
  void InvertSort()
  {
    int i;
    for(i=0;i<Y_Dime;i++)
    {
      Column[i]= Y_Dime - i;
    }
  }
   /*!
   * \brief Funkcja sprawdzajaca czy tablica zostala posortowana prawidlowo 
   */
  bool CheckCorrect()
  {
    int Counter = 0;
    int i;
    for(i=0;i<Y_Dime-1;i++)
    {
        if(Column[i]<=Column[i+1]){++Counter;}
    }
    if(Counter == Y_Dime-1)
    {
        return true;
    }
    else
    {
        cout<<"Blad na  "<<Counter<<endl;
        return false;
    }
  }
};