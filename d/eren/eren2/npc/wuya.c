#include <ansi.h>
inherit NPC;
void special_smart_fight(); 
void create()
{
        set_name("κ����", ({"wei wuya","wuya"}) );
        set("gender", "����" );
        set("title",HIG"ʮ���Ǿ�"NOR);
        set("nickname", HIG"����"NOR);
        set("long", "����������С��ͯ�ӣ�һ��Ҳ˵�����ж��ѿ������ϣ�ȴ����һ���ܺÿ��ĺ��ӣ�
����ƮƮ��������Ʈ�����ϡ�\n"); 
        set("attitude", "aggressive");
        set("combat_exp", 15000000);
        set("dungeon_npc","eren2");
        
        set("max_atman", 10000);
        set("atman", 10000);
        set("max_mana", 10000);
        set("mana", 10000);
        set("max_neili",20000);
        set("neili",20000);
        set("force_factor",100);
         
        
        set("resistance/gin",60);
        set("resistance/kee",60);
        set("resistance/sen",60);
        
        set_skill("parry",400);
        set_skill("move",400);
        set_skill("unarmed",400);
        set_skill("dodge",400);
        set_skill("spells",400);
        set_skill("necromancy",250);
        set_skill("changquan",300);
        map_skill("unarmed","changquan");
        
        set("cor", 40);
        set("cps", 40);
        set("int",40);
        set("agi",40);
        
        set("chat_chance", 1);
        set("chat_msg", ({
                
        }) );
        
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: special_smart_fight() :),    
        }) );
        
        setup();
        carry_object(__DIR__"obj/whitecloth")->wear();
        carry_object(__DIR__"obj/ironfist")->wield();
} 
special_smart_fight()
{
        int i;
        object *enemy,me,guard;
        string weapon_name;
        
        me=this_object();
        
        if (!guard=present("wei baiyi",environment(me))) 
                if (guard=find_living("wei baiyi")) {
                        message_vision(CYN"$N˵�������£�����������Ϊʦһ�ѣ�\n"NOR,me);
                        guard->move(environment(me));
                        }
        if (!guard=present("wei mayi",environment(me)))
                if (guard=find_living("wei mayi")) {
                        message_vision(CYN"$N˵�������£�����������Ϊʦһ�ѣ�\n"NOR,me);
                   guard->move(environment(me));
                        }
        
        if (!guard=present("wei qingyi",environment(me)))
                if (guard=find_living("wei qingyi")) {
                        message_vision(CYN"$N˵�������£�����������Ϊʦһ�ѣ�\n"NOR,me);
                        guard->move(environment(me));
                        }
        if (!guard=present("wei huangyi",environment(me)))
                if (guard=find_living("wei huangyi")) {
                        message_vision(CYN"$N˵�������£�����������Ϊʦһ�ѣ�\n"NOR,me);
                        guard->move(environment(me));
                        }       
        enemy = this_object()->query_enemy();
        i = sizeof(enemy);
        switch( random(4)){
                case 0: weapon_name="zhui";
                        break;
                case 1: weapon_name="chain";
                        break;
                case 2: weapon_name="mirror";
                        break;
                case 3: weapon_name="flag";
                        break;
                }

}  
