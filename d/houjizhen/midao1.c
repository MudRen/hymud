// midao1.c
// by dicky

inherit ROOM;

void create()
{
	set("short", "�ص�");
	set("long", @LONG
�����ص�һ·���¡��ص����Ե��ż�յ�͵ƣ�����綹��ǰ��һƬ
�������Ĳ�֪��ͨ�����
LONG);
       
        set("exits", ([
		 "east" : __DIR__"midao2",
		 "west" : __DIR__"midao",
	])); 

	setup();
	replace_program(ROOM);
}
