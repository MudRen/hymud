// Room: /open/dt/mafang.c

inherit ROOM;

void create()
{
	set("short", "��");
	set("long", @LONG
�����Ǵ�ͬ��������ƥ�ĵط�����Ϊ�ڿ͵������ܲ���
�㣬���Դ�Ҷ�����ƥ��������������ͳһ�������������
����ʮ��ƥëɫ�������һ��������ڸ�����һƥ��ϴ�裬��
ƥ��ëɫ���ף�һ����֪����һƥ��ԡ�
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"huayanlu2",
]));

	set("objects",([
	"/d/city/npc/mafu" : 1,
]));

	setup();
	replace_program(ROOM);
}
