<%@ include file="/WEB-INF/jsps/include.jsp" %>
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
 New Topic Listing
</h1>

<!-- Public Display -->

<!-- Wrap the list information into the content -->
<div class="bot_list_content">

	<!-- Display the error message -->
	<div class="bot_profile_sect_add_link ">

	<!-- Build the table for entering the new department information -->
	<form method="post">
	<table>

		<!-- First Name -->
		<tr>
			<td valign="top">
				Title:
			</td>
		</tr>
		<tr>
			<td>
				<spring:bind path="command.title">
					<input
						name="title"
						size="40"
						type="text" value="<c:out value="${status.value}"/>" />
				</spring:bind>
			</td>
		</tr>

		<!-- First Name -->
		<tr>
			<td valign="top">
				Topic Listing:
			</td>
		</tr>
		<tr>
			<td>
				<spring:bind path="command.message">
					<textarea cols="40" 						
						name="message"
						rows="12"></textarea>
				</spring:bind>
			</td>
		</tr>

		<!-- Email -->
		<tr>
			<td valign="top">
				Email (will not be displayed):
			</td>
		</tr>
		<tr>
			<td>
				<spring:bind path="command.email">
					<input
						size="40"
						type="text"
						name="email"
						value="" />
				</spring:bind>
			</td>
		</tr>
		
		<tr>
			<td>
				<input name="commit" type="submit" value=" Save Topic " />
			</td>
		</tr>

	</table>
	<!-- End of the table -->
	</form>

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
