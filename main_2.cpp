#include <iostream>

int getIntLen(int num) {
  int length = 0;
  while (num > 0) {
    num = num / 16;
    length = length + 1;
  }
  return length;
}

char *intTohex(int num) {
  bool is_negative = (num < 0) ? true : false;

  int sign_len = (is_negative) ? 3 : 2;
  int int_length = getIntLen(num);
  int total_length = getIntLen(num) + sign_len + 1;

  char *result = new char[total_length];

  for (int i = 0; i < total_length - 1; ++i) {
    result[i] = 'x';
  }
  if (is_negative) {
    num = num * (-1);
    result[0] = '-';
    result[1] = '0';
    result[2] = 'x';
  } else {
    result[0] = '0';
    result[1] = 'x';
  }

  for (int i = total_length - 2; i >= sign_len; --i) {
    int rem = num % 16;
    char symbol;
    if (rem > 9) {
      symbol = (rem - 9) + '@';
    } else {
      symbol = rem + '0';
    }
    result[i] = symbol;
    num = num / 16;
  }
  result[total_length - 1] = '\0';
  //   while (num > 0) {
  //     int ost = num % 16;
  //     char repa;

  //     if (ost > 9) {
  //       repa = char(64 + (ost - 9));
  //     } else {
  //       repa = char(48 + ost);
  //     }

  //     result[i] = repa;
  //     num = num / 16;
  //     i = i - 1;
  //   }

  return result;
}

int main() { std::cout << intTohex(0x7FFFFFFF) << std::endl; }