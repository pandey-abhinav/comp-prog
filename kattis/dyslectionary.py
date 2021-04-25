from sys import stdin, stderr, maxsize

words = []

def printd(*args, **kwargs):
  print(f"==> DEBUG :[{args}]", file=stderr)

def custom_print(words):
    p = 0
    for word in words:
        p = max(p, len(word))
    for word in words:
        print(word.rjust(p))

def process(words):
    printd(words)
    words = sorted(words, key = lambda x: x[len(x)::-1])
    printd(words)
    custom_print(words)

for i in stdin:
    word = i.split()
    if word != []:
        words.append(word[0])
    if word == []:
        process(words)
        words = []
        print()

process(words)
