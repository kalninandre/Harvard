def main():

    # Gets the input text
    text = get_user_text()

    # Counts the quantity of letters
    letters = get_letters(text)

    # Counts the quantity of sentences
    sentences = get_sentences(text)

    # Counts the quantity of words
    words = get_words(text)

    # Define the grande level
    grade = get_grade(letters, sentences, words)

    # Prints grade if between 1 and 16
    if grade <= 1:
        print('Before Grade 1')

    elif grade >= 16:
        print('Grade 16+')

    else:
        print(f'Grade {round(grade)}')


def get_user_text():
    while True:
        n = str(input("Text: "))

        if len(n) > 0:
            break
    return list(n)


def get_letters(text):

    letter_counter = 0

    for i in text:
        if i.isalpha():
            letter_counter += 1

    return letter_counter


def get_sentences(text):

    sentence_counter = 0

    for j in text:
        if j in ['.', '!', '?']:
            sentence_counter += 1

    return sentence_counter


def get_words(text):

    word_counter = 0

    for k in text:
        if k == " ":
            word_counter += 1

    return word_counter + 1


def get_grade(letters, sentences, words):

    l = (letters / words) * 100
    s = (sentences / words) * 100

    grade = (0.0588 * l) - (0.296 * s) - 15.8

    return grade


if __name__ == '__main__':
    main()