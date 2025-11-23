/* See LICENSE file for copyright and license details. */

/* Helper macros for spawning commands */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }
#define CMD(...)   { .v = (const char*[]){ __VA_ARGS__, NULL } }

/* appearance */
static const unsigned int borderpx       = 3;   /* border pixel of windows */
static const unsigned int snap           = 32;  /* snap pixel */
static const int swallowfloating         = 1;   /* 1 means swallow floating windows by default */
static const unsigned int gappih         = 10;  /* horiz inner gap between windows */
static const unsigned int gappiv         = 10;  /* vert inner gap between windows */
static const unsigned int gappoh         = 10;  /* horiz outer gap between windows and screen edge */
static const unsigned int gappov         = 10;  /* vert outer gap between windows and screen edge */
static const int smartgaps_fact          = 3;   /* gap factor when there is only one client; 0 = no gaps, 3 = 3x outer gaps */
static const int showbar                 = 0;   /* 0 means no bar */
static const int topbar                  = 1;   /* 0 means bottom bar */
static const int focusonwheel            = 0;
static int floatposgrid_x                = 5;  /* float grid columns */
static int floatposgrid_y                = 5;  /* float grid rows */
/* Status is to be shown on: -1 (all monitors), 0 (a specific monitor by index), 'A' (active monitor) */
static const int statusmon               = -1;

/* alt-tab configuration */
static const unsigned int tabmodkey        = 0x40; /* (Alt) when this key is held down the alt-tab functionality stays active. Must be the same modifier as used to run alttabstart */
static const unsigned int tabcyclekey      = 0x17; /* (Tab) when this key is hit the menu moves one position forward in client stack. Must be the same key as used to run alttabstart */
static const unsigned int tabposy          = 1;    /* tab position on Y axis, 0 = top, 1 = center, 2 = bottom */
static const unsigned int tabposx          = 1;    /* tab position on X axis, 0 = left, 1 = center, 2 = right */
static const unsigned int maxwtab          = 600;  /* tab menu width */
static const unsigned int maxhtab          = 200;  /* tab menu height */

/* Indicators: see patch/bar_indicators.h for options */
static int tagindicatortype              = INDICATOR_TOP_LEFT_SQUARE;
static int tiledindicatortype            = INDICATOR_NONE;
static int floatindicatortype            = INDICATOR_TOP_LEFT_SQUARE;
static int aotindicatortype              = INDICATOR_TOP_LEFT_LARGER_SQUARE;
static const char *fonts[] = {
    "Iosevka Nerd Font:size=21:style=Extended",
    "Font Awesome 6 Free:size=19",
    "Material Design Icons Desktop:size=18"
};
static const char dmenufont[] = "Iosevka Nerd Font:size=18:style=Extended";

static char c000000[]                    = "#141414"; // placeholder value

static char normfgcolor[]                = "#a7a7a7";
static char normbgcolor[]                = "#141414";
static char normbordercolor[]            = "#141414";
static char normfloatcolor[]             = "#303030";
static const char col_borderbar[]   	 = "#141414";

static char selfgcolor[]                 = "#5b6976";
static char selbgcolor[]                 = "#141414";
static char selbordercolor[]             = "#505050";
static char selfloatcolor[]              = "#505050";

static char titlenormfgcolor[]           = "#a7a7a7";
static char titlenormbgcolor[]           = "#141414";
static char titlenormbordercolor[]       = "#141414";
static char titlenormfloatcolor[]        = "#303030";

static char titleselfgcolor[]            = "#5b6976";
static char titleselbgcolor[]            = "#141414";
static char titleselbordercolor[]        = "#141414";
static char titleselfloatcolor[]         = "#a7a7a7";

static char tagsnormfgcolor[]            = "#303030";
static char tagsnormbgcolor[]            = "#141414";
static char tagsnormbordercolor[]        = "#141414";
static char tagsnormfloatcolor[]         = "#303030";

static char tagsselfgcolor[]             = "#5b6976";
static char tagsselbgcolor[]             = "#141414";
static char tagsselbordercolor[]         = "#141414";
static char tagsselfloatcolor[]          = "#a7a7a7";

