 inherit NPC;
void create()
{
        set_name("С����", ({ "baoer", "fang baoyu" }) );
        set("gender", "����");
        set("age", 12);
        set("long", 
        "һ��ʮһ����Ľ���ͯ�ӣ����ô���ݰף�ʮ������ϲ�������������Ͽ��顣\n"
        );
        set("attitude", "friendly");
        set("max_kee", 150); 
        set("combat_exp", 5000);
        set_skill("dodge", 30); 
        setup();
        carry_object(__DIR__"obj/jinyi")->wear();
        add_money("coin", 5);
}   
