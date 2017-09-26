<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.0 Transitional//EN" "http://www.w3.org/TR/REC-html40/loose.dtd">
<HTML>
<HEAD>
  <META http-equiv="Content-Type" content="text/html; charset=iso-8859-1">
  <META name="description" content="Internet Problem Solving Contest (IPSC) is an online programming contest for teams up three people.">
  <META name="keywords" content="IPSC, programming, contest, online contest">
  <TITLE>IPSC 1999 Solutions Problem H - Romeo and Juliet</TITLE>
<link rel="stylesheet" type="text/css" href="../../image/main.css">
  
</HEAD>
	
<BODY BGCOLOR=white TEXT="#191970" LINK="#F4A460" VLINK="#CD853F" ALINK="#FFDEAD">



<!-- Spidersoft WebZIP Banner Ad Insert -->
<!-- For removal instructions see:  http://www.spidersoft.com/webzip/help/noads.asp  -->

<SCRIPT FOR=window EVENT=onload LANGUAGE="JScript">
if (navigator.onLine){
  initAd();
}
</SCRIPT>

<script language="JScript">
<!--

function initAd() {
  document.all.AdLayer.style.posTop = -200;
  document.all.AdLayer.style.visibility = 'visible'
  MoveLayer('AdLayer');
}

function MoveLayer(layerName) {
  var x = 10;
  var y = 10;
  var diff = (document.body.scrollTop + y - document.all.AdLayer.style.posTop)*.40;
  var y = document.body.scrollTop + y - diff;
  eval("document.all." + layerName + ".style.posTop =  y");
  eval("document.all." + layerName + ".style.posLeft = x");
  setTimeout("MoveLayer('AdLayer');", 60);
}

if (navigator.onLine){
  document.write("<div bgcolor=#000000 style='height=70px;'></div>");
  document.write("<div id=AdLayer style='position:absolute; width:100%; height:80px; z-index:20; visibility:hidden;'>");
  document.write("<IFRAME SRC='http://www.spidersoft.com/ads/bwz468_60.asp' width=100% height=60 marginwidth=0 marginheight=0 hspace=0 vspace=0 frameborder=0 scrolling=no></IFRAME>");
  document.write("</div>");
}
 //-->
</script>

<!-- /Spidersoft WebZIP Banner Ad Insert -->




<!-- NAVIGATION BAR -->
<TABLE CLASS="navbar" CELLSPACING="0" WIDTH="100%" BGCOLOR="#191970">
	
<TR>
<TH colspan=1 ALIGN=LEFT>
<A HREF="../../ipsc.ksp.html">home</A> &nbsp;|&nbsp;
<A HREF="../old.php">problem archive</A>&nbsp;|&nbsp;
<A HREF="../../results/old.php">previous results</A>&nbsp;|&nbsp;
<A HREF="../../team/team.html">organizing team</A>
</TH>
<TH>&nbsp;</TH>
</TR>
	
<!-- guide, pravidla, etc. -->
<TR>
<TH ALIGN=LEFT>
<A HREF="../../guide.php">guide</A>&nbsp;|&nbsp;
<A HREF="../../rules.php">rules</A>&nbsp;|&nbsp;
<A HREF="../../techinfo.php">technical info</A>&nbsp;|&nbsp;
<A HREF="../../clock.php">clock</A>&nbsp;|&nbsp;
<A HREF="../../practice.php">practice session</A>&nbsp;|&nbsp;
<A HREF="../sample.php">sample problem set</A>
</TH>
<TH rowspan=2 class="clock" ALIGN="right" VALIGN=MIDDLE>
<FONT COLOR="#FAFAD2">8:48am</FONT>
</TH>
</TR>

<!-- linky kriticke pocas sutaze -->
<TR>
<TH ALIGN=LEFT>
<A HREF="../problems.html">problem set</A>&nbsp;|&nbsp;
<A HREF="../../results/results.html">online standings</A>&nbsp;|&nbsp;
<A HREF="../../register/register.html">registration</A>&nbsp;|&nbsp;
<A HREF="../../register/regteams.php">registered teams</A>&nbsp;|&nbsp;
<A HREF="../../guestbook/guestbook.html">guestbook</A>
</TH>
</TR>
	
</TABLE>
<!-- end of NAVIGATION BAR -->
	
