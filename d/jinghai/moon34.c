// Room: /d/jinghai/moon34.c

inherit ROOM;

void create()
{
	set("short", "刑房");
	set("long", @LONG
用地狱称呼这里一点也不过份，一进门你就感到一股阴森森
的血腥之气直钻进你的鼻子里，你的胃一阵收缩，你勉强压住呕
吐的感觉扫视了一圈，房子里摆满了各种叫不出名子的恐怖刑具，
房顶上钉满了铁钩，看来是吊人用的，还是赶快离开这里吧。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"moon30",
]));

	setup();
	replace_program(ROOM);
}
