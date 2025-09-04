<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8" %>
<% request.setCharacterEncoding("UTF-8"); %> // 한글깨짐 방지
<!DOCTYPE html>
<html>
<head>
    <meta charset="UTF-8">
    <title>회원 정보 페이지</title>
</head>
<body>
    <%
        String name = request.getParameter("name");
        int age = Integer.parseInt( request.getParameter("age") );
    %>
    <p>회원님의 이름은 <%=name%> 입니다.</p>
    <p>회원님의 나이는 <%=age%> 입니다.</p>
</body>
</html>
