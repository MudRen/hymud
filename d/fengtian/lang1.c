// Room: /d/fengtian/lang1.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
������ͨ����԰�����ȣ��������ԶԶ�����ʵ��й��ĺ�Ժ
������һ����Ϳ����ȵ������ˡ�
LONG
	);

	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"chufang",
  "north" : __DIR__"jjf3",
]));
        set("objects",([
        	__DIR__"npc/gongnv" :3,        
        	__DIR__"npc/taijian" :1,        	
        ]));
	setup();
	replace_program(ROOM);
}
