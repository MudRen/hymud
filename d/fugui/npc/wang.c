 inherit NPC;
inherit F_MASTER;
#include <ansi.h> 
void smart_fight();
void smart_busy();
void smart_attack(); 
int leave();
void create()
{
        set_name("����", ({ "master wang", "master", "wang" }) );
        set("nickname", HIR"һ�ɳ��� ӥ����"NOR);
        set("gender", "����" );
        set("apprentice_available", 10);
        set("class","fugui");
        set("reward_npc", 1);
        set("difficulty", 10);
        set("age", 36);
        set("int", 40);
        set("spi", 25);
        set("cor", 20);
        set("per", 40);
        set("attitude","heroism");
        set("max_neili", 1000);
        set("force", 1000);
        set("force_factor",40); 
        set("long",
"�����ñ������ѿ���ֻ�����Ե���Ƽ��ݣ���˵������������������\n�ӣ������Ѷ��˺ü��졣ֱͦͦ���ڴ���,����û��˯�ţ��۾�����\n���úܴ�\n"
        );
        set("chat_chance", 2);
        set("chat_msg", ({
                "�������������·����ţ�����ܵ�����ȥ�ˣ�\n",
        }) );
        set("inquiry",  ([
                "����·" : "��...��ͷ��ţ.....\n",
                "������" : "��....\n",
                ])                      ); 
        create_family("����ɽׯ", 7, "ׯ��");
        set("combat_exp", 4000000);
        set("rank_nogen",1);
	 	set_skill("fengmo-zhang",180);
	set_skill("liuhe-zhang",180);
set_skill("dagou-bang",80);
	set_skill("strike",190);
	set_skill("force", 250);             // 
	set_skill("force", 180);             // �����ڹ�
	set_skill("huntian-qigong", 330);    // ��������
	set_skill("dodge", 150);      	     // ��������
	set_skill("xiaoyaoyou", 320);        // ��ң��
	set_skill("parry", 150);             // �����м�
	set_skill("hand", 200);              // �����ַ�

	set_skill("blade", 180);             // ��������
	set_skill("liuhe-dao", 280);       // �������ϵ�
	set_skill("begging", 200);           // �л�����
	set_skill("checking", 200);          // ����;˵
	set_skill("training", 200);          // Ԧ����
	set_skill("strike",285);  // �����Ʒ�

	set_skill("xianglong-zhang",285);

	map_skill("strike","lianhua-zhang");
	prepare_skill("strike","lianhua-zhang");

	
	map_skill("force", "huntian-qigong");
	map_skill("hand",  "suohou-gong");
	map_skill("dodge", "xiaoyaoyou");
	map_skill("blade", "liuhe-blade");
	map_skill("parry", "yuejia-qiang");

	set_skill("yuejia-qiang", 380);        // �򹷰���
	set_skill("suohou-gong", 380);        // �򹷰���
set_skill("chansi-shou", 380);        // �򹷰���
set_skill("claw", 380);        // �򹷰���
set_skill("hand", 380);        // �򹷰���	
set_skill("club", 380);        // �򹷰���		
map_skill("parry", "yuejia-qiang");
map_skill("club", "yuejia-qiang");
map_skill("claw", "suohou-gong");
map_skill("hand", "chansi-shou");

	prepare_skill("hand",  "chansi-shou");
prepare_skill("claw",  "suohou-gong");

       set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "club.gong" :),
                (: perform_action, "club.qldj" :),
                (: perform_action, "club.zhtx" :),
                (: command("unwield yuejia qiang") :),
                (: command("wield yuejia qiang") :),
                (: perform_action, "claw.suo" :),
                (: perform_action, "hand.qin" :),                
                (: perform_action, "hand.qinna" :),                
                (: perform_action, "dodge.gjtq" :),                                
                (: perform_action, "dodge.canghaiyixiao" :),                                
                (: perform_action, "dodge.maishou" :),                                
        }) );

   
        set_temp("apply/iron-cloth",110);
        
        set("ranks",({ "����","���","С�ܼ�","�ܼ�","��ܼ�",
                        CYN"�ܹ�"NOR,CYN"���ܹ�"NOR,HIC"��ׯ��"NOR }));
        setup();
        carry_object(__DIR__"obj/oldcloth")->wear();
        carry_object(__DIR__"obj/spear")->wield();
} 
void reset()
{
                set("apprentice_available", 5);
} 

                
int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "fugui");
                ob->add("betrayer",-1);
                ob->add("score",-5000);
        if(ob->query("betrayer") < 0) ob->set("betrayer",0);
        add("apprentice_availavble", -1);
} 
void killed_enemy(object who)
{
        command("say �α���Ѱ��·�أ�\n");
} 
int accept_fight(object me)
{
        command("say ���ܣ����ŵ��������Ҵ�ɨһ��Ժ�Ӱɣ�");
        command("sleep");
        return 0;
} 
void init()
{
        ::init();
        add_action("do_killing", "kill");
} 
int do_killing(string arg)
{       
        object player, victim, weapon;
        string name;
        if(!arg) return 0;
        player = this_player();
        if( objectp(victim = present(arg, environment(this_object()))) && living(victim))
        {
                name = victim->name();
                if( name == "����")
                {
                        if (weapon = present("silver spear", this_object())) {
                                message_vision("$N����üͷ��\n", this_object());
                           message_vision("$N��֪����������һֻ����ǹ��\n", this_object());
                                weapon->wield();
                                call_out("do_unwie", 3);
                                }
                        return 0;
                }
                return 0;
        }
        return 0;               
} 
int do_unwie()
{
        if( !this_object()->is_fighting())
        {
                command("unwield spear");
                message_vision("$N�����ۡ������Ƿ�������ɵ��ڴ��ϡ�������\n", this_object());
                return 1;
        }
        else
                call_out("do_unwie", 3);
} 
int accept_object(object me, object ob)
{
        if(ob->query("name") == HIY"������"NOR)
        {
                command("touch " + me->query("id"));
                command("say ����֪����·����Ϣ�ˣ�\n");
                command("say ��λ" + RANK_D->query_respect(me)+ "���������л��ֻҪ��Ը�⣬�Ժ�������Ҹ���ɽׯ������.\n");
                me->set_temp("marks/������",1);
                return 1;
        }
        else
                tell_object(me,"����˵�����ⲻ������Ҫ�ġ�\n");
                return 0;      
} 
int leave() {
        if (this_player()->query("class")!="fugui") return 0;
        message_vision(CYN"$NЦЦ�������̫�����ס���ˡ���\n"NOR, this_object());
        message_vision(CYN"$N˵���˸���־���Ҳ���ǿ��ֻ���ҵĺ����ľ�����û��������ˡ�\n"NOR,this_object());
        return 1;
} 
smart_fight()
{
        int i;
        object *enemy;
        enemy = this_object()->query_enemy();
        i = sizeof(enemy);
        while(i--) {
                if( enemy[i] && living(enemy[i]) ) {
                        if (!enemy[i]->is_busy()
                                && enemy[i]->query("combat_exp")<this_object()->query("combat_exp")) {
                                this_object()->smart_busy();
                        }
                        {
                                this_object()->smart_attack();
                        } 
                }
        }
} 
smart_busy() {
        this_object()->perform_action("dodge.yingjichangkong");
}
smart_attack() {
        this_object()->perform_action("spear.bafangfengyu");    
        }      
