// Room: /d/yueyang/gaibangtang.c
// Last Modifyed by Winder on Dec. 4 2001

inherit ROOM;

void create()
{
	set("short", "���Ԫ��");
	set("long", @LONG
������ؤ����ھۻ᳡�������Ϻ����������Ų��ٲ����š���Ȼ��
�����ƺ������ң���ʵȴ���ǺϺ���棺��������ְ˾��ǰ��˳��һ
Ŀ��Ȼ��
LONG );
	set("exits", ([
		"south" : __DIR__"xuanyuantai",
	]));
	set("objects", ([
		__DIR__"npc/kangming" : 1,
	]));

	set("coor/x", -1420);
	set("coor/y", -2240);
	set("coor/z", 0);
	setup();

	
}
