inherit NPC; 
#include <ansi.h>

void create()
{
        set_name("�������", ({ "peng king" }) );
        set("gender", "����" );
        set("title",HIG"����"NOR);
        set("age", 66);
        set("long", "��Щ������ɫ���ǲ԰ף���Ȼ���ж���δ���������⣬���Ϻ�Ȼ���ǵ����Ĵ�硣\n"); 
        set("combat_exp", 1000);
        set("attitude", "heroism");
        set_skill("unarmed", 20);
        set_skill("parry", 20);
        set_skill("dodge", 20);
                set_skill("whip", 20);
        set("chat_chance", 2);
        set("chat_msg", ({
//                (:random_move :),
        "һ���������������ϳճյĳ���\n",
        "һ�����������ڵ��ϴ����̣����������дʣ��·����ڼ���������ĲƸ���\n",
        "һ�����˶�����ͭ���������Լ�ͷ�ϵİ׷���\n",
        }) ); 
        set("inquiry", ([
                "�������" : "�������Ǻ����ˣ�����δ��ͨ�����ʹ���¼ҵ��޹���Ī�ǲ�֪�������������ô����\n",
                "peng king" : "�������Ǻ����ˣ�����δ��ͨ�����ʹ���¼ҵ��޹���Ī�ǲ�֪�������������ô����\n",
        ]) ); 
        setup();
        add_money("gold", 10);
        carry_object(__DIR__"obj/dcloth")->wear();
        carry_object(__DIR__"obj/yudai")->wield();
        
}       