static char hidnormfgcolor[]             = "#a7a7a7";
static char hidselfgcolor[]              = "#5b6976";
static char hidnormbgcolor[]             = "#222222";
static char hidselbgcolor[]              = "#222222";

static char urgfgcolor[]                 = "#755a5b";
static char urgbgcolor[]                 = "#141414";
static char urgbordercolor[]             = "#755a5b";
static char urgfloatcolor[]              = "#755a5b";

static char *colors[][ColCount] = {
	/*                       fg                bg                border                float */
	[SchemeNorm]         = { normfgcolor,      normbgcolor,      normbordercolor,      normfloatcolor },
	[SchemeSel]          = { selfgcolor,       selbgcolor,       selbordercolor,       selfloatcolor },
	[SchemeTitleNorm]    = { titlenormfgcolor, titlenormbgcolor, titlenormbordercolor, titlenormfloatcolor },
	[SchemeTitleSel]     = { titleselfgcolor,  titleselbgcolor,  titleselbordercolor,  titleselfloatcolor },
	[SchemeTagsNorm]     = { tagsnormfgcolor,  tagsnormbgcolor,  tagsnormbordercolor,  tagsnormfloatcolor },
	[SchemeTagsSel]      = { tagsselfgcolor,   tagsselbgcolor,   tagsselbordercolor,   tagsselfloatcolor },
	[SchemeHidNorm]      = { hidnormfgcolor,   hidnormbgcolor,   c000000,              c000000 },
	[SchemeHidSel]       = { hidselfgcolor,    hidselbgcolor,    c000000,              c000000 },
	[SchemeUrg]          = { urgfgcolor,       urgbgcolor,       urgbordercolor,       urgfloatcolor },
};

const char *spcmd1[] = {"st", "-n", "spterm", "-g", "120x34", NULL };
static Sp scratchpads[] = {
   /* name          cmd  */
   {"spterm",      spcmd1},
};

/* Tags
 * In a traditional dwm the number of tags in use can be changed simply by changing the number
 * of strings in the tags array. This build does things a bit different which has some added
 * benefits. If you need to change the number of tags here then change the NUMTAGS macro in dwm.c.
 *
 * Examples:
 *
 *  1) static char *tagicons[][NUMTAGS*2] = {
 *         [DEFAULT_TAGS] = { "1", "2", "3", "4", "5", "6", "7", "8", "9", "A", "B", "C", "D", "E", "F", "G", "H", "I" },
 *     }
 *
 *  2) static char *tagicons[][1] = {
 *         [DEFAULT_TAGS] = { "•" },
 *     }
 *
 * The first example would result in the tags on the first monitor to be 1 through 9, while the
 * tags for the second monitor would be named A through I. A third monitor would start again at
 * 1 through 9 while the tags on a fourth monitor would also be named A through I. Note the tags
 * count of NUMTAGS*2 in the array initialiser which defines how many tag text / icon exists in
 * the array. This can be changed to *3 to add separate icons for a third monitor.
 *
 * For the second example each tag would be represented as a bullet point. Both cases work the
 * same from a technical standpoint - the icon index is derived from the tag index and the monitor
 * index. If the icon index is is greater than the number of tag icons then it will wrap around
 * until it an icon matches. Similarly if there are two tag icons then it would alternate between
 * them. This works seamlessly with alternative tags and alttagsdecoration patches.
 */

static char *tagicons[][NUMTAGS] = {
    [DEFAULT_TAGS]        = { "α", "β", "γ", "δ", "ε" },
    [ALTERNATIVE_TAGS]    = { "Α", "Β", "Γ", "Δ", "Ε" },
    [ALT_TAGS_DECORATION] = { "<α>", "<β>", "<γ>", "<δ>", "<ε>" },
};


/* There are two options when it comes to per-client rules:
 *  - a typical struct table or
 *  - using the RULE macro
 *
 * A traditional struct table looks like this:
 *    // class      instance  title  wintype  tags mask  isfloating  monitor
 *    { "Gimp",     NULL,     NULL,  NULL,    1 << 4,    0,          -1 },
 *    { "Firefox",  NULL,     NULL,  NULL,    1 << 7,    0,          -1 },
 *
 * The RULE macro has the default values set for each field allowing you to only
 * specify the values that are relevant for your rule, e.g.
 *
 *    RULE(.class = "Gimp", .tags = 1 << 4)
 *    RULE(.class = "Firefox", .tags = 1 << 7)
 *
 * Refer to the Rule struct definition for the list of available fields depending on
 * the patches you enable.
 */
