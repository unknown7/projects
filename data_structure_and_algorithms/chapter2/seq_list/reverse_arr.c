#include <stdio.h>
#include "seq_list.c"

void reverse(int *buf, int start, int end);
void rotate(int* nums, int numsSize, int k);

int main(int argc, char const *argv[])
{
    list list = init(10, 1);
    print_list(list);
    sort(list);


    // reverse(list->pn, 1, 10);
    // print_list(list);


    rotate(list->pn, list->len, 7);
    print_list(list);
    return 0;
}


//法4：调换位置，3次逆序法
void reverse(int *buf, int start, int end)
{
    int i=0;
    int temp=0;
    int cnt;
    cnt = (int)((end-start)/2+0.5);
    for(i=0;i<=cnt;i++)
    {
        temp = buf[start+i];
        buf[start+i]  = buf[end-i];
        buf[end-i] = temp;
    }
}
 
void rotate(int* nums, int numsSize, int k) {
/*
//测试reverse函数可以工作
    int i = 0;
    reverse(nums,0,numsSize-1);
    for(i = 0;i<numsSize;i++)
        printf("%d ",nums[i]);        
*/
    k = k%numsSize;
    if(k == 1 )
        return;
    reverse(nums,1,numsSize);
    reverse(nums,1,k-1);
    reverse(nums,k,numsSize);
 }