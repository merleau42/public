<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8" %>

<% request.setCharacterEncoding("UTF-8"); %>

<%
    int repeat = Integer.parseInt( request.getParameter("repeat") );
%>

<h2 align="center">입력한 숫자만큼 반복수행</h2>
<table border="1" style="margin: 0 auto; width: 30%;">
    <tr align="center" bgcolor="yellow">
        <th>글번호</th>
        <th>글제목</th>
        <th>글내용</th>
    </tr>

    <%
        for (int i = repeat; i > 0; i--) {
    %>
        <tr align="center">
            <td><%=i%></td>
            <td>제목 <%=i%></td>
            <td>내용 <%=i%></td>
        </tr>
    <%
        }
    %>
</table>