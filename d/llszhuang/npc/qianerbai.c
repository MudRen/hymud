#include <ansi.h>
inherit NPC;
void create()
{
        set_name("Ǯ����", ({ "qian erbai","qian","erbai"}) );
        set("long",@LONG
���˿��������ϣ�ȴ��Ƥ��������������İ�С��ԭ��Ӧ�Ǹ��������۵ĺ��ӣ�
������һ���۾���â��˸������������͸�ӱ��˷θ��㣬һ��̤�ڵ��ϣ���������ϥ
ͷ�����ż�������������̩ɽ�ĸо������ڶ�ʹ�˸е�������ƽ��֮����
LONG
         );
        set("title",BLU"�������"NOR);
        set("nickname","���Ƽ�");
        set("max_jing", 6000);
        set("max_qi", 6000);                    
        set("max_sen", 6000);
        set("max_neili",6000); 
        set("neili",6000);
        set("jiali",120);     
        set("combat_exp",5800000);
        set("cor",200);
        set("kar",200);
        set("age",65);
        set_skill("pixie-jian", 420);
        set_skill("dodge", 500);
        set_skill("parry", 500);
        set_skill("sword",420);
        set_skill("force",800); //��ֹ��������ָ
        set_skill("hamagong",500);
        set_skill("tiyunzong",500);
        map_skill("sword","pixie-jian");
        map_skill("parry","pixie-jian");
        map_skill("dodge","tiyunzong");
        map_skill("force","hamagong");
        set_temp("apply/attack",50);
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

