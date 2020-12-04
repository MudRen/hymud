// Room: /d/gaochang/mishi2.c

inherit ROOM;

int do_study(string arg);

void create()
{
        set("short", "������");
        set("long", @LONG
�����ǹ�����µĵ������ҡ�������С��ȴҲ�����ȫ��
ʯ��ʯ�Σ�ʯ��ʯ���������ڷŵļ�������Ҳ����ʯ�Ƶġ�
�����ƺ��ܾ���ǰ����������ס�������е�ʯ��(table)��ƽ
����һ�鱡����ʯ�壬����������Щʲô��
LONG
        );
    set("exits", ([
       "south" : __DIR__"mishi",
]) );
   set("objects", ([
// "/clone/book/skybook" : 1,
       ]) );

        set("item_desc", ([
                "table" : "����һ�����ʯ��ɵ�ʯ�����������Щ��ֵ�ͼ�Ρ�\n",
        ]));

        setup();
}

void init()
{
        add_action("do_study", "study");
}


int do_study(string arg)
{
        object me,who,fang;
        int    jing_cost;
        int i;
        me = this_player();
        who =me;
        
        if ( !arg || ( arg != "table" ) )
                return notify_fail("ʲô��\n");


         if(who->query("jinyong/book6")==3 && !query("iskillok1"))
{
      	fang = load_object("/d/hj/npc/boss2");
	fang->move(environment(who));	
      message_vision("ͻȻ����һ����Ӱ $N��$n˵���� �ѱ��ｻ������!\n",fang,who);	
	fang->kill_ob(who);
      	fang = load_object("/d/hj/npc/boss1");
	fang->move(environment(who));	
      message_vision("ͻȻ����һ����Ӱ $N��$n˵���� �ѱ��ｻ������!\n",fang,who);	
	fang->kill_ob(who);

     this_object()->set("iskillok1",1);
     set("iskillok1",1);
       return notify_fail("ԭ�����������˲�������ط���\n");
 }
 
         if (me->is_busy())
                return notify_fail("������æ��\n");

         if (me->is_fighting())
                return notify_fail("������æ��\n");


        if ( (int)me->query_skill("literate", 1) < 1)
                return notify_fail("���Ǹ���ä����ѧ���Ļ�(literate)�ɡ�\n");

        jing_cost = (-1) * random(2);
        if((int)me->query("jing") < jing_cost)
                return notify_fail("�����ھ����޷����У�\n");

        me->add("jing", jing_cost);

        message_vision("$N��ר���ж�ʯ���ϵĹŹ�ͼ�Ρ�\n", me);
 if ( (int)me->query_skill("literate", 1) < 250)


                {
                        me->improve_skill("literate", me->query("int")*10);
                        write("�����ʯ����ĥ��һ�ض����ƺ��Զ���ʶ���е��ĵá�\n");
                        me->set_temp("stone_learned",1);
                }


        if ( !me->query_temp("stone_learned") )
        {
                write("�����ʯ����ĥ��һ�ض�������������˵��̫��ǳ�ԣ�������˵�Ѻ��������ˡ�\n");
        }
        return 1;
}

