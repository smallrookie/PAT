/*
 * ��Ŀ�������������⣨�û����ɼ������У����Ի�óɼ��Ӹߵ��ͻ�ӵ͵��ߵ�����,��ͬ�ɼ�������¼��������ǰ�Ĺ�����
 *
 * ����������������У�������Ҫ������˵ĸ�����Ȼ���������򷽷�0�����򣩻���1�������ٷֱ��������ǵ����ֺͳɼ�����һ���ո������
 *
 * �������������ָ����ʽ������ֺͳɼ������ֺͳɼ�֮����һ���ո������
 *
 * ʾ��1��
 *    
 *   ���룺 
 *         3
 *         0
 *         fang 90
 *         yang 50
 *         ning 70
 *
 *   �����
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
