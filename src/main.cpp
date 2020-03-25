#include "Vector.hh"
#include "Quicksort.hh"
#include "Matrix.hh"
#include "Mergesort.hh"
#include "Heapsort.hh"
#include "Introsort.hh"
#include <fstream>
#include <chrono>
#include <cmath>
using namespace std;
#define SIZE_OF_VECTOR 1000000
#define SIZE 100
#define PERCENT_OF_SORT 99.7





int main()
{
  Matrix<int> QM1(SIZE,10000,Hazard,1);
  Matrix<int> QM2(SIZE,10000,Sort,25);
  Matrix<int> QM3(SIZE,10000,Sort,50);
  Matrix<int> QM4(SIZE,10000,Sort,75);
  Matrix<int> QM5(SIZE,10000,Sort,95);
  Matrix<int> QM6(SIZE,10000,Sort,99);
  Matrix<int> QM7(SIZE,10000,Sort,99.7);
  Matrix<int> QM8(SIZE,10000,AntySort,99);
  ExecutionQuickSort(QM1);
  ExecutionQuickSort(QM2);
  ExecutionQuickSort(QM3);
  ExecutionQuickSort(QM4);
  ExecutionQuickSort(QM5);
  ExecutionQuickSort(QM6);
  ExecutionQuickSort(QM7);
  ExecutionQuickSort(QM8);
  cout<<endl;


  Matrix<int> MM1(SIZE,10000,Hazard,1);
  Matrix<int> MM2(SIZE,10000,Sort,25);
  Matrix<int> MM3(SIZE,10000,Sort,50);
  Matrix<int> MM4(SIZE,10000,Sort,75);
  Matrix<int> MM5(SIZE,10000,Sort,95);
  Matrix<int> MM6(SIZE,10000,Sort,99);
  Matrix<int> MM7(SIZE,10000,Sort,99.7);
  Matrix<int> MM8(SIZE,10000,AntySort,99);
  ExecutionMergeSort(MM1);
  ExecutionMergeSort(MM2);
  ExecutionMergeSort(MM3);
  ExecutionMergeSort(MM4);
  ExecutionMergeSort(MM5);
  ExecutionMergeSort(MM6);
  ExecutionMergeSort(MM7);
  ExecutionMergeSort(MM8);
  cout<<endl;
  

  Matrix<int> IM1(SIZE,10000,Hazard,1);
  Matrix<int> IM2(SIZE,10000,Sort,25);
  Matrix<int> IM3(SIZE,10000,Sort,50);
  Matrix<int> IM4(SIZE,10000,Sort,75);
  Matrix<int> IM5(SIZE,10000,Sort,95);
  Matrix<int> IM6(SIZE,10000,Sort,99);
  Matrix<int> IM7(SIZE,10000,Sort,99.7);
  Matrix<int> IM8(SIZE,10000,AntySort,99);
  ExecutionIntroSort(IM1);
  ExecutionIntroSort(IM2);
  ExecutionIntroSort(IM3);
  ExecutionIntroSort(IM4);
  ExecutionIntroSort(IM5);
  ExecutionIntroSort(IM6);
  ExecutionIntroSort(IM7);
  ExecutionIntroSort(IM8);
  cout<<endl;
  cout<<endl;


//////////////////////////////////////////////////////////////////////////////////////////////
  Matrix<int> QQM1(SIZE,50000,Hazard,1);
  Matrix<int> QQM2(SIZE,50000,Sort,25);
  Matrix<int> QQM3(SIZE,50000,Sort,50);
  Matrix<int> QQM4(SIZE,50000,Sort,75);
  Matrix<int> QQM5(SIZE,50000,Sort,95);
  Matrix<int> QQM6(SIZE,50000,Sort,99);
  Matrix<int> QQM7(SIZE,50000,Sort,99.7);
  Matrix<int> QQM8(SIZE,50000,AntySort,99);
  ExecutionQuickSort(QQM1);
  ExecutionQuickSort(QQM2);
  ExecutionQuickSort(QQM3);
  ExecutionQuickSort(QQM4);
  ExecutionQuickSort(QQM5);
  ExecutionQuickSort(QQM6);
  ExecutionQuickSort(QQM7);
  ExecutionQuickSort(QQM8);
  cout<<endl;


  Matrix<int> MMM1(SIZE,50000,Hazard,1);
  Matrix<int> MMM2(SIZE,50000,Sort,25);
  Matrix<int> MMM3(SIZE,50000,Sort,50);
  Matrix<int> MMM4(SIZE,50000,Sort,75);
  Matrix<int> MMM5(SIZE,50000,Sort,95);
  Matrix<int> MMM6(SIZE,50000,Sort,99);
  Matrix<int> MMM7(SIZE,50000,Sort,99.7);
  Matrix<int> MMM8(SIZE,50000,AntySort,99);
  ExecutionMergeSort(MMM1);
  ExecutionMergeSort(MMM2);
  ExecutionMergeSort(MMM3);
  ExecutionMergeSort(MMM4);
  ExecutionMergeSort(MMM5);
  ExecutionMergeSort(MMM6);
  ExecutionMergeSort(MMM7);
  ExecutionMergeSort(MMM8);
  cout<<endl;


  Matrix<int> IIM1(SIZE,50000,Hazard,1);
  Matrix<int> IIM2(SIZE,50000,Sort,25);
  Matrix<int> IIM3(SIZE,50000,Sort,50);
  Matrix<int> IIM4(SIZE,50000,Sort,75);
  Matrix<int> IIM5(SIZE,50000,Sort,95);
  Matrix<int> IIM6(SIZE,50000,Sort,99);
  Matrix<int> IIM7(SIZE,50000,Sort,99.7);
  Matrix<int> IIM8(SIZE,50000,AntySort,99);
  ExecutionIntroSort(IIM1);
  ExecutionIntroSort(IIM2);
  ExecutionIntroSort(IIM3);
  ExecutionIntroSort(IIM4);
  ExecutionIntroSort(IIM5);
  ExecutionIntroSort(IIM6);
  ExecutionIntroSort(IIM7);
  ExecutionIntroSort(IIM8);
  cout<<endl;
  cout<<endl;


//////////////////////////////////////////////////////////////////////////////////////////////////////
  Matrix<int> QQQM1(SIZE,100000,Hazard,1);
  Matrix<int> QQQM2(SIZE,100000,Sort,25);
  Matrix<int> QQQM3(SIZE,100000,Sort,50);
  Matrix<int> QQQM4(SIZE,100000,Sort,75);
  Matrix<int> QQQM5(SIZE,100000,Sort,95);
  Matrix<int> QQQM6(SIZE,100000,Sort,99);
  Matrix<int> QQQM7(SIZE,100000,Sort,99.7);
  Matrix<int> QQQM8(SIZE,100000,AntySort,99);
  ExecutionQuickSort(QQQM1);
  ExecutionQuickSort(QQQM2);
  ExecutionQuickSort(QQQM3);
  ExecutionQuickSort(QQQM4);
  ExecutionQuickSort(QQQM5);
  ExecutionQuickSort(QQQM6);
  ExecutionQuickSort(QQQM7);
  ExecutionQuickSort(QQQM8);
  cout<<endl;


  Matrix<int> MMMM1(SIZE,100000,Hazard,1);
  Matrix<int> MMMM2(SIZE,100000,Sort,25);
  Matrix<int> MMMM3(SIZE,100000,Sort,50);
  Matrix<int> MMMM4(SIZE,100000,Sort,75);
  Matrix<int> MMMM5(SIZE,100000,Sort,95);
  Matrix<int> MMMM6(SIZE,100000,Sort,99);
  Matrix<int> MMMM7(SIZE,100000,Sort,99.7);
  Matrix<int> MMMM8(SIZE,100000,AntySort,99);
  ExecutionMergeSort(MMMM1);
  ExecutionMergeSort(MMMM2);
  ExecutionMergeSort(MMMM3);
  ExecutionMergeSort(MMMM4);
  ExecutionMergeSort(MMMM5);
  ExecutionMergeSort(MMMM6);
  ExecutionMergeSort(MMMM7);
  ExecutionMergeSort(MMMM8);
  cout<<endl;


  Matrix<int> IIIM1(SIZE,100000,Hazard,1);
  Matrix<int> IIIM2(SIZE,100000,Sort,25);
  Matrix<int> IIIM3(SIZE,100000,Sort,50);
  Matrix<int> IIIM4(SIZE,100000,Sort,75);
  Matrix<int> IIIM5(SIZE,100000,Sort,95);
  Matrix<int> IIIM6(SIZE,100000,Sort,99);
  Matrix<int> IIIM7(SIZE,100000,Sort,99.7);
  Matrix<int> IIIM8(SIZE,100000,AntySort,99);
  ExecutionIntroSort(IIIM1);
  ExecutionIntroSort(IIIM2);
  ExecutionIntroSort(IIIM3);
  ExecutionIntroSort(IIIM4);
  ExecutionIntroSort(IIIM5);
  ExecutionIntroSort(IIIM6);
  ExecutionIntroSort(IIIM7);
  ExecutionIntroSort(IIIM8);
  cout<<endl;
  cout<<endl;


  //////////////////////////////////////////////////////////////////////////////////////////////////////
  Matrix<int> QQQQM1(SIZE,500000,Hazard,1);
  Matrix<int> QQQQM2(SIZE,500000,Sort,25);
  Matrix<int> QQQQM3(SIZE,500000,Sort,50);
  Matrix<int> QQQQM4(SIZE,500000,Sort,75);
  Matrix<int> QQQQM5(SIZE,500000,Sort,95);
  Matrix<int> QQQQM6(SIZE,500000,Sort,99);
  Matrix<int> QQQQM7(SIZE,500000,Sort,99.7);
  Matrix<int> QQQQM8(SIZE,500000,AntySort,99);
  ExecutionQuickSort(QQQQM1);
  ExecutionQuickSort(QQQQM2);
  ExecutionQuickSort(QQQQM3);
  ExecutionQuickSort(QQQQM4);
  ExecutionQuickSort(QQQQM5);
  ExecutionQuickSort(QQQQM6);
  ExecutionQuickSort(QQQQM7);
  ExecutionQuickSort(QQQQM8);
  cout<<endl;


  Matrix<int> MMMMM1(SIZE,500000,Hazard,1);
  Matrix<int> MMMMM2(SIZE,500000,Sort,25);
  Matrix<int> MMMMM3(SIZE,500000,Sort,50);
  Matrix<int> MMMMM4(SIZE,500000,Sort,75);
  Matrix<int> MMMMM5(SIZE,500000,Sort,95);
  Matrix<int> MMMMM6(SIZE,500000,Sort,99);
  Matrix<int> MMMMM7(SIZE,500000,Sort,99.7);
  Matrix<int> MMMMM8(SIZE,500000,AntySort,99);
  ExecutionMergeSort(MMMMM1);
  ExecutionMergeSort(MMMMM2);
  ExecutionMergeSort(MMMMM3);
  ExecutionMergeSort(MMMMM4);
  ExecutionMergeSort(MMMMM5);
  ExecutionMergeSort(MMMMM6);
  ExecutionMergeSort(MMMMM7);
  ExecutionMergeSort(MMMMM8);
  cout<<endl;


  Matrix<int> IIIIM1(SIZE,500000,Hazard,1);
  Matrix<int> IIIIM2(SIZE,500000,Sort,25);
  Matrix<int> IIIIM3(SIZE,500000,Sort,50);
  Matrix<int> IIIIM4(SIZE,500000,Sort,75);
  Matrix<int> IIIIM5(SIZE,500000,Sort,95);
  Matrix<int> IIIIM6(SIZE,500000,Sort,99);
  Matrix<int> IIIIM7(SIZE,500000,Sort,99.7);
  Matrix<int> IIIIM8(SIZE,500000,AntySort,99);
  ExecutionIntroSort(IIIIM1);
  ExecutionIntroSort(IIIIM2);
  ExecutionIntroSort(IIIIM3);
  ExecutionIntroSort(IIIIM4);
  ExecutionIntroSort(IIIIM5);
  ExecutionIntroSort(IIIIM6);
  ExecutionIntroSort(IIIIM7);
  ExecutionIntroSort(IIIIM8);
  cout<<endl;
  cout<<endl;


   //////////////////////////////////////////////////////////////////////////////////////////////////////
  Matrix<int> QQQQQM1(SIZE,1000000,Hazard,1);
  Matrix<int> QQQQQM2(SIZE,1000000,Sort,25);
  Matrix<int> QQQQQM3(SIZE,1000000,Sort,50);
  Matrix<int> QQQQQM4(SIZE,1000000,Sort,75);
  Matrix<int> QQQQQM5(SIZE,1000000,Sort,95);
  Matrix<int> QQQQQM6(SIZE,1000000,Sort,99);
  Matrix<int> QQQQQM7(SIZE,1000000,Sort,99.7);
  Matrix<int> QQQQQM8(SIZE,1000000,AntySort,99);
  ExecutionQuickSort(QQQQQM1);
  ExecutionQuickSort(QQQQQM2);
  ExecutionQuickSort(QQQQQM3);
  ExecutionQuickSort(QQQQQM4);
  ExecutionQuickSort(QQQQQM5);
  ExecutionQuickSort(QQQQQM6);
  ExecutionQuickSort(QQQQQM7);
  ExecutionQuickSort(QQQQQM8);
  cout<<endl;


  Matrix<int> MMMMMM1(SIZE,1000000,Hazard,1);
  Matrix<int> MMMMMM2(SIZE,1000000,Sort,25);
  Matrix<int> MMMMMM3(SIZE,1000000,Sort,50);
  Matrix<int> MMMMMM4(SIZE,1000000,Sort,75);
  Matrix<int> MMMMMM5(SIZE,1000000,Sort,95);
  Matrix<int> MMMMMM6(SIZE,1000000,Sort,99);
  Matrix<int> MMMMMM7(SIZE,1000000,Sort,99.7);
  Matrix<int> MMMMMM8(SIZE,1000000,AntySort,99);
  ExecutionMergeSort(MMMMMM1);
  ExecutionMergeSort(MMMMMM2);
  ExecutionMergeSort(MMMMMM3);
  ExecutionMergeSort(MMMMMM4);
  ExecutionMergeSort(MMMMMM5);
  ExecutionMergeSort(MMMMMM6);
  ExecutionMergeSort(MMMMMM7);
  ExecutionMergeSort(MMMMMM8);
  cout<<endl;


  Matrix<int> IIIIIM1(SIZE,1000000,Hazard,1);
  Matrix<int> IIIIIM2(SIZE,1000000,Sort,25);
  Matrix<int> IIIIIM3(SIZE,1000000,Sort,50);
  Matrix<int> IIIIIM4(SIZE,1000000,Sort,75);
  Matrix<int> IIIIIM5(SIZE,1000000,Sort,95);
  Matrix<int> IIIIIM6(SIZE,1000000,Sort,99);
  Matrix<int> IIIIIM7(SIZE,1000000,Sort,99.7);
  Matrix<int> IIIIIM8(SIZE,1000000,AntySort,99);
  ExecutionIntroSort(IIIIIM1);
  ExecutionIntroSort(IIIIIM2);
  ExecutionIntroSort(IIIIIM3);
  ExecutionIntroSort(IIIIIM4);
  ExecutionIntroSort(IIIIIM5);
  ExecutionIntroSort(IIIIIM6);
  ExecutionIntroSort(IIIIIM7);
  ExecutionIntroSort(IIIIIM8);
  cout<<endl;
  cout<<endl;

}



