from cs50 import get_int

# Validate credit card using Luhn’s Algorithm and determine whether it's a VISA, Mastercard or Amex

# SOLUTION

# Get card number from user
number = get_int("Number: ")

# Find the length of the card number
n = len(str(number))

divide = 1
total_second = 0

# Loop through every second digit and apply the algorithm
for i in range(round(n / 2)):
    divide = divide * 100
    second_number = number % divide
    second_number = int(second_number / (divide / 10))
    multiplied = second_number * 2
    if (multiplied >= 10):
        first = int(multiplied / 10)
        second = multiplied % 10
        total_second = total_second + first + second
    else:
        total_second = total_second + multiplied

not_divide = 0.1
total_first = 0
x = 1

# Loop through every first digit and apply the algorithm
for j in range(round(n / 2)):
    not_divide = not_divide * 100
    first_number = number % not_divide
    first_number = int(first_number / x)
    x = x * 100
    total_first = total_first + first_number

# Calculate the total sum
total_sum = total_second + total_first


# If the card is invalid print INVALID
if (total_sum % 10 != 0):
    print("INVALID")

# Find which card is the valid card
else:
    if (int(n) == 15 and (int(number / 10000000000000) == 34 or int(number / 10000000000000) == 37)):
        print("AMEX")
    elif (int(n) == 16 and (int(number / 100000000000000) >= 51 and int(number / 100000000000000) <= 55)):
        print("MASTERCARD")
    elif ((int(n) == 16 or int(n) == 13) and (int(number / 1000000000000000) == 4 or int(number / 1000000000000) == 4)):
        print("VISA")


