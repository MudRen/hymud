// dingdang.c ����
#include <ansi.h>
inherit NPC;
string inquiry_yu();
string ask_wine();
string ask_tian();
void create()
{
        set_name("����", ({ "ding dang","ding"}) );
        set("gender", "Ů��" );
        set("age", 18);
        set("long", "һ��ʮ�߰������Ů�����������ӣ�һ�Ź��������������ޡ�\n");
        set("shen_type", 1);
        set("combat_exp", 100000);
        set("nickname", HIC"��������"NOR);
        set("str", 18);
        set("dex", 22);
        set("con", 25);
        set("int", 35);
        set("per",30);
        set("attitude", "friendly");

        set("qi", 5000);
        set("max_qi", 5000);
        set("jing", 5000);
        set("max_jing", 5000);
        set("neili", 15000);
        set("max_neili", 15000);
        set("jiali", 50);

        set_skill("force", 200);
        set_skill("unarmed", 200);
        set_skill("parry", 200);
        set_skill("dodge", 300);
        set_skill("taiji-shengong", 200);
        set_skill("taiji-quan", 300);
        set_skill("tiyunzong", 500);

        map_skill("force","taiji-shenfong");
        map_skill("unarmed","taiji-quan");
        map_skill("parry","taiji-quan");
        map_skill("dodge","tiyunzong");
        set("chat_change",15);
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "dodge.zong" :),
                (: perform_action, "unarmed.zhenup" :),
                (: perform_action, "unarmed.tu" :),
                (: perform_action, "unarmed.zhan" :),
                (: perform_action, "unarmed.ji" :),
                (: perform_action, "unarmed.jielidali" :),
                (: perform_action, "hand.leiting" :),
                (: perform_action, "hand.mian" :),
                (: perform_action, "strike.zheng" :),	
            
        }) );
        set("chat_msg",({
            "������߶��: Ҳ��֪���ҵ�����������ô���ˡ�\n",
            "��������Ĩ�˰����ᡣ\n",
            "����һ��ţ�˵��: ���У���Ҫ��Ħ���°��ҵ�����Ȼ�����\n",
            "����̾�˿�����˵��: Ҫ����������ͺ��ˡ�\n",
       }) );
       set("inquiry",([
           "ʯ����" : (: inquiry_yu :),
           "Ħ����" : "\n ǰ������ɽ�����ˣ���ҪС��ѽ���Ǹ���ͷ���书��ǿѽ��\n",
           "������" : "\n ��˵����ʯ�����������ҾͲ�֪���ˡ�\n",
		"�����̻��" : (:ask_wine:),
		"wine" : (:ask_wine:),
		"������" : "����������үү�������������£���үү���׵ģ��㻹�Ǳ������ˡ�\n",
		"���" : (:ask_tian:),
		"ʯ����" : (:ask_tian:),
		"ѩɽ��" : "үү������ѩɽ�ɵ����ˣ���ǧ��Ҫ������ǰ����\n",
		"xueshan" : "үү������ѩɽ�ɵ����ˣ���ǧ��Ҫ������ǰ����\n",
		"name" : "���ն���������Ҷ����Ҷ���������\n",
		"����" : "���ն���������Ҷ����Ҷ���������\n",
       ]) );
       set_temp("shoupa",1);
       setup();
//       carry_object("/d/city2/obj/baojia")->wear();
       carry_object("/d/city2/obj/shouzhuo")->wear();
       carry_object("/d/city2/obj/yupei")->wear();
       add_money("silver", 10);
}

