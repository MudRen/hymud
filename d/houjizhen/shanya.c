// shanya.c
// by dicky

#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short", "山脚下");
  set ("long", @LONG
前方是一座高峰，半山腰上有祥云绕绕，隐有红光。由于山峰比较
陡峭，所以这里看起来象一座峭壁，峭壁上多是青苔锈葛，看上去异常
的滑手。山峰上有鹤鸣阵阵，空山回音不绝。听人说，天气好的时候常
常能听到山上有人的啸声，人多以为是神仙在上面。不过，江湖人士说
传说中的踏雪山庄好像在这附近。
LONG);

	set("outdoors", "houjizhen");

	set("exits", ([ /* sizeof() == 3 */
		"eastdown" :  __DIR__"qiaobi",
	]));

	setup();
}



