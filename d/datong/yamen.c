// Room: /open/dt/yamen.c

inherit ROOM;

void create()
{
	set("short", "Ѳ������");
	set("long", @LONG
���е�ǽ�϶����ع���һ���ң����顰�����������ĸ����֣�
���ñ��ϻ���һ��ŭ������ͼ���Ѵ��ó��е�ʮ�����ϡ���ͬѲ
����˳���Ǵ󽫾�������˽�����ѣ�Ϊ�˸�����������������
��һ��һ�࣬����ͬ������þ���������
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"jinyangjie3",
]));

	setup();
	replace_program(ROOM);
}
