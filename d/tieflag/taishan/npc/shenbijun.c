 // weitianpeng.c
#include <ansi.h> 
inherit NPC; 
void create()
{
        set_name("��赾�", ({ "shen bijun","shen" }) );
        set("gender", "Ů��" );
        set("nickname", HIG"��������"NOR );
        set("long",
     "�����������κ���Ҳ�޷����ݵģ������û����������ˣ������������������ˣ�\n���˻�˵����ͼ�����ˡ�����������֧�����ܻ������ķ��ϣ����������ϵ�\n���ӣ�Ҳ��û����������ᡣ�����κ��ˣ�ȻҪ������һ�ۣ�����ԶҲ�޷����ǡ�\n����������еĵ�һ���ˡ�����ھ���  \n"
                );
        set("attitude", "peaceful");
         set("age", 24);
        set("str", 15);
        set("cps", 15);
        set("int",30);
        set("per", 70);
        set("combat_exp", 600000);
        set("neili", 200);
        set("max_neili", 200);
        set("mana", 100);
        set("max_mana", 100);
        set("max_qi", 400);
        set("max_jing", 400);
        set("max_sen", 400);
        set("force_factor", 10);
        set("chat_chance", 1);
        set("chat_msg", ({
             "��ھ�������Ȼ������̾�˿����������۾���\n",
                }) ); 
        set_skill("unarmed", 50);
        set_skill("dodge", 80);
        set_skill("parry", 80);
        set_skill("move", 80);
        set_skill("fall-steps", 50);
        set_skill("meihua-shou", 50);
        map_skill("dodge", "fall-steps");
        map_skill("unarmed", "meihua-shou");
                
        setup(); 
        carry_object("/d/fugui/npc/obj/w_skirt1")->wear();
}    
