// Room: /d/taiwan/zhangfang.c

inherit ROOM;

void create()
{
	set("short", "�ʷ�");
	set("long", @LONG
�����м�����ų�������,����ڵ�̫ʦ���������Ÿ������İ���� 
ͷ,�����ϼ��Ÿ�����۾�.��������֧ë���ڱ��ʲ��ϵ�㻮��.���ϳ� 
��һ����ɵ�������,�����Ÿ��豭.�����ſ����������ǽ�߰��ż����� 
�ߵĹ���.��������˸��־���. 
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"dayuan",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/shiye.c" : 1,
]));

	setup();
	replace_program(ROOM);
}
