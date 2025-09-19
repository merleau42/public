class Movie:
    def __init__(self): #생성자
        self.title='아바타' #멤버변수
        self.rating=9.3 #멤버변수
        self.running=130 #멤버변수
    def show_info(self): #정보출력함수
        print("제목:",self.title)
        print("평점:", self.rating)
        print("러닝타임:", self.running)

m = Movie()#Movie객체 생성
m.show_info()#객체내부의 함수 호출