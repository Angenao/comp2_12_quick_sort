#define WIN32_LEAN_AND_MEAN             // Windows ヘッダーからほとんど使用されていない部分を除外する
#include "Windows.h"                    // Windows API の機能定義

#include "../include/lib_func.h"

// クイックソート(引数が不適切であればfalseを返す)
bool quick_sort(item* begin, const item* end)
{
	// ToDo: クイックソートで並び替えてください

    if (begin == NULL || end == NULL || begin >= end) 
    {
        return false;
    }

    item* low = begin;
    item* high = const_cast<item*>(end - 1);

    while (low < high) 
    {
        item pivot = *high;
        item* i = low - 1;

        for (item* j = low; j < high; j++) 
        {
            if (j->key <= pivot.key) 
            {
                i++;
                item temp = *i;
                *i = *j;
                *j = temp;
            }
        }

        item temp = *(i + 1);
        *(i + 1) = *high;
        *high = temp;

        item* pi = i + 1;


        if (pi - low < high - pi) 
        {
            quick_sort(low, pi);
            low = pi + 1;
        }
        else 
        {
            quick_sort(pi + 1, high + 1);
            high = pi - 1;
        }
    }

    return true;
}
