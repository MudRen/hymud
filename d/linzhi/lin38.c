// Room: /d/linzhi/lin38.c

inherit ROOM;

void create()
{
	set("short", "���˹��ٲ�");
	set("long", @LONG
�����Ǽ��˹�����ˮ�����ٲ���ˮ���ٲ���25�ף�������
�Զ������䣬������ٲ��ƣ�����ʱ������Ͼ��εΪ׳�ۡ���˵
��������ͨ�ģ��л�����µı������û��˵��������ˮ����
�����
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"lin37",
]));
        set("outdoors", "linzhi");
        set("cannot_build_home", 1);
        set("altitude", 3800);
	setup();
	replace_program(ROOM);
}
