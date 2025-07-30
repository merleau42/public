<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8" %>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>로그인폼</title>
</head>
<body>
    <h2>아이디와 패스워드를 입력하세요.</h2>

    <form method="post" action="/module/login/login.jsp">
        아이디: <input type="text" name="id"><br>
        비밀번호: <input type="password" name="pw"><br>
        <input type="submit" value="입력 완료">
    </form>
</body>
</html>