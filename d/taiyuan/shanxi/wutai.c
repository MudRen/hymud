// Room: /huanghe/huanghe2.c
// Java. Sep 21 1998
inherit ROOM;
void create()
{
	set("short", "Ҷ�ŷ�");
	set("long", @long
�ɿ��ƺ��ճ����ɼ���֮���󣬿������½�ɫ������Ⱥɽ�������
Ѱ��ʯ���ǣ���������ۣ��ϱ������Ļƺӣ������������������飬��
�������֦�������������˼��¡�
long );
	set("exits", ([
  
  "eastdown" : __DIR__"huanghe3",
  "westdown" : __DIR__"huanghe2",
  "north" : __DIR__"daoguan",
  
	]));
	set("objects", ([
		//__DIR__"npc/hou" : 1,
	]));
//	set("no_clean_up", 0);
	        set("outdoors", "shanxi");
        set("coor/x",-350);
        set("coor/y",-430);
        set("coor/z",30);
	setup();
	//replace_program(ROOM);
}
