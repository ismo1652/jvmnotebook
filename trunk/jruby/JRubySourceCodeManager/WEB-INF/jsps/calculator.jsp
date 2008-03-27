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
	<input type="submit" value="Calculate">	
</form>

 <br>
 execution time: <c:out value="${processingtime}" />

 <p>
 <b>
 	Total Visits: <c:out value="${command.totalvisits}" />
 </b>
 
 <div style="background-color: #EEE; padding: 6px;">
	Take our poll in appreciation of the
	<br>November 7, 2006 Elections
	<br>
	Are you a democrat or republican?
	<br>
	<table>
	<tr>
		<td>
			<b>Democrat</b>
		</td>
 		<td>
			<input type="radio" name="poll" value="DEM" checked="checked"> 		
 		</td>
 	</tr>
 	<tr>
 		<td>
 			<b>Republican</b>
 		</td>
 		<td>
 			<input type="radio" name="poll" value="REP"> 		
 		</td>
	</tr>
	</table>
	<br>
	(click 'calculate' to submit)
	
	</div>
 
  
 <p>
 <a href="http://www.botspiritcompany.com/src/springruby/example_ruby_spring.html">View Demo JRuby and Spring Source</a>

</div>

</body>
</html>
