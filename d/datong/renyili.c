// Room: /open/dt/renyili.c

inherit ROOM;

void create()
{
	set("short", "��һ�����ӹ�");
	set("long", @LONG
���ǵ�����ͬ���ˣ�û�в�֪����һ���Ĵ����ģ���Ϊ����
����һ��������ÿ�����վ�ڻ���·�ϵ��˶��ӹ����С������
����������������Ƶķ�ׯ�ﻹ����̫�ȱ���ƽңţ�⡢��ϲ��
�������ԣ�ÿһ���������������������ͷ��
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"hongchanglu5",
]));

	set("objects",([
	__DIR__"npc/ren" : 1,
]));
	setup();
	replace_program(ROOM);
}
