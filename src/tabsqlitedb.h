
  
  

  


<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN"
  "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="en" lang="en">
  <head>
    <meta http-equiv="content-type" content="text/html;charset=UTF-8" />
    <meta http-equiv="X-UA-Compatible" content="chrome=1">
        <title>src/tabsqlitedb.h at 4ea9b877e7e8aa0a7524c3bd7ff61de47f734679 from kaio's ibus-table - GitHub</title>
    <link rel="search" type="application/opensearchdescription+xml" href="/opensearch.xml" title="GitHub" />
    <link rel="fluid-icon" href="https://github.com/fluidicon.png" title="GitHub" />

    <link href="https://assets2.github.com/stylesheets/bundle_common.css?3e7242cb1377e86d7cea496bd64f459f6cc8c4cf" media="screen" rel="stylesheet" type="text/css" />
<link href="https://assets1.github.com/stylesheets/bundle_github.css?3e7242cb1377e86d7cea496bd64f459f6cc8c4cf" media="screen" rel="stylesheet" type="text/css" />

    <script type="text/javascript" charset="utf-8">
      var GitHub = {}
      var github_user = 'kaio'
      
    </script>
    <script src="https://ajax.googleapis.com/ajax/libs/jquery/1.4.2/jquery.min.js" type="text/javascript"></script>
    <script src="https://assets0.github.com/javascripts/bundle_common.js?3e7242cb1377e86d7cea496bd64f459f6cc8c4cf" type="text/javascript"></script>
<script src="https://assets0.github.com/javascripts/bundle_github.js?3e7242cb1377e86d7cea496bd64f459f6cc8c4cf" type="text/javascript"></script>

        <script type="text/javascript" charset="utf-8">
      GitHub.spy({
        repo: "kaio/ibus-table"
      })
    </script>

    
  
    
  

  <link href="https://github.com/kaio/ibus-table/commits/4ea9b877e7e8aa0a7524c3bd7ff61de47f734679.atom" rel="alternate" title="Recent Commits to ibus-table:4ea9b877e7e8aa0a7524c3bd7ff61de47f734679" type="application/atom+xml" />

    <META NAME="ROBOTS" CONTENT="NOINDEX, FOLLOW">    <meta name="description" content="The tables engines for IBus" />
    <script type="text/javascript">
      GitHub.nameWithOwner = GitHub.nameWithOwner || "kaio/ibus-table";
      GitHub.currentRef = "";
    </script>
  

            <script type="text/javascript">
      var _gaq = _gaq || [];
      _gaq.push(['_setAccount', 'UA-3769691-2']);
      _gaq.push(['_trackPageview']);
      (function() {
        var ga = document.createElement('script');
        ga.src = ('https:' == document.location.protocol ? 'https://ssl' : 'http://www') + '.google-analytics.com/ga.js';
        ga.setAttribute('async', 'true');
        document.documentElement.firstChild.appendChild(ga);
      })();
    </script>

  </head>

  

  <body>
    

    
      <script type="text/javascript">
        var _kmq = _kmq || [];
        (function(){function _kms(u,d){if(navigator.appName.indexOf("Microsoft")==0 && d)document.write("<scr"+"ipt defer='defer' async='true' src='"+u+"'></scr"+"ipt>");else{var s=document.createElement('script');s.type='text/javascript';s.async=true;s.src=u;(document.getElementsByTagName('head')[0] || document.getElementsByTagName('body')[0]).appendChild(s);}}_kms('https://i.kissmetrics.com/i.js');_kms('http'+('https:'==document.location.protocol ? 's://s3.amazonaws.com/' : '://')+'scripts.kissmetrics.com/406e8bf3a2b8846ead55afb3cfaf6664523e3a54.1.js',1);})();
      </script>
    

    

    

    <div class="subnavd" id="main">
      <div id="header" class="pageheaded">
        <div class="site">
          <div class="logo">
            <a href="https://github.com/"><img src="/images/modules/header/logov3.png" alt="github" /></a>
          </div>
          
            






  
    <div class="userbox">
      <div class="inner">
        <div class="avatarname">
          <a href="http://github.com/kaio"><img src="https://secure.gravatar.com/avatar/bf9dcb4de0246087915f6d55077ada4d?s=140&d=https%3A%2F%2Fgithub.com%2Fimages%2Fgravatars%2Fgravatar-140.png" alt="" width="20" height="20"  /></a>
          <a href="http://github.com/kaio" class="name">kaio</a>

          
          
        </div>
        <ul class="usernav">
          <li><a href="https://github.com/">Dashboard</a></li>
          <li>
            
            <a href="https://github.com/inbox">Inbox</a>
            <a href="https://github.com/inbox" class="unread_count ">0</a>
          </li>
          <li><a href="https://github.com/account">Account Settings</a></li>
                    <li><a href="/logout">Log Out</a></li>
        </ul>
      </div>
    </div><!-- /.userbox -->
  


          
          <div class="topsearch">
  
    <form action="/search" id="top_search_form" method="get">
      <a href="/search" class="advanced-search tooltipped downwards" title="Advanced Search">Advanced Search</a>
      <input type="search" class="search my_repos_autocompleter" name="q" results="5" placeholder="Search&hellip;" /> <input type="submit" value="Search" class="button" />
      <input type="hidden" name="type" value="Everything" />
      <input type="hidden" name="repo" value="" />
      <input type="hidden" name="langOverride" value="" />
      <input type="hidden" name="start_value" value="1" />
    </form>
  
  
    <ul class="nav">
      <li><a href="/explore">Explore GitHub</a></li>
      <li><a href="http://gist.github.com">Gist</a></li>
      <li><a href="/blog">Blog</a></li>
      <li><a href="http://help.github.com">Help</a></li>
    </ul>
  
