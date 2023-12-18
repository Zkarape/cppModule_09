#include "PmergeMe.hpp"

// void PmergeMe::merge_vec_sort(int left, int mid, int right)
// {
//     int n1 = mid - left + 1;
//     int n2 = right - mid;
//     std::vector<int> leftArray(n1);
//     std::vector<int> rightArray(n2);

//     for (int i = 0; i < n1; i++)
//         leftArray[i] = _vec[left + i];
//     for (int j = 0; j < n2; j++)
//         rightArray[j] = _vec[mid + 1 + j];

//     int i = 0, j = 0, k = left;
//     while (i < n1 && j < n2) {
//         if (leftArray[i] <= rightArray[j]) {
//             _vec[k] = leftArray[i];
//             i++;
//         } else {
//             _vec[k] = rightArray[j];
//             j++;
//         }
//         k++;
//     }
//     while (i < n1) {
//         _vec[k] = leftArray[i];
//         i++;
//         k++;
//     }
//     while (j < n2) {
//         _vec[k] = rightArray[j];
//         j++;
//         k++;
//     }

// }

// void PmergeMe::merge_vec_part(int left, int right)
// {
//     if (left < right)
//     {
//         int mid = left + (left + right) / 2;
//         merge_vec_part( left, mid);
//         merge_vec_part( mid + 1, right);
//         merge_vec_sort(left, mid, right);
//     }
// }

// void PmergeMe::merge_deque_sort(int left, int mid, int right)
// {
//     int n1 = mid - left + 1;
//     int n2 = right - mid;
//     std::deque<int> leftArray(n1);
//     std::deque<int> rightArray(n2);

//     for (int i = 0; i < n1; i++)
//         leftArray[i] = _vec[left + i];
//     for (int j = 0; j < n2; j++)
//         rightArray[j] = _vec[mid + 1 + j];

//     int i = 0, j = 0, k = left;
//     while (i < n1 && j < n2) {
//         if (leftArray[i] <= rightArray[j]) {
//             _vec[k] = leftArray[i];
//             i++;
//         } else {
//             _vec[k] = rightArray[j];
//             j++;
//         }
//         k++;
//     }
//     while (i < n1) {
//         _vec[k] = leftArray[i];
//         i++;
//         k++;
//     }
//     while (j < n2) {
//         _vec[k] = rightArray[j];
//         j++;
//         k++;
//     }

// }

// void PmergeMe::merge_deque_part(int left, int right)
// {
//     if (left < right)
//     {
//         int mid = left + (left + right) / 2;
//         merge_deque_part(left, mid);
//         merge_deque_part(mid + 1, right);
//         merge_deque_sort(left, mid, right);
//     }
// }
