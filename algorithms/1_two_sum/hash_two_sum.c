#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int getinarr();
static int *hashindices(int *arr, int len, int target);

static int iarr[64+1];
/* this solution has a limitation:
 * the hash[] array use value 作索引, 
 * 所以value存在的最大值的2倍就是hash的大小
 * 这个空间占用很大(在输入存在个别特大值时)
 * 优点就是查差值不用算法直接下标索引
 */
/* 正统高效解决方案就是用map, 但是需要map.search查找
 * 计算出的差值
 * 但空间占用是固定的输入数个数
 */

/* use hash style,
 * both take advantage of index and val
 */
int main(int argc, char *argv[])
{
    int i = 0;
    int len;
    int target;
    int *ret = NULL;

    /* 1. get array & target */
    fprintf(stdout,"please input array(Enter):\n");
    len = getinarr();
    if (!len)
    {
        fprintf(stderr,"get array failed!\n");
        return 1;
    }

    fprintf(stdout,"please input target:\n");
    scanf("%d", &target);

    /* 2. pre reapply arry copy */

    /* 2. calculate the result */
    ret = hashindices(iarr,len,target);
    if (ret==NULL)
        fprintf(stdout,"no matched\n");
    else
        fprintf(stdout,"result[%d,%d]\n", ret[0], ret[1]);
    
    return 0;
}

/* get array from stdin
 * return len of array:
 * 0        * no input
 */
static int getinarr()
{
    char buf[1024];
    char *ptr;
    int i = 0;

    fgets(buf,sizeof(buf),stdin);
    ptr = strtok(buf," ");
    if (ptr)
        iarr[i++] = atoi(ptr);
    else
        return 0;

    while((ptr = strtok(NULL," ")) != NULL)
        iarr[i++] = atoi(ptr);
    return i;
}

/* calculate indices suited
 * input: 1. array 2. len of array
 * return pointer to indices array:
 * NULL     * no result
 * 0x...    * found
 */
static int *hashindices(int *arr, int len, int target)
{
    static int result[2+1];
    int *ret = NULL;
    int hash[200] = {0};     /* stores index and value */
    /* stupid way, loop-loop calculate */
    int i,j,flag;

    flag = 0;
    for (i=0;i<len;i++)
    {
        if (hash[target-arr[i]+100] != 0)
        {
            /* 前面执行过程中存入的值, 利用另一余数(value)做索引返回index值
             * hash存入的index为+1后的值, 以免出现0和初始化值冲突了
             */
            result[1] = hash[target-arr[i]+100]-1;
            result[0] = i;
            ret = result;
            flag = 1;
            break;
        }
        else
            hash[arr[i]+100] = i+1;
    }
    if (!flag)
        ret = NULL;
    return ret;
}

