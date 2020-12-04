// Room: /d/jinghai/moon17.c

inherit ROOM;

void create()
{
	set("short", "水寨烽火台");
	set("long", @LONG
高高的烽火台是明月水寨传警拒敌的要地，不论白天黑夜都
有水勇们轮班值守，若有敌情，他们便会燃起烽火台中间堆放的
干狼粪通知水塞做好准备，这里还有副抛石机，当水师不敌时便
可以把这里当做炮台抵挡敌人的进攻，不过自从水寨成立以来，
它们就从未被使用过。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "up" : __DIR__"moon27",
  "north" : __DIR__"moon10",
]));
        set("outdoors","jinghai");

	setup();
	replace_program(ROOM);
}
