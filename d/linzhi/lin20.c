// Room: /d/linzhi/lin20.c

inherit ROOM;

void create()
{
	set("short", "÷��ѩɽ�Ե�");
	set("long", @LONG
���ߵ���ԭɽ·�ϣ����ϲ�Զ����������÷��ѩɽ�ˡ�����
��·���£���ʱ�������ⷢ�����㲻�ɵ����С�ģ��ӿ���ǰ��
�ĽŲ���
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "eastdown" : __DIR__"lin19",
  "westup" : __DIR__"lin24",
]));
  set("objects", ([ /* sizeof() == 4 */
  __DIR__"npc/mob" : 1+random(2),
]));
        set("outdoors", "linzhi");
        set("cannot_build_home", 1);
        set("altitude", 5400);
	setup();
	replace_program(ROOM);
}
