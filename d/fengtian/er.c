// Room: /d/fengtian/er.c

inherit ROOM;

void create()
{
	set("short", "��������");
	set("long", @LONG
��������ס������ʵ�Ԫ�����һֱû�����ã����Իʵ�
Ȣ�˴������������˳��ĵ��ܶ�ׯ����������Ҳ�Ǹ�С�ұ���
�����Ǻ��м�ʶ�������ܻ��ֻʵۻ��ġ�
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"wo",
]));
        set("objects",([
        	__DIR__"npc/hh2" :1,        	
        __DIR__"npc/taijian" :1,        		
        ]));
	setup();
	replace_program(ROOM);
}
