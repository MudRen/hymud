// Room: /d/jinghai/jhd2.c

inherit ROOM;

void create()
{
	set("short", "了望木塔");
	set("long", @LONG
这座木塔全部是坚实的杉木造成的的，看上去荒废已久，塔
身倒还结实，但塔壁由于长年被风雨侵袭已经斑驳不堪，塔顶门
窗俱废，湿咸的海风把这里吹得一丝灰尘也没有，你站在这儿向
远方望去，海和天浑沌的连成一片，似乎亘古以来只有这个小小
的岛屿冲破了海洋的包裹，孤零地矗立在海天之间。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "down" : __DIR__"jhd1",
]));

	setup();
	replace_program(ROOM);
}
