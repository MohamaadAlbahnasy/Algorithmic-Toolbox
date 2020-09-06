#include <iostream>
#include <vector>

using std::vector;
long long merge_and_count_split_inversions(vector<int> &arr, vector<int> &aux, size_t low, size_t mid, size_t high)
{
  int k = low, i = low, j = mid + 1;
  int inversionCount = 0;

  // While there are elements in the left and right runs
  while (i <= mid && j <= high)
  {
    if (arr[i] <= arr[j])
    {
      aux[k++] = arr[i++];
    }
    else
    {
      aux[k++] = arr[j++];
      inversionCount += (mid - i + 1); // NOTE
    }
  }

  // Copy remaining elements
  while (i <= mid)
    aux[k++] = arr[i++];

  // Don't need to copy second half

  // copy back to the original array to reflect sorted order
  for (int i = low; i <= high; i++)
    arr[i] = aux[i];

  return inversionCount;
}

long long get_number_of_inversions(vector<int> &a, vector<int> &b, size_t left, size_t right)
{
  long long number_of_inversions = 0;
  if (right == left)
  {
    return 0;
  }
  size_t mid = left + ((right - left) / 2);
  number_of_inversions += get_number_of_inversions(a, b, left, mid);
  number_of_inversions += get_number_of_inversions(a, b, mid + 1, right);
  number_of_inversions += merge_and_count_split_inversions(a, b, left, mid, right);
  return number_of_inversions;
}

int main()
{
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < n; i++)
  {
    std::cin >> a[i];
  }
  vector<int> b = a;
  std::cout << get_number_of_inversions(a, b, 0, a.size() - 1) << '\n';
}
