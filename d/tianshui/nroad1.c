// Room: /d/tianshui/nroad1.c

inherit ROOM;

void create()
{
	set("short", "С�򱱽�");
	set("long", @LONG
������������ķ����ضΣ�һ������һ�ɵƺ���̣�Ц����
�������������һƬ����Ϊ���֡�����һ�������ſڹ��Ŵ���
������λ����վ�����ﲻʱ�������˻��ִ��к���������С���
��¥������Ϲ���һ������ң����顰���ɸ������ֽ���֡�
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"nroad2",
  "west" : __DIR__"jiyuan",
  "south" : __DIR__"cross",
  "east" : __DIR__"jiulou",
]));
	set("objects",([
	__DIR__"npc/drunk" : 1,
	__DIR__"npc/cleaner" : 1,
]));

	set("outdoors","tianshui");
	setup();
}