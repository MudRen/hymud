#include <ansi.h>
inherit NPC;
int *stat =({0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0});
int *low_index = ({});
void pay_him(object who, int amount);
void clear_stat();
void pre_cal();
void create()
{
        int i,amun;
        set_name( "��Ʀ��", ({ "pizi", "huang pi zi" }) );
        set("long", "һ���������ķ�������˵�С��å��\n");
        set("attitude", "friendly");
        set("title", HIW "�Ĺ�"NOR);
        set("force_factor", 30);
        //set("reward_npc", 1);
        //("difficulty", 40);
        set("fly_target",1);
        set("max_atman", 1000);
        set("atman", 1000);
        set("max_neili", 2000);
        set("neili", 2000);
        set("max_mana", 1000);
        set("mana", 1000);
        set("age", 33);
        //temp("apply/damage",600);
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
        set_skill("throwing",30);
        set_skill("unarmed",20);
        set_skill("dodge",50);
   set("combat_exp", 500000);
        setup();
                carry_object("/clone/misc/cloth")->wear();
        carry_object(__DIR__"obj/stone")->wield();

}
void init()
{
        object ob; 
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
//        add_action("do_bet", "bet");
        
} 
void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(10) ) {
                case 0:
                        say( "��Ʀ��Ц�����˵������λ" + RANK_D->query_respect(ob)
                                + "�����������֣����������ɡ�\n");
                        break;
                case 1:
                        say( "��Ʀ�ӻ��˻����е����ӣ��е�����λ" + RANK_D->query_respect(ob)
                                + "��С�����飬С�����顣���ɣ�\n");
                        break;
                case 2:
                        say( "��Ʀ��˵������λ" + RANK_D->query_respect(ob)
                                + "�������������� ����Ȼ����ӵĻ���ö࣡\n");
                        break;
        }   
        return; 
}
 
