// Room: /huanghe/huanghe2.c
// Java. Sep 21 1998
inherit ROOM;
void create()
{
	set("short", "�ƺ��±�");
	set("long", @long
ɽ�������ǻƺӡ��ƺ����ʵ�����Ѿ���ɳ�����ˡ���ɫ�ĺ�ˮ
�ںӴ��﷭���ţ������ţ�����һ�����޴�����ѣ�ǧ�徹�㣬������
�棬�����ƺ���������Ȫ��������̫��ɽ��׳����⡣
long );
	set("exits", ([
  
  "westup" : __DIR__"wutai",
  "eastdown" : __DIR__"huanghe4",
  
  
	]));
	set("objects", ([
		//__DIR__"npc/hou" : 1,
	]));
//	set("no_clean_up", 0);
	        set("outdoors", "shanxi");
        set("coor/x",-500);
        set("coor/y",-400);
        set("coor/z",100);
	setup();
	//replace_program(ROOM);
}
