// kanshou2.c

inherit NPC;

void create()
{
        set_name("�ⷿ����",({"kan shou","kan","shou"}));
        set("gender", "����" );
        set("age", 25);
        set("long",
                "һ������һ������ԭ����ˣ�����һ��������������վ�����\n");
        set("combat_exp",600000);
        set_temp("apply/defense",10);
        set_temp("apply/attack",5);
        set("attitude", "friendly");
        setup();
}
void init()
{       
        object ob;
        ::init(); 
        if( interactive(ob = this_player()) && !is_fighting() ) {
        remove_call_out("greeting");
        call_out("greeting", 1, ob);
     }
}

void greeting(object ob)
{

	if( !ob || environment(ob) != environment() )
		return;

	switch( random(2) ) 
	{
		case 0:
			message_vision("���ش�����$Nһ�ᣬ˵������λ"+
			RANK_D->query_respect(ob)+"��������\n",ob);
			break;
		case 1:
			say( "����˵������λ" + RANK_D->query_respect(ob)
			+ "�������Ʋſ��Խ�ȥ��\n");
			break;
	}
}

int accept_object(object who, object ob)
{
	if(who->query("class") != "jinghai")
		return 0;
	if( base_name(ob) != __DIR__"obj/wuqiling" )
		return 0;

	if( ob->query("master") != who->query("id") )
	{
		write("��������͵�������ƣ�û���ˡ�\n");
		call_out("dest",1,ob);
		return 1;
	}

	write(name()+"�������ƿ��˿�˵�������ȥ�ɡ�\n");

	who->delete_temp("jinghai_have_ling/wuqi");
	who->set_temp("can_enter_wm19",1);

	call_out("dest",1,ob);
	return 1;
}

private void dest(object ob)
{
	if(objectp(ob))
		destruct(ob);
}
