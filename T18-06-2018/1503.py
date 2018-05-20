from hashlib import md5

def search(s, sub): #rabin karp string pattern search
    n, m = len(s), len(sub)
    hsub_digest = md5(sub.encode('utf-8')).digest()
    offsets = []
    if m > n:
        return offsets

    for i in range(n - m + 1):
        if md5(s[i:i + m].encode('utf-8')).digest() == hsub_digest:
            if s[i:i + m] == sub:
                offsets.append(i)

    return offsets

def palindromeSubStrs(s): #based on manacher algorithm
    m = dict()
    n = len(s)

    R = [[0 for x in range(n + 1)] for x in range(2)]

    s = "@" + s + "#"

    for j in range(2):
        rp = 0
        R[j][0] = 0

        i = 1
        while i <= n:

            while s[i - rp - 1] == s[i + j + rp]:
                rp += 1

            R[j][i] = rp
            k = 1
            while (R[j][i - k] != rp - k) and (k < rp):
                R[j][i + k] = min(R[j][i - k], rp - k)
                k += 1
            rp = max(rp - k, 0)
            i += k

    s = s[1:len(s) - 1]

    m[s[0]] = 1
    for i in range(1, n):
        for j in range(2):
            for rp in range(R[j][i], 0, -1):
                m[s[i - rp - 1: i - rp - 1 + 2 * rp + j]] = 1
        m[s[i]] = 1

    return sorted(list(m.keys()), key=len, reverse=True)

while True:
    try:
        t = int(input())
        found = False
        m = {}
        strings = []
        for k in range(t):
            strings.append(input())
        strings.sort(key=len)
        subs = palindromeSubStrs(strings[0])
        if not len(subs):
            print(0)
        else:
            for sub_palin in subs:
                m[sub_palin] = 1
                for string in strings:
                    if len(search(string, sub_palin)):
                        m[sub_palin] += 1
                    if m[sub_palin] == len(strings):
                        print(len(sub_palin))
                        found = True
                        break
                if found:
                    break
        if not found:
            print(0)
    except EOFError:
        break

