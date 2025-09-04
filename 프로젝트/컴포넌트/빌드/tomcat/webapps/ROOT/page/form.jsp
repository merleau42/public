<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8" %>

<!DOCTYPE html>
<html>
<head>
    <meta charset="UTF-8">
    <title>제목</title>
</head>
<body>
    <p>이름과 나이를 입력하세요.</p>
    <form method="post" action="/page/profile.jsp">
        <p>이름 : <input type="text" name="name"></p>
        <p>나이 : <input type="text" name="age"></p>
        <input type="submit" value="입력완료">
    </form>
</body>
</html>
