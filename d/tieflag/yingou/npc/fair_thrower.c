
#include <ansi.h>

inherit NPC;
void pay_him(object who, int amount);
void create()
{
	int i,amun;
	set_name( "������", ({ "huang", "huang ma zi" }) );
	set("long", "���������ķ���ְҵ���֣������ϵĹ�������뻯��\n");
	set("attitude", "friendly");
	set("title", HIW "������"NOR);
        set("force_factor", 30);
/*        set("max_jing", 3000);
        set("max_qi", 3000);
        set("max_sen", 3000);
        set("eff_jing", 3000);
        set("eff_qi", 3000);
        set("eff_sen", 3000); 
        set("jing", 3000);
        set("qi", 99999);
        set("sen", 3000); */
        set("max_atman", 300);
        set("atman", 300);
        set("max_neili", 3000);
        set("neili", 2000);
        set("max_mana", 300);
        set("mana", 300);
	set("age", 33);
        set("gender", "����" );


	set("str", 35);
	set("cor", 30);
	set("cps", 25);
	set("per",5);
	set("lower_limit",1);
	set("too_late",0);
	set("first_dice",0);
        set("second_dice",0);
        set("third_dice",0);
	set("force_factor",250);
	set_skill("throwing",300);
	set_skill("unarmed",200);
	set_skill("dodge",500);
	set("combat_exp", 50000000);
	setup();
        carry_object(__DIR__"obj/yingoupao")->wear();
	carry_object(__DIR__"obj/guzi")->wield();

}
void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
//	add_action("do_bet", "bet");
	
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(10) ) {
                case 0:
                        say( "������Ц�����˵������λ" + RANK_D->query_respect(ob)
                                + "�����������֣������İɡ�\n");
                        break;
                case 1:
                        say( "�����ӻ��˻����е����ӣ��е�����λ" + RANK_D->query_respect(ob)
                                + "��С�Ŀ������Һ��ڣ���Ŀ��Զ���������ɣ�\n");
                        break;
                case 2:
                        say( "������˵������λ" + RANK_D->query_respect(ob)
                                + "�������������� �������ҵģ�\n");
                        break;
        }



	return;

}
 
