/*
 *
 * 题目描述：输入n个整数,依次输出每个数的约数的个数
 * 
 *
 * 输入描述：输入的第一行为N，即数组的个数（N <= 1000）
 *          接下来的1行包括N个整数，其中每个数的范围为（1 <= Num <= 1000000000）
 *          当N = 0 时输入结束
 *
 * 输出描述：可能有多组输入数据，对于每组输入数据，输出N行，其中每一行对应上面的一个数的约数的个数。
 *
 * 示例1：
 *        输入： 
 *              5
 *              1 3 4 6 12
 *        输出：
 *              1
 *              2
 *              3
 *              4
 *              6
 *
 */

#include <stdio.h>

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        int i, j, num, count = 0;
        int arr[n];
        for (i = 0; i < n; ++i) {
            scanf("%d", &num);
            if (num == 0) return 0;
            for (j = 1; j * j < num; ++j) {
                if (num % j == 0) count += 2;
            }
            if (j * j == num) count++;
            arr[i] = count;
            count = 0;
        }
        for (i = 0; i < n; ++i)
            printf("%d\n", arr[i]);
    }
    return 0;
}