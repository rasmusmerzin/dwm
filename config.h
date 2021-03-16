static const unsigned int borderpx = 2;
static const unsigned int snap = 12;
static const int showbar = 1;
static const int topbar = 1;
static const char *fonts[] = { "Fira Code:size=8" };
static const char dmenufont[] = "Fira Code:size=8";
static const char col_bg[] = "#1c1c1c";
static const char col_sh[] = "#444444";
static const char col_hl[] = "#bbbbbb";
static const char col_fg[] = "#ffffff";
static const char *colors[][3] = {
	[SchemeNorm] = { col_fg, col_bg, col_bg },
	[SchemeSel] = { col_fg, col_sh, col_hl },
};

static const char *tags[] = { "1", "2", "3", "4" };

static const Rule rules[] = {
	{ "st", NULL, NULL, 0, 0, -1 },
};

static const float mfact = 0.5;
static const int nmaster = 1;
static const int resizehints = 0;

static const Layout layouts[] = {
	{ "[=]", tile },
	{ "</>", NULL },
	{ "[M]", monocle },
};

#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY, view,       {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY, toggleview, {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY, tag,        {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY, toggletag,  {.ui = 1 << TAG} },

static char dmenumon[2] = "0";
static const char *dmenucmd[] = {
	"dmenu_run",
	"-m", dmenumon,
	"-fn", dmenufont,
	"-nb", col_bg,
	"-nf", col_fg,
	"-sb", col_sh,
	"-sf", col_fg,
	NULL
};
static const char *termcmd[] = { "st", NULL };
static const char *lockcmd[] = { "slock", NULL };
static const char *webcmd[] = { "xdg-open", "http://", NULL };
static const char *xkbcmd[] = { "cyclexkbmap", "us", "ee", NULL };
static const char *unicodecmd[] = { "ufuzz", NULL };
static const char *printcmd[] = {
	"scrot",
	"-e", "mkdir -p ~/Screenshots; mv $f ~/Screenshots",
	NULL
};
static const char *snipcmd[] = {
	"scrot",
	"-s",
	"-e", "mkdir -p ~/Screenshots; mv $f ~/Screenshots",
	NULL
};
static const char *colorcmd[] = {
	"sh",
	"-c", "printf '%b' \"$(xcolor)\" | xsel -b",
	NULL
};

static Key keys[] = {
	{ MODKEY,            XK_r,       spawn,           {.v = dmenucmd } },
	{ MODKEY,            XK_Return,  spawn,           {.v = termcmd } },
	{ MODKEY,            XK_x,       spawn,           {.v = lockcmd } },
	{ MODKEY,            XK_w,       spawn,           {.v = webcmd } },
	{ MODKEY,            XK_space,   spawn,           {.v = xkbcmd } },
	{ MODKEY,            XK_u,       spawn,           {.v = unicodecmd } },
	{ MODKEY,            XK_Print,   spawn,           {.v = printcmd } },
	{ MODKEY|ShiftMask,  XK_Print,   spawn,           {.v = snipcmd } },
	{ MODKEY,            XK_c,       spawn,           {.v = colorcmd } },
	{ MODKEY,            XK_b,       togglebar,       {0} },
	{ MODKEY,            XK_j,       focusstack,      {.i = +1 } },
	{ MODKEY,            XK_k,       focusstack,      {.i = -1 } },
	{ MODKEY,            XK_i,       incnmaster,      {.i = +1 } },
	{ MODKEY,            XK_d,       incnmaster,      {.i = -1 } },
	{ MODKEY,            XK_h,       setmfact,        {.f = -0.05} },
	{ MODKEY,            XK_l,       setmfact,        {.f = +0.05} },
	{ MODKEY,            XK_g,       zoom,            {0} },
	{ MODKEY,            XK_t,       setlayout,       {.v = &layouts[0]} },
	{ MODKEY,            XK_f,       setlayout,       {.v = &layouts[1]} },
	{ MODKEY,            XK_m,       setlayout,       {.v = &layouts[2]} },
	{ MODKEY,            XK_Tab,     togglefloating,  {0} },
	{ MODKEY,            XK_0,       view,            {.ui = ~0 } },
	{ MODKEY|ShiftMask,  XK_0,       tag,             {.ui = ~0 } },
	{ MODKEY,            XK_comma,   focusmon,        {.i = -1 } },
	{ MODKEY,            XK_period,  focusmon,        {.i = +1 } },
	{ MODKEY|ShiftMask,  XK_comma,   tagmon,          {.i = -1 } },
	{ MODKEY|ShiftMask,  XK_period,  tagmon,          {.i = +1 } },
	{ MODKEY,            XK_Escape,  killclient,      {0} },
	{ MODKEY|ShiftMask,  XK_q,       quit,            {0} },

	TAGKEYS(XK_1, 0)
	TAGKEYS(XK_2, 1)
	TAGKEYS(XK_3, 2)
	TAGKEYS(XK_4, 3)
};

static Button buttons[] = {
	{ ClkLtSymbol,   0,       Button1,  setlayout,    {0} },
	{ ClkLtSymbol,   0,       Button3,  setlayout,    {.v = &layouts[2]} },
	{ ClkClientWin,  MODKEY,  Button1,  movemouse,    {0} },
	{ ClkClientWin,  MODKEY,  Button3,  resizemouse,  {0} },
	{ ClkTagBar,     0,       Button1,  view,         {0} },
	{ ClkTagBar,     0,       Button3,  toggleview,   {0} },
	{ ClkTagBar,     MODKEY,  Button1,  tag,          {0} },
	{ ClkTagBar,     MODKEY,  Button3,  toggletag,    {0} },
};
