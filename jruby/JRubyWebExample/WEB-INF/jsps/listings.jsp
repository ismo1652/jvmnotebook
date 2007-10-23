<%@ page contentType="text/html" %>
<%@ taglib prefix="c" uri="http://java.sun.com/jstl/core" %>
<%@ taglib prefix="fmt" uri="http://java.sun.com/jstl/fmt" %>
<%@ taglib prefix="dt" uri="http://jakarta.apache.org/taglibs/datetime-1.0" %>
<%@ taglib prefix="req" uri="http://jakarta.apache.org/taglibs/request-1.0" %>
<html>
<head>
 	<title>Botlist - Ad Listings</title>
 
  	<META NAME="DESCRIPTION" CONTENT="BotList - Promote yourself or something else interesting">
 	<META NAME="keywords" CONTENT="listing, bot, botlist, botlisting, bot's list, list, ads, advertising">
  
	<link href="<c:url value="/company/stylesheets/scaffold.css" />" media="screen" rel="Stylesheet" type="text/css" />
  	<link href="<c:url value="/company/stylesheets/newspirit.css" />" media="screen" rel="Stylesheet" type="text/css" /> 
  	<link href="<c:url value="/company/stylesheets/botlist.css" />" media="screen" rel="Stylesheet" type="text/css" /> 
  	
</head>
<body>

		<div id="body_content_center">
			<div style="border-bottom: 1px solid #816943;">
				<img src="<c:url value="/company/images/building_orange_roof.jpg" />" >
 			</div>
			<h1 class="bot_titlelogo">
				BotList - Ad Listings | Current Ad Listings
			</h1>							
			
			<br>
			<div style="color: #777; font-size: 12pt;">
				Area: <c:out value="${command.city.cityName}" />
			</div>
			
			<!-- Section with City Listing -->
			<div style="margin: 40px;">
				<div style="border: 1px solid #DDD;">
					
					<a href="<c:url value="/spring/create_listing.html" />" >New Ad Listing</a> |
					<a href="<c:url value="/" />" >City Listings</a>					
					<p>					
					
					<table>
					<c:forEach items="${command.listings}"  var="listing" varStatus="status">
						<tr>
							<td>
								<c:out value="${status.count}" />)
							</td>
							<td>
								<a href="<c:url value="/spring/viewlisting.html" />?viewid=<c:out value="${listing.id}" />" >
									<c:out value="${listing.title}" />
								</a>
							</td>
							<td>								
								<fmt:formatDate pattern="EE dd, MMM yyyy hh:mm" value="${listing.createdOn.time}" />
							</td>
						</tr>
					</c:forEach>
					</table>
		
					
				</div>
			</div>
			
			<%@include file="/WEB-INF/jsps/general/default_footer.jsp" %>
		</div>	
  
</body>
</html>
