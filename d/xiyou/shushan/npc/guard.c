//Cracked by Roath
//����ɽ���ɡ�dhxy-evil 2000.7.5
inherit NPC;

void create()
{
        set_name("��ɽ��ͯ", ({ "jian tong", "tong" }));
        set("title", "��ɽ����");
        set("gender", "����");
        set("age", 8 + random(10));
        set("attitude", "peaceful");
        set("str", 18);
        set("int", 25);
        set("con", 20);
        set("cor", 20);
        set("class","swordsman");
        
        set("max_kee", 800);
        set("max_sen", 800);
        set("force", 1500);
        set("max_force", 1000);
        set("force_factor", 30);
        set("mana", 1500);
        set("max_mana", 1000);
        set("mana_factor", 30);
        set("combat_exp", 300000);
        set("daoxing", 500000);

      
   add_temp("apply/damage", 15);
   add_temp("apply/armor", 15);
        setup();
        
        carry_object("/d/obj/weapon/sword/changjian")->wield();
}

