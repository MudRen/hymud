 inherit NPC;
void create()
{
        set_name("����", ({ "rat" }) );
        set("race", "Ұ��");
        set("age", 5);
        set("long", "һֻ��ͷ���Եĺ���������������ؿ����㣬�������ҧ��ʲô������\n");
        set("max_qi", 100);
        set("limbs", ({ "ͷ��", "����", "β��" }) );
        set("verbs", ({ "bite" }) );
        set_skill("dodge", 80); 
        carry_object(__DIR__"obj/drug_flower");
        setup();
} 
