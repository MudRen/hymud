// luo-bing.c ���
// Last Modified by winder on Sep. 12 2001

#include <ansi.h>
inherit NPC;
inherit F_MASTER;
int ask_me();
void create()
{
	set_name("���", ({ "luo bing", "luo" }));
	set("title", HIR"�컨��"HIG"ʮһ����"NOR);
	set("nickname", HIG"ԧ�쵶"NOR);
	set("long","����һ���������ٸ���\n���Ǻ컨�����ĵ��ҵĻ�ң�����Ԫͨ��Ů����\n��һ�̵ֶ���һ������һ��������˫��ִ���У�����ʻ�֦��������Ȼ��\n");
	set("gender", "Ů��");
	set("class", "swordman");
	set("age", 24);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("per", 28);
	set("str", 21);
	set("int", 21);
	set("con", 21);
	set("dex", 21);
	
	set("max_qi", 1500);
	set("max_jing", 1200);
	set("neili", 1500);
	set("max_neili", 1500);
	set("jiali", 100);
	set("combat_exp", 500000);
	set("score", 50000);

	set_skill("force", 80);
	set_skill("honghua-shengong", 80);
	set_skill("dodge", 80);
	set_skill("youlong-shenfa", 120);
	set_skill("hand", 80);
	set_skill("benlei-shou", 120);
	set_skill("blade", 80);
	set_skill("qiuge-dao", 120);
	set_skill("throwing", 80);
	set_skill("wuying-feidao", 120);
	set_skill("parry", 80);
	set_skill("literate", 50);

	map_skill("force", "honghua-shengong");
	map_skill("dodge", "youlong-shenfa");
	map_skill("hand", "benlei-shou");
	map_skill("parry", "qiuge-dao");
	map_skill("blade", "qiuge-dao");
	prepare_skill("hand", "benlei-shou");
	set("env/wimpy", 60);
	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({	
		(: perform_action, "blade.luohuaqiuge" :),			
		(: exert_function, "powerup" :),
		(: exert_function, "regenerate" :),
		(: exert_function, "recover" :),
	}) );
        set("inquiry", ([

"Ӫ��" : (: ask_me :),
        ]));
	create_family("�컨��", 2, "����");
	setup();
	carry_object("/clone/cloth/female2-cloth")->wear();
	carry_object("/clone/cloth/female-shoe")->wear();
	carry_object("/clone/weapon/gangdao")->wield();
}

void init()
{
	object ob;

	::init();
	ob = this_player();
	if((int)ob->query("shen") < -1000 &&
		ob->query("family/master_id")=="luo bing")
	{
		command( "chat "+ob->query("name")+"�������а���թ֮ͽ���������������ʦ����\n");
		command("expell "+ ob->query("id"));
		this_player()->set("title","�컨��" + RED + "��ͽ" NOR);
	}
}

void attempt_apprentice(object ob)
{
	if ((int)ob->query("shen") < 5000)
	{
		command("say �Һ컨����ͽ���ϡ�");
		command("say ��λ" + RANK_D->query_respect(ob) + "ƽʱ��Ҫ����һЩ��������֮�£�");
		return;
	}
	command("say �ã�����������˻��������������ˣ�");
	command("recruit " + ob->query("id"));
}

int ask_me()
{
	int i;
        object ob;
	object who = this_player();
	object where = environment(who);
	if(!who->query_temp("book91"))
	{
		message_vision("$N��$n˵���� �ҵ��ɷ���̩���������ڰ��\n",this_object(),who);
  
		return 1;	
	}
  	if(((int)who->query("combat_exp",1)<=500000))
	{
		message_vision("����书̫���ˣ����书�õ������ɣ�\n",who);
		return 1;	
	}
	  	if(((int)who->query("jinyong/book9")>=1))
	{
		message_vision("$N��$n˵���� ��л��ȣ�\n",this_object(),who);
		call_out("destroying", 0);     
		return 1;	
	}
	command("thank " + who->query("id"));
	message_vision("$N��$n˵���� лл��������֮������\n",this_object(),who);
	message_vision("$N��$n˵���� ���Ƿ��޴���ȥ�����ڸ���������ׯ �ݱ�һ�¡���\n",this_object(),who);
if(!who->query("jinyong/book9"))	
{
        i = 300+random(800);
	who->set("jinyong/book9",1);
	who->add("combat_exp",i+8880);
	who->add("potential",i*10);
	who->add("mpgx",10);
	who->add("expmax",2);

	tell_object (who,"��Ӯ����"+chinese_number(i+8880)+"�㾭��"+
	           chinese_number(i*10)+"��Ǳ��"+"ʮ�����ɹ��� ����ɳ����ޣ���\n");
	who->save();
}
	call_out("destroying", 0);                       
	return 1;
}
void destroying()
{   
object ob=this_object();
   message_vision(HIM"$N˵�������������ʧ������......\n"NOR,ob);
destruct(this_object());
   return;      
}