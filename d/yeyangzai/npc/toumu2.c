#include <ansi.h>
inherit NPC;

void create()
{
	set_name("Ұ��կСͷĿ",({"xiao toumu","xiao","toumu"}));
        set("shen_type",-1);
	set("nickname","˳���");
	set("area","Ұ��կ");
	set("age",25);
	set_skill("dodge",80);
	set_skill("unarmed",80);
	set_skill("parry",80);
	set_skill("blade",80);
	set("max_neili",800);set("neili",800);
	set("combat_exp",100000);
        setup();
	carry_object("/clone/weapon/gangdao")->wield();
	add_money("silver",50);
	carry_object(__DIR__"obj/tongjia")->wear();
}
	
void init()
{
object ob;
	::init();
        if( interactive(ob = this_player())  ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
	string banghui;
        if( !ob || environment(ob) != environment() ) return;
	banghui=(string) ob->query("banghui");
        if(! banghui || query("banghui")!=banghui)   {
                command("say ����˽��Ұ��կ���ҿ����ǲ�����ˣ�\n");
		command("guard south");
                kill_ob(ob);
                ob->fight_ob(this_object());
                return;
        }
}


