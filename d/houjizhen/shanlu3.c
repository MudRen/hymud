//shanlu3.c
//by dicky

inherit ROOM;

void create()
{
	set("short", "С����");
	set("long", @LONG
�������һƬС���֣������ּ�С·�ϣ�������������ֵ�ס�����⣬
�����Ե�ʮ����������ľ�����ݺᣬ����û��ʲô��·�ˣ����Ͻ����˲���
�Ĺ�ʵ�����������·�˳�������ʱ�伢��
LONG
	);
        set("outdoors", "houjizhen");

	set("exits", ([
		"west" : __DIR__"shanlu2",
	]));

	set("objects",([
		__DIR__"npc/luren" : 1,
	]));


	setup();
//	replace_program(ROOM);
}



void init()
{
        add_action("do_cai", "cai");
}

int do_cai(string arg)
{
    object me;
    me = this_player();
    if (arg == "guo")
 	{   message_vision("$N���ִ�����ժ��һ��Ұ����\n", me);
     	new(__DIR__"obj/yeguo")->move(me);
     	return 1;
 	}
     return notify_fail("��Ҫ��ʲô? \n");
 }