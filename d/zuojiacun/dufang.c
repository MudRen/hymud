// Room: /d/zuojiacun/dufang.c

inherit ROOM;

void create()
{
	set("short", "�ķ�");
	set("long", @LONG
����һ��С�ķ���ׯ�������Ǹ����ӣ���˵������ʱ��Ǯ��
ǧ���˴���˽Źǣ����������˶�˵���Ķ����������������
��ʮ��ͷ�����ӣ�һ˫С�۾�ת��תȥ������ǰ����Ǯ�����ǡ�
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"lu6",
]));

	setup();
	replace_program(ROOM);
}
