inherit NPC;
#include "/d/migong/romnpc2.c"
void create()
{
        set_name("�Ų�����", ({"guboer xi", "xi"}));
        set("long", "������ʯɽ�̲�̶���ϱ��\n");
        set("age", 30);
	set("title", "��ǰ��ʹ");
        set("attitude", "peaceful");
        set("gender", "����");
	set("class", "yaomo");
        set("str", 20);
        set("int", 20);
        set("per", 10);
        set("con", 30);
        set("max_qi",500);
        set("max_jing", 500);
        set("combat_exp", 45000);
  set("combat_exp", 60000);

        set("eff_dx", 20000);
        set("nkgain", 250);


        setup();
        initlvl((500+random(500)),53);
        carry_object("/d/obj/armor/tenjia")->wear();
	carry_object("/d/obj/weapon/fork/gangcha")->wield();
}

