#include <ansi.h>
inherit NPC;
void create()
{
        set_name(RED "����ͻ�" NOR, ({ "lao hu","tiger" }) );
        set("race", "Ұ��");
        set("age", 20);
        set("attitude","aggressive");
        set("str",100);
        set("long",RED "    һֻ���͵ĵ����׶��ë���!!" NOR+"����:\n"+@LONG
               ë��һ�����ɫ��צ¶����ʮ��ֻ��
               ��������β��ޣ�����Ѫ������ꪡ�
               ����չ������������βҡͷ��������
               ɽ�к��þ�Ǳ�أ������¹�����
LONG);

        set("limbs", ({ "ͷ��", "����", "β��" }) );
        set("verbs", ({ "bite" }) );
        set("combat_exp", 1000000);
        setup();
        carry_object(__DIR__"obj/tigercloth")->wear();
}


