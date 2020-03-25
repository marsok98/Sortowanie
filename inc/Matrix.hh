#pragma once
#include <chrono>
#include "Vector.hh"

/*!
 * \brief Typ wyliczeniowy ktory opisuje tryb wypelniania obiektow klasy Matrix
 * 
 * Hazard - losowe elementy
 * Sort - Posortowane
 * AntySort - posortowane w odwrotnej kolejności
 */
enum Action
{
    Hazard,
    Sort,
    AntySort
};
/*!
 * \brief Typ wyliczeniowy ktory opisuje trzy zaimplementowane sortowania
 * 
 * Podawane do funcji jestesmy w stanie rozroznic
 * Odpowiedni napis moze byc wyswietlony
 */
enum TypeOfSort
{
    QuickType,
    MergeType,
    IntroType,
};
/*!
 * \brief Klasa opisujaca pojecie Macierzy
 * 
 * Klasa Matrix jest zlozona z tablic klasy Vector
 * Zdefiniowane sa tutaj metody, zdefiniowane operatory
 */
template<class Type>
class Matrix
{
    /*!
     * \brief Tablica do wskaznikow typu Vector
     */
    Vector<Type> *Row;
    /*!
    * \brief Pole opisujące rozmiar tablicy (ilosc elementow)
    * 
    */
    int X_Dime;
    /*!
    * \brief Pole procent wypelnienia tablicy elementami posortowanymi
    * 
    */
    double PercentOfSort;
    /*!
    * \brief Pole przechowujace jaki tryb wypelniania
    * 
    */
    Action Act;

    public:
    /*!
     * \brief Przeciazenie operatora [] (bez modyfikacji wartosci)
     *
     * Funkcja przeciążająca operator [], zwraca obiekt klasy Vector
     * wywolana z argumentem typu int. Nie mozna zmieniac wartosci
     */
    Vector<Type> operator [] (int i) const {return Row[i];}
    /*!
     * \brief Przeciazenie operatora [] (modyfikacja wartosci)
     *
     * Funkcja przeciążająca operator [], zwraca aktualny element,
     * wywolana z argumentem typu int. Mozna zmieniac wartosci
     */
    Vector<Type> &operator [] (int i) {return Row[i];}
    /*!
    * \brief Funkcja zwracająca wymiar tablicy obiektow klasy Vector
    */
    int GetX_Dime(){return X_Dime;}
    /*!
    * \brief Funkcja zwracająca procent wypelnienia elementami posortowanymi
    */
    double GetPercentOfSort(){return PercentOfSort;}
    /*!
    * \brief Funkcja zwracaja sposob wypelnienia tablicy
    */
    Action GetAct(){return Act;}
    /*!
    * \brief Funkcja wyswietlajaca na std::cout wszystkie elemenenty tej tablicy
    */
    void ToScreen()
    {
        int i;
        for(i=0;i<X_Dime;i++)
        {
            cout<<i<<"wiersz  ";
            Row[i].ToScreen();
            cout<<endl;
        }
    }
    /*!
    * \brief Dekostruktor
    * 
    * Usuwa z pamieci wskazniki Row
    */
    ~Matrix()
    {
        int i;
        for(i=0;i<X_Dime;i++)
        {
            Row[i].~Vector();
        }
    }
   /*!
    * \brief Konstruktor parametryczny
    *
    * Konstruktor tworzacy obiekt klasy Matrix
    * \param[in] X_Dime - ile obiektow klasy Vector
    * \param[in] Y_Dime - ile kazdy obiekt klasy Vector ma liczyc pol
    * \param[in] What Pole opisujace jaki tryb wypelniania tablic
    * \param[in] PercentOfSort - w ilu procentach wypelniona tablica
    */
    Matrix(int X_Dime,int Y_Dime,Action What, double PercentOfSort)
    {
        this->X_Dime = X_Dime;
        Row = new Vector<Type>[X_Dime];
        this->Act = What;
        this->PercentOfSort = PercentOfSort;
        int i;
        switch (What)
        {
            case Hazard:

                for(i=0;i<X_Dime;i++)
                {
                    Row[i].CreateColumn(Y_Dime);
                    Row[i].RandomTables();
                }
            break;

            case Sort:

                for(i=0;i<X_Dime;i++)
                {
                    Row[i].CreateColumn(Y_Dime);
                    Row[i].PercentSortTables(PercentOfSort);
                }
            break;

            case AntySort:

                for(i=0;i<X_Dime;i++)
                {
                    Row[i].CreateColumn(Y_Dime);
                    Row[i].InvertSort();
                }
            break;
            default:
            break;
        }  
    }

};




/*!
 * \brief Funkcja pokazujaca czas wykonywanych algorytmow
 * 
 * Funkcja wyswietla na standardowym wyjsciu dane o szybkosci algorytmow
 * Formatowanie jest przeznaczone do plikow z roszerzeniem .csv
 * Tak aby zaimportowane dane do Excela mozna bylo latwo obrabiać.
 * \param[in] Type - Typ sortowania jaki zostal uzyty
 * \param[in] Mat - Referencja do Macierzy ktora zostala posortowana
 * \param[in] Time_delay - Czas ktore zajelo dane sortowanie
 */
template<class TypeOfVector>
void ShowStatistic(TypeOfSort Type,Matrix<TypeOfVector> &Mat,std::chrono::duration<double> &Time_delay)
{
    int DimMatrix = Mat.GetX_Dime();
    int DimVector = Mat[0].GetY_Dime();
    switch (Type)
    {
        case QuickType:
            cout<<"QuickSort ";
            break;
        case MergeType:
            cout<<"MergeSort ";
            break;
        case IntroType:
            cout<<"IntroSort: ";
            break;
        default:
        break;
    }
    switch (Mat.GetAct())
    {

        case Hazard:
            cout<<DimMatrix<<"x"<<DimVector<<" Nieposortowana Czas: "<<Time_delay.count()<<endl;
            break;

        case Sort:
            cout<<DimMatrix<<"x"<<DimVector<<" Posortowana w "<<Mat.GetPercentOfSort()<<"% Czas: "<<Time_delay.count()<<endl;
            break;

        case AntySort:
            cout<<DimMatrix<<"x"<<DimVector<<" Posortowana odwrotnie, Czas: "<<Time_delay.count()<<endl;
            break;
    
    default:
        break;
    }
}


