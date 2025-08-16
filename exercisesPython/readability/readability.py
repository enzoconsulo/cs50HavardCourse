import re

def main():
    text = input("Text: ")

    grade = determineGrade(ammountOfLetters(text), ammountOfWords(text), ammountOfSentences(text))

    print(f"Grade: {grade}")
    print()

def ammountOfLetters(text):
    counter = 0
    for letter in text:
        if letter.isalpha():
            counter += 1
    return counter

def ammountOfWords(text):
    #i know that is simpler to just verify amount of " " and count to get the number of words, but i choose to separate each word in a vector to train
    words = []
    for i in text.split(" ") :                              # split the input text into substrings, using space (" ") as separator

        words.append("".join(                               # i is the iteratable element(in this case, the word i). x is each element among i
                            filter(lambda x: x.isalpha(),i) #  , so, will apply the function in x and discard the ones where function is == False
                            )                               #   and finally, "join" function group each character and append to words array
                    )
    return len(words)

def ammountOfSentences (text):
    sentences = re.split(r"[.?!]",text)                     # divide input in substrings, using "." , "?" , "!" as separator
    sentences = list(filter(lambda x:  x != "", sentences)) # filter empty elements (to exclude last string in case of ending with a "." , "?" , "!")
    return len(sentences)

def determineGrade (letters, words, sentences):
    L = letters/words
    L *= 100

    S = sentences/words
    S *= 100

    grade = round(0.0588*L - 0.296*S - 15.8)

    if grade > 16 :
        grade = "16+"

    elif grade < 1 :
        grade = "Before Grade 1"

    return grade

main()