</div>

        </div>
      </div>

      
      
        
    <div class="site">
      <div class="pagehead repohead vis-private fork  ">
        <h1>
          <a href="/kaio">kaio</a> / <strong><a href="https://github.com/kaio/ibus-table">ibus-table</a></strong>
          
            <span class="fork-flag">
              
              <span class="text">forked from <a href="/acevery/ibus-table">acevery/ibus-table</a></span>
            </span>
          
          
        </h1>

        
    <ul class="actions">
      

      
        <li class="for-owner" style="display:none"><a href="https://github.com/kaio/ibus-table/edit" class="minibutton btn-admin "><span><span class="icon"></span>Admin</span></a></li>
        <li>
          <a href="/kaio/ibus-table/toggle_watch" class="minibutton btn-watch " id="watch_button" style="display:none"><span><span class="icon"></span>Watch</span></a>
          <a href="/kaio/ibus-table/toggle_watch" class="minibutton btn-watch " id="unwatch_button" style="display:none"><span><span class="icon"></span>Unwatch</span></a>
        </li>
        
          
            <li class="for-notforked" style="display:none"><a href="/kaio/ibus-table/fork" class="minibutton btn-fork " id="fork_button" onclick="var f = document.createElement('form'); f.style.display = 'none'; this.parentNode.appendChild(f); f.method = 'POST'; f.action = this.href;var s = document.createElement('input'); s.setAttribute('type', 'hidden'); s.setAttribute('name', 'authenticity_token'); s.setAttribute('value', 'ae8d0743c0a5d601eead1131a9126aaff253e43b'); f.appendChild(s);f.submit();return false;"><span><span class="icon"></span>Fork</span></a></li>
            <li class="for-hasfork" style="display:none"><a href="#" class="minibutton btn-fork " id="your_fork_button"><span><span class="icon"></span>Your Fork</span></a></li>
          

          
          <li id="pull_request_item" class='ospr' style="display:none"><a href="/kaio/ibus-table/pull_request/" class="minibutton btn-pull-request "><span><span class="icon"></span>Pull Request</span></a></li>
          

          <li><a href="#" class="minibutton btn-download " id="download_button"><span><span class="icon"></span>Download Source</span></a></li>
        
      
      
      <li class="repostats">
        <ul class="repo-stats">
          <li class="watchers"><a href="/kaio/ibus-table/watchers" title="Watchers" class="tooltipped downwards">2</a></li>
          <li class="forks"><a href="/kaio/ibus-table/network" title="Forks" class="tooltipped downwards">3</a></li>
        </ul>
      </li>
    </ul>


        
  <ul class="tabs">
    <li><a href="https://github.com/kaio/ibus-table/tree/" class="selected" highlight="repo_source">Source</a></li>
    <li><a href="https://github.com/kaio/ibus-table/commits/" highlight="repo_commits">Commits</a></li>

    
    <li><a href="/kaio/ibus-table/network" highlight="repo_network">Network (3)</a></li>

    
      <li><a href="/kaio/ibus-table/forkqueue" highlight="repo_fork_queue">Fork Queue</a></li>
    

    

    
      
      <li><a href="/kaio/ibus-table/downloads">Downloads (4)</a></li>
    

    

    <li><a href="/kaio/ibus-table/graphs" highlight="repo_graphs">Graphs</a></li>

    <li class="contextswitch nochoices">
      <span class="toggle leftwards tooltipped" title="4ea9b877e7e8aa0a7524c3bd7ff61de47f734679">
        <em>Tree:</em>
        <code>4ea9b87</code>
      </span>
    </li>
  </ul>

  <div style="display:none" id="pl-description"><p><em class="placeholder">click here to add a description</em></p></div>
  <div style="display:none" id="pl-homepage"><p><em class="placeholder">click here to add a homepage</em></p></div>

  <div class="subnav-bar">
  
  <form action="/kaio/ibus-table/search" id="repo-search-form" method="get">
    <input type="search" class="search" name="q" results="5" placeholder="Search source code&hellip;" value="" />
    <input type="hidden" id="lang-value" name="langOverride" value="">
    <input type="hidden" id="start-value" name="start" value="">
  </form>

  <ul>
    <li>
      <a href="#" class="dropdown">Switch Branches (3)</a>
      <ul>
        
          
          
            <li><a href="/kaio/ibus-table/blob/master/src/tabsqlitedb.h" action="show">master</a></li>
          
        
          
          
            <li><a href="/kaio/ibus-table/blob/rewrite_c/src/tabsqlitedb.h" action="show">rewrite_c</a></li>
          
        
          
          
            <li><a href="/kaio/ibus-table/blob/rh/src/tabsqlitedb.h" action="show">rh</a></li>
          
        
      </ul>
    </li>
    <li>
      <a href="#" class="dropdown ">Switch Tags (4)</a>
              <ul>
                      
              <li><a href="/kaio/ibus-table/blob/0.1.2.20090104/src/tabsqlitedb.h">0.1.2.20090104</a></li>
            
                      
              <li><a href="/kaio/ibus-table/blob/0.1.2.20090101/src/tabsqlitedb.h">0.1.2.20090101</a></li>
            
                      
              <li><a href="/kaio/ibus-table/blob/0.1.1.20081115/src/tabsqlitedb.h">0.1.1.20081115</a></li>
            
                      
              <li><a href="/kaio/ibus-table/blob/0.1.1.20081014/src/tabsqlitedb.h">0.1.1.20081014</a></li>
            
                  </ul>
      
    </li>
    <li>
    
    <a href="/kaio/ibus-table/branches/master" class="manage">Branch List</a>
    
    </li>
  </ul>
