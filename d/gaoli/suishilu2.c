// Room in ����
inherit ROOM;
void create()	
{
	set("short", "��ʯ·");
	set("long", @LONG	
������һ����ʯ·�������Ѿ��Ǹ����ǵ��Ͻ��ˡ�������һƬ�ݵء�
������������ȥ�����Կ���һ�������ˡ���ʱ��������˴���������߹���
LONG
	);
set("outdoors", "gaoli");
set("exits", ([
		"east" : __DIR__"suishilu1",
		"northwest":__DIR__"caodi1",
       	]));
       setup();
	replace_program(ROOM);
}	
