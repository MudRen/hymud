// modified by vikee 2000.11
//����ɽ���ɡ�dhxy-evil 2000.7.5
#include <ansi.h>

inherit NPC;
inherit F_MASTER;
int ask_me();
int ask_jiu();
void attempt_apprentice(object ob);

void create()
{
        set_name(HIC"���ʿ"NOR, ({ "zui daoshi", "daoshi", "zui" }));
        set("long", 
"���ʿ�������˵�ʦ�ܣ���Ϊ�þƣ��������������š�\n");

        set("gender", "����");
        set("title","��ɽ����");
        set("age", 58);
        set("attitude", "peaceful");
        set("str", 20);
        set("int", 35);
        set("con", 30);
        set("per", 30);
        set("class","swordsman");
        
        set("kee", 2500);
        set("max_kee", 2500);
        set("sen", 3500);
        set("max_sen", 3500);
        set("force", 4000);
        set("max_force", 2000);
        set("max_mana", 3000);
        set("mana", 6000);
        set("force_factor", 80);
        set("mana_factor", 100);

        set("combat_exp", 2500000);
        set("daoxing", 3000000);

        set_skill("spells",180);
        set_skill("force", 180);
        set_skill("dodge", 170);
        set_skill("parry", 150);
        set_skill("sword", 180);
   
        create_family("��ɽ����", 5, "����");


   add_temp("apply/damage", 15);
   add_temp("apply/armor", 40);

        setup();
carry_object("/clone/misc/cloth")->wear();
         carry_object("/d/obj/weapon/sword/qingfeng")->wield();
}

