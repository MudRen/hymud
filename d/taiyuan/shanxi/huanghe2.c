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
  
  "eastup" : __DIR__"wutai",
  "westdown" : __DIR__"huanghe1",
  "south" : __DIR__"guandi",
  
	]));
	set("objects", ([
		//__DIR__"npc/hou" : 1,
	]));
//	set("no_clean_up", 0);
	        set("outdoors", "shanxi");
        set("coor/x",-400);
        set("coor/y",-430);
        set("coor/z",30);
	setup();
	//replace_program(ROOM);
}
