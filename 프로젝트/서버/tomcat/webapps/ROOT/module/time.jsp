<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8" %>
<%@ page import="java.sql.Timestamp" %>
<%@ page import="java.text.SimpleDateFormat" %>

<%
    Timestamp now = new Timestamp(System.currentTimeMillis());
    SimpleDateFormat format = new SimpleDateFormat("yyyy-MM-dd");
    String strDate = format.format(now);
%>
<p>오늘은 <%=strDate%> 입니다.</p>
<p>현재는 <%=now.getHours()%>시 <%=now.getMinutes()%>분 <%=now.getSeconds()%>초 입니다.</p>