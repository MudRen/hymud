inherit NPC;
#include "/d/migong/romnpc2.c"
void create()
{
        set_name("�����ʹ", ({"guard"}));
        set("long", "һ����������ĺ�������ʹ��\n");
        set("age", 30);
	set("attitude", "heroism");
        set("gender", "����");
        set("str", 25);
        set("int", 20);
        set("per", 10);
        set("con", 30);
        set("max_qi",800);
        set("max_jing", 800);
        set("combat_exp", 100000);
  set("combat_exp", 100000);

        set("neili", 500);
        set("max_neili", 500);

        setup();
initlvl((550+random(550)),45);       
	carry_object("/d/obj/weapon/fork/gangcha")->wield();
}
