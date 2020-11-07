from cs50 import get_float

# Return a minimum number of coins to be returned as change to the user

# SOLUTION

change = get_float("Change owed: ")
coins = 0

# Don't accept change owed thats negative
while (change < 0):
    change = get_float("Change owed: ")

# Round change by 100
rounded = change * 100

# Find the number of coins for the rounded change
while (rounded != 0):
    if (rounded >= 25):
        rounded = rounded - 25
        coins = coins + 1
    elif(rounded < 25 and rounded >= 10):
        rounded = rounded - 10
        coins = coins + 1
    elif(rounded < 10 and rounded >= 5):
        rounded = rounded - 5
        coins = coins + 1
    elif(rounded < 5 and rounded >= 1):
        rounded = rounded - 1
        coins = coins + 1
    elif(change < 0.01):
        break

print(coins)