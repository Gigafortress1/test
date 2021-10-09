#include <iostream>
#include <vector>
#include <string.h>
#include <math.h>
#include <bitset>
using namespace std;

struct num
{
    int bit;
    int value;
    int idx;
};

void CSet(int index, int n, int size, vector<struct num> nums, int& res, int sub_size) {//index:当前下标 n:我们要在剩下的数中取出n个 size:共有size个元素
    if (n == 0)//空集
        return ;
    else if (n == 1) {//要在剩下数种取出1个
        for (int i = index; i < size; i++) {
            nums[i].bit = 1;
            nums[i].idx = sub_size+1;
            int sum = 0;
            // for(int j = 0; j < size;j++){
            //     cout <<  "value = " << nums[j].value << " idx = " << nums[j].idx << " bit = " << nums[j].bit << endl;
            // }
            for (int i = 0; i < size; i++){
                if (nums[i].bit){
                    sum += nums[i].value*nums[i].idx;
                }
            }
//            cout << "sum = " << sum << endl;
            res = res^sum;
            nums[i].bit = 0;
        }
        return ;
    }
    else {//当要在剩下数中取出2个及以上时用递归
        for (int i = index; i <= size - n ; i++) {
            nums[i].bit = 1;
            nums[i].idx = sub_size+1;
            CSet(i + 1, n - 1, size, nums, res, sub_size+1);
            nums[i].bit = 0;
            nums[i].idx = 0;
        }
    }
}

int main()
{
    int n,res = 0;
    cin >> n;
    vector<struct num> nums(n);

    for(int i = 0; i < n; i++){
        cin >> nums[i].value;
        nums[i].bit = 0;
        nums[i].idx = 0;
    }
    for(int i = 1; i <= n; i++) {
        CSet(0, i, n, nums, res, 0);
    }

    cout << "result = " << res << endl;
}
