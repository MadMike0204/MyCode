/*
  冒泡排序
  flag作用：如果进行了一次排序，那么这次for循环结束后会继续进行一次，否则就结束（排好了）
  较小的元素像是气泡般慢慢「浮」到数列的顶端，故叫做冒泡排序。
*/
void bubble_sort(int t,int arr[])
{
    int temp;
    int flag = true;
    while(flag)
    {
        flag = 0;
        for(int i=0;i<t-1;i++)
        {
            if(arr[i] > arr[i+1]) // 大于号,升序 ; 小于号,降序
            {
                flag = 1;
                temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
            }
        }
    }
}