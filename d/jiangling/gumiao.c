//Edited by fandog, 02/15/2000
#include <ansi.h>;
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�����ش���Ƨ�����ʧ�ޣ�����Ҳ����ף���С��������ǻҳ�
������ȴ��֦�ִ������(lazhu)���ڰ��ϡ�
LONG );
	set("item_desc", ([
		"lazhu": "һ֦�ִ�����������ƺ���Ϊ���ʣ���������˵����\n"
	]) );
	set("exits", ([
		"east" : __DIR__"shangang2",
	]));
	set("objects", ([
		__DIR__"obj/foxiang" : 1,
	]));
	set("coor/x", -1500);
	set("coor/y", -2058);
	set("coor/z", 0);
	setup();
}

void init()
{
	add_action("do_dian", "dian");
	add_action("do_dian", "fire");
	add_action("do_open", "qiao");
	add_action("do_open", "open");
}

int do_dian(string arg)
{
	string dir;
	object me = this_player();

	if( !arg || arg=="" ) return 0;

	if( arg=="lazhu" )
	{
		if (! objectp(present("tangshi jianpu", me)))
			return notify_fail("�����������\n");

		if (! me->query("jinyong/book3"))
			return notify_fail("��û������������ʲô?\n");

		if (me->query("jinyong/book3")==5)
			return notify_fail("���Ѿ�ȡ�������˰�?\n");

		if (me->query("jinyong/book3")!=4)
			return notify_fail("��û������������ʲô?\n");


	message("vision", me->name()+"���������������ͻȻ���ַ�������и�����Ү����\n", environment(me));
		me->set_temp("marks/lazhu", 1);
		return 1;
	}
	else 
		return notify_fail("����Ҫ��ʲô��\n");
}
int do_open(string arg)
{
	int i;
	object fang;
	object who;
	object where;
	object foxiang, obj,me ;
me = this_player();
where = environment(me);
	who=me;
	if (!objectp(foxiang = present("dafo xiang", this_object())))
		return notify_fail("��֣����񲻼��ˣ�\n");
	if (foxiang->query("opened"))
		return notify_fail("����������˼Ҵ��ˣ�\n");
	if (me->query_temp("marks/lazhu") )
	{
		message("vision", me->name() + "����ȥ�˰��š��˵ü��£��ǰ��Ž������ˡ�"+me->name()+"����ָ�������������˳���������һ�գ�ֻ�����������ⱦ����������������֪��������֮�У������ж������鱦����\n", environment(me) );
     if(!query("iskillok1"))
      {
      	fang = load_object(__DIR__"npc/wanzhenshan");
	fang->move(environment(who));	
      message_vision("ͻȻ������ͻȻ����ɽɱ�˽��� ��$n˵���� �������ҵ�!\n",fang,who);	
	fang->kill_ob(who);
     this_object()->set("iskillok1",1);
     set("iskillok1",1);
      return 1;
      }	

     if(!query("iskillok2"))
      {
      	fang = load_object(__DIR__"npc/yandaping");
	fang->move(environment(who));	
      message_vision("ͻȻ������ͻȻ���������ָ���ɱ�˽��� ��$n˵���� û�뵽�� ���������ǵ���!\n",fang,who);	
	fang->kill_ob(who);
      	fang = load_object(__DIR__"npc/qichangfa");
	fang->move(environment(who));	
	fang->kill_ob(who);
     this_object()->set("iskillok2",1);
     set("iskillok2",1);
      return 1;
      }	


        fang = present("yan daping",where);
	if(fang)
	{
		who->start_busy(3);
		message_vision(""+ RANK_D->query_respect(who) +"�Ȱ��Դ�ƽ����ɡ�\n",who);
		return 1;
	}

        fang = present("wan zhenshan",where);
	if(fang)
	{
		who->start_busy(3);
		message_vision(""+ RANK_D->query_respect(who) +"�Ȱ�����ɽ����ɡ�\n",who);
		return 1;
	}
	

        fang = present("qi changfa",where);
	if(fang)
	{
		who->start_busy(3);
		message_vision(""+ RANK_D->query_respect(who) +"�Ȱ��ݳ�������ɡ�\n",who);
		return 1;
	}	

	if (!who->query_temp("killlc3"))
		return notify_fail("�ݳ���û�������޷�����ȡ���أ�\n");
	if (!who->query_temp("killlc2"))
		return notify_fail("�Դ�ƽû�������޷�����ȡ���أ�\n");
	if (!who->query_temp("killlc1"))
		return notify_fail("����ɽû�������޷�����ȡ���� ��\n");
				

		me->delete_temp("marks/lazhu");
		obj = new("/d/city/obj/goldring");
		obj -> move(foxiang); 
		obj = new("/d/city/obj/necklace");
		obj -> move(foxiang); 
		obj = new("/d/city/obj/goldring");
		obj -> move(foxiang); 
		obj = new("/d/city/obj/necklace");
		obj -> move(foxiang); 
		obj = new("/d/taohua/obj/mingzhu");
		obj -> move(foxiang); 
		obj = new("/d/taohua/obj/mingzhu");
		obj -> move(foxiang); 
		obj = new("/d/taohua/obj/mingzhu");
		obj -> move(foxiang);

		foxiang -> set("opened", 1); 
       if(((int)who->query("jinyong/book3")==4))
	{
		obj = new("/clone/book/tangshi_book2");
		obj -> move(foxiang);
		i = 500+random(3000);
		who->set("jinyong/book3",5);
		who->add("combat_exp",i+20000);
		who->add("potential",i*35);
		who->add("mpgx",10);
		who->add("expmax",2);
		//command("chat "+this_player()->query("name")+"��ɫ���ˣ������Ƕ�ԡ�");
		tell_object (who,"��Ӯ����"+chinese_number(i+20000)+"�㾭��"+
		           chinese_number(i*35)+"��Ǳ��"+"ʮ�����ɹ��� ����ɳ����ޣ���\n");
		message("channel:chat", HIB"������III����˵"+who->name() + "��������Ǿ�����������!"NOR"\n", users());
		who->save();
        }
		return 1;
	}
        else {
		write("�ں����������ʲô����\n");
		return 1;
        }
}