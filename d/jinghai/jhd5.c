// Room: /d/jinghai/jhd5.c

inherit ROOM;

void create()
{
	set("short", "����С·");
	set("long", @LONG
����һ����ɽ��������ȫ����С·��·��һ���Ƿ��ܵ�ɼ��
�֣�һ������̲����Ĵ��ˡ�·��խ���������������򰶱ߣ�
�����̱㱻��᾵���ʯ���÷��飬ը��������ˮ�齦�������ϡ�
������ˮ�������С·���ص�Χ���ţ����е㲻��ȷ���ǲ���Ӧ
�ü�����ǰ���ˡ�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"jhd3",
  "south" : __DIR__"jhd6",
]));
        set("outdoors","jinghai");

	setup();
	replace_program(ROOM);
}
