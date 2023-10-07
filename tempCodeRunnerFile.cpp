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