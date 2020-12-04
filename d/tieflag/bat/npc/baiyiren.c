 inherit NPC;
#include <ansi.h>  
void create()
{
        set_name("����������", ({ "white cloth man", "man" }) );
        set("nickname", HIC "һ��������" NOR );
        set("gender", "����");
        set("age", 32);
        set("long",
"
����һλ�书�����Ķ����ʿ������һ����ɨ��ԭ����,
�����޵У������������º�����У��첻֪��ȥ��
\n"
        );
        create_family("ӣ��", 1, "��ʿ"); 
        set("attitude", "heroism");
        set("combat_exp", 4500000);
        set("score", 200000);
 
        set("reward_npc", 1);
        set("difficulty", 20);
        set("class","ninja");
        set("chat_chance", 1);
        set("chat_msg", ({
"��������������ĵ��������й���ʿ���ǲ���һ����\n",
"���������˰�Ȼ�����Ҵ�������ʿ������ս���Ҳ��ҽ��ܣ�\n",
"�������������������һ���Ϳ��Ժ�ɨ���ǵĽ�����\n",
        }) ); 
        set("agi",45);
        set("int",30);
        set("str", 40);
        set("cor", 300);
        set("cps", 30);
        set("con", 30);
                       
        set("neili", 2500);
        set("max_neili", 2500);
        set("force_factor",90);
        set("mana",1500);
        set("max_mana",1500); 
        set_skill("unarmed", 200);
        set_skill("ghosty-force",300);
        set_skill("enmeiryu",180);
        set_skill("ittouryu",160);
        set_skill("ninjitsu",200);
        set_skill("dodge", 180);
        set_skill("ghosty-steps",200);
        set_skill("blade",160);
        set_skill("literate", 140);
        set_skill("force", 180);
        set_skill("parry", 140);
        set_skill("magic", 100);
        
        map_skill("magic", "ninjitsu");
        map_skill("unarmed", "enmeiryu");
        map_skill("blade", "ittouryu");
        map_skill("parry", "ittouryu");
        map_skill("force", "ghosty-force");
        map_skill("dodge", "ghosty-steps");
        
        
        set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
                (: perform_action,"unarmed.shiden" :),
                (: perform_action, "unarmed.shimon" :), 
                          }) );  
        setup(); 
        carry_object(__DIR__"obj/sword_katana");
        carry_object("/clone/misc/cloth")->wear();
}
void init(){
        ::init();
        if( !query_heart_beat(this_object()) ) set_heart_beat(1);
} 
void win_enemy(object loser)
{
say("���������ˡ��ߡ���һ����˵��������������಻��һ���ļһ�....\n"); 
}
void lose_enemy( object winner)
{
        object gweapon;
        say("\n������������Ȼ�����������һ�������ˣ� �ߴ���ʤ����\n\n");
        if (winner->query("class")=="shenshui" && winner->query_temp("marks/bai_ask"))
        if (!winner->query("marks/ʤ������")) {
                winner->set("marks/ʤ������",1);
                message_vision(CYN"���������˵����˵�������£��Ա��⡣\n"NOR,this_object());
                if (!gweapon=present("black blade",this_object())){
                        gweapon = new(__DIR__"obj/sword_katana");
                        gweapon->move(this_object());
                        }       
                gweapon->move(this_player());
        }
} 
int accept_fight(object me)
{
        message_vision(WHT"���������˳���һ����������ǽڿ������졣\n"NOR,this_object());
        set("qi",this_object()->query("max_qi"));
        set("jing",this_object()->query("max_jing"));
        command("say �ã��������д�һ���书��\n");
        return 1;
} 
int heal_up()
{
 this_object()->start_busy(0);
 ::heal_up();
 return 1;
}
