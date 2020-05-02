from cs50 import get_int
from cs50 import get_string

number = get_string("Number: ")
digit = 0
num_digits = len(number)
sum_of_double_odds = 0
sum_of_evens = 0
is_valid = False

for i in range(num_digits - 1, -1, -1):
    digit = int(number[i])

    if (num_digits - i - 1) % 2 == 0:
        sum_of_evens += digit

    else:
        multiple = 2 * digit
        if len(str(multiple)) > 1:
            temp = str(multiple)
            sum_of_double_odds += int(temp[1])
            sum_of_double_odds += int(temp[0])
        else:
            sum_of_double_odds += multiple

if (sum_of_evens + sum_of_double_odds) % 10 == 0:
    is_valid = True

first_two_digits = int(number[0:2])


if int(number[0]) == 4 and num_digits >= 13 and num_digits <= 16 and is_valid:
    print("VISA")
elif first_two_digits >= 51 and first_two_digits <= 55 and num_digits == 16 and is_valid:
    print("MASTERCARD")
elif (first_two_digits == 34 or first_two_digits == 37) and (num_digits == 15 and is_valid):
    print("AMEX")
else:
    print("INVALID")