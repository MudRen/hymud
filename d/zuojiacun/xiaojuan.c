// Room: /d/zuojiacun/xiaojuan.c

inherit ROOM;

void create()
{
	set("short", "��ŮС���");
	set("long", @LONG
����һ����ͨ�Ĳ��ݣ�ס����ŮС�������үү��С���Ǹ�
���µĺ��ӣ������һ�л������ڿ�������ά�֡����ڴ�С����
���߳���С���ˮ�Էǳ��ã���˵�����������κ������˵Ļ�
����������ັ���ı��ǡ�
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"lu19",
]));
		set("valid_startroom", 1);
	set("sleep_room", 1);
  	set("objects",([
	__DIR__"npc/girl" : 1,
	__DIR__"npc/yuwen2" : 1,	
]));
	setup();
	replace_program(ROOM);
}
