// Room: /open/dt/huichuntang.c

inherit ROOM;

void create()
{
	set("short", "�ش���");
	set("long", @LONG
�߽����һ�ɴ̱ǵ�ҩ��ʹ����΢�����е㲻�����ӭ��
��һ�Ŵ��̨��ʮ���������ŶӵȺ�ץҩ���Ա�һ��ľ��������
һλ���ˣ�һ������ʮ����ϴ�����ڰ�һ����������ڲ��˵�
Ѩ���ԭ�����ﲻ����ҩ�ģ�����Ҳ��һЩ��֢�������Ρ�
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"youfujie3",
]));

	set("objects",([
	__DIR__"npc/huiboss" : 1,
]));

	setup();
	replace_program(ROOM);
}
