// Changed by sjmao  09-11-97
inherit NPC;
inherit F_MASTER;
string expell_me(object me);

void create()
{
       set_name("����ү", ({"long shaoye","shaoye","taizi","long","prince"}));

set("long","�����Ĵ���ү��\n");
       set("gender", "����");
	set("int", 25);
       set("age", 26);
       set("title", "����̫��");
       set("attitude", "peaceful");
       set("combat_exp", 450000);
  set("daoxing", 300000);

       set("rank_info/respect", "����");
       set("class","dragon");
       set("per", 30);
       set("max_kee", 1000);
       set("max_gin", 1000);
       set("max_sen", 800);
       set("force", 800);
       set("max_force", 800);
       set("force_factor", 40);
       set("max_mana", 800);
       set("mana", 800);
       set("mana_factor", 40);
  
      create_family("��������", 2, "ˮ��");
	setup();

      
        carry_object("/d/obj/weapon/fork/gangcha.c")->wield();
}

