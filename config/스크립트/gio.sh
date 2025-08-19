### 상태 표시줄 버튼 [ ▲github.io ] 스크립트
clear;

time_kst=$(date -u -d '+9 hours' '+%Y-%m-%d_%H:%M:%S');
echo "[실행] ▲github.io\t$time_kst" >> ~/dev/config/스크립트/.log;

WEB=~/dev/프로젝트/웹;
GAME=~/dev/프로젝트/게임;

GIO=~/dev/subtree/github.io;

## [ github.io ]에 업로드할 내용을, 서브 폴더에 복사하기
## 관련 항목을 index.html에 반영할 것 (subtree/github.io/index.html)
# 게임
	LIAR_GAME="$GAME/바닐라JS/라이어게임";
		cp -r "$LIAR_GAME/단어수집기"		"$GIO/게임/라이어게임";
		cp -r "$LIAR_GAME/데이터베이스"		"$GIO/게임/라이어게임";
		cp -r "$LIAR_GAME/리소스"			"$GIO/게임/라이어게임";
		cp -r "$LIAR_GAME/시뮬레이터"		"$GIO/게임/라이어게임";

	GAME_ETC=기타;
		cp -r "$GAME/바닐라JS/빼빼로줍기/"	  "$GIO/게임";
		cp -r "$WEB/끝말잇기/"				 "$GIO/게임";

# 알고리즘
		cp -r "$WEB/양치기/"				"$GIO/알고리즘";
		cp -r "$WEB/코드실행기/"			"$GIO/알고리즘";

# 프론트엔드
		cp -r "$WEB/테이블/스프레드시트/"     "$GIO/프론트엔드";
		cp -r "$WEB/공개API/"				 "$GIO/프론트엔드";

	FRONT_ETC=기타;
		cp -r "$WEB/릴레이/연속변환기/"		  "$GIO/프론트엔드";
		cp -r "$WEB/계산기/"				 "$GIO/프론트엔드";

## 로컬 디렉토리의 전부를, 메인 저장소에 먼저 add/commit/push 시킴.
## 로컬 디렉토리의 일부만 add/commit 해도 되지만, 하나하나 지정하기 번거로움.
clear; cd ~/dev; git add .; git commit -m "▲GIO_$time_kst"; git push;

## 서브 폴더를 [ github.io ]에 push 함.
## 로컬 파일의 삭제 여부가 저장소에는 반영되지 않는 경우 --force 플래그를 사용.
REV=$(git subtree split --prefix=subtree/github.io)
git push https://github.com/merleau42/public $REV:main --force

exit 0;
