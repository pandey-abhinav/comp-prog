from sys import stdin, stderr, maxsize

def printd(*args, **kwargs):
    v = repr(*args)
    print(F"==> DEBUG : {v}", file=stderr)

if __name__ == "__main__":
    printd("Hello, World!")
