<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8" %>
<%
    StringBuffer sf = new StringBuffer("Reshiram");
    sf.reverse();

    out.println("객체의 내용 : " + sf.toString());
%>