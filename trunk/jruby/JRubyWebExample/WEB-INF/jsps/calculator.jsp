<%@ include file="/WEB-INF/jsps/include.jsp" %>

<div class="main_grid">
<form method="post" action="<c:url value="calculator.html"/>">
	Enter the first input and second input for the
	<br>corresponding operation:
	<p>
	<input name="x" size="3" value="<c:out value="${command.x}" />" >
		+
	<input name="y" size="3" value="<c:out value="${command.y}" />" >
		&nbsp;
</form>

 <br>
 execution time: <c:out value="${processingtime}" />

 <p>
 <b>
 	Total Visits: <c:out value="${command.totalvisits}" />
 </b>

  
 <p>
 <a href="http://www.botspiritcompany.com/src/springruby/example_ruby_spring.html">View Demo JRuby and Spring Source</a>

</div>

</body>
</html>
