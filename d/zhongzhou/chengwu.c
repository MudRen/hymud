inherit ROOM;

void create()
{
	set("short", "С����");
	set("long", @LONG
һ����Ϊ���µ�С�ݣ��ƺ���Ů�ӵľ���������������
��һ��ҩ¯������ɢ�������㡣
LONG);
	set("exits", ([
  		"west" : __DIR__"zhongzhoudu",
	]));
	set("no_clean_up", 0);
        set("objects", ([
                CLASS_D("hu") + "/cheng" : 1,
                CLASS_D("hu") + "/kill1" : 1,
                CLASS_D("hu") + "/kill2" : 1,
        ]));
	set("coor/x", -190);
	set("coor/y", 40);
	set("coor/z", 0);
	setup();
        //replace_program(ROOM);
}
