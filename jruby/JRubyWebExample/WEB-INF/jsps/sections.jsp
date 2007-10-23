<%@ page contentType="text/html" %>
<%@ taglib prefix="c" uri="http://java.sun.com/jstl/core" %>
<%@ taglib prefix="fmt" uri="http://java.sun.com/jstl/fmt" %>
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
				BotList - Ad Listings | Home
			</h1>	
			
			<div style="margin: 40px 40px 40px 40px;">
				<h3 class="bot_headerinfo">
				BotList allows you to promote your personal profile or
				something of interest.   We cannot force upon you
				what you should advertise, but we suggest
				posting personal profile listings, new and exciting websites, or
				upcoming events. (Note: application is currently in development)
				</h3>
				<br>
				<div style="color: #777; font-size: 12pt;">
					Area: <c:out value="${command.city.cityName}" />
				</div>
			</div>
			
			<!-- Section with City Listing -->
			<div style="margin: 20px;">
				<div style="border: 1px solid #DDD;padding: 10px;">
				
					<table class="sample">					
					<tr>
						<th>
							Sections
						</th>
					</tr>					
					<tr>
						<td>
							<a href="<c:url value="/spring/listings.html" />">General Listings</a>
						</td>
					</tr>
					</table>
				</div>
			</div>
			
			<%@include file="/WEB-INF/jsps/general/default_footer.jsp" %>
		</div>	
  
</body>
</html>
