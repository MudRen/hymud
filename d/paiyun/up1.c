// Room: /d/paiyun/up1.c

inherit ROOM;

void create()
{
	set("short", "��ɽС·");
	set("long", @LONG
����һ����ɽ����·��������·�ǳ�������·�߳�������ݣ�
·��ȴ���ǽ�ӡ����ӡ�������������˾������
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "northup" : __DIR__"up2",
  "southdown" : "/d/wuyi/chadong",
]));

	set("outdoors", "paiyun");
	setup();
}

void init()
{
	object ob;
	if(objectp(ob = previous_object()) && ob->query_temp("pass_changan_dutu"))
		ob->delete_temp("pass_changan_dutu");
}
