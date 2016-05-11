/*
*create by xiao
*Median of Two sorted arrays:
*	There are two sorted arrays nums1 and nums2 of size m and n 
*	respectively. Find the median of two sorted arrays. The overall run
*	time complexity should be O(log(m+n)).
*
*/
#include <stdio.h>
#include <stdlib.h>

double findmth(int *A, int m, int *B, int n, int k)
{
	if (m > n)
		return findmth(B, n, A, m, k);
	if (m == 0)
		return B[k - 1];
	if (k == 1)
		return A[0] < B[0] ? A[0] : B[0];
	
	int ka = (k/2) < m ? k/2 : m;
	int kb = k - ka;
	if (A[ka-1] < B[kb-1])
		return findmth(A + ka, m - ka, B, n , k - ka);
	else if (A[ka - 1] > B[kb - 1])
		return findmth(A, m, B + kb, n - kb , k - kb);
	else 
		return A[ka - 1];
}


double findMedianSortedArrays(int *nums1, int nums1Size, int *nums2, int nums2Size)
{
	if (nums1Size == 0 && nums2Size == 0)
		return 0.0;
	int len = nums1Size + nums2Size;
	if (len & 0x1)
		return findmth(nums1, nums1Size, nums2, nums2Size, len/2 + 1);
	else 
		return (findmth(nums1, nums1Size, nums2, nums2Size, len/2) + 
			findmth(nums1, nums1Size, nums2, nums2Size, len/2 + 1))/2;
}

int main()
{
	int num1[] = {1,3,4,5,6,9,10,19,21};
	int num2[] = {4,9,10,19,27};
	double mm = findMedianSortedArrays(num1, sizeof(num1)/sizeof(int), num2,sizeof(num2)/sizeof(int));
	printf("The median of arrays is :%f\n", mm);
	return 0;
}
