 //TIE@FY3
inherit NPC;
void create()
{
        set_name("������", ({ "bai xiao sheng", "bai"}) );
        set("gender", "����" );
        set("age", 42);
        set("long", "���ǵ����������ֵĵ�һ���ӣ������������ж���Ӣ�۶�����
���ı������ϡ�\n");
        set("combat_exp", 1000000);
        set("attitude", "friendly");
        set_skill("dodge", 100);
        set("intellgent",1);
        set("chat_chance", 10);
        set("chat_msg", ({
                name()+"����ʲô����Ҳ�����Ұ�����������ף�������\n",
                name()+"�����ҵı����׿���Ҫд����ǧ����������㡣\n",
        }) );
        
        setup();
        add_money("gold", 5);
        carry_object("/clone/misc/cloth")->wear();
}        
