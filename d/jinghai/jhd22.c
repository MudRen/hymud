// Room: /d/jinghai/jhd22.c

inherit ROOM;

void create()
{
	set("short", "ɽׯ����");
	set("long", @LONG
�����Ǿ�����������ϰ�书�ĵط���ÿ����פ�������Ƕ�Ҫ
�ص���������书������ϵĽ�һ��ѵ�����ڴ�֮��Ҳ���Ի���
�������飬������֮��������������������ʮ����������ܴ�һ
����ԭ������������ܹ���˼���档
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"jhd20",
]));
        set("objects",([
]));

	setup();
	replace_program(ROOM);
}
