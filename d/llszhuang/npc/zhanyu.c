#include <ansi.h>
inherit NPC;
void create()
{
        object sword;

        set_name("չ��", ({ "zhan fei"}) );
        set("long",@LONG
����Լ��ʮ�ţ����θ��ݣ��ֽž�����ͨ�˳���һЩ���������ɣ�˫Ŀ
ת����ʹ�˸е����Ǹ�������ǵ����
LONG
         );

        set("title",MAG"ì��˫��"NOR);
        set("max_jing", 4000);
        set("max_qi", 3000);                    
        set("max_sen", 4000);
        set("max_neili",5000); 
        set("neili",10000);
        set("jiali",70);     
        set("combat_exp",3900000);
        set("bellicosity",50000);
        set("cor",150);
        set("age",65);

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
        }
}

