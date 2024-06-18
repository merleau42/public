apt install sysstat
vi /root/monitoring.sh

# 1. 현재 시스템의 아키텍처 정보를 출력하기
# uname ㅡ 아키텍처, 운영체제, 호스트명, 커널 버전 등을 알려줌.
# uname ㅡ 운영체제(-s), 아키텍처(-p)
printf "#Architecture: "
uname -a

# nrpoc ㅡ 시스템에서 사용가능한 프로세서의 수를 알려줌. --all 옵션은 모든 프로세서 수를 알려줌.
printf "#CPU physical : "
nproc --all

# /proc/cpuinfo ㅡ 시스템에 있는 모든 프로세서(코어)의 정보가 담긴 파일. 프로세서마다 한 줄씩 차지함.
printf "#vCPU : "
cat /proc/cpuinfo | grep processor | wc -l

# free ㅡ 시스템의 메모리 정보를 알려줌. -m 옵션은 메모리를 MB단위로 보여줌.
# Mem이라는 문자열을 포함하는 행을 찾음. $2는 전체 메모리 용량. $3은 사용중인 메모리 용량.
printf "#Memory Usage: "
free -m | grep Mem | awk '{printf"%d/%dMB (%.2f%%)\n", $3, $2, $3/$2 * 100}'

# df ㅡ 파일 시스템 별로 사용 가능한 디스크 용량, 사용량, 사용하지 않는 용량, 마운트된 디렉터리를 알려줌.
# -a 옵션은 모든 파일 시스템을 출력, -BM 옵션은 블록 사이즈를(-B) 메가바이트(-M) 단위로 보여줌
# $3 필드는 사용 중인 용량, $4 필드는 사용 가능한 용량
# END는 awk 명령어의 마지막 줄을 처리하기 전에 실행되는 블록을 지정
printf "#Disk Usage: "

# /dev/mapper/로 시작하는 파일시스템의 사용 중인 디스크 용량을 합산하여 출력
df -aBM | grep /dev/mapper/ | awk '{sum+=$3}END{print sum}' | tr -d '\n'
printf "/"

# 현재 시스템에서 사용 가능한 디스크 공간의 총합을 출력한다.
df -aBM | grep /dev/mapper/ | awk '{sum+=$4}END{print sum}' | tr -d '\n'
printf "MB ("

# 앞선 필드3의 합과, 앞선 필드4의 합을 다시 구해서, (필드3합)/(필드4합)을 출력한다
df -aBM | grep /dev/mapper/ | awk '{sum1+=$3 ; sum2+=$4 }END{printf "%d", sum1 / sum2 * 100}' | tr -d '\n'
printf "%%)\n"


#mpstat은 각 CPU 코어의 사용률과 각 코어의 평균 사용률을 보여주는 명령어이다.
#$13은 CPU 사용률을 의미한다. 즉 100-$13은 CPU 유휴 시간의 백분율을 표시하는 것이다.
printf "#CPU load: "
mpstat | grep all | awk '{printf "%.2f%%\n", 100-$13}'


# who는 현재 시스템에 로그인한 사용자를 보여주는 명령어이다. -b옵션은 시스템 부팅 시간을 보여주는 명령어이다. 여기엔 "system boot"라는 문자열이 포함되어 있다.
# 이를 해결하기 위해 sed명령어를 사용하는 것이며 해당 명령어는 원하는 부분만 출력 및 변호나하는데 사용한다. 여기선 공백으로 치환하는 역할을 한다
printf "#Last boot: "
who -b | awk '{printf $3" "$4"\n"}'


# lsblk는 lvm을 사용하는 블록 디바이스가 있는지 확인하는 것이다.
# -gt은 왼쪽에 있는 값이 오른쪽에 있는 값보다 크면 참을 반환하는 비교 연산자이다.
printf "#LVM use: "
if [ "$(lsblk | grep lvm | wc -l)" -gt 0 ] ; then printf "yes\n" ; else printf "no\n" ; fi


# ss는 소켓 정보를 보여주는 명령어이다. -tunpl은 TCP/UDP 소켓 정보를 상세히 보여주는 옵션이다.
printf "#Connections TCP : "
ss | grep -i tcp | wc -l | tr -d '\n'
printf " ESTABLISHED\n"


# who는 현재 시스템에 로그인한 사용자를 보여주는 명령어이다. 해당 라인줄을 세어서 보여주는 명령어이다.
printf "#User log: "
who | wc -l


# 현재시스템의 IP 주소를 개행 없이 출력하는 명령어이다.
# ip link show는 시스템에 설치된 네트워크 인터페이스의 정보를 출력하는 명령어이다.
# 그 후는 출력된 결과 중에서, 첫 번째 필드가 "link/ether"인 라인의 두번째 필드를 출력한다. 여기서 "link/ether"는 이더넷 인터페이스의 물리적 주소(MAC 주소)를 나타내는 키워드이다.
printf "#Network: IP "
hostname -I | tr -d '\n'
printf "("
ip link show | awk '$1 == "link/ether" {print $2}' | sed '2, $d' | tr -d '\n'
printf ")\n"


# journalctl은 systemd의 로그 시스템인 journald에서 저장된 로그를 검색하고 출력하는 유틸리티이다. 이는 전통적인 로그 파일 대신 바이너리 파일 형식으로 로그를 저장하고, 이를 검색하기 위해 journalctl을 사용할 수 있다.
# _COMM=sudo를 추가함으로써 _COMM필드가 sudo인 로그 메시지를 검색할 수 있도록 한다.
printf "#Sudo : "
journalctl _COMM=sudo | wc -l | tr -d '\n'
printf " cmd\n"




###############################



#파일에 실행 권한을 추가하는 명령어이다.
chmod +x monitoring.sh 

# cron은 리눅스에서 백그라운드에서 동작하는 작업 스케줄러이다.
# -e옵션은 현재 사용자의 cron 작업을 편집 모드로 열어주는 옵션이다.
crontab -e
*/10 * * * * /root/monitoring.sh | wall



##############################
groupadd user42
usermod -aG sudo,user42 <사용자이름>
usermod -g user42 <사용자이름>


vm을 상태 저장하면서 종료
스냅샷을 남긴다.
터미널에서 cd /goinfre/intra id/vm이름 으로 가상머신이 설치된 폴더로 진입
shasum vm이름.vdi 를 실행
잠시 기다리면 가상머신의 서명이 나옴
여러차례 실행하면서 바뀌는지 확인
shasum vm이름.vdi > signature.txt 에 넣고 git push 해서 평가준비



https://velog.io/@joonpark/Born2BeRoot

https://velog.io/@kyj93790/Born2beroot-4.-Vim-%EC%84%A4%EC%B9%98-%EB%B0%8F-SSH-%EC%84%A4%EC%A0%95

https://velog.io/@tmdgks2222/42seoul-born2beroot-cron-monitoring.sh

https://velog.io/@kyj93790/Born2beroot-6.-%EC%8B%9C%EC%8A%A4%ED%85%9C-%EC%A0%95%EB%B3%B4-%EC%B6%9C%EB%A0%A5-cron-tab

https://velog.io/@garoulata/Born2beRoot