st = [1,3,5,7,9]
num = len(st)
print(num)st = [2,5,3,7,4]

result = min(st)
print(result)

result = max(st)
print(result)st = [1,2,3]
st.remove(2)
print(st)st = [1,2,3]
st.append(4) # [1,2,3,4]
st.extend([5,6]) # [1,2,3,4,5,6]
print(st)st = [1,2,4]
     #0 1 2
st.insert(2,3)
#첫번째 값은 추가할 위치, 두번째는 추가할 값
# 1 2 3 4
# 0 1 2 3st = [1,2,3,4]
st.clear()
print(st)st = [1,2,3,4,5]
result=st.pop(0) #0번째 인덱스 데이터 가져온다.
print(result) # 1
print(st) # [2,3,4,5]

st = ['A','B','C','D','E']
result=st.pop(3)
print(result)
print(st)st = ['A','B','C','A','A','B']
result=st.count('A')
print(result)st = ['A','B','C','A','A','B']
result=st.index('B')
print(result)org = "Yoon"
result=org.lower()
print(result)

result=org.upper()
print(result)org = " MIDDLE "
print(org)
result=org.lstrip()
print(org) # " MIDDLE "
print(result) # "MIDDLE "org = " MIDDLE "
print(org)
result=org.rstrip()
print(org) # " MIDDLE "
print(result) # " MIDDLE"
print(result+"HELLO") # " MIDDLEHELLO"org = " MIDDLE "
print(org)
result=org.strip()
print(org) # " MIDDLE "
print(result) # "MIDDLE"
print(result) # "MIDDLE"org="YoonSeongWoo"
rps=org.replace("oo","ee")
#rps="YeenSeongWee"
print(rps)
#문자열 "oo" 를 "ee"로 교체

org="YoonSeongWoo"
rps=org.replace("oo","ee",1)
#rps="YeenSeongWoo"
print(rps)
#문자열 "oo" 를 "ee"로 교체
#(첫번째꺼 1개만 교체)org = "ab_cd_ef"
ret = org.split("_")
print(ret)