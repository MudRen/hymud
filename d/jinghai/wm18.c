// Room: /d/jinghai/wm18.c

inherit ROOM;

void create()
{
	set("short", "�η�");
	set("long", @LONG
������һƬ�ڰ������ֲ�����ָ���Ĵ��������������غ���
��Ϣ��Խ���Ե���ɭ�ֲ���ͻȻ��һ�����ӭ�洵��������һ��
�˱ǵ�ù����ʲô����������ʲôҲ����������������һ�ɸ���
��ζ���������ģ���е����������������������ﲢ��͸�硣
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "eastdown" : __DIR__"wm14",
]));

	
	set("objects",([
	__DIR__"npc/lao_kanshou" : 1,
]));

	setup();
	replace_program(ROOM);
}