static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 *	WM_WINDOW_ROLE(STRING) = role
	 *	_NET_WM_WINDOW_TYPE(ATOM) = wintype
	 */
	RULE(.wintype = WTYPE "DIALOG", .isfloating = 1)
	RULE(.wintype = WTYPE "UTILITY", .isfloating = 1)
	RULE(.wintype = WTYPE "TOOLBAR", .isfloating = 1)
	RULE(.wintype = WTYPE "SPLASH", .isfloating = 1)
	RULE(.instance = "spterm", .tags = SPTAG(0), .isfloating = 1)
	RULE(.class = "Brave-browser", .title = "Picture in picture", .isfloating = 1, .iscentered = 1)
	RULE(.class = "Brave-browser", .role = "pop-up", .isfloating = 1, .iscentered = 1)

};

/* Bar rules allow you to configure what is shown where on the bar, as well as
 * introducing your own bar modules.
 *
 *    monitor:
 *      -1  show on all monitors
 *       0  show on monitor 0
 *      'A' show on active monitor (i.e. focused / selected) (or just -1 for active?)
 *    bar - bar index, 0 is default, 1 is extrabar
 *    alignment - how the module is aligned compared to other modules
 *    widthfunc, drawfunc, clickfunc - providing bar module width, draw and click functions
 *    name - does nothing, intended for visual clue and for logging / debugging
 */
static const BarRule barrules[] = {
	/* monitor   bar    alignment         widthfunc       drawfunc        clickfunc        hoverfunc      name */
	{ -1,        0,     BAR_ALIGN_CENTER, width_tags,     draw_tags,      click_tags,      hover_tags,    "tags" },
	{ -1,        0,     BAR_ALIGN_CENTER, width_ltsymbol, draw_ltsymbol,  click_ltsymbol,  NULL,          "layout" },
	{ statusmon, 0,     BAR_ALIGN_RIGHT,  width_status,   draw_status,    click_status,    NULL,          "status" },
};


/* layout(s) */
static const float mfact     = 0.50; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int nstack      = 0;    /* number of clients in primary stack area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

static const Layout layouts[] = {
	/* symbol     arrange function, { nmaster, nstack, layout, master axis, stack axis, secondary stack axis, symbol func } */
	{ "[\\]",     flextile,         { -1, -1, NO_SPLIT, DWINDLE, DWINDLE, 0, NULL } }, // fibonacci dwindle
	{ "[]=",      flextile,         { -1, -1, SPLIT_VERTICAL, TOP_TO_BOTTOM, TOP_TO_BOTTOM, 0, NULL } }, // tile
	{ "|M|",      flextile,         { -1, -1, SPLIT_CENTERED_VERTICAL, LEFT_TO_RIGHT, TOP_TO_BOTTOM, TOP_TO_BOTTOM, NULL } }, // centeredmaster
	{ "[M]",      flextile,         { -1, -1, NO_SPLIT, MONOCLE, MONOCLE, 0, NULL } }, // monocle
 	{ "><>",      NULL,             {0} },    /* no layout function means floating behavior */
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = {
	"dmenu_run",
	"-m", dmenumon,
	"-fn", dmenufont,
	"-nb", normbgcolor,
	"-nf", normfgcolor,
	"-sb", selbgcolor,
	"-sf", selfgcolor,
	NULL
};
static const char *termcmd[]  = { "st", NULL };

