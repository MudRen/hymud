
inherit NPC;

void create()
{
        set_name("��¹", ({ "she lu","lu"}) );
        set("race", "Ұ��");
        set("age", 5);
        set("long", "һֻ�����ڵ�ͷ�Բݡ���������ϣ������㣬���Ǵ����ֶ�������\n"
                    "�õ��ġ�\n");

        set("limbs", ({ "ͷ��", "����", "β��" }) );
        set("verbs", ({ "bite" }) );
        if( random(2) == 1){
        set("combat_exp", 5000+random(3000));}
        else {
        set("combat_exp", 20000+random(20000));
        set_skill("unarmed",60);}
        //set_wugong("unarmed",60,60,0);
        setup();
}


