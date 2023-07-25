

#include <iostream>
#include<bits/stdc++.h>
using namespace std;

/*
     Sequential Sort Algorithm
*/

void sequentialSort (int sortedArray[])
{

  std::sort (sortedArray, sortedArray + 10);

}

/*
     Merge Sort Algorithm
*/

void merge (int arr[], int left, int mid, int right)
{
  int n1 = mid - left + 1;
  int n2 = right - mid;

  int *leftArray = new int[n1];
  int *rightArray = new int[n2];

  for (int i = 0; i < n1; ++i)
    leftArray[i] = arr[left + i];
  for (int j = 0; j < n2; ++j)
    rightArray[j] = arr[mid + 1 + j];

  int i = 0, j = 0, k = left;

  while (i < n1 && j < n2)
    {
      if (leftArray[i] <= rightArray[j])
	{
	  arr[k] = leftArray[i];
	  ++i;
	}
      else
	{
	  arr[k] = rightArray[j];
	  ++j;
	}
      ++k;
    }

  while (i < n1)
    {
      arr[k] = leftArray[i];
      ++i;
      ++k;
    }

  while (j < n2)
    {
      arr[k] = rightArray[j];
      ++j;
      ++k;
    }

  delete[]leftArray;
  delete[]rightArray;
}


void mergeSort (int arr[], int left, int right)
{
  if (left < right)
    {
      int mid = left + (right - left) / 2;
      mergeSort (arr, left, mid);
      mergeSort (arr, mid + 1, right);
      merge (arr, left, mid, right);
    }
}


int main ()
{
  int nums[10] = { 12, 15, 97, 18, 21, 45, 915, 102, 954, 4 };
  int sortedArray1[10];
  int sortedArray2[10];
  for (int i = 0; i < 10; ++i)
    {
      sortedArray1[i] = nums[i];
      sortedArray2[i] = nums[i];
    }
/*
    Time calculaiton for merge sort startTime1 has thread 1 starttime and endTime1 has endtime 
    difference gives us the time used for this thread.
*/
  auto startTime1 = std::chrono::high_resolution_clock::now ();
  thread t1 (mergeSort, sortedArray1, 0, 9);
  t1.join ();
  auto endTime1 = std::chrono::high_resolution_clock::now ();

  auto duration1 =
    std::chrono::duration_cast < std::chrono::milliseconds >
    (endTime1 - startTime1).count ();
  std::
    cout << "Merge Sort Execution Time: " << duration1 << " milliseconds" <<
    std::endl;

/*
    Time calculaiton for Sequential sort startTime2 has thread 2 starttime and endTime2 has endtime 
    difference gives us the time used for this thread.
*/

  auto startTime2 = std::chrono::high_resolution_clock::now ();
  thread t2 (sequentialSort, sortedArray2);
  t2.join ();
  auto endTime2 = std::chrono::high_resolution_clock::now ();

  auto duration2 =
    std::chrono::duration_cast < std::chrono::milliseconds >
    (endTime2 - startTime2).count ();
  std::
    cout << "Sequential Sort Execution Time: " << duration2 << " milliseconds"
    << std::endl;

  return 0;
}