<!-- Title and Logo -->
<TABLE class="title" WIDTH="100%"><TR VALIGN="top">
<TD WIDTH="140"><A HREF="../../ipsc.ksp.html"><IMG BORDER=0 SRC="../../image/ipsc.gif" TITLE="Home" ALT="IPSC Logo"></a></TD>
<TD ALIGN=CENTER>
	<H5>Internet Problem Solving Contest</H5>
	<H1>IPSC 1999 Solutions<br> Problem H - Romeo and Juliet</H1>
</TD>
</TR></TABLE>
<!-- end of Title and Logo -->

<TABLE CLASS=page ALIGN=center WIDTH="97%"><TR><TD>
	

<ul>
<li><a href="h1.out">Output for easy input data set - H1</a></li>
<li><a href="h2.out">Output for easy difficult data set - H2</a></li>
<li><a href="sol_h.c">Program solving both data sets</a></li>
</ul>

<p>
Here we provide program solving the problem as well as correct output files
for both inputs.
</p>

<p>
In this problem you could use your knowledge of standard graph shortest
path algorithms. Our solution works like this:
</p>

<ol>
<li> First, use Dijkstra's algorithm for computing shortest paths from
    <b>JS</b> to all other junctions. More precisely for each junction
    compute the shortest time it takes to get there from <b>JS</b>.

<li> Second, find out, which of the nodes lie on some shortest path to
<b>JG</b>. This can be done easily by depth-first search. We start from
node <b>JG</b> and from each visited node <b>v</b> we continue to
search in all its neighbours <b>u</b> such that if we add edge
<b>uv</b> to the shortest path from <b>JG</b> to <b>u</b>, we get a
shortest path from <b>JG</b> to <b>v</b>.
</li>

<li> After steps 1. and 2. we know for each node whether Juliet can go
through this node and if yes, at what time she passes it. Now we repeat
steps 1. and 2. for Romeo (i. e. we use <b>RS</b> instead of <b>JS</b>
and <b>RG</b> instead of <b>JG</b>).
</li>

<li> Juliet and Romeo can meet if there is a node that lies on both some
shortest path for Romeo and some shortest path for Juliet and both of
them come to this node at the same time. Since we have computed all
necessary information for all nodes, we need only to perform  a
simple check for each node whether it fulfils conditions set above.
</li>
</ol>


<p>
Note, that the shortest path, computed here by Dijkstra's algorithms, could
be computed also by Floyd-Warshall algorithm, which is easier to implement
(but less efficient).
</p>

<!-- FOOTER -->
<HR CLASS="footer">
<TABLE WIDTH="80%" CLASS="footer" ALIGN="CENTER">
<TR>
<TD WIDTH="15%">e-mails</TD>
<TD WIDTH="15%"><a href="mailto:ipscreg@ksp.sk">questions</a></TD>
<TD WIDTH="15%"><a href="mailto:webmaster@ksp.sk">webmaster</a></TD>
<TD WIDTH="15"></TD>
<TD WIDTH="40%">LAST CHANGE: 1999</TD>
<TD>

<!-- Begin Nedstat Basic code -->
<!-- Title: The Internet Problem Solving Competition -->
<!-- URL: http://www.ksp.sk/ipsc -->
<script language="JavaScript" src="../../../m1.nedstatbasic.net/basic.js">
</script>
<script language="JavaScript">
<!--
  nedstatbasic("AAXgFg9qA69JYkEpU0ZAkfTgWD9w", 0);
// -->
</script>
<noscript>
<a target="_blank" href="http://v1.nedstatbasic.net/stats?AAXgFg9qA69JYkEpU0ZAkfTgWD9w"><img
src="http://m1.nedstatbasic.net/n?id=AAXgFg9qA69JYkEpU0ZAkfTgWD9w"
border="0" nosave width="18" height="18"></a>
</noscript>
<!-- End Nedstat Basic code -->


</TD>
<TD WIDTH="25"></TD>
<TD>
	<p>
	<a href="http://validator.w3.org/check/referer"><img border="0"
       	src="http://www.w3.org/Icons/valid-html40"
       	alt="Valid HTML 4.0!" height="31" width="88"></a>
	</p>
</TD>
</TR>
</TABLE>
<!--- end of FOOTER --> 
	   
<!-- END OF PAGE -->   
</TD></TR></TABLE>
</BODY>
</HTML>
