#include <stdio.h>

#include <algorithm>
#include <iostream>

struct Time {
  int GetNinesNum() {
    int ret = 0;
    for (int i = 1; i <= 1000; i *= 10) {
      ret += (year / i % 10) == 9 ? 1 : 0;
    }
    ret += month % 10 == 9 ? 1 : 0;
    ret += day % 10 == 9 ? 1 : 0;
    return ret;
  }
  bool Equal(const Time& t) {
    return (year == t.year && month == t.month && day == t.day);
  }
  bool CheckIsLastDay() {
    if (day < 28) {
      return false;
    }
    if (day == 28) {
      if (month == 2 &&
          (year % 400 != 0 && (year % 4 != 0 || year % 100 == 0))) {
        return true;
      } else {
        return false;
      }
    }
    if (day == 29) {
      if (month == 2 &&
          (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))) {
        return true;
      } else {
        return false;
      }
    }
    if (day == 30) {
      return month == 4 || month == 6 || month == 9 || month == 11;
    }
    if (day == 31) {
      return true;
    }
    return false;
  }
  void Inc() {
    if (CheckIsLastDay()) {
      day = 1;
      if (month == 12) {
        month = 1;
        year++;
      } else {
        month++;
      }
    } else {
      day++;
    }
  }
  void Print() { printf("%d %d %d, %d\n", year, month, day, GetNinesNum()); }
  int year;
  int month;
  int day;
};

int main() {
  int T;
  std::cin >> T;
  while (T--) {
    Time cur, last;
    std::cin >> cur.year >> cur.month >> cur.day >> last.year >> last.month >>
        last.day;
    int ans = 0;
    while (true) {
      ans += cur.GetNinesNum();
      // cur.Print();
      cur.Inc();
      if (cur.Equal(last)) {
        ans += cur.GetNinesNum();
        break;
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}