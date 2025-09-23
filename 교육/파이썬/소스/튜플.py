lst = [1,2,3]
result = type(lst)
print(result) # <class 'list'>

tpl = (1,2,3)
result = type(tpl)
print(result) # <class 'tuple'>lst = [1,2,3]
lst[0]=10

tpl = (1,2,3)
tpl[0]=10
#TypeError: 'tuple' object does not support item assignment
nums = (3,2,5,7,1)
result = len(nums)
print(result)
result = max(nums)
print(result)
result = min(nums)
print(result)
nums = ('A','A','B','C')

result = nums.count('A') #A의 갯수
print(result)

result = nums.index('B') #B의 시작위치
print(result)lst = list(range(1,5))
print(lst) # [1,2,3,4]

tpl = tuple(range(1,5))
print(tpl) # (1,2,3,4)lst = list(range(4,0,-1))
print(lst) # [1,2,3,4]

tpl = tuple(range(4,0,-1))
print(tpl) # (1,2,3,4)