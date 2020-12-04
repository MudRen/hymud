// Room: /d/linzhi/lin67.c

inherit ROOM;

void create()
{
	set("short", "��ԭ�ӵ�");
	set("long", @LONG
�����Ǹ�ԭ�ӵ������߼�˵ĵ��κ�����·һ����Ҳ��֪
�Ƿ��ߵ�ͨ������ϸ��ע���ţ�ѡ����һ���нŲ�ӡ�ǽ϶�ķ�
��������һ�ᣬ���÷���û���ߴ�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northwest" : __DIR__"lin68",
  "southeast" : __DIR__"lin66",
]));

  set("objects", ([ /* sizeof() == 4 */
  __DIR__"npc/mob" : 1+random(2),
]));
        set("outdoors", "linzhi");
        set("cannot_build_home", 1);
        set("altitude", 3800);
	setup();
	replace_program(ROOM);
}
