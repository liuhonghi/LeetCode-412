//
//  main.c
//  LeetCode-412
//
//  Created by HiLau on 2023/6/20.
//

#include <stdio.h>
#include <stdlib.h>


//FizzBuzz
//给你一个整数 n ，找出从 1 到 n 各个整数的 Fizz Buzz 表示，并用字符串数组 answer（下标从 1 开始）返回结果，其中：
//answer[i] == "FizzBuzz" 如果 i 同时是 3 和 5 的倍数。
//answer[i] == "Fizz" 如果 i 是 3 的倍数。
//answer[i] == "Buzz" 如果 i 是 5 的倍数。
//answer[i] == i （以字符串形式）如果上述条件全不满足。

char ** fizzBuzz(int n, int* returnSize){
    // 动态分配二维字符数组
    char ** answer=malloc(n*sizeof(char*));
    // 返回数组大小
    *returnSize=n;
    for(int i=1;i<=n;i++){
        if(i%3==0&&i%5==0){
            // 分配并复制"FizzBuzz"字符串
            answer[i-1]=malloc(9*sizeof(char));
            answer[i-1]="FizzBuzz";
        }
        else if(i%3==0&&i%5!=0){
            // 分配并复制"Fizz"字符串
            answer[i-1]=malloc(5*sizeof(char));
            answer[i-1]="Fizz";
        }
        else if(i%3!=0&&i%5==0){
            // 分配并复制"Buzz"字符串
            answer[i-1]=malloc(5*sizeof(char));
            answer[i-1]="Buzz";
        }
        else{
            // 分配并转换数字为字符串
            answer[i-1]=malloc(5*sizeof(char));
            sprintf(answer[i-1],"%d",i);
        }
    }
    // 返回二维字符数组指针
    return answer;
}

int main()
{
    int n = 15;
    int returnSize = 0;
    char** result = fizzBuzz(n, &returnSize);

    for(int i = 0; i < returnSize; i++)
    {
        printf("%s\n", result[i]);
        free(result[i]); // 记得释放内存
    }
    free(result); // 记得释放内存

    return 0;
}