</div>

  
  
  
  
  


        
    <div id="repo_details" class="metabox clearfix">
      <div id="repo_details_loader" class="metabox-loader" style="display:none">Sending Request&hellip;</div>

      

      <div id="repository_description" rel="repository_description_edit">
        
          <p>The tables engines for IBus
            <span id="read_more" style="display:none">&mdash; <a href="#readme">Read more</a></span>
          </p>
        
      </div>
      <div id="repository_description_edit" style="display:none;" class="inline-edit">
        <form action="/kaio/ibus-table/edit/update" method="post"><div style="margin:0;padding:0"><input name="authenticity_token" type="hidden" value="ae8d0743c0a5d601eead1131a9126aaff253e43b" /></div>
          <input type="hidden" name="field" value="repository_description">
          <input type="text" class="textfield" name="value" value="The tables engines for IBus">
          <div class="form-actions">
            <button class="minibutton"><span>Save</span></button> &nbsp; <a href="#" class="cancel">Cancel</a>
          </div>
        </form>
      </div>

      
      <div class="repository-homepage" id="repository_homepage" rel="repository_homepage_edit">
        <p><a href="http://github.com/kaio/ibus-table/" rel="nofollow">http://github.com/kaio/ibus-table/</a></p>
      </div>
      <div id="repository_homepage_edit" style="display:none;" class="inline-edit">
        <form action="/kaio/ibus-table/edit/update" method="post"><div style="margin:0;padding:0"><input name="authenticity_token" type="hidden" value="ae8d0743c0a5d601eead1131a9126aaff253e43b" /></div>
          <input type="hidden" name="field" value="repository_homepage">
          <input type="text" class="textfield" name="value" value="http://github.com/kaio/ibus-table/">
          <div class="form-actions">
            <button class="minibutton"><span>Save</span></button> &nbsp; <a href="#" class="cancel">Cancel</a>
          </div>
        </form>
      </div>

      <div class="rule "></div>

      <div id="url_box" class="url-box">
        <ul class="clone-urls">
          
            <li id="private_clone_url"><a href="git@github.com:kaio/ibus-table.git" data-permissions="Read+Write">SSH</a></li>
            <li id="http_clone_url"><a href="https://kaio@github.com/kaio/ibus-table.git" data-permissions="Read+Write">HTTP</a></li>
          
        </ul>
        <input type="text" spellcheck="false" id="url_field" class="url-field" />
              <span style="display:none" id="url_box_clippy"></span>
      <span id="clippy_tooltip_url_box_clippy" class="clippy-tooltip tooltipped" title="copy to clipboard">
      <object classid="clsid:d27cdb6e-ae6d-11cf-96b8-444553540000"
              width="14"
              height="14"
              class="clippy"
              id="clippy" >
      <param name="movie" value="https://assets3.github.com/flash/clippy.swf?v5"/>
      <param name="allowScriptAccess" value="always" />
      <param name="quality" value="high" />
      <param name="scale" value="noscale" />
      <param NAME="FlashVars" value="id=url_box_clippy&amp;copied=&amp;copyto=">
      <param name="bgcolor" value="#FFFFFF">
      <param name="wmode" value="opaque">
      <embed src="https://assets3.github.com/flash/clippy.swf?v5"
             width="14"
             height="14"
             name="clippy"
             quality="high"
             allowScriptAccess="always"
             type="application/x-shockwave-flash"
             pluginspage="http://www.macromedia.com/go/getflashplayer"
             FlashVars="id=url_box_clippy&amp;copied=&amp;copyto="
             bgcolor="#FFFFFF"
             wmode="opaque"
      />
      </object>
      </span>

        <p id="url_description">This URL has <strong>Read+Write</strong> access</p>
      </div>
    </div>


        

      </div><!-- /.pagehead -->

      









