//Cracked by Roath
//����ɽ���ɡ�koker 2001.3.10
inherit NPC;

void create()
{
        set_name("����", ({ "ming yue", "yue" }));
        set("long", 
"��������ɽ��������һ���Ķ����˲š�\n");
        set("gender", "Ů��");
        set("age", 26);
        set("attitude", "peaceful");
        set("str", 25);
        set("int", 23);
        set("con", 24);
        set("cor", 22);
        set("class","swordsman");
        
        set("max_kee", 1500);
        set("max_sen", 1500);
        set("force", 3000);
        set("max_force", 1500);
        set("force_factor", 60);
        set("mana", 3000);
        set("max_mana", 1500);
        set("mana_factor", 60);
        set("combat_exp", 500000);
        set("daoxing", 700000);

     
   add_temp("apply/damage", 15);
   add_temp("apply/armor", 15);

        setup();
carry_object("/clone/misc/cloth")->wear();
        carry_object("/d/obj/weapon/sword/changjian")->wield();
}

