#include <ansi.h>
inherit NPC;
void create()
{
        set_name("���Ĵ�", ({ "li sicui","li","sicui"}) );
        set("long",@LONG
��һ������˹���������̬�����������ӣ���ͦ΢���ıǣ��������������
�����ƿ��Ʊգ�ʱ�о��������һ����֪�������ǵ����������ֻ����ʮ��
��������൱Ӣ������������������������ʮ�����ϣ���˹��ƣ���������Ӧ��
�������ʮ��ֻ�����������������������ླ�磬�����ܿ˷�˥������ϰ���
LONG
         );
        set("title",RED"�������"NOR);
       set("nickname","���ּ�");
        set("max_jing", 6000);
        set("max_qi", 6000);                    
        set("max_sen", 6000);
        set("max_neili",6000); 
        set("neili",6000);
        set("jiali",150);     
        set("combat_exp",3800000);
        set("cor",140);
        set("age",45);

        set_skill("pixie-jian", 420);
        set_skill("dodge", 500);
        set_skill("parry", 500);
        set_skill("sword",420);
        set_skill("force",800); //��ֹ��������ָ
        set_skill("hamagong",400);
        set_skill("tiyunzong",500);
        map_skill("sword","pixie-jian");
        map_skill("parry","pixie-jian");
        map_skill("dodge","tiyunzong");
        map_skill("force","hamagong");
        prepare_skill("claw","spicyclaw");
        set_temp("apply/damage",50);
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

