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
  
  "westup" : __DIR__"huanghe3",
  "north" : "/d/taiyuan/dukou1",
  
  
	]));
	set("objects", ([
		//__DIR__"npc/hou" : 1,
	]));
//	set("no_clean_up", 0);
	        set("outdoors", "shanxi");
        set("coor/x",-300);
        set("coor/y",-430);
        set("coor/z",30);
	setup();
	//replace_program(ROOM);
}
