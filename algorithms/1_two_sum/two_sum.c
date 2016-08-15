#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int getinarr();
static int *calindices(int *arr, int len, int target);

static int iarr[64+1];

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
    ret = calindices(iarr,len,target);
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
static int *calindices(int *arr, int len, int target)
{
    static int result[2+1];
    int *ret = NULL;
    /* stupid way, loop-loop calculate */
    int i,j,flag;

    flag = 0;
    for (i=0;i<len;i++)
    {
        for(j=i+1;j<len;j++)
        {
            if (arr[i]+arr[j] == target)
            {
                result[0] = i;
                result[1] = j;
                ret = result;
                flag = 1;
                break;
            }
            else
                continue;
        }
        if (flag)
            break;
    }
    return ret;
}

