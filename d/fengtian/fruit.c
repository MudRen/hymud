// Room: /d/fengtian/fruit.c

inherit ROOM;

void create()
{
	set("short", "ˮ����");
	set("long", @LONG
����·��ȷ��ʢ�����Ͻ֣�������ˮ���궼����ͷ�ˣ��ϵ�
�����治���ر�ã��������ˮ�����Ǳ������еģ��ſ�����
��д��ÿ��ˮ���ļ۸�
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"kd3",
]));

	setup();
	replace_program(ROOM);
}
