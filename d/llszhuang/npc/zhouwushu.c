#include <ansi.h>
inherit NPC;
void create()
{
        set_name("������", ({ "zhou wushu","zhou","wushu"}) );
        set("long",@LONG
��������ĸߴ���ò���˫��ϸ������������һ�ֲ�̬�Ļ�ɫ��ʹ�˲�
���ÿ������ǣ������������һ�������������������
LONG
         );
        set("title",GRN"�������"NOR);
       set("nickname","�����");       
        set("max_jing", 4000);
        set("max_qi", 8000);                    
        set("max_sen", 4000);
        set("max_neili",7000); 
        set("neili",7000);
        set("jiali",50);     
        set("combat_exp",3500000);
        set("cor",100);
        set_skill("pixie-jian", 520);
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
        set_temp("apply/damage",250);
        set("chat_chance",3);
        set("chat_msg", ({
                "�˷��������Ŵ�������£���̬����֮����\n",
                "�˷��ƾ���ʢ������Ϫ��Ȫ�ľƺ�����һ��ڣ�Ц����ʹ�죬ʹ�죡\n"
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

