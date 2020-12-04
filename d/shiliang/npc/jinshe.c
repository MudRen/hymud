// Feb. 6, 1999 by Winder
// jinshe.c �����ɾ�
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
void dest(object ob);
int ask_me();
void create()
{
	set_name("��ѩ��", ({"xia xueyi", "xia", "xueyi"}));
	set("nickname", HIY"�����ɾ�"NOR);
	set("gender", "����");
	set("age", 25);
	set("long", 
		"�������˳ơ������ɾ�����һ���ֽܡ�����ѩ�ˡ�\n"
		"������ȫƾ�ö�ʱ��ʱа���˵��Ƕ����������ò�������\n"
		"��˵���������ܲң���Ҳ���ƫ��������\n"
		"���������������˵��ˣ���ɫ���ѿ���\n");
 	set("attitude", "peaceful");
	
	set("str", 100);
	set("int", 30);
	set("con", 30);
	set("dex", 135);
	set("chat_chance", 15);
	set("chat_msg", ({
		"��ѩ��ͻȻ��ݺݵ�˵�����Ƕ����㵽��ΪʲôҪ���ң���\n",
		"��ѩ�����з·�Ҫ���������\n",
                "ͻȻ����ѩ�ˡ��ۡ���һ�����³�һ��ڴ��ڵ�Ѫ��\n",
	}));
	set("inquiry", ([
		"������" : (: ask_me :),
		"����": "��....��..... \n",
	]));
	set("qi", 100000);
	set("max_qi", 100000);
	set("jing", 50000);
	set("max_jing", 50000);
	set("neili", 90000);
	set("max_neili", 90000);
	set("jiali", 100);
	set("no_get",1);
	
	set("combat_exp", 50000000);
	 
	set_skill("force", 300);		// �����ڹ�
	set_skill("huntian-qigong", 300);	// ��������
	set_skill("unarmed", 320);		// ����ȭ��
	set_skill("dodge", 300);		// ��������
	set_skill("parry", 300);		// �����м�
        set_skill("sword", 300);                // ��������
        set_skill("jinshe-jian",400);           // ���߽���
	
	map_skill("force", "huntian-qigong");
	map_skill("sword", "jinshe-jian");
	map_skill("parry", "jinshe-jian");
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "sword.kuangwu" :),                
                (: perform_action, "sword.kun" :),                
                (: perform_action, "sword.shi" :),                
                (: perform_action, "sword.suo" :),                
                (: perform_action, "sword.wan" :),                
        }) );
	set_temp("apply/attack",  250);
	set_temp("apply/defense", 250);        	
	set_temp("apply/damage", 1250);   
	set_temp("apply/armor", 1250);   
	setup();
	
	carry_object("/clone/misc/cloth")->wear();
        carry_object("/clone/weapon/changjian")->wield();
}
int accept_object(object who, object ob)
{
	object obn;
		int i;
		object where = environment(who);
	if( !who || environment(who) != environment() ) return 0;
	if ( !objectp(ob) ) return 0;
	if ( !present(ob, who) ) return notify_fail("��û�����������\n");
	if (  (string)ob->query("id") != "wen shoupa")
		    return notify_fail("��ѩ�˲���Ҫ���������\n");

	if (  !who->query_temp("book1321"))
		    return notify_fail("���õ����߽�����?\n");

	if (  !who->query_temp("book1322"))
		    return notify_fail("�������������������?\n");
	if (who->query("combat_exp",1) < 800000)
	{
	command("look  "+who->query("id"));
	command("sneer "+who->query("id"));
	return notify_fail("ƾ����㱾���������ҵ����£���\n");
	}	

         write(HIY "��ѩ�˽ӹ������������س���ͻȻ����Ȼ���¡� \n" NOR);
         write(HIR "��ѩ���૵����Ƕ�������֪��������⣬��ʵ��������ģ���Ҳ���ں��ġ�\n" NOR);         
         write(HIY "��ѩ��ת��ͷ������˵���Ҹ�������л���أ�\n" NOR);
         write(HIY "����ת��ȥ����Ĭ���������˼����ʲô��\n" NOR);
         write(HIY "��ѩ��ͻȻ�����˺ܴ�����Ƶض���˵���ҿ�\n" NOR);
         write(HIY "��Ҳ���������ˣ������������ұ�����Ѫ�ġ�������ܸ����\n" NOR);
         write(HIY "������������˵�Ѿ�û��ʲô���ˣ������ȥ�ɡ�\n" NOR);
         write(HIY "��ѩ��̾�˿����������ǳ�������Ҳ�ã���������Ҳ�ã�������ΪҲ�ã�ͨͨ�����޹ء�\n" NOR);
         write(HIY "��ѩ�˻��˻��֣����ˣ���������ˡ���˵Ԭ��־��С�Ӹ��嶾��ץȥ�ˡ�\n" NOR);
if((int)who->query("jinyong/book13")==1)
{
	i = 500+random(1800);
	who->set("jinyong/book13",2);
	who->add("combat_exp",i+8880);
	who->add("potential",i*10);
	who->add("mpgx",10);
	who->add("expmax",2);

	tell_object (who,"��Ӯ����"+chinese_number(i+8880)+"�㾭��"+
	           chinese_number(i*10)+"��Ǳ��"+"ʮ�����ɹ��� ����ɳ����ޣ���\n");
	who->save();	
	
	
}
         obn = new("/clone/book/jinshe1");
         obn->move(who);
         obn = new("/clone/book/jinshe2");
         obn->move(who);
         obn = new("/clone/book/jinshe3");
         obn->move(who);

         //destruct(ob);
         return 1;
}
void dest(object ob)
{
    destruct(ob);
}

int ask_me()
{
	int i;
        object ob;
	object who = this_player();
	object where = environment(who);
	
	  	if(!who->query_temp("book131"))
	{
		message_vision("$N��$n˵���� ��Ů����������ɱ��Ķ���ץ���� ��\n",this_object(),who);
		
		return 1;	
	}
	  	if(((int)who->query("jinyong/book13")>=1))
	{
		message_vision("$N��$n˵���� ��������,����˵ʲô����\n",this_object(),who);
		
		return 1;	
	}

if(!who->query("jinyong/book13"))
{
	i = 200+random(800);
	who->set("jinyong/book13",1);
	who->add("combat_exp",i+8880);
	who->add("potential",i*10);
	who->add("mpgx",10);
	who->add("expmax",2);

	tell_object (who,"��Ӯ����"+chinese_number(i+8880)+"�㾭��"+
	           chinese_number(i*10)+"��Ǳ��"+"ʮ�����ɹ��� ����ɳ����ޣ���\n");
	who->save();	
	
	
}
	command("thank " + who->query("id"));
	message_vision("$N��$n˵���� лл����������Ů��֮������\n",this_object(),who);
	message_vision("$N��$n˵�������Ǹ��¼ҹ������ˣ�������ȥȡ�˽��߽�������ȥ�������ǿ��������Ӱɡ�\n",this_object(),who);

	                  
	return 1;
}
