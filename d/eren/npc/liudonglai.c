#include <ansi.h>
#include <command.h>
#include <condition.h> 
inherit NPC;
int kill_him(); 
void create()
{ 
        set_name("������",({"liu donglai","liu","donglai"}));
        set("title",YEL"��������"NOR);
        set("long", "һ��������������ˣ����źܿ������뷢���ѷ��ף�����ȴ���Ƿ�����棬������
��Ů�ˡ�������Ҳ�����úܺã���ָ�޳���������������������յ�����Ҳ���ڷ�
������\n");
        set("age",59);
        set("combat_exp", 6400000);
        set("attitude", "friendly");
        
        set("inquiry", ([
             "������" : (: kill_him :),
        ]));
        set("no_busy",9);
        set("max_atman", 1000);
        set("atman", 1000);
        set("max_mana", 1000);
        set("mana", 1000);
        set("max_neili",2000);
        set("neili",2000);
        set("force_factor",300); 
        
                set("reward_npc", 1);
        set("difficulty", 20);
        
    set_skill("move", 120);
    set_skill("parry",150);
    set_skill("dodge", 120);
    set_skill("force", 280);
    set_skill("literate", 180);
    set_skill("unarmed",220);
    set_skill("sword",450);

 

        
        set("str",40);
        set("cor", 40);
        set("cps", 40);
        set("agi",40);
        set("fle",100);
        set("class","quanli");
        set("no_fly",1);
        
        set("resistance/gin",30);
        set("resistance/kee",50);
        set("resistance/sen",40);
        
//      setting up special NPC function: healer, defense, zombie-killer
//         defense_type: 1. xiaohun-sword; 2.xiaohun-whip;3 yue-strike;4 lingxi-zhi;
        
        set("defense_type",random(2)+1);        
//      set("zombie-killer",1);
//      set("officer-killer",1);
//      set("dungeon_npc","check");
        
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                             (: perform_action, "sword.yueyinghanshan" :),
        }) );
         

        setup();
        carry_object("/clone/misc/cloth")->wear();
        carry_object("/clone/weapon/gangjian")->wield();
}  
void init()
{
        add_action("do_killing", "kill");
        ::init();
} 
int kill_him()
{
        object me, another;

        me = this_player();
        if (this_object()->is_fighting()) {
                tell_object(me,"����������û�ջش��㡣\n");
                return 1;
                }
                        
        message_vision(CYN"$N�������Ǵ����������£���Ȼ�����������䣬���������ص�ʮ����ǰ����
���ǻ���ͬ�����ġ���������Ϊ������ʵ�ڲ��Ǹ�������������Ϊ�˸�Ů�ˣ���
�������磬���������ҵģ����ǰ�����ȴ������Ȩ�ƺ�Ǯ�ƣ�ǿռ��������\n"NOR,this_object());
        if( me->query_temp("killed_yuan_ma"))
        {
         message_vision("\n\n\n$N��̾һ���������ԣ����������ˣ����ҡ��㣬ɱ�����ˣ��ˣ���\n\n"NOR,this_object());
        this_object()->kill_ob(me);
        me->kill_ob(this_object());
        }
        return 1;

}
void die()
{
        int i;
        object killer,owner; 
        if(objectp(killer = query_temp("last_damage_from"))) {
             if(owner=killer->query("possessed")) killer = owner;
             killer->set_temp("wanma/������_ma", 1);
        }
        
        ::die(); 

}
int do_killing(string arg)
{
        
        object player, victim, weapon;
        string name;
        player = this_player();
        if( !arg) return 0;
        if( objectp(victim = present(arg, environment(this_object()))) && living(victim))
        {
                name = (string)victim->name();
                if( (string)name == "Ԭ����")
                {
                message_vision("$Nһ�ѵ���Ԭ������ǰ��������ɻ䣬��ս�پ�����\n", this_object());
                this_object()->kill_ob(player);
                player->kill_ob(this_object());
                return 0;
                }
        }
        return 0;               
} 