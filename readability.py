from cs50 import get_string

text = get_string("Text: ")

letters = 0
words = 1
sentences = 0

for i in range(len(text)):
    if text[i].isalpha():
        letters += 1

    if text[i].isspace():
        words += 1

    if text[i] == '.' or text[i] == '!' or text[i] == '?':
        sentences += 1

l = letters / words * 100
s = sentences / words * 100
index = 0.0588 * l - 0.296 * s - 15.8
index = round(index)

if index >= 1 and index <= 16:
    print(f"Grade {index}")
else:
    if index < 1:
        print("Before Grade 1")
    if index > 16:
        print("Grade 16+")
