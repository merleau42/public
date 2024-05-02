if status is-interactive
	# 심볼릭 링크: ~/.config/fish/config.fish
	export dev="~/dev";
	export 42="~/dev/42";
	export out="~/goinfre/out.out";
	export FLAGS="-Werror -Wextra -Wall";

	export msg_d="깃허브 git add, git push는 여기서";
	export msg_r="git clone 해서 폴더 만들기 -- 내부에서 작업하기";
	export msg_R="제출시 git ls-files 확인. git set_url 리트주소";
	export msg_w="완료될 때까지 터미널을 닫지마세요";
	alias warn="echo $msg_w";
	
	export NAME="get_next_line";

	alias d="clear; cd $dev; echo $msg_d; pwd; ls";
	alias e="clear; cd $dev/exercises; pwd; ls";
	alias b="clear; cd $dev/알고리즘/c; pwd; ls";

	alias f="clear; cd $42/finish; pwd; ls";
	alias r="clear; cd $42/rendu; echo $msg_r; pwd; ls";
	alias R="clear; cd $42/rendu/$NAME; echo $msg_R; pwd; ls";
	alias m="clear; cd $42/machine; pwd; ls";

	alias fre="clear; cd ~/goinfre";

	alias g="clear; warn; git add .; warn; date | sed 's/ [AP]M.\+//' | tr ' ' '_' | xargs git commit -m
; warn; git push";
	alias z="d; g";

	alias c="clear; cc $FLAGS *.c -o $out";
	alias sc="clear; cc $FLAGS $42/integrate/$NAME.c -o $out";
	alias ec="clear; cc $FLAGS $dev/exercises/*.c -o $out";

	alias a="clear; $out";

	echo "메일주소 복사 : keunykim@student.42gyeongsan.kr";
	echo "진행중인 과제 : $NAME";
end