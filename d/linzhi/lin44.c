// Room: /d/linzhi/lin44.c

inherit ROOM;

void create()
{
	set("short", "��ԭɽ��·");
	set("long", @LONG
����һ����ԭɽ��·��·������б����С�ĵ��������棬ʱ
ʱע���ŷ��򡣲�Զ��һȺҰ������ɽ����۳ң�����û��ע��
�����ڴ��ڡ�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"lin43",
  "northwest" : __DIR__"lin47",
]));

  set("objects", ([ /* sizeof() == 4 */
  __DIR__"npc/mob" : 1+random(2),
]));
        set("outdoors", "linzhi");
        set("cannot_build_home", 1);
        set("altitude", 4000);
	setup();
	replace_program(ROOM);
}
