if status is-interactive
	# 심볼릭 링크: ~/.config/fish/config.fish
	export dev="~/dev";
	export 42="~/dev/42";
	export out="~/goinfre/out.out";
	export FLAGS="-Werror -Wextra -Wall";

	export msg_d="깃허브 git add, git push는 여기서";
	export msg_r="git clone 해서 폴더 만들기 -- 내부에서 작업하기";
	export msg_R="제출시 git ls-files 확인. git set_url 리트주소";
	
	export NAME="get_next_line";

	alias d="clear; cd $dev; echo $msg_d; pwd; ls";
	alias r="clear; cd $42/rendu; echo $msg_r; pwd; ls";
	alias R="clear; cd $42/rendu/$NAME; echo $msg_R; pwd; ls";
	alias e="clear; cd $dev/exercises; pwd; ls";

	alias g="clear; git add .; date | sed 's/ [AP]M.\+//' | tr ' ' '_' | xargs git commit -m
; git push";

	alias c="clear; cc $FLAGS *.c -o $out";
	alias sc="clear; cc $FLAGS $42/integrate/$NAME.c -o $out";
	alias ec="clear; cc $FLAGS $dev/exercises/*.c -o $out";

	alias a="clear; $out";

	echo "진행중인 과제: $NAME";
end