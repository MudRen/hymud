// Room: /d/gaochang/zoulang1.c

inherit ROOM;


string look_writing();


void create()
{
	set("short", "����");
	set("long", @LONG
�����Ǻ�����ȡ�����һ��֧������ĸ�ǽ�ϣ���һ������
���߰����õ��ݶ�����������������������Ҳ�ò�������˸���
�����ͼ�Σ�ÿ�����ƺ�������˵һ���渶��˵ķ𾭹��¡���
��ǽ������һ����(writing)��
LONG
	);

	set("exits", ([
		"northwest" : __DIR__"zoulang2",
		"southwest" : __DIR__"eroom3",
	]));


	setup();
}




void init()
{
	add_action("do_study", "study");
}


int do_study(string arg)
{
	object me;
	int    jing_cost;

	me = this_player();

	if ( !arg || ( arg != "qiangbi" ) )
		return notify_fail("ʲô��\n");

	if ( (int)me->query_skill("literate", 1) < 1)
		return notify_fail("���Ǹ���ä����ѧ���Ļ�(literate)�ɡ�\n");

	jing_cost = 0;
	if((int)me->query("jing") < jing_cost)
		return notify_fail("�����ھ����޷����У�\n");

	me->add("jing", jing_cost);

	message_vision("$N��ר���ж�ǽ���ϵĹŹ�ͼ�Ρ�\n", me);

//	switch( random(5) ) 
//	{
//	    case 0:
		if ( (int)me->query_skill("dodge", 1) < 220)
		{
			me->improve_skill("dodge", me->query("int"));
			write("�����ǽ����ĥ��һ�ض����ƺ��Ի����Ṧ�е��ĵá�\n");
			me->set_temp("stone_learned",1);
		}


	if ( !me->query_temp("stone_learned") )
	{
		write("�����ǽ����ĥ��һ�ض�������������˵��̫��ǳ�ԣ�������˵�Ѻ��������ˡ�\n");
	}
	return 1;
}