printf "#Architecture: "
uname -a

printf "#CPU physical : "
cat /proc/cpuinfo | grep "^physical id" | wc -l

printf "#vCPU : "
cat /proc/cpuinfo | grep "^processor"   | wc -l

printf "#Memory Usage: "
free --mebi | grep Mem | awk '{printf "%d/%dMB (%.2f%%)\n", $3, $2, $3/$2 * 100}'

printf "#Disk Usage: "
df | grep /dev/mapper/ | awk '{used+=$3; cap+=$2} END {printf "%d/%dGb (%d%%)\n", used/1024, cap/1024^2, used/cap*100}'

printf "#CPU load: "
mpstat | grep all | awk '{printf "%.2f%%\n", 100-$NF}'

printf "#Last boot: "
who -b | sed -E 's/\s+system boot\s+//'

printf "#LVM use: "
lsblk | grep lvm | wc -l | sed -E 's/.*[1-9].*/yes/' | sed -E 's/0+/no/'

printf "#Connections TCP : "
ss --tcp | grep ESTAB | wc -l | awk '{printf "%d ESTABLISHED\n", $1}'

printf "#User log: "
who | wc -l

printf "#Network: IP ";
hostname -I | awk '{printf "%s (", $1}'
ip link show | awk '$1 == "link/ether" {print $2}' | sed '2, $d' | tr -d '\n'
printf ")\n"

printf "#Sudo : "
journalctl _COMM=sudo | wc -l | tr -d '\n'
printf " cmd\n"