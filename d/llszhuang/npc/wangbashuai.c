#include <ansi.h>
inherit NPC;
void create()
{
        set_name("����˥", ({ "wang bashuai","wang","bashuai"}) );
        set("long",@LONG
���˹�����Ŀ��Ƥ���ǵ������������ˣ�����������ӵ�����������
��ħӥ�����˸е�����������
LONG
         );
        set("title",CYN"�������"NOR);
       set("nickname","�����");
        set("max_jing", 6000);
        set("max_qi", 8000);                    
        set("max_sen", 6000);
        set("max_neili",7000); 
        set("neili",7000);
        set("jiali",190);     
        set("combat_exp",15000000);
        set("cor",250);
        set("age",35);
        set_skill("pixie-jian", 420);
        set_skill("dodge", 500);
        set_skill("parry", 500);
        set_skill("sword",520);
        set_skill("force",800); //��ֹ��������ָ
        set_skill("hamagong",500);
        set_skill("tiyunzong",500);
        map_skill("sword","pixie-jian");
        map_skill("parry","pixie-jian");
        map_skill("dodge","tiyunzong");
        map_skill("force","hamagong");

        set_temp("apply/damage",150);
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



