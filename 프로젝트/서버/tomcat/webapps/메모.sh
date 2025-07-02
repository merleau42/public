# 자바 폴더를 못찾는 경우에 실행
echo "export JAVA_HOME=$(dirname $(dirname $(readlink -f $(which javac))))" >> ~/.bashrc