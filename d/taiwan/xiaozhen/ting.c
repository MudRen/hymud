// Room: /d/taiwan/ting.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�ߴ�����Ĵ���,�ĽǵĴ������Ƶض���,���ſ��β�������,���� 
������Ѿ�߲�Ϣ.���е����������ǰһ�ŵ���̫ʦ����.�����˵��� 
�ټ��Ľ���. 
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"dayuan",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/caizhu.c" : 1,
  __DIR__"npc/obj/jiudai" : 1,
  __DIR__"npc/obj/kaoya" : 1,
  __DIR__"npc/obj/niurou" : 1,

]));
	setup();
	replace_program(ROOM);
}
