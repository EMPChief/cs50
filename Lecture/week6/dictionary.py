word_set = set()

def check_word(word):
    return word.lower() in word_set

def load(dictionary):
    with open(dictionary) as f:
        word_set.update(f.read().split())
    return True

def size():
    return len(word_set)

def unload():
    return True

