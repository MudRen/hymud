inherit NPC;
void create()
{
        set_name("��ڤ����", ({ "death roc" }) );
        set("race", "Ұ��");
        set("age", 25);
        set("long", "һֻ����ʮ�����͵Ĵ�����\n");
        set("str",100);
        set("limbs", ({ "ͷ��", "����", "β��" }) );
       set("verbs", ({ "bite", "claw" }) );
        set("max_kee",3000);
       set("combat_exp",3400000);
        set("max_force",2000);
        set("force",4000);
        set("force_factor",100);
        set_temp("apply/attack",80);
        set_temp("apply/armor",80);
        set_skill("force",200);
        set_skill("dodge", 500);
        setup();             
}

