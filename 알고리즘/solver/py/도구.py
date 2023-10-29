#소수 판별

def isPrime(n):
    if n==1: return False
    for i in range(2,n): 
        if not(n%i): return False
    return True


# x + A*(x<B) - D
# =
