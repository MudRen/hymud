

inherit ROOM;

void create()
{
 set("coor",({50,4700,10}));
	set("short", "��");
	set("long",
"������Զ�ǵ���,��ר������ĵط���ֻ��Ժ���ﵽ��������ƥ��ǧ����������Ӧ��\n"
"���С�ֻ�������������ζ����Ũ����ֱҪ����Ѭ��!\n"
);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"sroad1",
]));
set("objects",([
 __DIR__"npc/mafanzi":1,]));
               /* "east" : "/d/snow/bank",*/

	setup();
	replace_program(ROOM);
}