/*
* Xresources preferences to load at startup.
*
*     Name                      Type       Address
*    ------------------------------------------------
*     "nmaster"                 INTEGER    &nmaster
*     "mfact"                   FLOAT      &mfact
*     "color1"                  STRING     &color1
*
* In the Xresources file setting resources shoud be prefixed with "dwm.", e.g.
*
*    dwm.nmaster: 1
*    dwm.mfact: 0.50
*    dwm.color1: #FA6EFA
*
* Note that the const qualifier must be removed from the variables if you plan on
* overriding them with values from Xresources. While resources can be reloaded
* using the xrdb function some changes may only take effect following a restart.
*/
ResourcePref resources[] = {
	/* Resource name            Type       Address                */
	{ "normfgcolor",            STRING,    &normfgcolor },
	{ "normbgcolor",            STRING,    &normbgcolor },
	{ "normbordercolor",        STRING,    &normbordercolor },
	{ "normfloatcolor",         STRING,    &normfloatcolor },
	{ "selfgcolor",             STRING,    &selfgcolor },
	{ "selbgcolor",             STRING,    &selbgcolor },
	{ "selbordercolor",         STRING,    &selbordercolor },
	{ "selfloatcolor",          STRING,    &selfloatcolor },
	{ "titlenormfgcolor",       STRING,    &titlenormfgcolor },
	{ "titlenormbgcolor",       STRING,    &titlenormbgcolor },
	{ "titlenormbordercolor",   STRING,    &titlenormbordercolor },
	{ "titlenormfloatcolor",    STRING,    &titlenormfloatcolor },
	{ "titleselfgcolor",        STRING,    &titleselfgcolor },
	{ "titleselbgcolor",        STRING,    &titleselbgcolor },
	{ "titleselbordercolor",    STRING,    &titleselbordercolor },
	{ "titleselfloatcolor",     STRING,    &titleselfloatcolor },
	{ "tagsnormfgcolor",        STRING,    &tagsnormfgcolor },
	{ "tagsnormbgcolor",        STRING,    &tagsnormbgcolor },
	{ "tagsnormbordercolor",    STRING,    &tagsnormbordercolor },
	{ "tagsnormfloatcolor",     STRING,    &tagsnormfloatcolor },
	{ "tagsselfgcolor",         STRING,    &tagsselfgcolor },
	{ "tagsselbgcolor",         STRING,    &tagsselbgcolor },
	{ "tagsselbordercolor",     STRING,    &tagsselbordercolor },
	{ "tagsselfloatcolor",      STRING,    &tagsselfloatcolor },
	{ "hidnormfgcolor",         STRING,    &hidnormfgcolor },
	{ "hidnormbgcolor",         STRING,    &hidnormbgcolor },
	{ "hidselfgcolor",          STRING,    &hidselfgcolor },
	{ "hidselbgcolor",          STRING,    &hidselbgcolor },
	{ "urgfgcolor",             STRING,    &urgfgcolor },
	{ "urgbgcolor",             STRING,    &urgbgcolor },
	{ "urgbordercolor",         STRING,    &urgbordercolor },
	{ "urgfloatcolor",          STRING,    &urgfloatcolor },
};

