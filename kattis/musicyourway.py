from sys import stdin, stderr, maxsize
from logging import debug
from operator import itemgetter

attributes = input()
attributes = attributes.split()

songs = []
m = input()
for _ in range(int(m)):
    song = input()
    songs.append(song.split())

cmds = []
n = input()
for i in range(int(n)):
    cmd = input()
    cmds.append(cmd)
    idx = attributes.index(cmd)
    print(*attributes)
    songs = sorted(songs, key=itemgetter(idx))
    for song in songs: print(*song)
    if i != int(n)-1 : print()
