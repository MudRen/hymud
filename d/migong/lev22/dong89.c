#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIW"����֮ʧ��԰"NOR);
	set("long", HIW @LONG
 ������磬Ʈ��������,����,�ذ����ɷ����Ļƽ����̳ɣ����ܵ�ǽ��
���컨���������������ıڻ��;��µ�ʯ�񡣿���������ˮ��ɢ��������
�Ĺ�â���޿�����Ʈ���ڿ��е�����ʹ��һ��������á�
LONG NOR);
	set("exits", ([
		"north" : __DIR__"dong12",
		"south" : __DIR__"dong90",
                	]));
         set("objects", ([
              __DIR__"npc/boss15": 3,
             __DIR__"npc/boss27": 3,
__DIR__"npc/lev3": 1,
__DIR__"npc/lev2": 1,
"/clone/box/gboxm" : random(3),
                ]));
               set("objects", ([
              __DIR__"npc/lev"+(random(7)+3) : 3,
             __DIR__"npc/lev"+(random(7)+3) : 3,
                ]));
	set("no_clean_up", 0);set("magicroom",1);set("outdoors","migong");set("magicset",1);
	setup();
	replace_program(ROOM);
}