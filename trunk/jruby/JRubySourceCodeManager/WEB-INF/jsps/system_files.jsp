<%@ page contentType="text/html" %>
<%@ taglib prefix="c" uri="http://java.sun.com/jstl/core" %>
<%@ taglib prefix="fmt" uri="http://java.sun.com/jstl/fmt" %>
<%@ taglib prefix="dt" uri="http://jakarta.apache.org/taglibs/datetime-1.0" %>
<%@ taglib prefix="req" uri="http://jakarta.apache.org/taglibs/request-1.0" %>
<html>
<head>
 	<title>BotCode Analytics</title>
 
  	<META NAME="DESCRIPTION" CONTENT="Bot Listing of Spiritcompany Downloads">
 	<META NAME="keywords" CONTENT="botspiritcompany, bot, southeast, east, south, botverse, ror, rails">
  
	<link href="<c:url value="/company/stylesheets/scaffold.css" />" media="screen" rel="Stylesheet" type="text/css" />
  	<link href="<c:url value="/company/stylesheets/newspirit.css" />" media="screen" rel="Stylesheet" type="text/css" /> 
  	<link href="<c:url value="/company/stylesheets/bot_general.css" />" media="screen" rel="Stylesheet" type="text/css" /> 
  	
</head>
<body>

<%@ taglib prefix="spring" uri="/spring" %>

<!-- ============================================ -->
<!-- Berlin Brown -->
<!-- Create Listing -->
<!-- ============================================ -->

<div class="body_content_wrapper">

 <!-- ============================================ -->
<!-- Berlin Brown -->
<!-- ============================================ -->

<h1 class="bot_titlelogo">
 Spirit Company Downloads
</h1>

<!-- Public Display -->

<!-- Wrap the list information into the content -->
<div class="bot_list_content">
	
	The Following links are snapshots of the most downloaded
	applications and projects from newspiritcompany.com
	<p>
	Click on any of the downloads below for complete source to 
	various projects found on the site.
	<br>
	<a href="http://www.newspiritcompany.com/">newspiritcompany.com</a>
	<br>
	This application is itself a project, you can also find the full source
	download <a href="http://www.botspiritcompany.com/src/springfiledir/spring_mvc_demo.html">here</a>.
	<br>
	<a href="http://www.botspiritcompany.com/src/springfiledir/spring_mvc_demo.html">SpringMVC/JRuby File Dir Demo Source</a>	
	
	<br>
	
	<!-- Display the error message -->
	<div class="bot_profile_sect_add_link ">
	
	<a href="<c:url value="/spring/system_files.html" />" >
		(download files home)
	</a>
	<br>
	filter:
	<a href="<c:url value="/spring/system_files_source.html?src=java" />">java</a> |		
	<a href="<c:url value="/spring/system_files_source.html?src=cpp" />">cpp</a> |
	<a href="<c:url value="/spring/system_files_source.html?src=c" />">c</a> |
	<a href="<c:url value="/spring/system_files_source.html?src=lisp" />">lisp</a> |
	<a href="<c:url value="/spring/system_files_source.html?src=scm" />">scm</a> |
	<a href="<c:url value="/spring/system_files_source.html?src=rb" />">rb</a> |
	<a href="<c:url value="/spring/system_files_source.html?src=py" />">py</a> |
	<a href="<c:url value="/spring/system_files_source.html?src=txt" />">txt</a> |
	<a href="<c:url value="/spring/system_files_source.html?src=xml" />">xml</a> |
	<a href="<c:url value="/spring/system_files_source.html?src=bat" />">bat</a> |
		
	<!-- Build the table for entering the new department information -->
	<table>
		<tr>
				<td></td>
				<td>URL</td>
				<td>File Size</td>
				<td>Date</td>
				<td>Project (click for more info)</td>
		</tr>
		<c:forEach items="${command.files}"  var="file" varStatus="status">
			<tr>
				<td>
					<c:out value="${status.count}"/>
				</td>
				<td>					
					<a href="http://www.botspiritcompany.com/src/dump/<c:out value="${file.filename}" />" >
						<c:out value="${file.filename}" />
					</a>
				</td>
				<td><c:out value="${file.fsize}" /></td>
				<td>
					<req:setAttribute name="pattern"><jsp:getProperty name="file" property="fmtime" />000</req:setAttribute>
					<dt:format pattern="MM/dd/yyyy">
						<req:attribute name="pattern" />
					</dt:format>
				</td>
				<td>
					<a href="<c:url value="/spring/system_files.html" />?project=<c:out value="${file.projectname}" />" >
						<c:out value="${file.projectname}" />
					</a>
				</td>
			</tr>
		</c:forEach>
		
	</table>
	<!-- End of the table -->

	</div>

</div>


 <!-- Display Footer Information -->
 <div class="bot_footer_group">

	<!-- Copyright and Terms of Use Section -->
	<div class="bot_footer_copyright_links">
		<a href="/universe_home/terms_of_use">Terms of Use</a> |
		<a href="/universe_home/about">About</a> |
		<a href="/universe_home/about">Help</a>
		<br>
		<!-- Print the Copyright Notice -->

		&copy; Newspiritcompany.com 2006. All rights reserved.
    </div>
<!-- End of Copy Right Information -->
 </div>

</div>

<!-- Include the default footer  -->
<%@ include file="/WEB-INF/jsps/default_footer.jsp" %>
