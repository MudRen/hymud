// Room: /d/fengtian/wo.c

inherit ROOM;

void create()
{
	set("short", "�Է�");
	set("long", @LONG
�ʵ���Ϣ�ĵط���Ҳ�ǻʵ�Ԫ����˻ʺ���Է����ʺ�޸�
�ʵ۶��꣬����Ҳ�ྴ�����
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"jjf5",
  "west" : __DIR__ "er",
]));
        set("objects",([
        	__DIR__"npc/hh" :1,        	
        	__DIR__"npc/gongnv" :1,        		
        ]));
	setup();
	replace_program(ROOM);
}
