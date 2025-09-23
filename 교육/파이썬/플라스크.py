# 터미널에서 [ python ]대신 [ ./.venv/bin/python ]으로 실행
from flask import Flask, request
app = Flask(__name__)


#! GET
@app.route("/")
def hello():
	return "Hello, Flask!\n"

@app.route("/movie", methods=['GET'])
def get_movie():
	return "영화 정보 조회\n"

@app.route("/movie/<movie_id>", methods=['GET'])
def get_movie_by_id(movie_id):
	return f'영화 정보 조회: {movie_id}\n'


#! PUT
@app.route("/movie/<movie_id>", methods=['PUT'])
def update_movie(movie_id):
	data=request.get_json()
	print(data)
	return f'영화 정보 수정 완료!\n'


#! POST
@app.route("/movie", methods=['POST'])
def add_movie():
	data=request.get_json()
	print(data)
	return f'영화 정보 추가 완료!\n'


#! DELETE
@app.route("/movie/<movie_id>", methods=['DELETE'])
def delete_movie():
	print(data)
	return f'영화 정보 삭제 완료!\n'


#! 기타
if __name__ == '__main__':
	app.run(debug=True)


#! curl 사용법
"""	#: POST
clear;
curl -X POST http://127.0.0.1:5000/movie \
		-H "Content-Type: application/json" \
		-d '{"title":"Inception"}'
"""

