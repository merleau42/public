# 터미널의 java 폴더에서 실행할 것.
# 링킹-컴파일하여 자바 코드를 작동하고, 지저분한 .class 파일들 제거함
clear; javac pkgs/*.java practice/Flow.java; java pkgs.Main; rm pkgs/*.class practice/*.class