static const Key keys[] = {
	/* modifier                     key            function                argument */
	{ MODKEY,                       XK_t,          spawn,                  {.v = dmenucmd } },
	{ MODKEY,			              XK_f,    		  spawn,                  {.v = termcmd } },
	{ MODKEY|ShiftMask,             XK_b,          togglebar,              {0} },
	{ MODKEY,                       XK_j,          focusstack,             {.i = +1 } },
	{ MODKEY,                       XK_k,          focusstack,             {.i = -1 } },


	{ MODKEY,                       XK_i,          incnmaster,             {.i = +1 } },
	{ MODKEY,                       XK_d,          incnmaster,             {.i = -1 } },
	{ MODKEY|ControlMask,           XK_i,          incnstack,              {.i = +1 } },
	{ MODKEY|ControlMask,           XK_u,          incnstack,              {.i = -1 } },
	{ MODKEY,                       XK_h,          setmfact,               {.f = -0.05} },
	{ MODKEY,                       XK_l,          setmfact,               {.f = +0.05} },
	{ MODKEY|ShiftMask,             XK_h,          setcfact,               {.f = +0.25} },
	{ MODKEY|ShiftMask,             XK_l,          setcfact,               {.f = -0.25} },
	{ MODKEY|ShiftMask,             XK_o,          setcfact,               {0} },


	{ MODKEY|Mod1Mask,              XK_Down,       moveresize,             {.v = "0x 25y 0w 0h" } },
	{ MODKEY|Mod1Mask,              XK_Up,         moveresize,             {.v = "0x -25y 0w 0h" } },
	{ MODKEY|Mod1Mask,              XK_Right,      moveresize,             {.v = "25x 0y 0w 0h" } },
	{ MODKEY|Mod1Mask,              XK_Left,       moveresize,             {.v = "-25x 0y 0w 0h" } },
	{ MODKEY|Mod1Mask|ShiftMask,    XK_Down,       moveresize,             {.v = "0x 0y 0w 25h" } },
	{ MODKEY|Mod1Mask|ShiftMask,    XK_Up,         moveresize,             {.v = "0x 0y 0w -25h" } },
	{ MODKEY|Mod1Mask|ShiftMask,    XK_Right,      moveresize,             {.v = "0x 0y 25w 0h" } },
	{ MODKEY|Mod1Mask|ShiftMask,    XK_Left,       moveresize,             {.v = "0x 0y -25w 0h" } },


	{ MODKEY|ShiftMask,             XK_j,          movestack,              {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_k,          movestack,              {.i = -1 } },
	{ MODKEY,                       XK_Return,     zoom,                   {0} },

	{ MODKEY, 			              XK_bracketright,          incrgaps,               {.i = +1 } },
	{ MODKEY,    						  XK_bracketleft,           incrgaps,               {.i = -1 } },
	{ MODKEY|Mod1Mask,              XK_bracketright,          incrigaps,              {.i = +1 } },
	{ MODKEY|Mod1Mask,			     XK_bracketleft,           incrigaps,              {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_bracketright,          incrogaps,              {.i = +1 } },
	{ MODKEY|ShiftMask,			     XK_bracketleft,           incrogaps,              {.i = -1 } },


	{ MODKEY|Mod1Mask,              XK_0,          togglegaps,             {0} },
	{ MODKEY|Mod1Mask|ShiftMask,    XK_0,          defaultgaps,            {0} },


	{ Mod1Mask,                     XK_Tab,        alttabstart,            {0} },

	
	{ MODKEY, 	 	 	 		        XK_q,          killclient,             {0} },
	{ MODKEY|ShiftMask,             XK_Delete,     quit,                   {1} },
	{ MODKEY|ControlMask|ShiftMask, XK_Delete,     quit,                   {0} },


	{ MODKEY,                       XK_u,          focusurgent,            {0} },
	{ MODKEY|ShiftMask,             XK_F5,         xrdb,                   {.v = NULL } },


	{ MODKEY|ControlMask,           XK_t,          rotatelayoutaxis,       {.i = +1 } },   /* flextile, 1 = layout axis */
	{ MODKEY|ControlMask,           XK_Tab,        rotatelayoutaxis,       {.i = +2 } },   /* flextile, 2 = master axis */
	{ MODKEY|ControlMask|ShiftMask, XK_Tab,        rotatelayoutaxis,       {.i = +3 } },   /* flextile, 3 = stack axis */
	{ MODKEY|ControlMask|Mod1Mask,  XK_Tab,        rotatelayoutaxis,       {.i = +4 } },   /* flextile, 4 = secondary stack axis */
	{ MODKEY|Mod5Mask,              XK_t,          rotatelayoutaxis,       {.i = -1 } },   /* flextile, 1 = layout axis */
	{ MODKEY|Mod5Mask,              XK_Tab,        rotatelayoutaxis,       {.i = -2 } },   /* flextile, 2 = master axis */
	{ MODKEY|Mod5Mask|ShiftMask,    XK_Tab,        rotatelayoutaxis,       {.i = -3 } },   /* flextile, 3 = stack axis */
	{ MODKEY|Mod5Mask|Mod1Mask,     XK_Tab,        rotatelayoutaxis,       {.i = -4 } },   /* flextile, 4 = secondary stack axis */
	{ MODKEY|ControlMask,           XK_Return,     mirrorlayout,           {0} },          /* flextile, flip master and stack areas */


	{ MODKEY|ShiftMask,             XK_space,      togglefloating,         {0} },
	{ MODKEY|ShiftMask,             XK_space,      togglealwaysontop,      {0} },


	{ MODKEY,                       XK_grave,      togglescratch,          {.ui = 0 } },
	{ MODKEY|ControlMask,           XK_grave,      setscratch,             {.ui = 0 } },
	{ MODKEY|ShiftMask,             XK_grave,      removescratch,          {.ui = 0 } },


	{ MODKEY,              			  XK_space,      unfloatvisible,         {0} },
	{ MODKEY|Mod1Mask,              XK_space,      unfloatvisible,         {.v = &layouts[0]} },


	{ MODKEY|ShiftMask,             XK_f,          togglefullscreen,       {0} },
//	{ MODKEY|ShiftMask,             XK_f,          fullscreen,             {0} },


	{ MODKEY,                       XK_Left,      focusmon,               {.i = -1 } },
	{ MODKEY,                       XK_Right,     focusmon,               {.i = +1 } },
	{ MODKEY|ControlMask,           XK_Left,      tagmon,                 {.i = -1 } },
	{ MODKEY|ControlMask,           XK_Right,     tagmon,                 {.i = +1 } },


	/* Client position is limited to monitor window area */

	{ ControlMask|Mod1Mask,                     XK_u,            floatpos,               {.v = "-26x -26y" } }, // ↖
	{ ControlMask|Mod1Mask,                     XK_i,            floatpos,               {.v = "  0x -26y" } }, // ↑
	{ ControlMask|Mod1Mask,                     XK_o,            floatpos,               {.v = " 26x -26y" } }, // ↗
	{ ControlMask|Mod1Mask,                     XK_j,            floatpos,               {.v = "-26x   0y" } }, // ←
	{ ControlMask|Mod1Mask,                     XK_l,            floatpos,               {.v = " 26x   0y" } }, // →
	{ ControlMask|Mod1Mask,                     XK_m,            floatpos,               {.v = "-26x  26y" } }, // ↙
	{ ControlMask|Mod1Mask,                     XK_comma,        floatpos,               {.v = "  0x  26y" } }, // ↓
	{ ControlMask|Mod1Mask,                     XK_period,       floatpos,               {.v = " 26x  26y" } }, // ↘


	{ MODKEY|ShiftMask,          				     XK_underscore,      setborderpx,            {.i = -1 } },
	{ MODKEY|ShiftMask,       					     XK_plus,     	    setborderpx,            {.i = +1 } },


	{ MODKEY|ControlMask,           XK_Prior,      cyclelayout,            {.i = -1 } },
	{ MODKEY|ControlMask,           XK_Next,       cyclelayout,            {.i = +1 } },


	{ MODKEY,                       XK_F1,         mpdchange,              {.i = -1} },
	{ MODKEY,                       XK_F2,         mpdchange,              {.i = +1} },
	{ MODKEY,                       XK_Escape,     mpdcontrol,             {0} },
	TAGKEYS(                        XK_1,                                  0)
	TAGKEYS(                        XK_2,                                  1)
	TAGKEYS(                        XK_3,                                  2)
	TAGKEYS(                        XK_4,                                  3)
	TAGKEYS(                        XK_5,                                  4)

};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
	/* click                event mask           button          function        argument */
	{ ClkLtSymbol,          0,                   Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,                   Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,                   Button2,        zoom,           {0} },
	{ ClkStatusText,        0,                   Button2,        spawn,          {.v = termcmd } },
	/* placemouse options, choose which feels more natural:
	 *    0 - tiled position is relative to mouse cursor
	 *    1 - tiled postiion is relative to window center
	 *    2 - mouse pointer warps to window center
	 *
	 * The moveorplace uses movemouse or placemouse depending on the floating state
	 * of the selected client. Set up individual keybindings for the two if you want
	 * to control these separately (i.e. to retain the feature to move a tiled window
	 * into a floating position).
	 */
	{ ClkClientWin,         MODKEY,              Button1,        moveorplace,    {.i = 1} },
	{ ClkClientWin,         MODKEY,              Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,              Button3,        resizemouse,    {0} },
	{ ClkClientWin,         MODKEY|ShiftMask,    Button3,        dragcfact,      {0} },
	{ ClkClientWin,         MODKEY|ShiftMask,    Button1,        dragmfact,      {0} },
	{ ClkTagBar,            0,                   Button1,        view,           {0} },
	{ ClkTagBar,            0,                   Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,              Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,              Button3,        toggletag,      {0} },
};

