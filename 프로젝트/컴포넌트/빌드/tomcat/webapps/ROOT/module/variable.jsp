<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8" %>

<%! // %!선언문% public 이랑 비슷함. ---- 전역 변수/함수
    String str1 = "Kingdora";
    String getStr1() {
        return str1;
    }
%>

<%  // %스크립트릿% ---- 지역 변수. 메소드 선언 불가.
    String str2 = "Sodra";
%>

<p>전역변수: <%=str1%></p>
<p>전역함수: <%=getStr1()%></p>
<p>지역변수: <%=str2%></p>
