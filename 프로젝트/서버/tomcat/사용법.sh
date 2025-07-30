# 서버 실행하고 7777 포트로 접속
./bin/startup.sh
./bin/shutdown.sh

# 자바 폴더를 못찾는 경우에 실행
echo "export JAVA_HOME=$(dirname $(dirname $(readlink -f $(which javac))))" >> ~/.bashrc