<script type="text/javascript">
  GitHub.currentCommitRef = "4ea9b877e7e8aa0a7524c3bd7ff61de47f734679"
  GitHub.currentRepoOwner = "kaio"
  GitHub.currentRepo = "ibus-table"
  GitHub.downloadRepo = '/kaio/ibus-table/archives/4ea9b877e7e8aa0a7524c3bd7ff61de47f734679'

  
    GitHub.hasWriteAccess = true
    GitHub.hasAdminAccess = true
    GitHub.watchingRepo = true
    GitHub.ignoredRepo = false
    GitHub.hasForkOfRepo = null
    GitHub.hasForked = true
  

  
</script>










  <div id="commit">
    <div class="group">
        
  <div class="envelope commit">
    <div class="human">
      
        <div class="message"><pre><a href="/kaio/ibus-table/commit/4ea9b877e7e8aa0a7524c3bd7ff61de47f734679">已经可以通过 --xml ，使得 ibus 配置面板可以使用了，呵呵</a> </pre></div>
      

      <div class="actor">
        <div class="gravatar">
          
          <img src="https://secure.gravatar.com/avatar/0b1452e6cf2f765a727d4cdd49667bfe?s=140&d=https%3A%2F%2Fgithub.com%2Fimages%2Fgravatars%2Fgravatar-140.png" alt="" width="30" height="30"  />
        </div>
        <div class="name"><a href="/microcai">microcai</a> <span>(author)</span></div>
        <div class="date">
          <abbr class="relatize" title="2010-06-04 08:28:58">Fri Jun 04 08:28:58 -0700 2010</abbr>
        </div>
      </div>

      

    </div>
    <div class="machine">
      <span>c</span>ommit&nbsp;&nbsp;<a href="/kaio/ibus-table/commit/4ea9b877e7e8aa0a7524c3bd7ff61de47f734679" hotkey="c">4ea9b877e7e8aa0a7524</a><br />
      <span>t</span>ree&nbsp;&nbsp;&nbsp;&nbsp;<a href="/kaio/ibus-table/tree/4ea9b877e7e8aa0a7524c3bd7ff61de47f734679/configure.ac" hotkey="t">f78a2b442b6f6f874986</a><br />
      
        <span>p</span>arent&nbsp;
        
        <a href="/kaio/ibus-table/commit/db013dba7f3e9330f9612e3f2136a88a1547e1f7" hotkey="p">db013dba7f3e9330f961</a>
      

    </div>
  </div>

    </div>
  </div>



  
    <div id="path">
      <b><a href="/kaio/ibus-table/tree/4ea9b877e7e8aa0a7524c3bd7ff61de47f734679">ibus-table</a></b> / <a href="/kaio/ibus-table/tree/4ea9b877e7e8aa0a7524c3bd7ff61de47f734679/src">src</a> / tabsqlitedb.h       <span style="display:none" id="clippy_1825">src/tabsqlitedb.h</span>
      
      <object classid="clsid:d27cdb6e-ae6d-11cf-96b8-444553540000"
              width="110"
              height="14"
              class="clippy"
              id="clippy" >
      <param name="movie" value="https://assets3.github.com/flash/clippy.swf?v5"/>
      <param name="allowScriptAccess" value="always" />
      <param name="quality" value="high" />
      <param name="scale" value="noscale" />
      <param NAME="FlashVars" value="id=clippy_1825&amp;copied=copied!&amp;copyto=copy to clipboard">
      <param name="bgcolor" value="#FFFFFF">
      <param name="wmode" value="opaque">
      <embed src="https://assets3.github.com/flash/clippy.swf?v5"
             width="110"
             height="14"
             name="clippy"
             quality="high"
             allowScriptAccess="always"
             type="application/x-shockwave-flash"
             pluginspage="http://www.macromedia.com/go/getflashplayer"
             FlashVars="id=clippy_1825&amp;copied=copied!&amp;copyto=copy to clipboard"
             bgcolor="#FFFFFF"
             wmode="opaque"
      />
      </object>
      

    </div>

    <div id="files">
      <div class="file">
        <div class="meta">
          <div class="info">
            <span class="icon"><img alt="Txt" height="16" src="https://assets0.github.com/images/icons/txt.png?3e7242cb1377e86d7cea496bd64f459f6cc8c4cf" width="16" /></span>
            <span class="mode" title="File Mode">100644</span>
            
              <span>43 lines (33 sloc)</span>
            
            <span>1.247 kb</span>
          </div>
          <ul class="actions">
            
              <li><a id="file-edit-link" href="#" rel="/kaio/ibus-table/file-edit/__ref__/src/tabsqlitedb.h">edit</a></li>
            
            <li><a href="/kaio/ibus-table/raw/4ea9b877e7e8aa0a7524c3bd7ff61de47f734679/src/tabsqlitedb.h" id="raw-url">raw</a></li>
            
              <li><a href="/kaio/ibus-table/blame/4ea9b877e7e8aa0a7524c3bd7ff61de47f734679/src/tabsqlitedb.h">blame</a></li>
            
            <li><a href="/kaio/ibus-table/commits/master/src/tabsqlitedb.h">history</a></li>
          </ul>
        </div>
        
  <div class="data syntax type-c">
    
      <table cellpadding="0" cellspacing="0">
        <tr>
          <td>
            <pre class="line_numbers"><span id="LID1" rel="#L1">1</span>
