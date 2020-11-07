from cs50 import get_string

# Task: Calculate the approximate grade level needed to comprehend a text (Coleman-Liau index) the provided by the user

# SOLUTION

# Get the text from the user
text = get_string("Text: ")

letters = 0
words = 0
sentences = 0

# Count all the words, sentences and letters in the given text
for i in range(len(text)):
    if (ord(text[i]) >= 65 and ord(text[i]) <= 122):
        letters = letters + 1
        # If there is at least 1 letter found, means there is 1 word
        if (letters == 1):
            words = 1
    elif (ord(text[i]) == 32):
        words = words + 1
    elif(ord(text[i]) == 33 or ord(text[i]) == 63 or ord(text[i]) == 46):
        sentences = sentences + 1

# What's the average number of letters per 1 word
avg_letters = letters / words
L = avg_letters * 100

# What's the average number of sentences per 1 word
avg_sentences = sentences / words
S = avg_sentences * 100

# Coleman-Liau formula
index = round(0.0588 * L - 0.296 * S - 15.8)

# Print result
if (index >= 16):
    print(f"Grade 16+")
elif(index < 1):
    print(f"Before Grade 1")
else:
    print(f"Grade {index}")
