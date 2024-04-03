if status is-interactive
	# 하드링크: ~/789ff
	export dev="~/dev";
	export 42="~/dev/42";
	export out="~/goinfre/out.out";
	export FLAGS="-Werror -Wextra -Wall";
	
	export NAME="libft";

	alias d="clear; cd $dev; pwd; ls";
	alias r="clear; cd $42/rendu; pwd; ls";
	alias R="clear; cd $42/rendu/$NAME; pwd; ls";
	alias e="clear; cd $dev/exercise; pwd; ls";

	alias g="clear; git add .; git commit -m 'commit'; git push";

	alias c="clear; cc $FLAGS *.c -o $out";
	alias sc="clear; cc $FLAGS $42/integrate/$NAME.c -o $out";
	alias ec="clear; cc $FLAGS $dev/exercises/*.c -o $out";

	alias a="clear; $out";

end