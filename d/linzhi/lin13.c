// Room: /d/linzhi/lin13.c

inherit ROOM;

void create()
{
	set("short", "��ԭ��·");
	set("long", @LONG
����һ����ԭ��·��·����ɽ�ư�͹��ʱ��ɽ�紵��������
���������������Щ���⡣�����µ���ʱ��ʱ�£����˲�һ��
�����͸е���Щ���ˡ�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northdown" : __DIR__"lin12",
  "south" : __DIR__"lin14",
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
