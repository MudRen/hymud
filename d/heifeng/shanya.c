// Room: /d/heifeng/shanya.c

inherit ROOM;

void create()
{
	set("short", "��ɽ��");
	set("long", @LONG
�����Ǻڷ�կ�����һ��Сɽ�£�һ���峺��Ȫˮ��������
�ʶ��¡�����������ӳ���������£�����һ���������ڣ�������
һ��СС��é���ݡ�
LONG
	);

	set("outdoors", "heifeng");

	set("exits", ([ /* sizeof() == 2 */
  "southdown" : __DIR__"shanquan",
  "north" : __DIR__"maowu",
]));

	setup();
	replace_program(ROOM);
}
