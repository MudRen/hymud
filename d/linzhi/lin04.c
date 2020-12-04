// Room: /d/linzhi/lin04.c

inherit ROOM;

void create()
{
	set("short", "ɽ��");
	set("long", @LONG
������һ��ɽ����ˮ�����ش�ɽ���㵽����������Զ����ɽ
���ϳ���һЩС�ݣ�����ˮ�ƻ�����ȥ�������ڿ��ˣ�������
�����(fill)��ˮ�ȡ�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southup" : __DIR__"lin03",
  "westdown" : __DIR__"lin05",
]));
  set("objects", ([ /* sizeof() == 4 */
  __DIR__"npc/mob" : 1+random(2),
]));
        set("outdoors", "linzhi");
        set("resource/water", 1); 
        set("cannot_build_home", 1);
        set("altitude", 2600);
	setup();
	replace_program(ROOM);
}
