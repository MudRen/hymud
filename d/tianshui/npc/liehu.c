// design by ���ֺ�(find) . all right reserved.

// liehu.c

inherit NPC;

void su_xing(object me,object ob);

void create()
{
        set_name("����", ({ "lie hu" }) );
	set("title","�Ի�");
        set("gender", "����" );
        set("age", 33);
        set("long", "ֻ������ɫ���ƣ���������Ѫ����
���������˺��ص��ˡ�\n");
        set("combat_exp", 20);
        set("attitude", "friendly");
        set("env/wimpy", 60);
	set("max_kee",200);
	set("kee",5);
	set("eff_kee",5);

        setup();
        carry_object("/clone/misc/cloth")->wear();
        add_money("coin", 20);
}

void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() )
	{
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
	object me = this_object();
	if( !ob || environment(ob) != environment() ) return;
	say( "����ʹ��������ţ������ȥ����û�뵽...������...��λ"+ RANK_D->query_respect(ob)+ "�Ⱦ���...\n");

	me->unconcious();
	remove_call_out("su_xing");
	call_out("su_xing", 20, me, ob);
}

void su_xing(object me, object ob)
{
	if ( (int)me->query("eff_kee") <= 100 ) 
	{
		me->die();
	}
	else
	{
		message_vision("\n�������˹�����˵��: �ҷ�����һ��...����ɽ����������һͷ...��ţһ���Ĺ��\n\n",ob);
		message_vision("�Ҿ��Ǳ���ҧ�˵ģ������ܵÿ��...�������ˣ�ɽ...������...��......\n\n",ob);
		message_vision("���������ڵ��������ض��˼��¡�\n",ob);
		environment(this_object())->set("item_desc",([
		"��" : "
       ��������.....
       ��
   ������ 
   ��\n",
		"����" : "
       ��������.....
       ��
   ������ 
   ��\n",
]));
		me->die();
	}
	return;
}