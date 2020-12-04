// minju.c

inherit ROOM;
void create()
{
        set("short","���");
        set("long",@LONG                                   
����һ������ͨ�ı����񷿣�һ��СС��Ժ�䡣Ժ�������
�Ų���ԭľ��һ��ľ�����Ϲ������ӡ�ľ��֮���ľ�����ߣ���
��������������Ǹ�ľ����
LONG
        ); 



        set("exits",([
               "south":__DIR__"xiaolu4",
		"northwest" : __DIR__"minju1",
		"northeast" : __DIR__"minju2",
        ]) );

	set("objects",([
	__DIR__"npc/laozhao" : 1,
]));
        setup();
}

int valid_leave(object me, string dir)
{
	object room;

	if(wizardp(me))
		return 1;

	if( (dir != "northwest") && (dir != "northeast") )
		return 1;

	if(!me->query_temp("valid_enter_drying_room"))
		return notify_fail("������ס��˵����������ľ�ĺ�ɷ���û�����ͱ��ȥ�ˡ�\n");

	if(!objectp(room = find_object(query("exits/"+dir))))
		return 1;

	if(sizeof(filter_array(all_inventory(room),(: userp :))))
		return notify_fail("������ס��˵�����Ǽ䷿���������ڸɻ��أ����Ȼ���ٽ�ȥ�ɡ�\n");
	return 1;
}
