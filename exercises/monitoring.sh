vi /root/monitoring.sh
apt install sysstat

# 현재 시스템의 아키텍처 정보를 출력하기
# uname ㅡ 커널(Linux) 호스트(kky) 배포판(6.1.0-amd) 커널버전(#상세) 아키텍쳐(x86_64) 운영체제(GNL/Linux)
printf "#Architecture: "
uname -a

# /proc/cpuinfo ㅡ 시스템에 있는 모든 프로세서(코어)의 정보가 담긴 파일. 프로세서마다 한 문단씩 차지함.
printf "#CPU physical : "
cat /proc/cpuinfo | grep "^physical id" | wc -l

printf "#vCPU : "
cat /proc/cpuinfo | grep "^processor"   | wc -l

# free ㅡ 시스템의 메모리 정보를 알려줌. --mega 옵션은 메모리를 MB단위로 보여줌.
# Mem이라는 문자열을 포함하는 행을 찾음. $2는 전체 메모리 용량. $3은 사용중인 메모리 용량.
printf "#Memory Usage: "
free --mebi | grep Mem | awk '{printf "%d/%dMB (%.2f%%)\n", $3, $2, $3/$2 * 100}'

# df ㅡ 파일 시스템 / 사용 가능한 용량(capa) / 사용 중인 용량(used) / 남은 용량 / 마운트 포인트를 알려줌.
# 옵션을 따로 주지 않으면 KiB 단위로 보여줌. (키비바이트, 1024의 거듭제곱)
# awk는 모든 줄에서 동일한 명령을 실행하고, 마지막에는 END 이후의 명령을 실행함
printf "#Disk Usage: "
df | grep /dev/mapper/ | awk '{used+=$3; cap+=$2} END {printf "%d/%dGb (%d%%)\n", used/1024, cap/1024^2, used/cap*100}'

# mpstat은 각 CPU 코어의 사용률을 보여주는 명령어. 마지막 idle은 놀고있는 비율을 의미함.
printf "#CPU load: "
mpstat | grep all | awk '{printf "%.2f%%\n", 100-$NF}'

# who는 현재 시스템에 로그인한 사용자를 보여주는 명령어. -b옵션은 시스템 부팅 시간을 보여줌.
printf "#Last boot: "
who -b | sed -E 's/\s+system boot\s+//'

# lsblk에서 lvm에 해당하는 라인 갯수를 셈
printf "#LVM use: "
lsblk | grep lvm | wc -l | sed -E 's/.*[1-9].*/yes/' | sed -E 's/0+/no/'

# ss --tcp는 TCP 연결을 보여줌. 이 중에서 올바르게 승인된 것을 ESTAB 이라고함.
printf "#Connections TCP : "
ss --tcp | grep ESTAB | wc -l | awk '{printf "%d ESTABLISHED\n", $1}'

# who는 현재 시스템에 로그인한 사용자를 보여주는 명령어이다. 해당 라인줄을 세어서 보여주는 명령어이다.
printf "#User log: "
who | wc -l

# ip link show는 시스템에 설치된 네트워크 인터페이스의 정보를 출력하는 명령어이다.
# 첫번째 필드가 "link/ether" 인 라인의 두번째 필드를 출력한다.
# 여기서 "link/ether"는 이더넷 인터페이스의 물리적 주소를(MAC) 나타내는 키워드이다.
printf "#Network: IP "
hip=$(hostname -I)
mac=$(ip a | sed -E 's/^[0-9]+: +/뷁/' | tr -d '\n' | tr '뷁' '\n' | grep $hip | sed -E 's/.+ether ([^ ]+?).+/\1/')
printf "${hip}(${mac})\n"

# journalctl을 써보려고 했지만, 불필요한 라인을 걸러내야해서 다른 방법을 찾아봄.
printf "#Sudo : "
journalctl _COMM=sudo | grep COMMAND | grep TSID= | wc -l | awk '{printf "%d cmd\n", $1}'
# journalctl _COMM=sudo | grep COMMAND | grep -v 'user NOT in sudoers' | wc -l | awk '{printf "%d cmd\n", $1}'
# ls -lR /var/log/sudo | grep 'log$' | wc -l | awk '{printf "%d cmd\n", $1}'




###############################

#파일에 실행 권한을 추가
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
터미널에서 cd /goinfre/intra id/vm 이름으로 가상머신이 설치된 폴더로 진입
shasum vm이름.vdi 를 실행
잠시 기다리면 가상머신의 서명이 나옴
여러차례 실행하면서 바뀌는지 확인
shasum vm이름.vdi > signature.txt 에 넣고 git push 해서 평가준비

https://velog.io/@joonpark/Born2BeRoot
https://velog.io/@kyj93790/Born2beroot-4.-Vim-%EC%84%A4%EC%B9%98-%EB%B0%8F-SSH-%EC%84%A4%EC%A0%95
https://velog.io/@tmdgks2222/42seoul-born2beroot-cron-monitoring.sh
https://velog.io/@kyj93790/Born2beroot-6.-%EC%8B%9C%EC%8A%A4%ED%85%9C-%EC%A0%95%EB%B3%B4-%EC%B6%9C%EB%A0%A5-cron-tab
https://velog.io/@garoulata/Born2beRoot
