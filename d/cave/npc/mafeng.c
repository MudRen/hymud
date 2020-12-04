#include <ansi.h>
inherit NPC;
void smart_fight();
void smart_busy();
void smart_attack();  
void create()
{
    set_name("���", ({"ma feng","ma"}) );
    set("gender", "����" );
    set("nickname", BLU"���꽣"NOR);
    set("title", "������ �ֶ滤��");
    set("long", "���˵����ǲ���ɫ���������⣬����ӥ�����۾�Ҳ����ר����ʬ��أӥ��\n");
    set("attitude", "friendly");
    set("combat_exp", 1000000);
    set("class","shenshui");
    
    set("age", 35);
    set("cor", 25);
    set("cps", 25);
    set("per", 8);
    set("fle", 40);
    set("force", 1000);
    set("max_neili", 1000);
    set_temp("apply/armor", 100);
    set("reward_npc", 1);
    set("difficulty", 2);
    
    set_skill("sword", 100);
    set_skill("nine-moon-sword", 120);
    set_skill("parry", 150);
    set_skill("dodge", 150);
    set_skill("move", 150);
    set_skill("nine-moon-steps",120);
    set_skill("force",150);
    set_skill("nine-moon-force",150);
    set_skill("unarmed",150);
    set_skill("nine-moon-claw",100);
    
    map_skill("force","nine-moon-force");
    map_skill("dodge","nine-moon-steps");
    map_skill("move","nine-moon-steps");
    map_skill("sword", "nine-moon-sword");
    map_skill("unarmed", "nine-moon-claw");
    
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: smart_fight() :),    
        }) );
    
    set("chat_chance", 1);
    set("chat_msg", ({
        "��������վ�ţ��·�ľͷ��һ��������\n",
    }) ); 
        setup();
        carry_object(__DIR__"obj/duansword")->wield();
        carry_object("/clone/misc/cloth")->wear();    
        if (!random(5)) carry_object(__DIR__"obj/stone_1");
                else add_money("gold", random(3));
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
        string where, location;
        if( !interactive(ob) || environment(ob) != environment() )
                return;
        if (!ob->query("vendetta/authority") ){
            message_vision("$N�ٺٵ�����������˽��������ĵ�ͷ���������ɣ�\n", this_object() );
                this_object()->kill_ob(ob);
                ob->kill_ob(this_object());
        }
        return;
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
        this_object()->perform_action("dodge.lianhuanbu");
}
smart_attack() {
        this_object()->perform_action("sword.shuanglengcanxia");        
        }   
