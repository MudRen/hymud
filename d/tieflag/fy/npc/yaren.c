 inherit NPC;
void create()
{
        set_name("��ɧ����", ({ "yaren", "ren"}) );
        set("gender", "����" );
        set("age", 22);
        set("long", "����һλС�вŻ������ˣ�����׷����С�\n");
        set("combat_exp", 500000);
        set("attitude", "friendly");
        set("intellgent",1);
        
        set_skill("dagger", 100);
        set_skill("dodge", 100);   
        set_skill("iron-cloth", 200);
        set_skill("unarmed",100);
        set_skill("parry",100);
        
        
        set("chat_chance", 1);
        set("chat_msg", ({
                "��ɧ��������������������仭��������С������ө�����ҹɫ����ˮ���Կ�ţ��֯Ů�ǡ���\n",
                "��ɧ����������ȥ���ƺ����ڴ򸹸塣\n",
        }) );
        
        setup();
        add_money("coin", 5);
        carry_object(__DIR__"obj/fycloth")->wear();
        carry_object(__DIR__"obj/ironpen")->wield();
}     
