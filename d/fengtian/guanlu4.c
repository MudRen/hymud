
/*�˶δ����� PLAYERHOME_D �Զ�����,����ı������κ�����!!*/
#include <room.h>
/*�����Զ��������.*/
// Room: /d/fengtian/guanlu4.c

inherit ROOM;

void create()
{
	set("short", "�ٵ�");
	set("long", @LONG
����ʢ�����ź���һ�������Ĺٵ��������ٵ�ͨ��ʢ���»�
·��������ʢ�����ǵķ������ڡ�
LONG
	);

	set("exits", ([
  "south" : __DIR__"xh3",
  "north" : "/d/yanjing/gate",
]));
        set("outdoors", "fengtian");

	set("objects",([
"/clone/npc/man" : 2,
]));

	setup();

	replace_program(ROOM);
}
