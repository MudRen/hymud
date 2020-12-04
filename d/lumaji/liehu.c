// Room: /d/lumaji/liehu.c

inherit ROOM;

void create()
{
	set("short", "���Ի���");
	set("long", @LONG
����������Ի��ҡ����Ի��Դ���Ϊ�������Ծ������ڼҡ�
��ʱ���Ի������Ͱ�һЩ���µ��������������ϰ塣����������
�߳������������������߼�������һЩϡ�ٵ�Ұζ��
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"lu13",
]));

	set("objects",([
	__DIR__"npc/liehu_zhao" : 1,
]));

	setup();
}

int valid_leave(object ob,string dir)
{
	ob->delete_temp("liehu_zhao");
	return ::valid_leave(ob,dir);
}