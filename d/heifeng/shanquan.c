// Room: /d/heifeng/shanquan.c

inherit ROOM;

void create()
{
	set("short", "ɽȪ");
	set("long", @LONG
������ɽ���һ��Ȫˮ�������ɽ�����ʶ��£�Ȫˮ�峺��
�ף��������ɽȪ��Ӧ�źڷ�կ����ˮ�������ʱ�򶼻���С�
ඵ���������ˮ(fill)��
LONG
	);

	set("outdoors", "heifeng");

	set("exits", ([ /* sizeof() == 3 */
  "northup" : __DIR__"shanya",
  "south" : __DIR__"corr08",
  "east" : __DIR__"xiaolu1",
]));

	set("resource/water", 1);

	setup();
	replace_program(ROOM);
}
