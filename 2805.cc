#include <iostream>
#include <set>
#include <algorithm>
#include <functional>

using namespace std;

long long		trees[1000000];
int				N, M;

//  height로 잘랐을 때 필요한 만큼(M)을 얻을 수 있으면 ture or false.
bool			good(long long height)
{
    long long count = 0;
    long long tmp;
    
    for (int i = 0; i < N; i++)
    {
        tmp = trees[i] - height;

        if (tmp <= 0)
            break;
        count += tmp;
    }
    return (count >= M);
}

long long		cut(long long left, long long right)
{
    if (left >= right - 1)
    {
        if (good(right))
            return right;
        else
            return left;
    }
    
    long long mid = (left + right) / 2;
    if (good(mid))
        return cut(mid, right);
    else
        return cut(left, mid - 1);
}

int				main(void)
{
    ios_base::sync_with_stdio(false);

    long long h;
    bool success;

    cin >> N >> M;
    for (int i = 0; i < N; i++)
        cin >> trees[i];

    sort(trees, trees + N, greater<long long>());

    h = cut(0, trees[0] - 1);
    cout << h << endl;
    return (0);
}
