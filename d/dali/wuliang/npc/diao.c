// fox.c
// Date: Sep.22 1997

inherit NPC;

void create()
{
        set_name("������", ({ "shandian diao", "shandiandiao" }) );
        set("race", "Ұ��");
        set("age", 4);
        set("long", "һֻ���ɳ��Ե���������\n");
//        set("attitude", "aggressive");
        set("attitude", "peace");
        set("shen_type", -1);

        set("limbs", ({ "��ͷ", "����", "ǰצ", "��ץ", "β��" }) );
        set("verbs", ({ "bite", "claw" }) );
        set("combat_exp", 100000);
 set("max_neili", 2000);
  set("max_qi", 2000);
   set("max_jing", 2000);
        set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 3000);
        set_temp("apply/damage", 3000);

        setup();

        set("chat_chance", 10);
        set("chat_msg", ({
                "���������Ų��Ų�����ǽ䱸�����顣\n",
                "���������Ŷ��ɵ��۹���㿴��ȫ��һ���ܽ��ŵ�ģ����\n",
        }) );
}

