// /d/taiyuan/road7.c
// Room in ̫ԭ
// modify by yang

inherit ROOM;

void create()
{
	set("short", "�߹عؿ�");
	set("long", @LONG
�����Ǿ���̫ԭ�����ı߹عؿ��ˡ����������Ǳ��ұ���֮�ء�
�����м����ٱ����ڼ�������������ˡ�
LONG );
	set("exits", ([
//		"west"  : "/d/tuyuhun/silk",
 		"south"  : __DIR__"road9a",
		
	]));
	set("objects",([
	__DIR__"npc/bing":2,
	]));
 	set("outdoors", "taiyuan");
	setup();
	replace_program(ROOM);
}



