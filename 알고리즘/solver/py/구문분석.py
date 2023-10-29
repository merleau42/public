import nltk
nltk.download('punkt')
nltk.download('averaged_perceptron_tagger')
from nltk import word_tokenize, pos_tag, RegexpParser

# 예제 문장
sentence = "Since cinema was an entirely fantasmatic art, these innovations were completely unnecessary."

# 문장 토큰화 및 품사 태깅
tokens = word_tokenize(sentence)
tagged = pos_tag(tokens)

# 구문 분석을 위한 문법 규칙 정의
grammar = r"""
    NP: {<DT>?<JJ>*<NN>}
    VP: {<VB.*><NP|PP>?}
    PP: {<IN><NP>}
    ADJP: {<JJ>}
    ADVP: {<RB>}
    CONJP: {<CC>}
    INTJ: {<UH>}
    X: {<.*>}  # 다른 모든 형태소
"""

# 문장 분석
tree = RegexpParser(grammar).parse(tagged)

# 트리를 기호로 출력
for subtree in tree.subtrees():
    if subtree.label():
        print(subtree.label(), end=' ')
