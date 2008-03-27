<%@ include file="/WEB-INF/jsps/include.jsp" %>

  <div class="main_grid">
	<b>Final Results:</b>
	<c:out value="${command.x}" /> + <c:out value="${command.y}" /> 
		= <c:out value="${command.total}" />
	
	<br>
	<b>Extended information:</b>
	<br>
	<div style="background-color: #EEE; padding: 6px;">
		Subtraction:<br>
		<c:out value="${command.subtract}" /><br>
		
		Multiply:<br>
		<c:out value="${command.multiply}" /><br>
		
		Average:<br>
		<c:out value="${command.average}" />
	</div>
	<p>	
	<div>
		<a href="<c:url value="calculator.html" />">Return to Calculator</a>
	</div>
	<br>
	execution time: <c:out value="${processingtime}" />
	
	<p>
	<b>
 		Total Visits: <c:out value="${command.totalvisits}" />
	</b>	
	
	<p>
	<b>Poll Results</b>
	<br>
	<table>
		<tr>
			<td>	
				Democrats
			</td>
			<td>
				<c:out value="${command.dems}" />
			</td>
		</tr>
		<tr>
			<td>	
				Republicans
			</td>
			<td>
				<c:out value="${command.reps}" />
			</td>
		</tr>
	</table>
				
   </div>
</body>
</html>
