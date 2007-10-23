<%@ page contentType="text/html"%>
<%@ taglib prefix="c" uri="http://java.sun.com/jstl/core"%>
<%@ taglib prefix="fmt" uri="http://java.sun.com/jstl/fmt"%>
<%@ taglib prefix="spring" uri="/spring" %>
<%@ taglib prefix="form" uri="http://www.springframework.org/tags/form" %>

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
	<img src="<c:url value="/company/images/building_orange_roof.jpg" />">
 </div>
<h1 class="bot_titlelogo">BotList - View Listing | Home</h1>

<div style="margin: 20px;">

<div style="border: 1px solid #DDD; padding: 10px; margin-right: 100px;">
<!-- Display the error message -->
<div class="bot_profile_sect_add_link ">

	<!-- Build the table for entering the new department information -->
	<a href="<c:url value="/spring/listings.html" />" >Listings</a>
	
	<p>
	
	<a href="<c:url value="/spring/contactlisting.html?viewid=${command.id}" />">Contact Ad Poster</a>
	<br>
<table width="550" class="viewlisting">
	
	<!-- First Name -->
	<tr>
		<td>
			<span style="color: #777;">
			<i>Created - <fmt:formatDate pattern="EE dd, MMM yyyy hh:mm" 
					value="${command.createdOn.time}" /></i>								
			</span>
		</td>		
	</tr>
	
	<!-- First Name -->
	<tr>
		<td valign="top">
			<b>Title:</b>
		</td>
	</tr>
	<tr>
		<td>
			<c:out value="${command.title}" />
		</td>
	</tr>
	
	<tr>
		<td valign="top">
			<b>Topic Listing:</b>
		</td>
	</tr>
	<tr>
		<td valign="top">
			<c:out value="${command.message}" />
		</td>
	</tr>	
	<%-- If available, display  url and keywords --%>
	<c:if test="${not empty command.mainUrl}">
	<tr><td><b>Ad Listing URL (click for more)</b></td></tr>
	<tr>		
		<td>
			<a href="<c:out value="${command.mainUrl}" />" ><c:out value="${command.mainUrl}" /></a>		
		</td>
	</tr>
	</c:if>
	
	<c:if test="${not empty command.keywords}">
		<tr><td><b>tags: </b></td></tr>
		<tr>
			<td>
				<c:out value="${command.keywords}" />
			</td>
		</tr>
	</c:if>
		
</table>
<!-- End of the table -->

</div>

</div>

</div>

<%@include file="/WEB-INF/jsps/general/default_footer.jsp"%>
</div>

</body>
</html>
