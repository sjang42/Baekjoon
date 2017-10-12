#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
using namespace std;

int main()
{
    set<string>     s;
    vector<string>  ans;
    int             n, m;   cin >> n >> m;
 
    // 듣지 못한 사람 저장
    while (n--)
    {
        string name;
        cin >> name;
        s.insert(name);
    }
    // 보지 못한 사람을 듣지 못한 사람에 있었는지 체크
    while (m--)
    {
        string name;

        cin >> name;
        if (s.count(name))
            ans.push_back(name);
    }

    // 답의 이름들을 사전 순으로 정렬
    sort(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    for (auto &name : ans)
        cout << name << '\n';
    return 0;
}
