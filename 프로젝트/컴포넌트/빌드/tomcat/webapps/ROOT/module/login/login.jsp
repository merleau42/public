<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8" %>

<% request.setCharacterEncoding("UTF-8"); %>

<%
    String id = request.getParameter("id");
    String pw = request.getParameter("pw");

    boolean VID = id.equals("abcd");
    boolean VPW = pw.equals("z1234");

    String result1 = "";
    String result2 = "";

    if (VID && VPW)
        result1 = "로그인 성공";
    if (!VID && VPW)
        result1 = "아이디가 일치하지 않습니다";
    if (VID && !VPW)
        result1 = "비밀번호가 일치하지 않습니다";
    if (!VID && !VPW)
        result1 = "아이디와 비밀번호가 일치하지 않습니다";

    if (VID) {
        if (VPW) 
            result2 = "로그인 성공";
        else
            result2 = "비밀번호가 일치하지 않습니다";
    }
    else
        result2 = "아이디가 일치하지 않습니다";
%>

<p>결과1: <%=result1%></p>
<p>결과2: <%=result2%></p>