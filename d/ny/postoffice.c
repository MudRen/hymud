
// Room: /d/snow/postoffice.c

inherit ROOM;

void create()
{
    
	set("coor",({-20,4850,10}));
	set("short", "�ٸ���վ");
	set("long",
"�����Ǹ�����Զ�ǹٸ������������������վ��������Ϊ������Զ������������ͨ�������\n"
"һƬ���˾�ס�Ĵ�ɳĮ��������վ�������˾����ˣ���վ�Ĺ�Ա���ԾͿ�ʼ��һЩ���յ���\n"
"����һ�����ʱ�䣬һ����Ҳ�е��������ⱻ�ϼ��ó���\n"
);

	set("exits", ([ /* sizeof() == 1 */
        "east" : __DIR__"nroad2",
                "west" : __DIR__"yamen_square"
	]));
	set("outdoors", "ny");
	set("objects", ([
        __DIR__"npc/post_officer" : 1,   
	"/clone/misc/dache" : 1 
	]) );

	setup();
}

int valid_leave(object me, string dir)
{
	object mbox;

    return 1;
	if( mbox = me->query_temp("mbox_ob") ) {
		tell_object(me, "�㽫���佻����վ��\n");
		destruct(mbox);
	}
	return 1;
}
