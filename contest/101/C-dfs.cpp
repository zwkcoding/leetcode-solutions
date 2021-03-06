/*************************************************************************
    > File Name: C.cpp
    > Author: tiankonguse
    > Mail: i@tiankonguse.com
    > Created Time: 2019年03月15日 16:42:56
 ************************************************************************/

#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<string>
#include<stack>
#include<map>
#include<set>
#include<queue>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<time.h>
#include "../../include/base.h"
using namespace std;


#ifdef __int64
typedef __int64 LL;
#else
typedef long long LL;
#endif

const int debug = 0;
typedef unsigned uint;
typedef unsigned char uchar;
auto __ =[]() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}
();

class Solution {
    vector<int> have;
    int setSize;
    vector<int> bit;
    int n;

    int dfs(int pos, int preSum, int fullFlah) {
        if(pos < 0) {
            return preSum;
        }
        if(fullFlah) {
            return dfs(pos-1, preSum*setSize, fullFlah);
        }

        int val = bit[pos];

        int ans = 0;
        for(int i=1; i<val; i++) {
            if(have[i]) {
                ans += dfs(pos-1, preSum, 1);
            }
        }
        if(have[val]) {
            ans += dfs(pos-1, preSum, 0);
        }
        return ans;
    }
public:
    int atMostNGivenDigitSet(vector<string>& D, int N) {
        setSize = D.size();
        have.resize(10,0);
        for(int i=0; i<setSize;i++) {
            have[D[i][0]-'0'] = 1;
        }

        while(N>0) {
            bit.push_back(N%10);
            N /= 10;
        }
        int ans = 0;
        int tmpSUm = 1;
        for(int i=1; i<bit.size(); i++) {
            tmpSUm = tmpSUm * setSize;
            ans += tmpSUm;
        }
        ans += dfs(bit.size()-1, 1, 0);
        return ans;
    }
};

template <class ansType, class dataType1, class dataType2 = int>
void test(ansType& expectAns, dataType1& firstData, dataType2 secondData = dataType2()) {
    Solution work;
    ansType ans;
    ans = work.atMostNGivenDigitSet(firstData, secondData);

    static int index = 0;
    index++;
    bool check = eq(ans, expectAns);
    printf("\n");
    if(!check) {
        printf("index %d: NO\n", index);
        output("firstData", firstData);
        output("secondData", secondData);
        output("ans", ans);
        output("expectAns", expectAns);
    } else {
        printf("index %d: YES\n", index);
    }
    printf("\n");

}

int main() {
    vector<string> first;
    int second;
    int expectAns;


    first = {"1","3","5","7"};
    second = 100;
    expectAns = 20;
    test(expectAns, first, second);



    first = {"1"};
    second = 11;
    expectAns = 2;
    test(expectAns, first, second);

    first = {"1","4","9"};
    second = 1000000000;
    expectAns = 29523;
    test(expectAns, first, second);


    return 0;
}

