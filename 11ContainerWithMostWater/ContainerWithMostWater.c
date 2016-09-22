/*************************************************************************
    > File Name: ContainerWithMostWater.c
    > Author: zhang zheng
    > E-mail: kezy-5566@163.com 
    > Created Time: Thu 22 Sep 2016 05:57:03 PM CST
    Container With Most Water:
    	Given n non-negative integers a1,a2,...,an, where each represents
	a point at coordinate (i,ai). n vertical lines are drawn such that 
	the two endpoints of line i is at (i,ai) and (i,0). Find two lines,
	which together with x-axis forms a container, such that the 
	container contains the most water.
    Note: You may not slant the container.
 ************************************************************************/

#include<stdio.h>

/*最简单的方法，但是运行时间不符合要求*/
int maxArea(int *height, int heightSize) 
{
	int max_area = 0;
	int area = 0;
	for (int i=0; i<heightSize; i++) {
		for (int j=i+1; j<heightSize; j++) {
			area = (j-i) * (height[i] < height[j] ? height[i] : height[j]);
			max_area = max_area > area ? max_area : area;
		}
	}
	return max_area;
}

/*从两边向中间不断靠拢，
 假设当前的两条线x,y组成的容积最大，那么x的左边线及y的右边线不可能比它们更大，
 所以往中间找*/
int maxArea(int *height, int heightSize)
{
	int max_area = 0;
	int area = 0;
	int left = 0, right = heightSize-1;
	int temp = 0;
	while (left < right) {
		area = (right-left) * (height[left] < height[right] ? height[left] : height[right]);
		max_area = max_area > area ? max_area : area;
		if (height[left] < height[right]) {
			temp = left;
			/*找出比左边大的线*/
			while (temp < right && height[temp] <= height[left])
				temp++;
			left = temp;
		} else {
			temp = right;
			/*找出比右边大的线*/
			while (temp > left && height[temp] <= height[right])
				temp--;
			right = temp;
		}
	}
	return max_area;
}

int maxArea(int *height, int heightSize)
{
	int max_area = 0;
	int area = 0;
	int left = 0, right = heightSize-1;
	while (left < right) {
		area = (right-left) * (height[left] < height[right] ? height[left] : height[right]);
		max_area = max_area > area ? max_area : area;
		if (height[left] < height[right]) {
			left++;
		} else {
			right--;
		}
	}
	return max_area;
}

