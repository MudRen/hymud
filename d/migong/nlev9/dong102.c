#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{      set("short", WHT"����ʯ��"NOR);
	set("long", WHT @LONG
 �������Ǽ�������ʯ�����ܲ�ͣ����ˮ�����,ʯ�����и�
���������ʯ���� 
LONG NOR);
	set("exits", ([
		"south" : __DIR__"dong101",

                	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}