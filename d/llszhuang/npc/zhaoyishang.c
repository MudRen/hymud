#include <ansi.h>
inherit NPC;
void create()
{
        set_name("��һ��", ({ "zhao yishang","zhao","yishang"}) );
        set("long",@LONG
��һ����������ң��ײб��ң��������������������ΰ֮����������
�벿���������ݰ�Ķ��ڣ�����Ƿ����ĺ�Ҳ����ڸ��ˣ�һ����ͭ����
�������������μ�����һ��������̬��
LONG
         );
        set("title",RED"�������"NOR);
        set("nickname","�����");
        set("max_jing", 5000);
        set("max_qi", 8000);
        set("max_sen", 5000);
        set("max_neili",5000); 
        set("neili",5000);
        set("jiali",150);     
        set("combat_exp",3500000);
        set("cor",100);
        set("age",35);
        set_skill("pixie-jian", 420);
        set_skill("dodge", 500);
        set_skill("parry", 500);
        set_skill("sword",420);
        set_skill("force",800); //��ֹ��������ָ
        set_skill("hamagong",400);
        set_skill("tiyunzong",400);
        map_skill("sword","pixie-jian");
        map_skill("parry","pixie-jian");
        map_skill("dodge","tiyunzong");
        map_skill("force","hamagong");
        set_temp("apply/damage",150);

        set("chat_chance_combat",10);
        set("chat_msg_combat", ({
                (: exert_function,"powerup" :),
        }) );

        setup();
        carry_object("/clone/weapon/changjian")->wield();
}                          
void init()
{
        object ob;
        ::init();
        if (interactive(ob = this_player())) {
                remove_call_out("kill_ob");
                call_out("kill_ob", 1, ob);
         if(random(15) < 2)
                this_object()->set_leader(ob);
        }
}

