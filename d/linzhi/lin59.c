// Room: /d/linzhi/lin59.c

inherit ROOM;

void create()
{
	set("short", "�ް���");
	set("long", @LONG
���Ǳ���Ϊ"����"�ĹŰ����ˣ�����Լ50�ף���Χ18�ף���
˵��������2000��2500����ʷ�ˡ������ϲ���������������
���е���������ѡ�������ͽԶ��ǰ�����ݡ�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"lin58",
  "south" : __DIR__"lin60",
]));
        set("outdoors", "linzhi");
        set("cannot_build_home", 1);
        set("altitude", 4000);
	setup();
	replace_program(ROOM);
}
