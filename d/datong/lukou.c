// Room: /open/dt/lukou.c

inherit ROOM;

void create()
{
	set("short", "·��");
	set("long", @LONG
���ǽ��������ŵ�һ��·�ڣ����ڱ�����¥�����裬�����
��ɳ��������������������֮�������������Ⱥ��֮�أ����Ե�
���ɨ�úܸɾ�������ȥ����̹��·���ϱ��������ǳ����Ļ���
·�����治Զ���ߴ�����Ľ������Ǵ�ͬ���ǵ����š�
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"huayanlu3",
  "east" : __DIR__"huayanlu4",
  "south" : __DIR__"nanmen",
  "north" : __DIR__"tanhuanglu3",
]));

	set("outdoors","datong");

	setup();
	replace_program(ROOM);
}
