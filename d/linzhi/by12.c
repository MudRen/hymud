// Room: /d/linzhi/by12.c

inherit ROOM;

void create()
{
	set("short", "�׹�����");
	set("long", @LONG
�������׹�������ֻ����ˮ�峺���ף���ֻ�в������Ĵ���
���ں��������ɵط��衣�㽫��������У�һ�ֱ����Ŀ��Ϯ��
��ͷ������ˮ�ܸɾ����������á�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"by11",
  "north" : __DIR__"yg01",
]));
        set("outdoors", "linzhi");
        set("cannot_build_home", 1);
        set("resource/water", 1); 
        set("altitude", 2600);
	setup();
	replace_program(ROOM);
}
