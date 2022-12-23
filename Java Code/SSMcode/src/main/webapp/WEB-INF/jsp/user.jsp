<%--
  Created by IntelliJ IDEA.
  User: Zhenglin Li
  Date: 2021/12/19
  Time: 17:16
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>user</title>
</head>
<body>
id:${requestScope.user.id}<br/>
email:${requestScope.user.email}<br/>
username:${requestScope.user.username}<br/>
role:${requestScope.user.role}<br/>
mobile:${requestScope.user.mobile}<br/>
</body>
</html>
