// Room: /open/dt/shuiguodian.c

inherit ROOM;

void create()
{
	set("short", "ˮ����");
	set("long", @LONG
��ͬ��ˮ�������ˮ����������ڵ�ˮ����������ɫ��ȫ��
����һ��ֻ��һЩ���صĺ͹�������Ĺ�Ʒ����Ϊ�ӹ��ڽ�ˮ��
�˵��˵�Ҫ���Ѻܶ�Ľ�Ǯ����������������ˮ������Ҳ��
�治�ã��������ڴ˵�������Ϊɳ�ʣ���������ʢ����ƻ��ȴʮ
�ָ����֭��
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"jinyangjie2",
]));

	set("objects",([
	__DIR__"npc/fruit_seller" : 1,
]));

	setup();
	replace_program(ROOM);
}
