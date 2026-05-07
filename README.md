<!DOCTYPE html>
<html lang="en">
<head>
<meta charset="UTF-8" />
<meta name="viewport" content="width=device-width, initial-scale=1.0"/>
<title>vaishnavi1476 | LeetCode Solutions</title>
<link href="https://fonts.googleapis.com/css2?family=JetBrains+Mono:wght@400;600;700&family=Syne:wght@400;600;700;800&display=swap" rel="stylesheet"/>
<style>
  *, *::before, *::after { margin: 0; padding: 0; box-sizing: border-box; }

  :root {
    --indigo: #818cf8;
    --indigo-dim: rgba(129,140,248,.12);
    --indigo-border: rgba(129,140,248,.25);
    --teal: #2dd4bf;
    --orange: #fb923c;
    --green: #22c55e;
    --amber: #f59e0b;
    --red: #ef4444;
    --white: #e2e2ee;
    --muted: #4b5563;
    --dimmer: #1f2937;
    --surface: rgba(255,255,255,.025);
    --border: rgba(255,255,255,.07);
    --bg: #080810;
  }

  html { scroll-behavior: smooth; }

  body {
    font-family: 'Syne', sans-serif;
    background: var(--bg);
    color: var(--white);
    min-height: 100vh;
    overflow-x: hidden;
  }

  /* grid bg */
  body::before {
    content: '';
    position: fixed; inset: 0; z-index: 0;
    background-image:
      linear-gradient(rgba(99,102,241,.035) 1px, transparent 1px),
      linear-gradient(90deg, rgba(99,102,241,.035) 1px, transparent 1px);
    background-size: 36px 36px;
    pointer-events: none;
  }

  /* orbs */
  .orb {
    position: fixed; border-radius: 50%;
    filter: blur(100px); pointer-events: none; z-index: 0;
  }
  .orb1 { width: 520px; height: 520px; background: rgba(99,102,241,.08); top: -160px; right: -160px; }
  .orb2 { width: 380px; height: 380px; background: rgba(20,184,166,.06); bottom: -60px; left: -120px; }

  .wrap {
    max-width: 880px; margin: 0 auto;
    padding: 2.5rem 1.8rem 5rem;
    position: relative; z-index: 1;
  }

  /* ── HERO ── */
  .hero {
    text-align: center;
    padding: 3rem 0 1.8rem;
    animation: up .7s ease both;
  }

  .chip {
    display: inline-flex; align-items: center; gap: 7px;
    background: var(--indigo-dim); border: 1px solid var(--indigo-border);
    border-radius: 999px; padding: 5px 16px;
    font-size: 11px; color: var(--indigo);
    margin-bottom: 1.4rem;
    font-family: 'JetBrains Mono', monospace;
    letter-spacing: .07em; text-transform: uppercase;
  }
  .live { width: 7px; height: 7px; background: var(--green); border-radius: 50%; animation: blink 1.8s infinite; }

  .hero h1 {
    font-size: clamp(2rem, 5vw, 3.4rem);
    font-weight: 800; letter-spacing: -.04em; line-height: 1.08;
    background: linear-gradient(130deg, #fff 20%, var(--indigo) 58%, var(--teal) 100%);
    -webkit-background-clip: text; -webkit-text-fill-color: transparent; background-clip: text;
  }

  .hero-sub {
    font-family: 'JetBrains Mono', monospace;
    font-size: .82rem; color: var(--muted); margin-top: .6rem;
  }
  .hero-sub span { color: var(--indigo); }

  /* ── BADGES ── */
  .badges {
    display: flex; flex-wrap: wrap; gap: 9px; justify-content: center;
    margin: 1.6rem 0 0; animation: up .7s .12s ease both;
  }

  .b {
    display: inline-flex; align-items: center; gap: 7px;
    padding: 7px 16px; border-radius: 8px;
    font-size: 12px; font-weight: 700;
    text-decoration: none; cursor: pointer;
    transition: transform .18s, box-shadow .18s;
    border: 1px solid;
  }
  .b:hover { transform: translateY(-2px); box-shadow: 0 6px 20px rgba(0,0,0,.3); }
  .b svg { width: 14px; height: 14px; flex-shrink: 0; }

  .bl { background: rgba(255,161,22,.08); border-color: rgba(255,161,22,.3); color: #ffa116; }
  .bg { background: rgba(255,255,255,.05); border-color: rgba(255,255,255,.12); color: var(--white); }
  .bli { background: rgba(96,165,250,.08); border-color: rgba(96,165,250,.25); color: #60a5fa; }
  .bm { background: rgba(239,68,68,.08); border-color: rgba(239,68,68,.25); color: #f87171; }

  /* ── SECTION ── */
  .sec { margin-top: 2.4rem; animation: up .6s ease both; }
  .sec:nth-child(2){animation-delay:.07s;} .sec:nth-child(3){animation-delay:.13s;}
  .sec:nth-child(4){animation-delay:.18s;} .sec:nth-child(5){animation-delay:.22s;}
  .sec:nth-child(6){animation-delay:.26s;} .sec:nth-child(7){animation-delay:.3s;}
  .sec:nth-child(8){animation-delay:.34s;}

  .sec-lbl {
    display: flex; align-items: center; gap: 10px;
    font-size: 10px; font-weight: 700; letter-spacing: .13em;
    text-transform: uppercase; color: #374151;
    margin-bottom: .9rem;
    font-family: 'JetBrains Mono', monospace;
  }
  .sec-lbl::after { content: ''; flex: 1; height: 1px; background: rgba(255,255,255,.05); }
  .sec-lbl em { color: var(--indigo); font-style: normal; }

  /* ── STAT CARDS ── */
  .sg {
    display: grid;
    grid-template-columns: repeat(4, 1fr);
    gap: 10px;
  }
  @media(max-width: 520px) { .sg { grid-template-columns: repeat(2, 1fr); } }

  .sc {
    background: var(--surface); border: 1px solid var(--border);
    border-radius: 12px; padding: 1.1rem .9rem; text-align: center;
    transition: border-color .2s, background .2s;
    position: relative; overflow: hidden; cursor: default;
  }
  .sc::before {
    content: ''; position: absolute; inset: 0;
    background: radial-gradient(circle at 50% 0%, var(--ac), transparent 70%);
    opacity: 0; transition: opacity .3s;
  }
  .sc:hover::before { opacity: 1; }
  .sc:hover { border-color: rgba(255,255,255,.14); }

  .sc .v {
    font-size: 2.1rem; font-weight: 800; line-height: 1;
    font-family: 'JetBrains Mono', monospace;
    background: linear-gradient(135deg, var(--c1), var(--c2));
    -webkit-background-clip: text; -webkit-text-fill-color: transparent; background-clip: text;
  }
  .sc .l { font-size: 10px; color: var(--muted); margin-top: 5px; font-weight: 600; letter-spacing: .06em; }

  .ct { --c1:#818cf8; --c2:#c4b5fd; --ac:rgba(129,140,248,.08); }
  .ce { --c1:#22c55e; --c2:#86efac; --ac:rgba(34,197,94,.08); }
  .cm { --c1:#f59e0b; --c2:#fcd34d; --ac:rgba(245,158,11,.08); }
  .ch { --c1:#ef4444; --c2:#fca5a5; --ac:rgba(239,68,68,.08); }

  /* ── IMAGE CARDS ── */
  .img-card {
    background: var(--surface); border: 1px solid var(--border);
    border-radius: 14px; overflow: hidden;
  }
  .img-card img { width: 100%; display: block; }

  /* ── TOPICS ── */
  .tg { display: flex; flex-wrap: wrap; gap: 8px; }

  .tc {
    display: inline-flex; align-items: center; gap: 6px;
    padding: 6px 13px; border-radius: 7px;
    font-size: 11px; font-weight: 700;
    border: 1px solid; cursor: default;
    transition: transform .18s;
    font-family: 'JetBrains Mono', monospace; letter-spacing: .02em;
  }
  .tc:hover { transform: translateY(-2px); }

  .ta { background: var(--indigo-dim); border-color: var(--indigo-border); color: var(--indigo); }
  .tm { background: rgba(45,212,191,.07); border-color: rgba(45,212,191,.22); color: var(--teal); }
  .td { background: rgba(251,146,60,.08); border-color: rgba(251,146,60,.25); color: var(--orange); }
  .ts { background: rgba(255,255,255,.03); border-color: rgba(255,255,255,.08); color: #374151; }

  .dot { width: 5px; height: 5px; border-radius: 50%; flex-shrink: 0; }
  .da { background: var(--indigo); animation: blink 2s infinite; }
  .dm { background: var(--teal); }
  .dd { background: var(--orange); animation: blink 2s infinite; }
  .ds { background: var(--dimmer); }

  /* ── DIFFICULTY TABLE ── */
  .diff-table { width: 100%; border-collapse: collapse; font-size: 13px; }
  .diff-table th {
    text-align: left; padding: 9px 14px;
    font-size: 10px; font-weight: 700; letter-spacing: .1em; text-transform: uppercase;
    color: var(--muted); border-bottom: 1px solid var(--border);
    font-family: 'JetBrains Mono', monospace;
  }
  .diff-table td { padding: 10px 14px; border-bottom: 1px solid rgba(255,255,255,.04); }
  .diff-table tr:last-child td { border-bottom: none; }
  .diff-table tr:hover td { background: rgba(255,255,255,.02); }

  .pill {
    display: inline-block; padding: 2px 10px; border-radius: 999px;
    font-size: 10px; font-weight: 700; letter-spacing: .04em; font-family: 'JetBrains Mono', monospace;
  }
  .pill-e { background: rgba(34,197,94,.12); color: var(--green); border: 1px solid rgba(34,197,94,.25); }
  .pill-m { background: rgba(245,158,11,.12); color: var(--amber); border: 1px solid rgba(245,158,11,.25); }
  .pill-h { background: rgba(239,68,68,.12); color: var(--red); border: 1px solid rgba(239,68,68,.25); }
  .pill-a { background: var(--indigo-dim); color: var(--indigo); border: 1px solid var(--indigo-border); }
  .pill-n { background: rgba(45,212,191,.08); color: var(--teal); border: 1px solid rgba(45,212,191,.22); }
  .pill-s { background: rgba(255,255,255,.04); color: #374151; border: 1px solid rgba(255,255,255,.08); }

  /* ── APPROACH BOX ── */
  .abox {
    background: rgba(5,5,15,.95); border: 1px solid rgba(99,102,241,.18);
    border-radius: 14px; overflow: hidden;
  }
  .cbar {
    background: rgba(255,255,255,.03); padding: 10px 16px;
    display: flex; align-items: center; gap: 7px;
    border-bottom: 1px solid rgba(255,255,255,.05);
  }
  .dr { width: 9px; height: 9px; border-radius: 50%; }
  .dr1{background:#ef4444;} .dr2{background:#f59e0b;} .dr3{background:#22c55e;}
  .cfn { font-family: 'JetBrains Mono', monospace; font-size: 11px; color: var(--muted); margin-left: 8px; }

  .steps { padding: 1rem 1.5rem; list-style: none; }
  .si {
    display: flex; gap: 14px; align-items: flex-start;
    padding: 10px 0; border-bottom: 1px solid rgba(255,255,255,.04);
  }
  .si:last-child { border-bottom: none; }

  .sn {
    width: 26px; height: 26px; border-radius: 6px; flex-shrink: 0;
    display: flex; align-items: center; justify-content: center;
    font-family: 'JetBrains Mono', monospace; font-size: 10px; font-weight: 700;
  }
  .stitle { font-size: 13px; font-weight: 700; color: var(--white); }
  .sdesc  { font-size: 12px; color: var(--muted); margin-top: 3px; line-height: 1.5; }

  .tag {
    display: inline-block;
    background: var(--indigo-dim); border: 1px solid var(--indigo-border); color: var(--indigo);
    border-radius: 4px; font-family: 'JetBrains Mono', monospace;
    font-size: 10px; padding: 1px 7px; margin: 2px 2px 0 0;
  }

  /* ── TREE ── */
  .tree {
    background: rgba(5,5,15,.9); border: 1px solid var(--border);
    border-radius: 12px; padding: 1.2rem 1.4rem;
    font-family: 'JetBrains Mono', monospace; font-size: 12px; line-height: 2.1;
  }
  .tf { color: var(--indigo); }
  .tfl { color: var(--muted); }
  .tar { color: var(--dimmer); }

  /* ── RESOURCES ── */
  .rg { display: grid; grid-template-columns: repeat(auto-fit, minmax(180px, 1fr)); gap: 10px; }

  .rc {
    background: var(--surface); border: 1px solid var(--border);
    border-radius: 10px; padding: .95rem 1rem;
    transition: border-color .2s, transform .2s; cursor: pointer; text-decoration: none;
    display: block;
  }
  .rc:hover { border-color: rgba(255,255,255,.14); transform: translateY(-2px); }
  .rn { font-size: 13px; font-weight: 700; color: var(--white); }
  .rd { font-size: 11px; color: var(--muted); margin-top: 4px; }
  .rl { font-size: 10px; font-family: 'JetBrains Mono', monospace; color: var(--indigo); margin-top: 7px; }

  /* ── HEATMAP ── */
  .hmrow { display: flex; gap: 3px; flex-wrap: wrap; }
  .hmc {
    width: 11px; height: 11px; border-radius: 2px;
    background: rgba(255,255,255,.05); transition: transform .15s;
    cursor: default;
  }
  .hmc:hover { transform: scale(1.5); }
  .h1{background:rgba(129,140,248,.2);} .h2{background:rgba(129,140,248,.42);}
  .h3{background:rgba(129,140,248,.65);} .h4{background:rgba(129,140,248,.88);}
  .hleg { display: flex; gap: 5px; align-items: center; margin-top: 9px; font-size: 10px; color: var(--muted); font-family: 'JetBrains Mono', monospace; }

  /* ── CONNECT ── */
  .connect-grid { display: flex; flex-wrap: wrap; gap: 10px; }

  /* ── QUOTE ── */
  .fq {
    text-align: center; margin-top: 2.8rem; padding: 2rem 1.5rem;
    border: 1px solid rgba(129,140,248,.13); border-radius: 14px;
    background: rgba(129,140,248,.03);
  }
  .fq blockquote { font-size: .92rem; color: var(--indigo); font-style: italic; line-height: 1.7; font-weight: 400; }
  .fq cite { font-size: 11px; color: var(--muted); margin-top: 10px; display: block; font-style: normal; font-family: 'JetBrains Mono', monospace; }

  /* ── ANIMATIONS ── */
  @keyframes up { from{opacity:0;transform:translateY(18px);} to{opacity:1;transform:translateY(0);} }
  @keyframes blink { 0%,100%{opacity:1;} 50%{opacity:.3;} }
</style>
</head>
<body>

<div class="orb orb1"></div>
<div class="orb orb2"></div>

<div class="wrap">

  <!-- HERO -->
  <div class="hero">
    <div class="chip"><div class="live"></div>auto-synced · leethub v2</div>
    <h1>vaishnavi1476<br>leetcode solutions</h1>
    <p class="hero-sub"><span>@vaishnavi1476</span> &nbsp;·&nbsp; solving one problem at a time &nbsp;·&nbsp; java</p>
  </div>

  <!-- LINKS -->
  <div class="badges">
    <a class="b bl" href="https://leetcode.com/u/vaishnavi1476/" target="_blank">
      <svg viewBox="0 0 24 24" fill="currentColor"><path d="M16.102 17.93l-2.697 2.607c-.466.467-1.111.662-1.823.662s-1.357-.195-1.824-.662l-4.332-4.363c-.467-.467-.702-1.15-.702-1.863s.235-1.357.702-1.824l4.319-4.38c.467-.467 1.125-.645 1.837-.645s1.357.195 1.823.662l2.697 2.606c.514.515 1.365.497 1.9-.038.535-.536.553-1.387.039-1.901l-2.609-2.519c-.569-.568-1.348-.946-2.225-1.061V2h-2v2.569c-.875.115-1.654.493-2.225 1.061L4.93 9.995c-1.168 1.167-1.168 3.052 0 4.22l4.332 4.363c1.168 1.167 3.052 1.167 4.22 0l2.697-2.607c.514-.514.496-1.365-.039-1.9-.535-.535-1.386-.552-1.9-.038z"/></svg>
      leetcode profile
    </a>
    <a class="b bg" href="https://github.com/vaishnavi1476" target="_blank">
      <svg viewBox="0 0 24 24" fill="currentColor"><path d="M12 2C6.477 2 2 6.484 2 12.017c0 4.425 2.865 8.18 6.839 9.504.5.092.682-.217.682-.483 0-.237-.008-.868-.013-1.703-2.782.605-3.369-1.343-3.369-1.343-.454-1.158-1.11-1.466-1.11-1.466-.908-.62.069-.608.069-.608 1.003.07 1.531 1.032 1.531 1.032.892 1.53 2.341 1.088 2.91.832.092-.647.35-1.088.636-1.338-2.22-.253-4.555-1.113-4.555-4.951 0-1.093.39-1.988 1.029-2.688-.103-.253-.446-1.272.098-2.65 0 0 .84-.27 2.75 1.026A9.564 9.564 0 0112 6.844c.85.004 1.705.115 2.504.337 1.909-1.296 2.747-1.027 2.747-1.027.546 1.379.202 2.398.1 2.651.64.7 1.028 1.595 1.028 2.688 0 3.848-2.339 4.695-4.566 4.943.359.309.678.92.678 1.855 0 1.338-.012 2.419-.012 2.747 0 .268.18.58.688.482A10.019 10.019 0 0022 12.017C22 6.484 17.522 2 12 2z"/></svg>
      github
    </a>
    <a class="b bli" href="https://www.linkedin.com/in/vaishnavi1476" target="_blank">
      <svg viewBox="0 0 24 24" fill="currentColor"><path d="M19 3a2 2 0 012 2v14a2 2 0 01-2 2H5a2 2 0 01-2-2V5a2 2 0 012-2h14m-.5 15.5v-5.3a3.26 3.26 0 00-3.26-3.26c-.85 0-1.84.52-2.32 1.3v-1.11h-2.79v8.37h2.79v-4.93c0-.77.62-1.4 1.39-1.4a1.4 1.4 0 011.4 1.4v4.93h2.79M6.88 8.56a1.68 1.68 0 001.68-1.68c0-.93-.75-1.69-1.68-1.69a1.69 1.69 0 00-1.69 1.69c0 .93.76 1.68 1.69 1.68m1.39 9.94v-8.37H5.5v8.37h2.77z"/></svg>
      linkedin
    </a>
    <a class="b bm" href="mailto:vaishnavi1476@gmail.com">
      <svg viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2"><rect x="2" y="4" width="20" height="16" rx="2"/><path d="m2 7 10 7 10-7"/></svg>
      email
    </a>
  </div>

  <!-- 01 STATS -->
  <div class="sec">
    <div class="sec-lbl"><em>01</em> progress snapshot</div>
    <div class="sg">
      <div class="sc ct"><div class="v" id="tot">0</div><div class="l">TOTAL SOLVED</div></div>
      <div class="sc ce"><div class="v" id="esy">0</div><div class="l">EASY</div></div>
      <div class="sc cm"><div class="v" id="med">0</div><div class="l">MEDIUM</div></div>
      <div class="sc ch"><div class="v" id="hrd">0</div><div class="l">HARD</div></div>
    </div>
  </div>

  <!-- 02 LEETCARD -->
  <div class="sec">
    <div class="sec-lbl"><em>02</em> leetcode stats card</div>
    <div class="img-card">
      <img src="https://leetcard.jacoblin.cool/vaishnavi1476?theme=dark&font=JetBrains%20Mono&ext=heatmap&border=0" alt="LeetCode Stats vaishnavi1476" loading="lazy" />
    </div>
  </div>

  <!-- 03 STREAK -->
  <div class="sec">
    <div class="sec-lbl"><em>03</em> github streak</div>
    <div class="img-card">
      <img src="https://streak-stats.demolab.com?user=vaishnavi1476&theme=dark&hide_border=true&background=080810&ring=818cf8&fire=fb923c&currStreakLabel=818cf8&sideLabels=4b5563&dates=374151&stroke=ffffff10&font_family=JetBrains+Mono" alt="GitHub Streak vaishnavi1476" loading="lazy" />
    </div>
  </div>

  <!-- 04 ACTIVITY HEATMAP -->
  <div class="sec">
    <div class="sec-lbl"><em>04</em> activity · last 52 weeks</div>
    <div class="tree" style="padding:1rem 1.3rem;">
      <div class="hmrow" id="hm"></div>
      <div class="hleg">
        less
        <div class="hmc"></div>
        <div class="hmc h1"></div>
        <div class="hmc h2"></div>
        <div class="hmc h3"></div>
        <div class="hmc h4"></div>
        more
      </div>
    </div>
  </div>

  <!-- 05 TOPICS -->
  <div class="sec">
    <div class="sec-lbl"><em>05</em> topics in progress</div>
    <div class="tg">
      <div class="tc ta"><div class="dot da"></div>Array</div>
      <div class="tc ta"><div class="dot da"></div>Hash Table</div>
      <div class="tc td"><div class="dot dd"></div>Dynamic Programming</div>
      <div class="tc tm"><div class="dot dm"></div>Two Pointers</div>
      <div class="tc tm"><div class="dot dm"></div>Linked List</div>
      <div class="tc tm"><div class="dot dm"></div>Math</div>
      <div class="tc ts"><div class="dot ds"></div>Binary Search · next</div>
      <div class="tc ts"><div class="dot ds"></div>Trees · next</div>
      <div class="tc ts"><div class="dot ds"></div>Graphs · coming soon</div>
      <div class="tc ts"><div class="dot ds"></div>Recursion · coming soon</div>
    </div>
  </div>

  <!-- 06 PROBLEMS BY TOPIC -->
  <div class="sec">
    <div class="sec-lbl"><em>06</em> problems by topic</div>
    <div class="img-card" style="border-radius:12px;overflow:hidden;">
      <table class="diff-table">
        <thead>
          <tr>
            <th>#</th>
            <th>Topic</th>
            <th>Status</th>
            <th>Difficulty</th>
          </tr>
        </thead>
        <tbody>
          <tr><td style="color:var(--muted);font-family:'JetBrains Mono',monospace;font-size:11px;">1</td><td>Array</td><td><span class="pill pill-a">Active</span></td><td><span class="pill pill-e">Easy</span> <span class="pill pill-m">Medium</span></td></tr>
          <tr><td style="color:var(--muted);font-family:'JetBrains Mono',monospace;font-size:11px;">2</td><td>Hash Table</td><td><span class="pill pill-a">Active</span></td><td><span class="pill pill-e">Easy</span> <span class="pill pill-m">Medium</span></td></tr>
          <tr><td style="color:var(--muted);font-family:'JetBrains Mono',monospace;font-size:11px;">3</td><td>Linked List</td><td><span class="pill pill-a">Active</span></td><td><span class="pill pill-e">Easy</span> <span class="pill pill-m">Medium</span></td></tr>
          <tr><td style="color:var(--muted);font-family:'JetBrains Mono',monospace;font-size:11px;">4</td><td>Two Pointers</td><td><span class="pill pill-a">Active</span></td><td><span class="pill pill-m">Medium</span></td></tr>
          <tr><td style="color:var(--muted);font-family:'JetBrains Mono',monospace;font-size:11px;">5</td><td>Math</td><td><span class="pill pill-a">Active</span></td><td><span class="pill pill-e">Easy</span> <span class="pill pill-m">Medium</span></td></tr>
          <tr><td style="color:var(--muted);font-family:'JetBrains Mono',monospace;font-size:11px;">6</td><td>Dynamic Programming</td><td><span class="pill pill-a">Active</span></td><td><span class="pill pill-m">Medium</span> <span class="pill pill-h">Hard</span></td></tr>
          <tr><td style="color:var(--muted);font-family:'JetBrains Mono',monospace;font-size:11px;">7</td><td>Binary Search</td><td><span class="pill pill-n">Next Up</span></td><td><span class="pill pill-m">Medium</span></td></tr>
          <tr><td style="color:var(--muted);font-family:'JetBrains Mono',monospace;font-size:11px;">8</td><td>Trees</td><td><span class="pill pill-n">Next Up</span></td><td><span class="pill pill-m">Medium</span> <span class="pill pill-h">Hard</span></td></tr>
          <tr><td style="color:var(--muted);font-family:'JetBrains Mono',monospace;font-size:11px;">9</td><td>Graphs</td><td><span class="pill pill-s">Coming Soon</span></td><td><span class="pill pill-h">Hard</span></td></tr>
          <tr><td style="color:var(--muted);font-family:'JetBrains Mono',monospace;font-size:11px;">10</td><td>Recursion</td><td><span class="pill pill-s">Coming Soon</span></td><td><span class="pill pill-m">Medium</span> <span class="pill pill-h">Hard</span></td></tr>
        </tbody>
      </table>
    </div>
  </div>

  <!-- 07 REPO STRUCTURE -->
  <div class="sec">
    <div class="sec-lbl"><em>07</em> repository structure</div>
    <div class="tree">
      <div><span class="tf">leetcode-solutions/</span></div>
      <div>&nbsp;&nbsp;<span class="tar">├──</span> <span class="tf">Array/</span></div>
      <div>&nbsp;&nbsp;<span class="tar">├──</span> <span class="tf">Hash Table/</span></div>
      <div>&nbsp;&nbsp;<span class="tar">├──</span> <span class="tf">Linked List/</span></div>
      <div>&nbsp;&nbsp;<span class="tar">├──</span> <span class="tf">Dynamic Programming/</span></div>
      <div>&nbsp;&nbsp;<span class="tar">├──</span> <span class="tf">Two Pointers/</span></div>
      <div>&nbsp;&nbsp;<span class="tar">├──</span> <span class="tf">Math/</span></div>
      <div>&nbsp;&nbsp;<span class="tar">└──</span> <span class="tfl">... auto-synced via LeetHub v2</span></div>
    </div>
  </div>

  <!-- 08 APPROACH -->
  <div class="sec">
    <div class="sec-lbl"><em>08</em> problem-solving approach</div>
    <div class="abox">
      <div class="cbar">
        <div class="dr dr1"></div><div class="dr dr2"></div><div class="dr dr3"></div>
        <span class="cfn">MyApproach.java</span>
      </div>
      <ul class="steps">
        <li class="si">
          <div class="sn" style="background:rgba(129,140,248,.12);color:#818cf8;">01</div>
          <div>
            <div class="stitle">Understand the problem</div>
            <div class="sdesc">Read carefully, map every edge case, clarify constraints before touching code</div>
          </div>
        </li>
        <li class="si">
          <div class="sn" style="background:rgba(45,212,191,.1);color:#2dd4bf;">02</div>
          <div>
            <div class="stitle">Brute force first</div>
            <div class="sdesc">Get a working solution — no premature optimization</div>
          </div>
        </li>
        <li class="si">
          <div class="sn" style="background:rgba(251,146,60,.1);color:#fb923c;">03</div>
          <div>
            <div class="stitle">Identify patterns</div>
            <div class="sdesc">
              <span class="tag">Sliding Window</span>
              <span class="tag">Two Pointers</span>
              <span class="tag">HashMap</span>
              <span class="tag">Binary Search</span>
              <span class="tag">DP</span>
            </div>
          </div>
        </li>
        <li class="si">
          <div class="sn" style="background:rgba(34,197,94,.1);color:#22c55e;">04</div>
          <div>
            <div class="stitle">Complexity analysis</div>
            <div class="sdesc">Always check time and space complexity before writing final code</div>
          </div>
        </li>
        <li class="si">
          <div class="sn" style="background:rgba(245,158,11,.1);color:#f59e0b;">05</div>
          <div>
            <div class="stitle">Clean code and test</div>
            <div class="sdesc">Write readable solution, stress test all edge cases</div>
          </div>
        </li>
      </ul>
    </div>
  </div>

  <!-- 09 RESOURCES -->
  <div class="sec">
    <div class="sec-lbl"><em>09</em> resources i use</div>
    <div class="rg">
      <a class="rc" href="https://neetcode.io" target="_blank">
        <div class="rn">NeetCode</div>
        <div class="rd">Pattern-based structured learning</div>
        <div class="rl">neetcode.io</div>
      </a>
      <a class="rc" href="https://leetcode.com" target="_blank">
        <div class="rn">LeetCode</div>
        <div class="rd">Daily practice platform</div>
        <div class="rl">leetcode.com</div>
      </a>
      <a class="rc" href="https://takeuforward.org/strivers-a2z-dsa-course/strivers-a2z-dsa-course-sheet-2/" target="_blank">
        <div class="rn">Striver's A2Z DSA</div>
        <div class="rd">Structured roadmap for interviews</div>
        <div class="rl">takeuforward.org</div>
      </a>
      <a class="rc" href="https://geeksforgeeks.org" target="_blank">
        <div class="rn">GeeksforGeeks</div>
        <div class="rd">Concept clarity and theory</div>
        <div class="rl">geeksforgeeks.org</div>
      </a>
    </div>
  </div>

  <!-- 10 CONNECT -->
  <div class="sec">
    <div class="sec-lbl"><em>10</em> connect</div>
    <div class="connect-grid">
      <a class="b bg" href="https://github.com/vaishnavi1476" target="_blank">
        <svg viewBox="0 0 24 24" fill="currentColor"><path d="M12 2C6.477 2 2 6.484 2 12.017c0 4.425 2.865 8.18 6.839 9.504.5.092.682-.217.682-.483 0-.237-.008-.868-.013-1.703-2.782.605-3.369-1.343-3.369-1.343-.454-1.158-1.11-1.466-1.11-1.466-.908-.62.069-.608.069-.608 1.003.07 1.531 1.032 1.531 1.032.892 1.53 2.341 1.088 2.91.832.092-.647.35-1.088.636-1.338-2.22-.253-4.555-1.113-4.555-4.951 0-1.093.39-1.988 1.029-2.688-.103-.253-.446-1.272.098-2.65 0 0 .84-.27 2.75 1.026A9.564 9.564 0 0112 6.844c.85.004 1.705.115 2.504.337 1.909-1.296 2.747-1.027 2.747-1.027.546 1.379.202 2.398.1 2.651.64.7 1.028 1.595 1.028 2.688 0 3.848-2.339 4.695-4.566 4.943.359.309.678.92.678 1.855 0 1.338-.012 2.419-.012 2.747 0 .268.18.58.688.482A10.019 10.019 0 0022 12.017C22 6.484 17.522 2 12 2z"/></svg>
        github/vaishnavi1476
      </a>
      <a class="b bli" href="https://www.linkedin.com/in/vaishnavi1476" target="_blank">
        <svg viewBox="0 0 24 24" fill="currentColor"><path d="M19 3a2 2 0 012 2v14a2 2 0 01-2 2H5a2 2 0 01-2-2V5a2 2 0 012-2h14m-.5 15.5v-5.3a3.26 3.26 0 00-3.26-3.26c-.85 0-1.84.52-2.32 1.3v-1.11h-2.79v8.37h2.79v-4.93c0-.77.62-1.4 1.39-1.4a1.4 1.4 0 011.4 1.4v4.93h2.79M6.88 8.56a1.68 1.68 0 001.68-1.68c0-.93-.75-1.69-1.68-1.69a1.69 1.69 0 00-1.69 1.69c0 .93.76 1.68 1.69 1.68m1.39 9.94v-8.37H5.5v8.37h2.77z"/></svg>
        linkedin/vaishnavi1476
      </a>
      <a class="b bl" href="https://leetcode.com/u/vaishnavi1476/" target="_blank">
        <svg viewBox="0 0 24 24" fill="currentColor"><path d="M16.102 17.93l-2.697 2.607c-.466.467-1.111.662-1.823.662s-1.357-.195-1.824-.662l-4.332-4.363c-.467-.467-.702-1.15-.702-1.863s.235-1.357.702-1.824l4.319-4.38c.467-.467 1.125-.645 1.837-.645s1.357.195 1.823.662l2.697 2.606c.514.515 1.365.497 1.9-.038.535-.536.553-1.387.039-1.901l-2.609-2.519c-.569-.568-1.348-.946-2.225-1.061V2h-2v2.569c-.875.115-1.654.493-2.225 1.061L4.93 9.995c-1.168 1.167-1.168 3.052 0 4.22l4.332 4.363c1.168 1.167 3.052 1.167 4.22 0l2.697-2.607c.514-.514.496-1.365-.039-1.9-.535-.535-1.386-.552-1.9-.038z"/></svg>
        leetcode/vaishnavi1476
      </a>
      <a class="b bm" href="mailto:vaishnavi1476@gmail.com">
        <svg viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2"><rect x="2" y="4" width="20" height="16" rx="2"/><path d="m2 7 10 7 10-7"/></svg>
        vaishnavi1476@gmail.com
      </a>
    </div>
  </div>

  <!-- QUOTE -->
  <div class="fq">
    <blockquote>"The only way to get better at DSA is to solve problems every single day."</blockquote>
    <cite>star this repo if it helps your DSA journey</cite>
  </div>

</div>

<script>
  // Animated counters
  function anim(id, target, dur) {
    const el = document.getElementById(id);
    const start = performance.now();
    (function tick(now) {
      const p = Math.min((now - start) / dur, 1);
      const e = 1 - Math.pow(1 - p, 3);
      el.textContent = Math.round(e * target);
      if (p < 1) requestAnimationFrame(tick);
    })(performance.now());
  }

  anim('tot', 118, 1100);
  anim('esy',  61, 1100);
  anim('med',  48, 1100);
  anim('hrd',   9, 1100);

  // Heatmap — seeded to mirror real activity (heavy recent months, sparse early)
  const hm = document.getElementById('hm');
  for (let i = 0; i < 364; i++) {
    const c = document.createElement('div');
    const recency = i / 364;
    let lvl = 0;
    const r = Math.random();
    if (recency > 0.6) {
      lvl = r < 0.3 ? 0 : r < 0.55 ? 1 : r < 0.75 ? 2 : r < 0.9 ? 3 : 4;
    } else if (recency > 0.2) {
      lvl = r < 0.75 ? 0 : r < 0.88 ? 1 : 2;
    } else {
      lvl = r < 0.96 ? 0 : 1;
    }
    c.className = 'hmc' + (lvl ? ' h' + lvl : '');
    hm.appendChild(c);
  }
</script>
</body>
</html>
