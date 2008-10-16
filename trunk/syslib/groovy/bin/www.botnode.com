<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" lang="en" xml:lang="en" >
 <head>
 <title>Botnode - Software Development Projects</title>
 <meta name="DESCRIPTION" content="Botnode software development projects." />
 <meta name="keywords" content="software, jruby, java, j2ee, ruby, factor, hacking, botlisting, bot's list, list, ads, advertising, social bookmarking, networking, social networking, reddit, digg" />

 <style type="text/css">

 body {
 	margin: 0px 0px 0px 0px;
	font-family: arial,helvetica,verdana,geneva,sans-serif;
	font-size: 12pt;
 }

 div.main_header {
 	padding: 10px 10px 10px 10px;
	background-color: #333;
	color: #fff;
	font-size: 30pt;

 }

 div.main_content {
 	padding: 20px 20px 20px 20px;
 }

 /** Link styles */
 a, a:link {
 	font-weight: bold;
 	color: #000066;
 	font-size: 11pt;
 }
 a:active {
    font-weight: bold;
	color: #990033;
	font-size: 11pt;
 }

 /** SMALLER Links **/
 a.small {
 	color: #999;
 	font-size: 10pt;
 }
 a.small:link {
 	color: #999;
 	font-size: 10pt;
 }

 a.small:active {
	color: #999;
	font-size: 10pt;
 }

 /** New tags, left and right sections for main content */
 #left_sect {
	float: left;
	width: 45%;
	margin: 2px 2px 2px 2px;
 }
 #right_sect {
	float: left;
	width: 45%;
	margin: 2px 2px 2px 2px;
 }

 /** Header */
 div.sect_header {
 	padding: 6px 6x 6px 6px;
 	color: #FFF;
 	font-size: 14pt;
 	font-weight: bold;
 	margin: 4px 0px 0px 0px;
 	text-align: center;
 	border-bottom: 1px solid #222;
 }
 .grey1 {
 	background-color: #777;
 }
 .grey2 {
	background-color: #AAA;
 }
 .grey3 {
	background-color: #999;
 }

 </style>
 </head>

 <body>

  	<div class="main_header">
  		[ Welcome to botnode.com ]
  	</div>

	<div class="main_content">

		<div style="clear: both;"></div>
	 	<div id="left_sect" class="left_sect">

			<div class="sect_header grey1">Free Open Source Software</div>
			<div>
				"Free software that can be used, studied, and modified without restriction, and which can be copied and
				redistributed in modified or unmodified form either without restriction".  Most of the software
				created by botnode.com falls under a free/open source software license unless stated otherwise.  Here is
				a list of the most popular projects on the site.

				<div style="margin-top: 6px;">
					#<a href="http://code.google.com/p/openbotlist/">Open Botlist</a> - Botlist contains an open source suite of software applications for social bookmarking
					and collecting online news content for use on the web. Multiple web front-ends exist for Django, Rails, and J2EE.
					Users and remote agents are allowed to submit interesting articles.

					<br />#<a href="http://code.google.com/p/octanemech/">Octane Mech</a> - Octane Mech is a 3D, OpenGL based Mech game written in Haskell.
					glAnts-mech - This project is a combination mech game and simulation that will allow you to interact with simple artificial ants. Once you provoke them, they will send fire ants out to protect the nest. You will be able to use the maze environment to plan or run

					<br />#<a href="http://code.google.com/p/haskellnotebook/">Haskell Notebook</a> - The Haskell Notebook (another Haskell Cookbook)
					contains some common and not so common Haskell programming idioms that are contained in a collection of working/compilable examples.
					There is also a collection of source code from other functional programming languages including Lisp and Erlang.

					<br />#<a href="http://code.google.com/p/jvmnotebook/">JVM Notebook</a> - JVM Notebook - Cookbook examples of JVM language code
					(JRuby, Jython, Scala, ABCL).

					<br />#<a href="http://code.google.com/p/octane-lang/">Octanelang and My Embedded Language (MEL)</a>
					<br />#<a href="http://code.google.com/p/octaneos/">OctaneOS</a> - Octane Operating System, Simple Monolithic Operating System.
				</div> <!-- End of free sect links -->

			</div> <!-- End of Free Software Sect -->


			<div class="sect_header grey3">Interesting External Links</div>
			<div>
				<a href="http://planet.factorcode.org/">Planet Factor</a> - RSS aggregator for factor development.
				<br /><a href="http://norvig.com/">Norvig.com</a> - Peter Norvig's homepage.
				<br /><a href="http://www.nist.gov/dads/?">Dictionary of Algorithms and Data Structures</a>
				<br /><a href="http://anybots.com/">Anybots.com</a> - Anybots has developed the first humanoid robot of its kind that walks dynamically and can jump.
				<br /><a href="http://steve-yegge.blogspot.com/">Steve Yegge</a> - Software Development Blog
				<br /><a href="http://blog.tmorris.net/">Blog by Tony Morris - Scala Development</a>
				<br /><a href="http://sequence.complete.org/">Haskell News</a>
			</div> <!-- End of Section Links -->

			<div class="sect_header grey3">Contact</div>
			<div>
				Berlin B.
				<br /> <span style="font-style: italic">berlin dot brown _at_ gmail.com</span>
				<br /> Atlanta, Ga
				<br /><a href="http://www.botnode.com">botnode.com</a>

				<br />
				<div style="text-align: left">
					<img src="home_imgs/me_pic_hat2.jpg" />
				</div>

			</div> <!-- End of Contact Sect -->

			<div class="sect_header grey1">Meta Information</div>
			<div style="font-size: small">
				Updated: 8/1/2008
			</div>

	 	</div> <!-- End of Left Sect -->

	 	<div id="right_sect" class="right_sect">

			<div class="sect_header grey2">Software Related Essays</div>
			<div style="margin-top: 6px;">
					#<a href="http://berlinbrowndev.blogspot.com/2008/06/is-java-new-cobol-yes-what-does-that_14.html">Java is the new COBOL, what does that mean?</a>
					<br />#<a href="http://berlinbrowndev.blogspot.com/2008/08/application-server-benchmarks-including.html">Application server performance testing, includes Django, ErlyWeb and others</a>
					<br />#<a href="http://berlinbrowndev.blogspot.com/2008/07/neophyte-schemelisp-interpreter-in.html">Scheme Lisp Interpreter in Erlang</a>
					<br />#<a href="http://berlinbrowndev.blogspot.com/2008/07/simple-lisp-implementation-in-java-ode.html">Simple Lisp Implementation in Java</a>
					<br />#<a href="http://berlinbrowndev.blogspot.com/2008/07/enterprise-common-lisp-setting-up.html">Setting up HUNCHENTOOT</a>
					<br />#<a href="http://berlinbrowndev.blogspot.com/2008/07/code-snippet-erlang-server-common-lisp.html">Erlang Server, Common Lisp Client</a>
					<p>
						<a href="http://www.botnode.com/botwiki/index.php?title=Main_Page">botnode development wiki</a>  - Wiki page associated with development on botnode.com projects
						<br /><a href="http://www.botnode.com/newspirit/">newspiritcompany.com - legacy site, mirrror</a>
					</p>
			</div>

			<div class="sect_header grey1">Project Hosting</div>
			<div>
					The botnode projects are hosted on various sites including google.code.com and github.

					<br /><a href="http://github.com/berlinbrown/octane_spacesim/tree/master">github - octane space simulator</a>
					<br /><a href="http://github.com/berlinbrown/openbotlist/tree/master">github - botlist</a>
					<br /><a href="http://code.google.com/u/berlin.brown/">code.google.com</a>
			</div>

			<div class="sect_header grey2">Folklore</div>
			<div>

				<br />
				<div style="text-align: left">
					<img src="home_imgs/folklore_music_1.png" />
				</div>
				<div style="font-size: small">
					Album cover of dieselboy's substance-d and sixth session.
				</div>

			</div> <!-- End of folklore section -->


			<div class="sect_header grey2">Task List (current projects)</div>
			<div>

				<a class="small" href="http://code.google.com/p/octane-lang/issues/detail?id=1">Jul 17, 2008 - Octane-lang/MEL: Text Mining/Agent Libraries</a>

			</div> <!-- End of Task List -->


	 	</div> <!-- End of Right Sect -->

		<div style="clear: both;"></div> <!-- The end, clear both -->

  	</div> <!-- End of main content section -->

	<div id="google_track_info">
		<script type="text/javascript">
		var gaJsHost = (("https:" == document.location.protocol) ? "https://ssl." : "http://www.");
		document.write(unescape("%3Cscript src='" + gaJsHost + "google-analytics.com/ga.js' type='text/javascript'%3E%3C/script%3E"));
		</script>
		<script type="text/javascript">
		var pageTracker = _gat._getTracker("UA-286501-7");
		pageTracker._trackPageview();
		</script>
	</div> <!-- End of google track -->

 </body>
</html>
