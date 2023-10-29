import sys; input=(lambda x=sys.stdin.readline:x().rstrip());
import re

a='bar'
print (re.sub(r'(.)',r'\1.+',a[:-1])+a[-1])