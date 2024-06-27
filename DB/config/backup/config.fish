export PS1='\[\033[01;31m\]\w\[\033[00m\]\$ '

export dev="~/dev/DB";
export FT="~/dev/DB/42";
export out="~/goinfre/out.out";
export FLAGS="-Werror -Wextra -Wall";

export msg_d="깃허브 git add, GIT PULL, git push는 여기서";
export msg_r="git clone 해서 폴더 만들기 -- 내부에서 작업하기";
export msg_R="제출시 git ls-files 확인. git set_url 리트주소";
alias warn="echo 업로드가 끝날 때까지 터미널을 닫지마세요";

export NAME="미니민희톡";

alias d="clear; cd $dev; echo $msg_d; pwd; ls";
alias e="clear; cd $dev/exercises; pwd; ls";
alias alc="clear; cd $dev/알고리즘/c; pwd; ls";

alias f="clear; cd $FT/finish; pwd; ls";
alias r="clear; cd $FT/rendu; echo $msg_r; pwd; ls";
alias R="clear; cd $FT/rendu/$NAME; echo $msg_R; pwd; ls";
alias m="clear; cd $FT/machine; pwd; ls";

alias fre="clear; cd ~/goinfre";
alias tree="pwd && find . | sed -n '2~1p' | grep '\/\.' -v  | sed 's/[^\/]\+\?\//\//g' | sed 's/\/\([^\/]\)/└─\1/g' | sed 's/\//  /g'";
alias tree2="pwd && du -ha | grep '\/\.' -v | sed 's|\(.\+\)\t\(.\+\)|\2   \(\1\)|' | sort | sed 's/[^\/]\+\?\//\//g' | sed 's/\/\([^\/]\)/└─\1/g' | sed 's/\//  /g'";

alias g="clear; pwd; warn; git add .; date | sed 's/ [AP]M.\+//' | tr ' ' '_' | xargs git commit -m; git push";
alias z="d; g; cd -";
alias ㅋ="d; g; cd -";
alias x="clear";
alias ㅌ="clear";

alias c="clear; cc $FLAGS *.c -o $out";
alias sc="clear; cc $FLAGS $FT/integrate/$NAME.c -o $out";
alias ec="clear; cc $FLAGS $dev/exercises/*.c -o $out";
alias ecc="clear; cc $dev/exercises/*.c -o $out";

alias a="clear; $out";

echo "메일주소 복사 : keunykim@student.42gyeongsan.kr";
echo "진행중인 과제 : $NAME";

# ----심볼릭 링크
# 피쉬 :: ~/.config/fish/config.fish
# 배쉬 :: ~/.bashrc
# ----배쉬
# 원본 PS1='\[\]\s-\v\$ \[\]'
# 구문 :: \[ 부터 \] 까지
# 색상넣기 :: \033
# 색상값 :: [0;00m]z
# -----if status is-interactive <동작> end
# 터미널 명령어로서 fish가 아니라, 콘솔로서의 fish를 실행할때 동작하는 내용.. 이지만 지웠음