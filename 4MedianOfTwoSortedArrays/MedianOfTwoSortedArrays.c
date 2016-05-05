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

double findMedianSortedArrays(int *nums1, int nums1Size, int *nums2, int nums2Size)
{
	if (nums1Size == 0 && nums2Size == 0)
		return 0.0;
	
	int len = nums1Size + nums2Size;
	double median;
	if (nums1[nums1Size - 1] < nums2[0])	
	if (len % 2 == 0) {
	} else {
		
	}
}
