inherit NPC;
#include "/d/migong/romnpc2.c"
void create()
{
        set_name("«��", ({"lu niang"}));
        set("long",
"��ͷ�ϲ��ż����ɫ«����������Ȼ������ȴ�ڲ�ס���ϵ�������\n");
        set("age", 20);
	set("title", "«����");
        set("attitude", "friendly");
        set("gender", "Ů��");
	set("class", "yaomo");
        set("str", 20);
        set("int", 20);
        set("per", 30);
        set("con", 30);
        set("max_qi",800);
        set("max_jing", 800);
	set_temp("apply/damage", 15);
	set_temp("apply/armor", 15);
        set("combat_exp", 160000);
  set("combat_exp", 100000);



        setup();
        initlvl((500+random(500)),54);
        carry_object("/d/obj/cloth/skirt")->wear();
	carry_object("/d/qujing/bibotan/obj/luhua")->wield();
}
void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 3, ob);
        }
}

void greeting(object ob)
{
        if( !ob || !present(ob, environment(this_object())) ) return;
	
	if((string)ob->query("family/family_name")=="�ݿ�ɽ�޵׶�" 
	&& (string)ob->query("family/family_name")=="��ʯɽ�̲�̶"
        && (string)ob->query("family/family_name")=="��ѩɽ") {
	command("xixi " + ob->query("id"));
	return;
	}
	command("look " + ob->query("id") );
	command("say �ְ����֣���������θ�ڡ�");
	command("chan " + ob->query("id") );
	kill_ob(ob);
	ob->fight_ob(this_object());

	return;
}
