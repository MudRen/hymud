// Room: /d/linzhi/lin10.c

inherit ROOM;

void create()
{
	set("short", "��ԭ���");
	set("long", @LONG
���ߵ����ֻ��Զ��ɽ��������������ơ�һֻͺ������
��ͷ���������㲻��������Щ���š�������ȥ������տ���Ұ��
�㲻�ɵüӿ��˽Ų������治Զ�͵���һ���ˡ�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"lin09",
  "westdown" : __DIR__"bye",
  "south" : __DIR__"lin29",
]));
        set("outdoors", "linzhi");
        set("cannot_build_home", 1);
        set("altitude", 2600);
	setup();
	replace_program(ROOM);
}
