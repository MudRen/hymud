// Room: /d/linzhi/lin09.c

inherit ROOM;

void create()
{
	set("short", "��ԭ���");
	set("long", @LONG
���ߵ����ֻ��Զ��ɽ��������������ơ�һֻͺ������
��ͷ���������㲻��������Щ���š�������ȥ������տ���Ұ��
�㲻�ɵüӿ��˽Ų���
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"lin08",
  "southwest" : __DIR__"lin10",
]));

  set("objects", ([ /* sizeof() == 4 */
  __DIR__"npc/mob" : 1+random(2),
]));
        set("outdoors", "linzhi");
        set("cannot_build_home", 1);
        set("altitude", 2600);
	setup();
	replace_program(ROOM);
}
