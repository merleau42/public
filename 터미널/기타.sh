#	~/.bashrc 마지막에 다음을 입력.
#	명령어 qq를 입력하면 마지막으로 작업한 폴더로 이동함.

vim ~/.bashrc
export PROMPT_COMMAND="export PROMPT_COMMAND='pwd > ~/.last_dir'"
alias zz='cd "$(<~/.last_dir)"'