<span id="LID2" rel="#L2">2</span>
<span id="LID3" rel="#L3">3</span>
<span id="LID4" rel="#L4">4</span>
<span id="LID5" rel="#L5">5</span>
<span id="LID6" rel="#L6">6</span>
<span id="LID7" rel="#L7">7</span>
<span id="LID8" rel="#L8">8</span>
<span id="LID9" rel="#L9">9</span>
<span id="LID10" rel="#L10">10</span>
<span id="LID11" rel="#L11">11</span>
<span id="LID12" rel="#L12">12</span>
<span id="LID13" rel="#L13">13</span>
<span id="LID14" rel="#L14">14</span>
<span id="LID15" rel="#L15">15</span>
<span id="LID16" rel="#L16">16</span>
<span id="LID17" rel="#L17">17</span>
<span id="LID18" rel="#L18">18</span>
<span id="LID19" rel="#L19">19</span>
<span id="LID20" rel="#L20">20</span>
<span id="LID21" rel="#L21">21</span>
<span id="LID22" rel="#L22">22</span>
<span id="LID23" rel="#L23">23</span>
<span id="LID24" rel="#L24">24</span>
<span id="LID25" rel="#L25">25</span>
<span id="LID26" rel="#L26">26</span>
<span id="LID27" rel="#L27">27</span>
<span id="LID28" rel="#L28">28</span>
<span id="LID29" rel="#L29">29</span>
<span id="LID30" rel="#L30">30</span>
<span id="LID31" rel="#L31">31</span>
<span id="LID32" rel="#L32">32</span>
<span id="LID33" rel="#L33">33</span>
<span id="LID34" rel="#L34">34</span>
<span id="LID35" rel="#L35">35</span>
<span id="LID36" rel="#L36">36</span>
<span id="LID37" rel="#L37">37</span>
<span id="LID38" rel="#L38">38</span>
<span id="LID39" rel="#L39">39</span>
<span id="LID40" rel="#L40">40</span>
<span id="LID41" rel="#L41">41</span>
<span id="LID42" rel="#L42">42</span>
<span id="LID43" rel="#L43">43</span>
</pre>
          </td>
          <td width="100%">
            
              <div class="highlight"><pre><div class='line' id='LC1'><span class="cm">/*- coding: utf-8 -*-</span></div><div class='line' id='LC2'><span class="cm"> * vim:et sts=4 sw=4</span></div><div class='line' id='LC3'><br/></div><div class='line' id='LC4'><span class="cm">#  ibus-table - The Tables engine for IBus</span></div><div class='line' id='LC5'><span class="cm">#</span></div><div class='line' id='LC6'><span class="cm"># Copyright (c) 2008-2009 Yu Yuwei &lt;acevery@gmail.com&gt;</span></div><div class='line' id='LC7'><span class="cm">#</span></div><div class='line' id='LC8'><span class="cm"># This library is free software; you can redistribute it and/or</span></div><div class='line' id='LC9'><span class="cm"># modify it under the terms of the GNU Lesser General Public</span></div><div class='line' id='LC10'><span class="cm"># License as published by the Free Software Foundation; either</span></div><div class='line' id='LC11'><span class="cm"># version 2.1 of the License, or (at your option) any later version.</span></div><div class='line' id='LC12'><span class="cm">#</span></div><div class='line' id='LC13'><span class="cm"># This library is distributed in the hope that it will be useful,</span></div><div class='line' id='LC14'><span class="cm"># but WITHOUT ANY WARRANTY; without even the implied warranty of</span></div><div class='line' id='LC15'><span class="cm"># MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU</span></div><div class='line' id='LC16'><span class="cm"># Lesser General Public License for more details.</span></div><div class='line' id='LC17'><span class="cm">#</span></div><div class='line' id='LC18'><span class="cm"># You should have received a copy of the GNU Lesser General Public</span></div><div class='line' id='LC19'><span class="cm"># License along with this library; if not, write to the Free Software</span></div><div class='line' id='LC20'><span class="cm"># Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA</span></div><div class='line' id='LC21'><br/></div><div class='line' id='LC22'><span class="cm">*/</span></div><div class='line' id='LC23'><br/></div><div class='line' id='LC24'><span class="cp">#ifndef TABSQLITEDB_H_</span></div><div class='line' id='LC25'><span class="cp">#define TABSQLITEDB_H_</span></div><div class='line' id='LC26'><br/></div><div class='line' id='LC27'><span class="cp">#include &lt;sqlite3.h&gt;</span></div><div class='line' id='LC28'><br/></div><div class='line' id='LC29'><span class="k">typedef</span> <span class="k">struct</span> <span class="n">_tabsqlitedb</span><span class="p">{</span></div><div class='line' id='LC30'>&nbsp;&nbsp;<span class="n">sqlite3</span> <span class="o">*</span> <span class="n">db</span><span class="p">;</span></div><div class='line' id='LC31'>&nbsp;&nbsp;<span class="n">sqlite3</span> <span class="o">*</span> <span class="n">udb</span><span class="p">;</span></div><div class='line' id='LC32'><span class="p">}</span><span class="n">tabsqlitedb</span><span class="p">;</span></div><div class='line' id='LC33'><br/></div><div class='line' id='LC34'><span class="n">tabsqlitedb</span> <span class="o">*</span></div><div class='line' id='LC35'><span class="n">tabsqlitedb_new</span><span class="p">(</span><span class="k">const</span> <span class="n">gchar</span> <span class="o">*</span> <span class="n">db</span><span class="p">,</span> <span class="k">const</span> <span class="n">gchar</span> <span class="o">*</span> <span class="n">udb</span><span class="p">);</span></div><div class='line' id='LC36'><br/></div><div class='line' id='LC37'><span class="kt">void</span></div><div class='line' id='LC38'><span class="n">tabsqlitedb_destory</span><span class="p">(</span><span class="n">tabsqlitedb</span> <span class="o">*</span> <span class="n">db</span><span class="p">);</span></div><div class='line' id='LC39'><br/></div><div class='line' id='LC40'><span class="n">gboolean</span> <span class="n">tabsqlitedb_getime</span><span class="p">(</span><span class="n">tabsqlitedb</span> <span class="o">*</span> <span class="n">db</span><span class="p">,</span> <span class="k">const</span> <span class="kt">char</span> <span class="o">*</span> <span class="n">attr</span><span class="p">,</span> <span class="kt">char</span> <span class="o">**</span> <span class="n">val</span><span class="p">);</span></div><div class='line' id='LC41'><br/></div><div class='line' id='LC42'><span class="cp">#endif </span><span class="cm">/* TABSQLITEDB_H_ */</span><span class="cp"></span></div><div class='line' id='LC43'><br/></div></pre></div>
            
          </td>
        </tr>
      </table>
    
  </div>


      </div>
    </div>

  


    </div>
  
      

      <div class="push"></div>
    </div>

    <div id="footer">
      <div class="site">
        <div class="info">
          <div class="links">
            <a href="http://github.com/blog"><b>Blog</b></a> |
            <a href="http://support.github.com?sso=fJglILVplEP9XzAKdgghAQDu1FWBrNSwFXhDefE-_G4N4S8wVB2KY3_vyAnXsOvobXMmA2Vjfy8BTKzLAFGiII1dKBYxEjKO5v32gVx6_bJTGsVgqtVWtETxJ76BjzyF_nKdcZkSq9ozNS0puD1YXIk9YWpzfL0fcOTpRnH9WGlR6-BPICeLnlwRWE0vxSrxqD7VmR7QPprnhe9qZOExueWU1Vkgk13jPUOyouhHo1s">Support</a> |
            <a href="http://github.com/training">Training</a> |
            <a href="http://github.com/contact">Contact</a> |
            <a href="http://develop.github.com">API</a> |
            <a href="http://status.github.com">Status</a> |
            <a href="http://twitter.com/github">Twitter</a> |
            <a href="http://help.github.com">Help</a> |
            <a href="http://github.com/security">Security</a>
          </div>
          <div class="company">
            &copy;
            2010
            <span id="_rrt" title="0.24072s from fe3.rs.github.com">GitHub</span> Inc.
            All rights reserved. |
            <a href="/site/terms">Terms of Service</a> |
            <a href="/site/privacy">Privacy Policy</a>
          </div>
        </div>
        <div class="sponsor">
          <div>
            Powered by the <a href="http://www.rackspace.com ">Dedicated
            Servers</a> and<br/> <a href="http://www.rackspacecloud.com">Cloud
            Computing</a> of Rackspace Hosting<span>&reg;</span>
          </div>
          <a href="http://www.rackspace.com">
            <img alt="Dedicated Server" src="https://assets0.github.com/images/modules/footer/rackspace_logo.png?3e7242cb1377e86d7cea496bd64f459f6cc8c4cf" />
          </a>
        </div>
      </div>
    </div>

    <script>window._auth_token = "ae8d0743c0a5d601eead1131a9126aaff253e43b"</script>
    

    <script type="text/javascript">
      _kmq.push(['trackClick', 'entice_banner_link', 'Entice banner clicked']);
      
    </script>
    
  </body>
</html>

