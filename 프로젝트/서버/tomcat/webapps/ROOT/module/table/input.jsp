<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8" %>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>숫자 반복</title>
</head>
<body>
    <h2>반복 수행할 숫자를 입력하세요.</h2>

    <form method="post" action="/module/table/table.jsp">
        반복할 숫자 입력: <input type="text" name="repeat"><br>
        <input type="submit" value="입력완료">
    </form>
</body>
</html>