string inquiry_yu()
{
 object me=this_player();
 object obn;
 message_vision("����˵������λ"+ RANK_D->query_respect(me)+"���������ҵķ����\n"
         +"����ȥ����ѩɽ�ɱ�л�̿�ץȥ����������������Ҳ��֪�����ǻ����\n"
         , me );
 if(query_temp("shoupa")==0)
 {  message_vision("������˵������λ"+ RANK_D->query_respect(me)+"�����Ѿ���"
       +"��ȥĦ���¿����ˣ�Ҳ��֪����ô���ˡ�\n",me);
   return "�漱�ˣ�";
 }
   message_vision("������˵������λ"+ RANK_D->query_respect(me)+"����������"
       +"һ����������������֮��㿴���ҵ�����\n"
       +"��Ͱ��������������������׵ġ������ˡ�\n" , me);
   obn=new("/d/xiakedao/obj/shoupa");
   obn->move(me);
   set_temp("shoupa",0);
   return "�����ӻ����ó�һ��Ư���������������㡣\n";
}


string ask_tian()
{
	object me=this_player();
	
	if ( me->query_temp("book111"))
	{
	command("sigh");
	return "����������ˣ��Ҹ�ι�˵㡸�����̻�ơ��������ã�ϣ����û�¡�";
	}
	else {
	return "��Ҳ��ʶ������ޣ����ˣ������������°ɡ�";
	}
}

string ask_wine()
{
	int i;
	object ob, *obs,who;
	object me=this_player();
	who=me;
	if (!me->query_temp("book111"))
	{
	command("look  "+me->query("id"));
	command("sneer "+me->query("id"));
	return "���ҵ��Ҷ�����үү���� ��˵���ڼ��ϸ�����";
	}

	if (!me->query_temp("book112") )
	{
	command("look  "+me->query("id"));
	command("sneer "+me->query("id"));
	return "���ҵ��Ҷ�����үү���� ��˵������ɽ������";
	}
	

	if (me->query("combat_exp",1) < 500000)
	{
	command("look  "+me->query("id"));
	command("sneer "+me->query("id"));
	return "ƾ����㱾�������ܱ���������£���";
	}	

	if (query_temp("wine") )
	{
	command("look  "+me->query("id"));
	command("sneer "+me->query("id"));
	return "�����̻���Ѿ��������˰���";
	}
	if ( me->query_temp("book111") && me->query_temp("book112") )
	{
	command("ah "+me->query("id"));
	add_action("do_pretty", "pretty");
	command("say һ����үү������Ȱ�һ�ȥ���ǲ��ǣ�ԭ�����Ѿ�֪����͵�����ı�����");
	command("sigh");
	command("say �����ǰ�������ʣ����˼�������ǻ�����ģ����������֪����ô��ɵ�ˣ������˼ҵĻ�Ҳ����˵�ˡ�");
	command("disapp");
	me->set_temp("pretty/ding", 1);

	if (me->query_temp("pretty/ding")) 
        {
        command("giggle");
        command("happy2 "+me->query("id"));
        command("blush");
        command("say лл������������Ҫ������������磬����Ұ���ʣ�µġ������̻�ơ�����ȥ��үү�ɡ�");
        ob=new("/d/yixing/npc/jiu.c");
	message_vision("������һƿ�������̻�ơ����˸�$N��\n", me);
	ob->move(this_player());
	me->set("got/wine", 1);
	me->delete_temp("book111", 1);
	me->delete_temp("book112", 1);
	me->delete_temp("pretty/ding", 1);
	me->delete_temp("first/ask");
	set_temp("wine",1);
if(!who->query("jinyong/book11"))	
{
        i = 300+random(800);
	who->set("jinyong/book11",1);
	who->add("combat_exp",i+9880);
	who->add("potential",i*12);
	who->add("mpgx",10);
	who->add("expmax",2);

	tell_object (who,"��Ӯ����"+chinese_number(i+9880)+"�㾭��"+
	           chinese_number(i*12)+"��Ǳ��"+"ʮ�����ɹ��� ����ɳ����ޣ���\n");
	who->save();
}

	} 

	return "������Ը������ǰ�Ǹ�����˼ҿ��ĵ���硣";
	}
	else {
		return "�������үү�ģ����Լ�����Ҫ�ɡ�";
		}
}

