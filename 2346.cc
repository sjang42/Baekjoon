#include <cstdio>
#include <deque>

using namespace std;

int main(void) {
  int N;
  deque<pair<int, int> > circle;
  int order[1111];
  int count = 0;

  // get inputs
  scanf("%d", &N);
  for (int i = 1; i <= N; i++) {
    int tmp;

    scanf("%d", &tmp);
    circle.push_back(make_pair(i, tmp));
  }

  // process
  while (!circle.empty()) {
    pair<int, int> top = circle.front();
    circle.pop_front();

    int step = top.second - 1;
    bool neg = false;

    if (step < 0) {
      neg = true;
      step *= -1;
      step--;
    }
    order[count++] = top.first;

    // spin
    for (int i = 0; i < step; i++) {
      if (!neg) {
        pair<int, int> tmp = circle.front();

        circle.push_back(tmp);
        circle.pop_front();
      } else {
        pair<int, int> tmp = circle.back();

        circle.push_front(tmp);
        circle.pop_back();
      }
    }
  }

  // print answer
  printf("%d", order[0]);
  for (int i = 1; i < count; i++) printf(" %d", order[i]);
  printf("\n");
  return (0);
}
