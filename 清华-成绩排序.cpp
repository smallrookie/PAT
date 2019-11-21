/*
 * 题目描述：输入任意（用户，成绩）序列，可以获得成绩从高到低或从低到高的排列,相同成绩都按先录入排列在前的规则处理。
 *
 * 输入描述：输入多行，先输入要排序的人的个数，然后输入排序方法0（降序）或者1（升序）再分别输入他们的名字和成绩，以一个空格隔开。
 *
 * 输出描述：按照指定方式输出名字和成绩，名字和成绩之间以一个空格隔开。
 *
 * 示例1：
 *    
 *   输入： 
 *         3
 *         0
 *         fang 90
 *         yang 50
 *         ning 70
 *
 *   输出：
 *        fang 90
 *        ning 70
 *        yang 50
 *
 *
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student {
    char name[20];
    int score;
    struct Student* next;
}Student;

int main() {
    int i, n, type;
    typedef struct Student* pStu;
    while (scanf("%d%d", &n, &type) != EOF) {
        pStu head = (pStu)malloc(sizeof(Student));
        strcpy(head->name, "abcd");
        head->score = -1;
        head->next = NULL;

        pStu p = head->next;
        for (i = 0; i < n; ++i) {
            p = (pStu)malloc(sizeof(Student));
            scanf("%s%d", p->name, &p->score);
            p->next = NULL;

            pStu q = head;
            while (q->next && (type == 0 ? q->next->score >= p->score : q->next->score <= p->score))
                q = q->next;
            pStu tmp = q->next;
            q->next = p;
            p->next = tmp;
        }
        p = head->next;
        for (i = 0; i < n && p; ++i) {
            printf("%s %d\n", p->name, p->score);
            p = p->next;
        }
    }
    return 0;
}
