import re

def main():
    text = input("Text: ")

    grade = determineGrade(ammountOfLetters(text), ammountOfWords(text), ammountOfSentences(text))

    print(f"Grade: {grade}")
    print()

def ammountOfLetters(text):
    counter = sum(1 for letter in text if letter.isalpha())
    return counter

def ammountOfWords(text):
    return len(text.split(" "))

def ammountOfSentences (text):
    return len(list(filter(lambda x:  x != "", re.split(r"[.?!]",text))))

def determineGrade (letters, words, sentences):
    L = (letters/words)*100

    S = (sentences/words)*100

    grade = round(0.0588*L - 0.296*S - 15.8)

    if grade > 16 :
        grade = "16+"

    elif grade < 1 :
        grade = "Before Grade 1"

    return grade

main()
