using namespace std;
#include <bits/stdc++.h>
#define INF 987654321
#define ROW 250
#define COL 250
//https://www.acmicpc.net/problem/

int r, c, h;			// 행렬 규모
int grid[ROW][COL];		// 행렬의 상황을 매핑
int vist[ROW][COL];		// 좌표의 방문 여부나, 재방문 횟수-1

int dist[ROW][COL];		// 좌표까지 최단 거리 (이동 횟수, 노드의 level)
int depth;				// 가장 멀리 도달한 거리 (이동 횟수)

// 각각의 연결 요소에 담겨있는 좌표의 유형과 갯수
map<int, map<int,int>> connected; 

int meet;				// 새로 방문한 노드의 수
int Rank[ROW][COL];		// 좌표가 최초로 방문된 순서

int name;				// 탐색 중인 연결 요소의 이름
int band[ROW][COL]; 	// 좌표가 소속된 연결 요소

void init(){
	connected.clear();
	fill(&vist[0][0], &vist[0][0] + ROW*COL, 0);
	fill(&dist[0][0], &dist[0][0] + ROW*COL, -1);
	fill(&Rank[0][0], &Rank[0][0] + ROW*COL, 0);
}

struct Point {		// 좌표
	int y, x, z;

	// 인접 좌표를 생성하는 덧셈 연산 (좌표+방향=인접)
	Point operator+(const Point &cursor) const{
		return {this->y+cursor.y, this->x+cursor.x} ;
	}
};

Point Start;	// 시작점
Point Final;	// 목적지
vector<Point> StartGroup;	// 시작점 그룹

// 인접성의 기준 (탐색할 좌표를 생성하는 기준)
Point adjacent[] = { {1,0}, {-1,0}, {0,1}, {0,-1} };

// 통로와 장애물 기호
set<int> startable;
set<int> passable;
set<int> obstacle;

void draw(int arr[ROW][COL], int beg=0) {
	cout << "\n\n\n";
	for (int i=beg; i<r+beg; i++) {
		for (int j=beg; j<c+beg; j++) {
			cout << arr[i][j] << '\t';
		}
		cout << '\n';
	}
}

void draw_collection(string option="int"){
	cout << "\n\n\t";
	for (auto i: connected[0]){
		cout << "│연결" << i.first << '\t';
	}

	set<int> item;
		for (auto i: connected)
			if (i.first > 0)
				for (auto j: i.second)
					item.insert(j.first);

	for (auto kind: item){
		cout << "\n";
		if (option=="int") cout << kind << '\t';
		if (option=="char") cout << (char)kind << '\t';
		for (auto i: connected[0]){
			cout << "│" << connected[i.first][kind]
				 << "\t";
		}
	}

	cout << "\n───────\t";
	for (auto i: connected[0])
		cout << "┼──────\t";

	cout << "\n갯수\t";
	for (auto i: connected[0])
		cout << "│" << i.second << '\t';
}


// 탐색 예약 배제 ㅡ 비정상적인 좌표
bool insane(Point next){
	return	 !(0 <= next.y && next.y < r
			&& 0 <= next.x && next.x < c);
}

// 특정 원소가 컨테이너에 존재하는지 확인
template<typename T> bool FIND(int thing, T _list){
	return _list.find( thing ) != _list.end();
}

void BFS(queue<Point> &reserve);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

	// 테스트 케이스의 갯수
	int T=1;

	while(T--){
		// 행렬의 규모를 입력
		cin >> r >> c;

		// 배열 초기화
		init();

		// 방문할 좌표가 예약되는 스케쥴
		queue<Point> reserve;

		// 통로, 장애물, 재화의 기호를 정의
		startable = {'o', 'v'};
		passable = {'o', 'v', '.'};
		obstacle = {'#'};

		// 지도를 매핑하기
		for (int i=0; i<r; i++){
			for (int j=0; j<c; j++){
				// 다닥다닥 붙어서 지도가 주어지는 경우
				char tmp;
				cin >> tmp;
				grid[i][j]=tmp;

				// 의미있는 좌표를 표집
				if ( FIND(grid[i][j], startable) )
					StartGroup.push_back( {i, j} );
			}
		}

		// 개선 ㅡ 시작 그룹의 좌표로 개별 출발 (연결 요소)
		for (Point e: StartGroup) {
			int i = e.y,  j = e.x;
			if ( vist[i][j] ) continue;
			reserve.push( {i, j} );
			dist[i][j]=0;
			vist[i][j]=0;
			meet=0;
			depth=0;
			name++;
			BFS( reserve );
			connected[0][name] = meet;
			draw(band);
			draw_collection("char");
		}

		// 모든 방문을 마치고, 수집품으로 로직 작성
		int sheep=0, wolf=0;
		for (auto e: connected) {
			if (e.first == 0) continue;
			if (e.second['v'] >= e.second['o'])
				wolf += e.second['v'];
			else
				sheep += e.second['o'];
		}
		cout << sheep << ' ' << wolf;
	}
	
	return 0;
}

void BFS(queue<Point> &reserve){
	// 시작점으로 부터 방문 시작 ㅡ 예약이 없어질때까지 방문
	while ( !reserve.empty() ) {
		// 좌표를 방문하여 현재 위치를 갱신
		// 방문한 좌표를 스케쥴에서 제거하기
		Point current = reserve.front();
		reserve.pop();

		// 이미 방문했다면 즉시 떠나고, 처음이면 방문 기록
		if ( vist[current.y][current.x]++ )
			continue;

		// 최초의 방문에서 할 일
		meet++;

		// 동일 레벨 중에서도 해당 노드에만 적용될 작업
		Rank[current.y][current.x] = meet;
		band[current.y][current.x] = name;
		connected[name][grid[current.y][current.x]]++;

		// 목적지에 방문하였다면?
		if (current.x == Final.x && current.y == Final.y) {
			// 뭔가를 하거나 break;
		}

		// 인접 좌표를 생성 ㅡ for문을 깨서 직접 설정도 가능
		vector<Point> preview;
		for ( Point dir : adjacent) {
			preview.push_back( current + dir );
		}

		// 다음 레벨 탐색 ㅡ 현재 위치와 인접하는 좌표를 방문 예약
		for ( Point next : preview) {
			// 인접 좌표의 스케쥴 편입 여부를 검사 (예시)
			// ㅡ 인접 좌표가 비정상적인 좌표라면 탈락
			// ㅡ 인접 좌표의 최단 거리가 이미 평가되었다면 탈락
			// ㅡ 인접 좌표가 장애물/용암/벽 등 통제 구역이라면 탈락
			if ( insane(next) )  continue;
			if ( dist[next.y][next.x] != -1 )  continue;
			if ( FIND(grid[next.y][next.x], obstacle) )  continue;
			
			// 인접 좌표가 모든 검열을 통과함
			// 인접 좌표에 (=다음 레벨 모든 좌표에) 적용시킬 내용
			dist[next.y][next.x] = dist[current.y][current.x] + 1;
			depth = dist[next.y][next.x];

			// 인접 좌표를 방문 예약
			reserve.push( next );
		}
	}
}